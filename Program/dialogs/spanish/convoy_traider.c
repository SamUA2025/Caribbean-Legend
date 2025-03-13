//#include "DIALOGS\convoy_traider.h"
void ProcessDialogEvent()
{
	ref NPChar, d;
	aref Link, Diag;
	string NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
		case "prepare_convoy_quest":
			if (isBadReputation(pchar, 40)) 
			{
				dialog.text = RandPhraseSimple("¡Ahhh, demonios! ¡Sé quién eres! Solo un completo idiota te contrataría para escoltar su barco. ¡Adiós!","¡Oh, sé quién eres! ¿Contratarte como escolta, dices? No soy ningún tonto...");
				link.l1 = RandPhraseSimple("¡Eh, qué lástima!","¡La gente ciertamente se asusta demasiado fácilmente estos días!");
				link.l1.go = "convoy_refused";
			}
			else
			{
				dialog.text = TimeGreeting()+", "+GetAddress_Form(NPChar)+"¡ Yo soy "+GetFullName(NPChar)+", un mercader. ¿Oí que estás buscando trabajo?";
				link.l1 = "Algo así. Y, según he oído, ¿estás buscando al capitán que te escoltará a ti y a tu barco hasta tu destino?";
				link.l1.go = "prepare_convoy_quest_2";
			}
		break;
		
		case "prepare_convoy_quest_2":
			dialog.text = "Exactamente. Además, creo que eres justo la persona adecuada para mi escolta. ¿Qué dirías?";
			link.l1 = "Bueno, hazme una oferta, y tal vez, tendrás un trato.";
			link.l1.go = "prepare_convoy_quest_3";
		break;
		
		case "prepare_convoy_quest_3":
			LookShipConvoy();
			GenerateConvoyQuest(npchar);
			dialog.text = "Necesito ser escoltado a "+XI_ConvertString("Colonia"+pchar.quest.destination+"Gen")+", que está ubicado en "+XI_ConvertString(GetIslandByCityName(pchar.quest.destination)+"Eso")+", en "+FindRussianDaysString(sti(pchar.ConvoyQuest.iDay))+", y por eso te pagaré "+FindRussianMoneyString(sti(pchar.ConvoyQuest.convoymoney))+". ¿Entonces, tu decisión?";
			link.l1 = "Estoy dentro.";
			link.l1.go = "convoy_agreeded";
			link.l2 = "No creo que sea una propuesta interesante.";
			link.l2.go = "convoy_refused";
		break;
		
		case "convoy_refused":
			chrDisableReloadToLocation = false;
			npchar.LifeDay = 0;
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("convoy_refused");
		break;
		
		case "convoy_agreeded":
			chrDisableReloadToLocation = false;
		    pchar.convoy_quest = pchar.quest.destination;
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("convoy_agreeded");
		break;
		
		case "complete_convoy_quest":
			dialog.text = "¡Oh! Gracias. Bajo tu protección me sentí seguro como nunca antes. Aquí está tu bien merecida recompensa.";
			Link.l1 = "De nada.";
			link.l1.go = "exit";
			//слухи
			AddSimpleRumour(LinkRandPhrase("A merchant captain by the name of " + GetFullName(npchar) + " says that captain " + GetMainCharacterNameDat() + " can be trusted when one needs an escort.", 
				"Negociant named " + GetFullName(npchar) + " says that captain " + GetMainCharacterNameDat() + " can be trusted. "+ GetSexPhrase("He","She") +" protected his ship in the best way possible while escorting him to " + XI_ConvertString("Colony" + pchar.quest.destination + "Gen") + ".", 
				"I heard that you keep the word given to trader captains that ask you for an escort. A trader named " + GetFullName(npchar) + " speaks well about you."), sti(npchar.nation), 40, 1);
			pchar.quest.generate_convoy_quest_progress = "completed";
			chrDisableReloadToLocation = false;
			npchar.LifeDay = 0;
			AddDialogExitQuest("convoy_refused");
		break;
	}
} 

// boal 03.05.04 квест сопроводить торговца -->
void GenerateConvoyQuest(ref npchar)
{
	int iTradeMoney, iNation;

	DeleteAttribute(NPChar, "Ship");
    SetShipToFantom(NPChar, "trade", true);

	iNation = GetRelation2BaseNation(sti(npchar.nation)); //если привезти нужно во вражеский город
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.ConvoyQuest.City), GetArealByCityName(pchar.quest.destination));
	if (sti(daysQty) > 14) daysQty = 14;
	pchar.ConvoyQuest.iDay = makeint(sti(daysQty)*(frand(1.3)+0.7));
	iTradeMoney = (sti(daysQty)*600*sti(pchar.GenQuest.Convoy.Shipmod)+rand(100))*sti(daysQty)/sti(pchar.ConvoyQuest.iDay);
	if (iNation == RELATION_ENEMY && sti(npchar.nation != PIRATE)) iTradeMoney = makeint(iTradeMoney * 1.4); //то размер награды увеличивается
	pchar.ConvoyQuest.convoymoney = iTradeMoney;			


	//Log_Info(FindRussianDaysString(sti(daysQty)));
	//Log_Info(pchar.quest.destination);
	//Log_Info(pchar.ConvoyQuest.City);

	SetTimerCondition("generate_convoy_quest_timer", 0, 0, sti(pchar.ConvoyQuest.iDay), false);

	pchar.quest.generate_convoy_quest_progress = "begin";

	pchar.quest.generate_convoy_quest_failed.win_condition.l1 = "NPC_Death";
	pchar.quest.generate_convoy_quest_failed.win_condition.l1.character = "QuestTrader";
	pchar.quest.generate_convoy_quest_failed.win_condition = "generate_convoy_quest_failed";
}

void LookShipConvoy()
{
	switch(makeint(6-sti(RealShips[sti(Pchar.Ship.Type)].Class)))
	{
		case 0:
			pchar.GenQuest.Convoy.Shipmod = 0.7;
		break;
		case 1:
			pchar.GenQuest.Convoy.Shipmod = 1;
		break;
		case 2:
			pchar.GenQuest.Convoy.Shipmod = 1.2;
		break;
		case 3:
			pchar.GenQuest.Convoy.Shipmod = 1.5;
		break;
		case 4:
			pchar.GenQuest.Convoy.Shipmod = 2.2;
		break;
		case 5:
			pchar.GenQuest.Convoy.Shipmod = 3;
		break;
	}
}
