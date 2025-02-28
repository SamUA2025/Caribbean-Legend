// Жоаким Мерриман - португальский сумрачный гений
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
			{
				if (pchar.questTemp.HWIC.Holl == "AbbySeekIsland" && !CheckAttribute(npchar, "quest.HWICHoll.Task"))
				{
					dialog.text = "Guten Tag, Herr! Ich bin Doktor Joachim Merriman. Habe ich das Vergnügen, mit Kapitän zu sprechen "+GetFullName(pchar)+"?";
					link.l1 = "Ja, das bin ich. Wie zum Teufel kennst du meinen Namen? Ich erinnere mich nicht, dich zuvor getroffen zu haben.";
					link.l1.go = "JoakimSeekSkull";
					break;
				}
				if (CheckCharacterItem(pchar, "SkullAztec"))
				{
					dialog.text = "Ich freue mich, Sie zu sehen, Kapitän. Ich kann an Ihrem federnden Schritt erkennen, dass Sie mich sehr glücklich machen werden. Haben Sie den Schädel von Yum Cimil?";
					link.l1 = "Ich habe den Schädel, von dem du sprichst. Er knistert geradezu vor Energie, wie ein brüllender Ofen.";
					link.l1.go = "JoakimFindSkull";
					break;
				}
				dialog.text = "Haben Sie noch etwas zu sagen, Kapitän?";
				link.l1 = "Nein, Senor Merriman. Ich gehe..";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				if (pchar.questTemp.HWIC.Self == "JoakimMeeting" && !CheckAttribute(npchar, "quest.HWICHoll.Task"))
				{
					dialog.text = "Guten Tag, Herr! Ich bin Doktor Joachim Merriman. Habe ich das Vergnügen, mit Kapitän zu sprechen?"+GetFullName(pchar)+"?";
					link.l1 = "Ja, das bin ich. Wie zum Teufel kennst du meinen Namen? Ich erinnere mich nicht, dich vorher getroffen zu haben.";
					link.l1.go = "JoakimSeekSkull";
					break;
				}
				if (CheckCharacterItem(pchar, "SkullAztec"))
				{
					DelLandQuestMark(npchar);
					DelMapQuestMarkCity("Villemstad");
					dialog.text = "Ich freue mich, Sie zu sehen, Kapitän. Ich kann an Ihrem munteren Schritt erkennen, dass Sie mich sehr glücklich machen werden. Haben Sie den Schädel von Yum Cimil?";
					link.l1 = "Ich habe den Schädel, von dem du sprichst. Er knistert förmlich vor Energie, wie ein brüllender Ofen.";
					link.l1.go = "JoakimFindSkull";
					break;
				}
				dialog.text = "Haben Sie noch etwas hinzuzufügen, Kapitän?";
				link.l1 = "Nein, Doktor Merriman. Ich gehe.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "Guten Tag. Wünschen Sie etwas von mir?";
			link.l1 = "Nein, tut mir leid.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Landlady"://хозяйка дома
			dialog.text = "Wenn Sie gekommen sind, um Doktor Merriman zu sehen, er ist nicht hier. Er lebt nicht mehr hier.";
			link.l1 = "Ich verstehe.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady";
		break;
		
		case "Landlady_1"://хозяйка дома
			dialog.text = "Wenn Sie gekommen sind, um Doktor Merriman zu sehen, muss ich Ihnen mitteilen, dass er nicht zu Hause ist. Er ist gerade auf Reisen und ich weiß nicht, wann er zurückkehren wird.";
			link.l1 = "Ich verstehe.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady_1";
		break;
		
		case "Landlady_2"://хозяйка дома
			dialog.text = "Wenn Sie gekommen sind, um Doktor Merriman zu sehen, er ist nicht hier. Er wohnt nicht mehr hier.";
			link.l1 = "Ich verstehe.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady_2";
		break;
		
		case "JoakimSeekSkull":
			PlaySound("Voice\English\hambit\Joakim Merriman-01.wav");
			dialog.text = "Ihre Angelegenheiten sind nicht so privat, wie Sie vielleicht glauben, Kapitän! Aber seien Sie nicht beunruhigt, ich habe einen Vorschlag für Sie! Ich bin ein Mann der Wissenschaft, eine Art Naturphilosoph, der die faszinierende Kultur der indischen Heiden der Spanischen Hauptstadt und der Westindischen Inseln studiert. Wären Sie so freundlich, mit mir zu meinem Haus zu gehen und die potenziell sehr profitablen Details in meinem Wohnzimmer zu besprechen?";
			link.l1 = "Sie haben meine Neugier und meine Aufmerksamkeit. Führen Sie den Weg.";
			link.l1.go = "JoakimSeekSkull_1";
		break;
		
		case "JoakimSeekSkull_1":
			dialog.text = "Sie werden dies nicht ablehnen, Herr! Mein Haus ist nicht weit von hier. Folgen Sie mir!";
			link.l1 = "...";
			link.l1.go = "JoakimSeekSkull_2";
		break;
		
		case "JoakimSeekSkull_2":
			DialogExit();
			AddLandQuestMark(npchar, "questmarkmain");
			LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "Villemstad_houseSp1_room", "goto", "goto1", "JoakimInRoom", -1);
		break;
		
		case "JoakimSeekSkull_3":
			PlaySound("Voice\English\hambit\Joakim Merriman-01.wav");
			dialog.text = "Wir können hier ohne Angst vor lauschenden Ohren sprechen. Sie haben kürzlich meinen Nachbarn Solomon Shneur besucht. Ich war gerade unterwegs und, Sie müssen mir verzeihen, Kapitän, habe zufällig einige Details Ihres Gesprächs mit Solomon mitbekommen. Es war alles so faszinierend, dass ich die gesamte Unterhaltung anhören musste!";
			link.l1 = "Ein Lauscher, der Angst vor anderen Lauschern hat, hm?";
			link.l1.go = "JoakimSeekSkull_4";
		break;
		
		case "JoakimSeekSkull_4":
			dialog.text = "Nun, nun, Kapitän! Es ist überhaupt nicht so! Solomon ist mein Nachbar und er besucht mich oft. Wir sind gute Freunde trotz unserer religiösen Unterschiede! Ich weiß von seinen Missgeschicken... genauso wie jeder andere in Willemstad! Solomon verkündet seine Probleme jedem, der morgens, mittags und abends zuhört. Aber genug davon. Der alte Jude muss Ihnen bereits von einem alten Jadetotenschädel erzählt haben, der zusammen mit seinem Gold auf einer unbekannten Insel versteckt ist. Hat er Ihnen davon erzählt?";
			link.l1 = "Er erzählte mir von einem Schädel, erwähnte aber nicht, dass er aus Jade gemacht war. Er sagte auch, es sei der Schädel seines Großvaters, um ehrlich zu sein, dachte ich, es wäre entweder ein kabbalistischer Horror oder der alte Tölpel hat einige Fledermäuse im Glockenturm.";
			link.l1.go = "JoakimSeekSkull_5";
		break;
		
		case "JoakimSeekSkull_5":
			dialog.text = "Nein, Kapitän, Solomon ist völlig vernünftig, nur exzentrisch. Der Schädel existiert. Es ist ein alter indischer Schatz, Der Jadenschädel von Yum Cimil! Ich habe keine Ahnung, wie der alte Jude seine Krallen darauf bekommen hat. Ich habe die Hälfte meines Lebens nach ihm gesucht\nSuche nach dieser Insel, wo Solomon sein Familienvermögen versteckt hat. Der Schädel muss dort in seiner Truhe sein. Liefern Sie mir diesen Jadenschädel und ich werde Ihnen eine halbe Million Pesos zahlen.";
			link.l1 = "Ein halbes Tausend? Das ist kaum meiner Zeit wert - warte mal... hast du gesagt ein halbes Million Stück von Acht?! Machst du Witze? Ich habe noch nie so viel Geld auf einmal gesehen in meinem Leben!";
			link.l1.go = "JoakimSeekSkull_6";
		break;
		
		case "JoakimSeekSkull_6":
			dialog.text = "Sie sind immer noch ein junger Kapitän... Also, sind Sie dabei? Sie geben mir den Jadeschädel und ich gebe Ihnen im Gegenzug fünfhunderttausend Achtstücke. Abgemacht?";
			link.l1 = "Ha, ein Vermögen für einen alten Schädel? Natürlich bin ich dabei.";
			link.l1.go = "JoakimSeekSkull_7";
		break;
		
		case "JoakimSeekSkull_7":
			dialog.text = "Hervorragend. Es ist immer eine Freude, mit einem Mann zu arbeiten, der den Gewinn versteht. Sie können mich hier in meinem Haus finden, wenn Sie mich weiter benötigen. Viel Glück!";
			link.l1 = "Danke Ihnen, Doktor Merriman. Ich werde Sie nicht zu lange warten lassen.";
			link.l1.go = "exit";
			npchar.quest.HWICHoll.Task = "true";
			LAi_SetOwnerType(npchar);
			AddDialogExitQuestFunction("CheckIslandCoordinates");//вот тут-то мы и проверим, есть ли у нас координаты острова, и далее будем исходить из результата.
		break;
		
		case "JoakimFindSkull":
			PlaySound("Voice\English\hambit\Joakim Merriman-02.wav");
			dialog.text = "Oh, ja! Sie haben definitiv recht mit seiner Kraft... Aber genug Worte, lassen Sie mich es sehen, ich zittere vor Ungeduld.";
			link.l1 = "Hier, bitte, nimm es. Ich hoffe, ich habe mich nicht geirrt?";
			link.l1.go = "JoakimFindSkull_1";
			DelLandQuestMark(npchar);
		break;
		
		case "JoakimFindSkull_1":
			RemoveItems(PChar, "SkullAztec", 1);
			dialog.text = "Ach, unglaublich! Ja, das ist es. Ausgezeichnet, Kapitän, allerbeste! Endlich! Ich habe es endlich bei mir! Ich habe so viele Jahre auf diesen Moment gewartet!";
			link.l1 = "Was ist mit dem Geld, das Sie versprochen haben, Doktor Merriman?";
			link.l1.go = "JoakimFindSkull_2";
		break;
		
		case "JoakimFindSkull_2":
			AddMoneyToCharacter(pchar, 500000);
			dialog.text = "Oh, ja, natürlich! Eine halbe Million Acht-Reales-Stücke. Nimm sie, du hast sie verdient.";
			link.l1 = "Freut mich, Geschäfte mit Ihnen zu machen. Schwer zu glauben, dass so eine kleine Sache so viel wert sein kann...";
			link.l1.go = "JoakimFindSkull_3";
		break;
		
		case "JoakimFindSkull_3":
			dialog.text = "Kleine Sache? Du weißt nicht, wovon du sprichst. Dies ist... bah, dein philisterhafter Verstand kann kaum die Größe der unglaublichen Macht hinter diesem wertvollen Schädel erfassen. Um ehrlich zu sein, habe ich sowieso keine Zeit zu verschwenden\nDanke, Kapitän, für das, was du getan hast. Nun ist es Zeit, Lebewohl zu sagen. Ich muss gehen.";
			link.l1 = "Auf Wiedersehen, Doktor Merriman. Vielleicht treffen wir uns wieder.";
			link.l1.go = "JoakimFindSkull_4";
		break;
		
		case "JoakimFindSkull_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Landlady");
			sld.Dialog.Filename = "Quest\HollandGambit\Joakim.c";
			sld.dialog.currentnode = "Landlady_2";
			SetFunctionTimerCondition("Caleuche_StartTotal", 0, 0, 180, false); // таймер на Калеуче
		break;
		
		case "JoakimSeekSkull_8":
			PlaySound("Voice\English\hambit\Joakim Merriman-01.wav");
			DelLandQuestMark(npchar);
			dialog.text = "Wir können hier sprechen, Kapitän. Ich weiß, dass Sie ein enger Vertrauter von Abigail Shneur sind, der Tochter meines Nachbarn Solomon. Sie ist mit Ihrem Schiff zu ihrem Liebhaber gesegelt... aber das ist eigentlich egal.";
			link.l1 = "Worauf wollen Sie hinaus, Doktor?";
			link.l1.go = "JoakimSeekSkull_9";
		break;
		
		case "JoakimSeekSkull_9":
			dialog.text = "Wenn Sie Solomon kennen, dann müssen Sie seine Geschichte vom Schiffbruch und seinen verlorenen Schätzen kennen, die er auf einer unbekannten Insel versteckt hat. Er hat diese Geschichte bereits jedem in Willemstad erzählt.";
			link.l1 = "Warum vermutest du, dass ich sowohl etwas darüber gehört habe als auch mich um das Unglück des alten Juden kümmere?";
			link.l1.go = "JoakimSeekSkull_10";
		break;
		
		case "JoakimSeekSkull_10":
			dialog.text = "Magst du Solomon nicht? Ich versichere dir, dass er nur ein harmloser alter Exzentriker ist. Vergiss ihn. Lass uns Geschäfte machen\nIch hatte mehrere lange Gespräche mit Solomon. Du kannst dir nicht vorstellen, wie ich mich fühlte, als ich herausfand, dass dieser alte Jude Besitzer eines alten unbezahlbaren Artefakts ist, das ich seit Jahren suche! Der verrückte alte Mann hat es zusammen mit seinem erbärmlichen Geld auf irgendeiner Insel versteckt und er kann sich nicht einmal an ihren Standort erinnern\nIch brauche dieses Artefakt. Bring es mir und ich zahle dir eine halbe Million Achtstücke.";
			link.l1 = "Ein halbe Million Acht-Reales-Münzen? Du machst wohl Witze, Doktor. Ich habe in meinem Leben noch nie so viel Geld auf einmal gesehen!";
			link.l1.go = "JoakimSeekSkull_11";
		break;
		
		case "JoakimSeekSkull_11":
			dialog.text = "Sie sind immer noch ein junger Mann. Also, sind Sie dabei? Sie geben mir den Schädel und ich gebe Ihnen im Gegenzug fünfhunderttausend Achtstücke. Dazu können Sie auch Solomons Geld nehmen. Laut den Worten des alten Mannes müssen es etwa zweihunderttausend Pesos sein... Also insgesamt siebenhunderttausend Achtstücke für Sie. Abgemacht, Kapitän?";
			link.l1 = "Schlag mich tot! Natürlich ist das ein Handel! Aber wie soll ich diese Insel finden?";
			link.l1.go = "JoakimSeekSkull_12";
		break;
		
		case "JoakimSeekSkull_12":
			dialog.text = "Spreche mit Abigail. Vielleicht erinnert sie sich an etwas. Frage Solomon. Siehst du, wenn ich wüsste, wo die Insel zu finden ist, würde ich nicht um deine Hilfe bitten.";
			link.l1 = "Ich verstehe. Entschuldigung für meine dumme Frage. Jetzt diese Insel finden. Stellen Sie nur sicher, dass Sie mit meiner Bezahlung warten.";
			link.l1.go = "JoakimSeekSkull_13";
		break;
		
		case "JoakimSeekSkull_13":
			dialog.text = "Genau. Ich freue mich, dass wir uns verstehen, Kapitän. Viel Glück bei Ihrer Suche. Sie können mich immer hier in meinem Haus finden.";
			link.l1 = "Ich werde Sie nicht zu lange warten lassen, Doktor Merriman. Auf Wiedersehen!";
			link.l1.go = "JoakimSeekSkull_14";
		break;
		
		case "JoakimSeekSkull_14":
			DialogExit();
			pchar.questTemp.HWIC.Self = "SeekAbiIsland";
			AddQuestRecord("Holl_Gambit", "3-55");
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload3", true);//закроем комнату Аби
			npchar.quest.HWICHoll.Task = "true";
			LAi_SetOwnerType(npchar);
			NextDiag.CurrentNode = "First time";
			AddLandQuestMark(characterFromId("Merdok"), "questmarkmain");
			AddMapQuestMarkCity("SentJons", false);
		break;
		
		// калеуче
		case "caleuche":
			PlaySound("Voice\English\LSC\Chymiset-03.wav");
			dialog.text = "Jaaaaa. Die Opfersteine sind rot vom Blut meiner Feinde! Yum Cimil hat mir seine Macht verliehen, die Toten zu befehlen! Mit dieser Macht werde ich bald über die Lebenden herrschen!";
			link.l1 = "Sehr melodramatisch, Merriman. Was planst du mit deiner Armee von wandelnden Leichen zu tun? Spielst du Caesar und versuchst, die Welt zu erobern?";
			link.l1.go = "caleuche_1";
			CreateLocationParticles("large_smoke", "goto", "goto37", 0.5, 0, 0, "");
		break;
		
		case "caleuche_1":
			dialog.text = "Schweig, du Narr! Erwartest du etwa, dass ich meinen geheimen Plan in einem Monolog enthülle?! Nun, ich sehe keinen Grund, es nicht zu tun, du wirst diese Begegnung nicht überleben! Meine untoten Legionen werden zuerst alle dunklen Höhlen und Verliese der Karibik besetzen. Meine Außenposten werden in jedem Dorf liegen, auf mein Signal warten. Und wenn die Zeit gekommen ist, werden meine wandelnden Leichen ausmarschieren und die Länder der Lebenden bedecken!\nSchade, dass du es nicht mehr erleben wirst, du erbärmlicher kleiner Gutmensch, du Möchtegern-Protagonist! Du hast mein Heiligtum betreten - und du wirst es nicht lebend verlassen! Ich werde meine Armee der Dunkelheit anführen!";
			link.l1 = "Hör zu, Kumpel, du führst hier nichts außer Jack und Scheiße, und Jack hat gerade die Stadt verlassen.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			PlaySound("Types\warrior04.wav");
			dialog.text = "Oh ho ho! Du würdest es wagen, mich und meine skelettartigen Diener herauszufordern?! Dann sieh, was ich wirklich bin, und zittere vor Angst!";
			link.l1 = "Komm und hol dir etwas.";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			npchar.model = "Meriman_2";
			Characters_RefreshModel(npchar);
			PlaySound("Ambient\Teno_inside\teleporter.wav");
			dialog.text = "";
			link.l1 = "Ahhh! Süßer Jesus!";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			PlaySound("Voice\English\hambit\Joakim Merriman-04.wav");
			dialog.text = "Verstehst du jetzt, wer vor dir steht, du winselnder Wurm?! Ich habe eine Rechnung mit dir zu begleichen! Yum Cimil selbst begünstigt mich! Ich werde deine Seele verschlingen!";
			link.l1 = "In Ordnung, Knochenkopf. Lass uns tanzen.";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "goto", "goto37", "none", "", "", "Caleuche_MerrimanTeleport", -1);
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(pchar, "goto", "goto37");
			pchar.questTemp.Caleuche.Merriman_hide = "true";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//--> блок реагирования на попытку залезть в сундук
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Du bist ein "+GetSexPhrase("Dieb, Herr! Wachen, nehmt ihn","Diebin, Mädchen! Wachen, nehmt sie fest")+"!!!","Nur schau dir das an! Kaum war mein Rücken gedreht, hast du beschlossen, meine Kiste zu kontrollieren! Schnappt den Dieb!!!","Wachen! Raub! Fangt den Dieb!!!");
			link.l1 = "Verdammt!";
			link.l1.go = "exit";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//<-- блок реагирования на попытку залезть в сундук
	}
}
