// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;   
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("junger Mann","junge Dame")+"?","Was brauchen Sie, "+GetSexPhrase("schön","hübsche")+"? Frag nur."),"Fragen schon wieder","Hihi, wenn es dir recht ist - Fragen...",""+GetSexPhrase("Hm, warum suchst du dir nicht eine Schönheit aus? Ich fange an, Verdächtigungen gegen dich zu hegen...","Hm, warum wählst du dir nicht eine Schönheit aus? Wir haben hier leider keine Jungs, hihi...")+"","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, entschuldigen Sie mich.","Eigentlich, vergiss es."),"Ich... entschuldigung, ich habe momentan keine Fragen.","Du hast recht, es ist bereits das dritte Mal. Entschuldige mich.","Vielleicht nächstes Mal, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			/* //--> Бремя гасконца
			if (CheckAttribute(pchar, "questTemp.Sharlie.Gigolo") && pchar.questTemp.Sharlie.Gigolo == "start")
			{
				DelLandQuestMark(npchar);
				link.l1 = "Hör zu, Aurora, ich brauche ein Mädchen für die Nacht. Und ich möchte sie mit nach Hause nehmen. Kannst du das arrangieren?";
                link.l1.go = "Gigolo";
			}	
			//<-- Бремя гасконца */
		break;
		
		//--> Бремя гасконца
		case "Gigolo":
			dialog.text = "Natürlich, Liebling. Hast du bereits eine passende Maiden gefunden oder soll ich?";
			link.l1 = "Tatsächlich habe ich das getan. Ich habe ein Auge auf ein Mädchen namens Lucille geworfen.";
			link.l1.go = "Gigolo_1";
		break;
		
		case "Gigolo_1":
			dialog.text = "Meinen Sie Lucille Montaigne?";
			link.l1 = "Ehrlich gesagt, ich habe nicht nach ihrem Nachnamen gefragt. Alles was ich weiß, ist, dass sie ein junges, schönes und blondes Mädchen namens Lucille ist.";
			link.l1.go = "Gigolo_2";
		break;
		
		case "Gigolo_2":
			dialog.text = "Ja, das beschreibt sie sehr gut. Also gut. Aber sag mir, warum sie? Sind die anderen Mädchen nicht nach deinem Geschmack?";
			link.l1 = "Nun, Sie sehen... sie hat gerade erst hier angefangen zu arbeiten, also glaube ich, dass sie noch nicht erfahren genug im 'Gewerbe' ist, um meiner Börse zu viel zur Last zu fallen.";
			link.l1.go = "Gigolo_2_1";
			link.l2 = "Sie sehen, ich verehre Blondinen mit heller Haut. Lucille wird in dieser Hinsicht perfekt sein.";
			link.l2.go = "Gigolo_2_2";
		break;
		
		case "Gigolo_2_1":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand1) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 5000;
				dialog.text = "Nun, Monsieur, das ist nicht wahr! Sie ist jung, hübsch und erfahren, alle meine Kunden bewundern sie geradezu. Sie wird Ihnen viel kosten. Fünftausend Pesos für eine Nacht mit ihr, und nicht einen einzigen Peso weniger.";
				if (sti(pchar.money) >= 5000)
				{
					link.l1 = "Teuer, aber sehr gut. Haben Sie Ihr Geld.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Das ist teuer! So viel habe ich nicht. Wir sprechen später.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 2500;
				dialog.text = "Seufz, Sie haben recht, Monsieur, sie ist hübsch und jung, aber sie fehlt an Erfahrung. Meine Kunden bemerken sie normalerweise nicht, deshalb habe ich gefragt. Aber wenn Sie wirklich bescheidene Mädchen mögen, sage ich, sie ist eine gute Wahl. Sie wird Sie zweitausendfünfhundert Pesos kosten.";
				if (sti(pchar.money) >= 2500)
				{
					link.l1 = "Ach, sie wird es gut machen. Haben Sie Ihr Geld.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Das ist teuer! Ich habe nicht so viel. Ich werde später mit dir reden.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_2_2":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand2) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 4500;
				dialog.text = "Du wärst nicht der Erste, Schöner. Manchmal stehen meine Kunden Schlange für ihre Aufmerksamkeit, da sie sich sehr von den dunkelhäutigen Töchtern unserer Inseln unterscheidet. Sie wird dich viertausendfünfhundert Pesos kosten.";
				if (sti(pchar.money) >= 4500)
				{
					link.l1 = "Teuer, aber sehr gut. Haben Sie Ihre Münze.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Das ist teuer! Ich habe nicht so viel. Ich werde später mit dir reden.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 3000;
				dialog.text = "Wirklich, Monsieur? Schon Heimweh? Meine Kreolen und insbesondere meine Mulatten sind leidenschaftlicher als diese entspannte Pariser Gassenkatze. Aber ach, es ist Ihre Wahl. Sie wird Sie drei tausend Pesos kosten.";
				if (sti(pchar.money) >= 3000)
				{
					link.l1 = "Teuer, aber sehr gut. Haben Sie Ihr Geld.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Das ist teuer! So viel habe ich nicht. Ich werde später mit dir reden.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_3":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharlie.Gigolo.Money));
			dialog.text = "Wie du wünschst, Liebster. Lucille wird dich um elf Uhr abends sehnsüchtig erwarten. Außerdem darf sie nicht später als sieben Uhr morgens zurückkehren. Wenn du nicht vor Mitternacht ankommst, wird sie sich einem anderen Kunden widmen, und dann musst du bis zum nächsten Abend warten, um sie zu nehmen. \nUnd denke nicht daran... ihr in irgendeiner Weise weh zu tun, es sei denn, du bereust es. Eine faire Warnung, Liebster.";
			link.l1 = "Machen Sie sich keine Sorgen, ich werde sie wie eine Geliebte behandeln, nicht wie ein Unmensch. Ich werde sie um elf Uhr abholen. Was soll ich bis dahin tun?";
			link.l1.go = "Gigolo_4a";
		break;
		
		case "Gigolo_4a":
			dialog.text = "Nun, ich weiß es nicht einmal, Liebling. Schau in der Taverne vorbei, plaudere mit dem Wirt...";
			link.l1 = "Nicht die schlechteste Idee. Genau das werde ich tun. Hab einen schönen Tag!";
			link.l1.go = "Gigolo_4";
		break;
		
		case "Gigolo_4":
			//DeleteAttribute(pchar, "GenQuest.CannotWait");
			DialogExit();
			AddQuestRecord("SharlieC", "2");
			pchar.questTemp.Sharlie.Gigolo = "girl";
			Sharlie_CreateGigoloGirl();
			QuestPointerDelLoc("fortfrance_town", "reload", "reload9_back");
			QuestPointerDelLoc("fortfrance_brothel", "reload", "reload3");
			QuestPointerToLoc("fortfrance_town", "reload", "reload4_back");
			SetCurrentTime(17, 30);
			//NewGameTip("Доступна функция перемотки времени! Она доступна через опцию 'мысли вслух' в меню действий (ENTER).");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
