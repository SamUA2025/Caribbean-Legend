// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel type de questions?","Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Vous avez déjà essayé de me poser une question "+GetAddress_Form(NPChar)+"... ","Tu parles de cette question pour la troisième fois aujourd'hui...","Ecoutez, si vous n'avez rien à me dire sur les affaires du port, alors ne me dérangez pas avec vos questions.","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire."),"Peu importe.","En effet, déjà la troisième fois...","Désolé, mais je ne suis pas intéressé par les affaires du port pour l'instant.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatHavana")
            {
                link.l1 = "Bonne journée à vous. J'aimerais en savoir plus sur une corvette nommée '"+pchar.questTemp.Slavetrader.ShipName+"sous le commandement de Francois Gontier.";
                link.l1.go = "Havana_ratP_1";
			}
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Excusez-moi, un homme du nom de Joachim Merriman est-il arrivé à votre port ? Un señor d'âge mûr, portugais, avec une moustache, une barbiche et des yeux perçants ?";
				link.l1.go = "caleuche";
			}
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_3" && !CheckAttribute(npchar, "quest.Mtraxx"))
			{
				link.l1 = "Je m'intéresse à un navire nommé 'Cantavro'. Je cherche son capitaine - Esberdo Cabanas, pour une affaire privée. Pourriez-vous m'aider ?";
				link.l1.go = "mtraxx";
			}
		break;
		
		case "Havana_ratP_1":
			dialog.text = NPCStringReactionRepeat("Oui, il était ici. Mais il est déjà parti. Demandez à notre aubergiste à son sujet, il a loué une chambre à l'étage.","Vous avez déjà posé la question et j'ai répondu.","Je vous dis que vous avez déjà posé des questions sur ce Gontier..","Je vous prie de ne pas me déranger !","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Merci. Je ferai cela.","Hm, eh bien ...","Oui, j'ai vraiment demandé ...","Pardon, "+npchar.name+"... ",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Je ne peux rien te dire à son sujet. Même s'il est arrivé, il ne s'est jamais enregistré nulle part.";
			link.l1 = "Je vois. Quel dommage... Très bien, je vais continuer ma recherche ...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "mtraxx":
			dialog.text = "Voyons voir... la goélette 'Cantavro' a pris la mer il y a deux jours pour une patrouille... cependant, la destination n'est pas indiquée. C'est un navire militaire, donc la destination est connue uniquement de son capitaine et du commandant du fort. Je vous suggère de parler directement avec le commandant, vous pouvez le trouver au fort, si vous souhaitez en savoir plus. Malheureusement, c'est tout ce que je peux faire pour vous.";
			link.l1 = "Je vois. Eh bien, merci pour votre temps...";
			link.l1.go = "exit";
			npchar.quest.Mtraxx = "true";
			AddQuestRecord("Roger_1", "5");
			DelLandQuestMark(npchar);
			AddLandQuestMark(characterFromId("Havana_tavernkeeper"), "questmarkmain");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
