// диалоги персонажей по квесту Мангароса
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
        case "First time":
			dialog.text = "Was willst du?";
			link.l1 = "Nichts.";
			link.l1.go = "exit";
		break;
		
		// Амелия - знахарка-цыганка
		case "amelia":
			dialog.text = "Was willst du in meinem Haus?";
			if (CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "amelia")
			{
				link.l1 = "Dein Name ist Amelia, nicht wahr? Ich kam, um dich über eine Pflanze zu fragen. Manga Rosa.";
				link.l1.go = "amelia_1";
			}
			else
			{
				link.l1 = "Ich habe dir noch nichts zu erzählen. Aber eines Tages komme ich zurück...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "amelia";
		break;
		
		case "amelia_1":
			dialog.text = "Interessant! Und wer hat dir von mir erzählt, tapferer junger Mann?";
			link.l1 = "Einer deiner Leute. Sie sagte, dass du die Geheimnisse dieser Pflanze kennst und du kannst mir beibringen, wie man daraus spezielle Tränke herstellt...";
			link.l1.go = "amelia_2";
		break;
		
		case "amelia_2":
			dialog.text = "Zeigen Sie mir zuerst die Pflanze, von der Sie sprechen. Vielleicht wissen Sie gar nichts darüber und verschwenden nur meine Zeit. Wo ist Ihre Manga Rosa?";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Hier, schau mal.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "Hm...";
				link.l1.go = "amelia_exit";
			}
		break;
		
		case "amelia_exit":
			dialog.text = "Und was wolltest du mir zeigen? Du hast keine Manga Rosa. Also raus hier, Kumpel, bevor ich wütend werde. Dieses Gespräch ist beendet.";
			link.l1 = "Aber...";
			link.l1.go = "exit";
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_wait":
			dialog.text = "Du schon wieder? Such nicht nach Ärger, Junge...";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Beruhige dich, Amelia. Ich habe es letztes Mal irgendwo fallen lassen. Hier, ich habe dir Manga Rosa mitgebracht. Schau mal.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "Hello, friend.";
				link.l1.go = "amelia_exit";
			}
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_3":
			dialog.text = "Lass uns mal sehen... Es scheint, dass du etwas darüber weißt. Und willst du, dass ich dir die Geheimnisse meiner Tränke verrate?";
			link.l1 = "Genau. Und nicht umsonst, wie ich verstehe...";
			link.l1.go = "amelia_4";
		break;
		
		case "amelia_4":
			dialog.text = "Du hast es richtig verstanden, junger Mann! Du siehst nicht aus wie ein kompletter Idiot. Nun, ich kann einem Mann, der nach Wissen sucht und diese seltene Pflanze nicht auf nutzloses Rauchzeug verschwendet, etwas beibringen...";
			link.l1 = "Amelia, bevor wir mit dem Handeln beginnen... könntest du mir freundlicherweise einige grundlegende Kenntnisse über Tränke vermitteln, die ich aus Manga Rosa herstellen kann?";
			link.l1.go = "amelia_5";
		break;
		
		case "amelia_5":
			dialog.text = "Kein Handeln, Kumpel. Ich werde dir den Preis nennen und es wäre deine Entscheidung, ihn zu zahlen oder nicht. Zähle nicht auf irgendeinen Handel oder Rabatt, das ist kein Markt. Und was deine Frage betrifft... Du kannst besondere Tränke aus Manga Rosa herstellen, die deine körperlichen Fähigkeiten stärken. Sie können dich stärker, ausdauernder oder schneller machen, oder sie können deinen Körper komplett verändern und dich in jeder Hinsicht stärker machen, aber ein solcher Trank hätte eine schwächere Wirkung als die beiden vorherigen.";
			link.l1 = "Sehr interessant. Nenne deinen Preis.";
			link.l1.go = "amelia_6";
		break;
		
		case "amelia_6":
			dialog.text = "Ich kann dir drei Rezepte beibringen. Für jedes Rezept verlange ich eine Pflanze und fünfhundert Goldmünzen.";
			link.l1 = "Erzähl mir mehr über diese Tränke. Was macht jeder von ihnen?";
			link.l1.go = "amelia_7";
		break;
		
		case "amelia_7":
			dialog.text = "Du musst ein Meister der Alchemie sein, wenn du einen einzigen Trank herstellen willst. Jeder Trank hält zwei Tage oder weniger, je nachdem, wann du ihn trinkst, wenn du ihn um Mitternacht trinkst, wird er fast zwei volle Tage dauern\nDer erste Trank verleiht dir Kraft und Ausdauer. Du wirst besser kämpfen, weniger Schaden nehmen und mehr Gewicht tragen können\nDer zweite Trank macht dich schneller, agiler, unermüdlicher und verbessert auch deine Zielsicherheit\nDer dritte Trank hat die halbe Wirkung der beiden vorherigen Tränke. Aber er gibt dir auch Charme, Selbstvertrauen und Glück\nAlle auf Manga Rosa basierenden Tränke haben eine positive Wirkung auf deine Gesundheit. Du darfst nur einen Trank auf einmal trinken, mische sie niemals, sonst werden sie dir nichts nützen, im Gegenteil, du wirst eine starke Vergiftung bekommen\nAlso, hübscher, bist du bereit, jetzt sofort für das Wissen zu bezahlen, oder brauchst du Zeit zum Nachdenken?";
			if (CheckCharacterItem(pchar, "cannabis7") && PCharDublonsTotal() >= 500)
			{
				link.l1 = "Ja, ich bin bereit.";
				link.l1.go = "amelia_8";
			}
			link.l2 = "Ich muss ein wenig nachdenken. Das ist eine große Entscheidung, die getroffen werden muss.";
			link.l2.go = "exit";
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_next":
			if (!CheckAttribute(npchar, "quest.ChickenGod") && CheckCharacterItem(pchar, "talisman11")) {
				if (CheckAttribute(npchar, "quest.recipe_power") || CheckAttribute(npchar, "quest.recipe_fast") || CheckAttribute(npchar, "quest.recipe_total")) {
					link.chickengod = "Amelia, you seem to have a knack for such things. Can you tell me if there is a demand for such stones among your people? I find them everywhere - it's like everyone is obsessed with them!";
					link.chickengod.go = "chickengod";
				}
			}
			
			if (CheckAttribute(npchar, "quest.ChickenGod") && !CheckAttribute(npchar, "quest.ChickenGod.Complete") && GetCharacterItem(pchar, "talisman11") >= 113) {
				link.chickengod = "Here you go, Amelia. Just as you ordered: one hundred and thirteen adder stones.";
				link.chickengod.go = "chickengod_collected";
			}
		
			if (CheckAttribute(npchar, "quest.recipe_all"))
			{
				dialog.text = "Ach, du bist es, junger Mann! Also, haben meine Tränke dir geholfen?";
				link.l1 = "Sie haben wirklich, Amelia. Danke!";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "Ach, du bist es, junger Mann! Willst du einige Rezepte kaufen?";
				if (CheckCharacterItem(pchar, "cannabis7") && PCharDublonsTotal() >= 500)
				{
					link.l1 = "Genau. Deshalb bin ich hier.";
					link.l1.go = "amelia_8";
				}
				
				link.l2 = "Noch nicht, Amelia. Ich zahle dir nur einen Besuch ab.";
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_8":
			dialog.text = "Sehr gut. Welches Rezept möchten Sie kaufen?";
			if (!CheckAttribute(npchar, "quest.recipe_power"))
			{
				link.l1 = "Das Rezept für den Trank der Stärke und Ausdauer.";
				link.l1.go = "power";
			}
			if (!CheckAttribute(npchar, "quest.recipe_fast"))
			{
				link.l2 = "Das Rezept für den Trank der Beweglichkeit und Unermüdlichkeit.";
				link.l2.go = "fast";
			}
			if (!CheckAttribute(npchar, "quest.recipe_total"))
			{
				link.l3 = "Das Rezept eines komplexen Tranks.";
				link.l3.go = "total";
			}
		break;
		
		case "power":
			dialog.text = "Gut. Ich habe es 'Gezeitenwelle' genannt. Hier, nimm eine Anleitung. Lies sie sorgfältig durch. Und vergiss nicht, wie man es richtig benutzt!";
			link.l1 = "Danke, Amelia...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosapower");
			SetAlchemyRecipeKnown("mangarosapower");
			npchar.quest.recipe_power = true;
		break;
		
		case "fast":
			dialog.text = "Gut. Ich habe es 'Sturm' genannt. Hier, nimm eine Anleitung. Lies sie sorgfältig. Und vergiss nicht, es richtig zu verwenden!";
			link.l1 = "Danke, Amelia...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosafast");
			SetAlchemyRecipeKnown("mangarosafast");
			npchar.quest.recipe_fast = true;
		break;
		
		case "total":
			dialog.text = "Gut. Ich habe es 'Meeresumarmung' genannt. Hier, nimm eine Anleitung. Lies sie sorgfältig durch. Und vergiss nicht, sie richtig zu benutzen!";
			link.l1 = "Danke, Amelia...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosatotal");
			SetAlchemyRecipeKnown("mangarosatotal");
			npchar.quest.recipe_total = true;
		break;
		
		case "recipe_exit":
			DialogExit();
			NextDiag.CurrentNode = "amelia_next";
			RemoveDublonsFromPCharTotal(500);
			RemoveItems(pchar, "cannabis7", 1);
			Log_Info("You have given 500 doubloons and one Manga Rosa");
			PlaySound("interface\important_item.wav");
			if (CheckAttribute(npchar, "quest.recipe_power") && CheckAttribute(npchar, "quest.recipe_fast") && CheckAttribute(npchar, "quest.recipe_total"))
			{
				npchar.quest.recipe_all = true;
				CloseQuestHeader("mangarosa");
			}
		break;
		
		case "chickengod":
			dialog.text = "Bei Gott, tatsächlich! Es hat wenig Wert, kann aber für diejenigen nützlich sein, die wissen. Bringe mir hundertdreizehn davon und ich werde eine meiner Kisten für dich öffnen.";
			link.l1 = "Das ist ein ganzer Haufen Steine! Warum sagst du mir nicht zuerst, warum du sie brauchst?";
			link.l1.go = "chickengod_1";
		break;
		
		case "chickengod_1":
			dialog.text = "Nein, Liebling, wenn du fragen musst, dann ist dieses Wissen noch nicht von Nutzen für dich.";
			link.l1 = "Und was befindet sich in der Kiste, die Sie so großzügig versprochen haben zu öffnen?";
			link.l1.go = "chickengod_2";
		break;
		
		case "chickengod_2":
			dialog.text = "Eine große Menge Dinge, nützlich für Kapitäne, die Handarbeit nicht scheuen. Verschwende meine Zeit nicht, Liebling, du kannst sowieso nicht so viele Kiesel sammeln.";
			link.l1 = "Wir werden sehen!";
			link.l1.go = "exit";
			
			npchar.quest.ChickenGod = true;
		break;
		
		case "chickengod_collected":
			dialog.text = "Ha-ha-ha! Ich war ein Scherz, Liebling!";
			link.l1 = "Witze werden auf dich sein, wenn sie dich, Hexe, in deiner eigenen Hütte verbrennen!";
			link.l1.go = "chickengod_collected_1";
		break;
		
		case "chickengod_collected_1":
			dialog.text = "Das ist nicht mein Schicksal, Liebster... Du hast diese Zigeunerin stolz gemacht! Hier, diese Truhe gehört dir zum Plündern.";
			link.l1 = "Danke dir, Amelia. Aber ich hoffe wirklich, dass da drinnen etwas Nützliches ist, außer deiner alten Unterwäsche...";
			link.l1.go = "exit";
			
			TakeNItems(pchar, "talisman11", -113);
			npchar.quest.ChickenGod.Complete = true;
			AddDialogExitQuestFunction("ChickenGod_AmeliaOpenChest");
		break;
	}
} 
