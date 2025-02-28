// официантка Наталия Бушелл
#include "DIALOGS\%language%\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "Oh! Und sie sagten mir, du wärst ertrunken... Lügner!";
				link.l1 = "Sicher, das haben sie! Hah! Mir geht's gut!";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Guten Tag, "+GetAddress_Form(NPChar)+"! Das erste Mal hier? Ich habe dich noch nie gesehen... Ich hoffe, du besuchst uns öfter, Sancho kann eine ausgezeichnete Auswahl an Getränken anbieten. Ja, und mein Name ist Nathalie und ich helfe Sancho bei den Angelegenheiten der Taverne.";
				link.l1 = TimeGreeting()+". Mein Name ist "+GetFullName(pchar)+". Freut mich, dich zu treffen. Und du konntest mich vorher nicht sehen. Ich bin erst kürzlich hierher gekommen.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Ach, "+GetFullName(pchar)+"! "+TimeGreeting()+"! Willst du etwas?";
				link.l1 = LinkRandPhrase("Hast du etwas Interessantes zu sagen?","Gibt es Neuigkeiten auf der Insel?","Wirst du mir die neuesten Klatsch und Tratsch erzählen?");
				link.l1.go = "rumours_LSC";
				link.l2 = "Ich möchte Ihnen ein paar Fragen über die Insel stellen.";
				link.l2.go = "int_quests"; //информационный блок
				link.l5 = "Wollte nur wissen, wie es dir geht. Wir sehen uns!";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // первая встреча
			dialog.text = "Kürzlich? Hat ein weiteres Schiff einen Unfall gehabt? Ich habe nichts gehört... Oder sind Sie nicht genauso wie Monsieur Turam auf dem Wrack des Mastes angekommen? Oh, verzeihen Sie meine Neugier, die Natur der Frauen, wissen Sie.";
			link.l1 = "Nein, es ist in Ordnung, Nathalie. Ich bin hier auf einer Barke angekommen, aber sie ist gesunken. Es war schön, dich zu treffen. Bis später!";
			link.l1.go = "exit";
			link.l2 = "Nein, es ist in Ordnung. Ich wollte Ihnen nur ein paar Fragen zur Insel stellen.";
			link.l2.go = "int_quests"; //информационный блок
			NextDiag.TempNode = "First time";
		break;
		
//--------------------------------------- блок вопросов и ответов ---------------------------------------------
		case "int_quests":
			dialog.text = "Ich höre zu.";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "Du arbeitest in der Taverne. Was kannst du mir über den Besitzer erzählen?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "Und wie bist du hier gelandet?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "Wie viele Menschen leben hier?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "Bist du niemals überrascht, hier neue Gesichter zu sehen?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "Keine Fragen. Wenn Sie mich entschuldigen würden...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "Nur positive Dinge,  "+GetAddress_Form(NPChar)+". Sancho hat immer eine große Auswahl an Getränken - von alten Weinen bis hin zu einfachem Bier und Rum. Vor einigen Jahren fand er einen riesigen Vorrat an Vintage-Weinen. Sancho hatte zwei Monate damit verbracht, Kisten mit Flaschen in seinen Laden zu bringen\nUnd jetzt sind wir gut mit Wein versorgt, den nur Gouverneure sich damals im Archipel leisten konnten. Auch Rum ist kein Problem. Sancho kann dich nicht nur mit Getränken versorgen, sondern auch mit frischen Nachrichten, einem guten Rat und einem warmen Bett für die Nacht.";
			link.l1 = "Ich sehe...";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "Oh, das ist eine traurige Geschichte. Vor sieben Jahren bin ich mit meinem Verehrer von zu Hause weggelaufen und wir beschlossen, von Santiago nach Belize zu ziehen. Der Navigator machte einen Fehler in der Nähe von Main, also segelten wir in die falsche Richtung nach Norden und wurden von einem Sturm erwischt. Unser Schiff sank nicht weit vom äußeren Ring\nMein Verehrer starb an diesem Tag, genau wie die meisten anderen. Ich und die Überlebenden haben hier, auf der Insel, neue Leben begonnen.";
			link.l1 = "Traurige Geschichte...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "Ziemlich viel. Die Clans der Rivados und Narwale sind stark in der Anzahl, sie leben schon seit Jahrzehnten hier. Es gibt nicht so viele gewöhnliche Leute, aber die Taverne ist jede Nacht voll. Ich schaffe es kaum, Getränke zu servieren.";
			link.l1 = "Wirklich? Interessant.";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
		break;
		
		case "ansewer_4":
			dialog.text = "Und warum sollten wir das tun? Es kommen sehr oft viele neue Gesichter. Ich weiß nicht einmal, wie viele von uns hier leben. Manchmal sehe ich einen Mann zum ersten Mal und er erzählt mir, dass er schon seit einem Jahr hier lebt.";
			link.l1 = "Nun...";
			link.l1.go = "int_quests";
			npchar.quest.answer_4 = "true";
		break;
// <-- блок вопросов и ответов
		
//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Was machst du da, huh? Dieb!","Schau dir das an! Kaum war ich in Gedanken versunken, hast du beschlossen, meine Truhe zu überprüfen!","Entschieden, meine Truhen zu überprüfen? Das wirst du nicht ungestraft tun!");
			link.l1 = "Verdammt!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Was?! Du hast beschlossen, meine Kisten zu überprüfen? Das wirst du nicht ungestraft tun!";
			link.l1 = "Dummes Mädchen!";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//замечание по обнажённому оружию
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("Hör zu, du solltest besser deine Waffen weglegen. Es macht mich nervös.","Weißt du, mit dem Schwert herumzulaufen ist hier nicht geduldet. Nimm es weg.","Hör zu, spiel nicht den mittelalterlichen Ritter, der mit einer Waffe herumläuft. Leg sie weg, sie steht dir nicht...");
			link.l1 = LinkRandPhrase("Gut.","In Ordnung.","Wie du sagst...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar,"Hör zu, ich bin Bürger der Stadt und ich bitte dich, dein Schwert wegzustecken.","Hör zu, ich bin ein Bürger der Stadt und ich bitte dich, dein Schwert zu scheiden.");
				link.l1 = LinkRandPhrase("Gut.","In Ordnung.","Wie du sagst...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar,"Sei vorsichtig, Kumpel, beim Laufen mit einer Waffe. Ich kann nervös werden...","Ich mag es nicht, wenn Leute vor mir gehen und ihre Waffe bereithalten. Das macht mir Angst...");
				link.l1 = RandPhraseSimple("Hab's verstanden.","Ich nehme es weg.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
