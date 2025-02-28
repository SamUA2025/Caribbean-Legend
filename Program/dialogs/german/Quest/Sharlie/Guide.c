// гид
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Brauchst du etwas?";
			link.l1 = "Nein, nichts.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "guide_0":
			SetAchievement("Test_Ach");
			PlaySound("Voice\English\LE\Greguar\Greguar_01.wav");
			dialog.text = "Willkommen in der Karibik, Monsieur! Erlauben Sie mir, mich vorzustellen, ich bin "+GetFullName(npchar)+". Sie sind neu in unserer Kolonie, richtig?";
			link.l1 = "Grüße, Monsieur. Mein Name ist "+GetFullName(pchar)+". Ja, ich bin gerade ausgestiegen. Ich glaube, ich habe dich vorher nicht gesehen... Kenne ich dich?";
			link.l1.go = "guide_1";
		break;
		
		case "guide_1":
			DelLandQuestMark(npchar);
			dialog.text = "Nein, Monsieur, das tun Sie nicht, aber ich konnte die Gelegenheit nicht verpassen, mich einem feinen Adeligen wie Ihnen vorzustellen.\nOh, ich erinnere mich an meinen ersten Tag hier, den Tag meiner Ankunft in der Neuen Welt. Die Dinge sind hier sehr anders. Der lokale Lebensstil kann Ihre Gesundheit und Brieftasche ruinieren.\nDeswegen biete ich Ihnen meine bescheidene Hilfe an. Kostenlos, was hier ziemlich selten ist, haha! Ich kann Sie mit unserer Kolonie und dem Archipel vertraut machen. Betrachten Sie es als kleine Tour.";
			link.l1 = "Das ist sehr freundlich von Ihnen, danke, Monsieur! Ich freue mich, Ihr Angebot anzunehmen. Wissen ist schließlich Macht.";
			link.l1.go = "guide_2";
			link.l2 = "Ich schätze Ihr Angebot, Monsieur, wirklich, aber ich werde passen.";
			link.l2.go = "guide_exit";
		break;
		
		case "guide_exit":
			dialog.text = "Wie Sie wünschen, Monsieur. Es war jedenfalls schön, Sie kennenzulernen. Ehrenwerte Herren sind hier seltene Gäste. Ich wünsche Ihnen viel Glück!";
			link.l1 = "Du auch, "+GetFullName(npchar)+"!";
			link.l1.go = "guide_exit_1";			
		break;
		
		case "guide_exit_1":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_2":
			dialog.text = "Es freut mich, das zu hören. Es ist mir eine Freude. Nun, lassen Sie mich Ihnen einige Grundlagen vorstellen. Die meisten Kolonien sind nach einem ähnlichen Schema aufgebaut: eine Siedlung an der Küste, geschützt durch eine Festung und Stadtmauern mit Toren. Adlige, Reiche, Soldaten, Seeleute, Kaufleute, Söldner und Verbrecher - sie alle leben innerhalb dieser Mauern zusammen.\nManchmal trifft man auch Kapitäne, Mönche, Zigeuner und Bettler. Indianer werden Sie auf den Straßen jedoch nicht finden, diese Wilden machen den Leuten Unbehagen. Wenn Sie Indianer sehen wollen, müssen Sie in den Dschungel hinaus. Folgen Sie mir, ich zeige Ihnen einige unserer lokalen Einrichtungen.";
			link.l1 = "";
			link.l1.go = "guide_3";			
		break;
		
		case "guide_3": // идем в таверну
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload4_3", "Guide_tavern", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_4":
			dialog.text = "Dies ist der wichtigste Ort in jeder Kolonie - die Taverne. Ja, in Europa mögen diese Orte als Hort des Abschaums und der Schurkerei betrachtet werden, aber hier in der Neuen Welt ist es anders. Ein Wirt kann Ihnen ein Zimmer zum Schlafen anbieten, etwas Rum, saftigen Klatsch und eine Arbeit.\nWenn Sie Informationen benötigen, versuchen Sie, mit den Gästen hier zu sprechen. Kaufen Sie einem Betrunkenen ein weiteres Getränk und Sie könnten etwas Interessantes als Gegenleistung bekommen... oder auch nicht! Glücksspiel ist hier beliebt, aber hüten Sie sich vor den Betrügern. Wenn Sie jemanden beim Schummeln erwischen, zögern Sie nicht, ihn auf der Stelle zu töten. Niemand wird Sie dafür verurteilen.\nEine Taverne ist auch ein Ort, an dem Sie Besatzung und Offiziere für Ihr Schiff anheuern können, vorausgesetzt, Sie besitzen eines. Denken Sie daran: Die Taverne bietet Informationen, Arbeit, Besatzung und Unterhaltung.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-2.08, 5.32, 68.88, false, -15.00, -0.60, 55.00);
		break;
		
		case "guide_5": // к магазину
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload6_3", "Guide_store", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_6":
			dialog.text = "Der Laden ist das Handelszentrum jeder Kolonie. Kapitäne besuchen diesen Ort genauso oft wie die Werft. Hier können Sie Munition, Vorräte oder Handelsgüter kaufen. Der Handel ist ziemlich knifflig.\nErstens dauert es eine Weile, die besten Orte zum Kaufen oder Verkaufen zu finden. Zweitens benötigen Sie gute Handelsfertigkeiten, um mit den örtlichen Händlern zu verhandeln.\nDeshalb stellen die meisten Kapitäne Zahlmeister ein, um an ihrer Stelle Geschäfte zu führen. Vergessen Sie also nicht, einen Profi einzustellen, wenn... oder falls Sie Ihr eigenes Schiff bekommen. Dies ist entscheidend, Sie wollen hier kein Geld verschwenden. Ein Fehler und Sie sind ruiniert. Noch eine letzte Sache. Händler in Geschäften können Ihnen oft Lieferverträge anbieten, das könnte in Zukunft nützlich sein.";
			link.l1 = "";
			link.l1.go = "guide_26";
			locCameraFromToPos(-21.10, 6.60, 45.21, false, -30.00, 3.70, 45.00);
		break;
		
		case "guide_7": // к тюрьме
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload_jail", "Guide_prison", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_8":
			dialog.text = "Und das ist das Gefängnis. Ein schmutziger Ort. Die schlimmsten Verbrecher enden ziemlich schnell mit einem Strick um den Hals, also werden hier meistens die kleinen Fische festgehalten.\nWenn du mit ihnen plaudern willst, sprich mit dem Gefängniswärter. Er lässt dich gegen eine kleine Gebühr, oder sogar kostenlos, wenn du überzeugend genug bist, hinein! Es kann nützlich sein, aber denke daran, dass man diesen Abschaum nicht vertrauen kann, obwohl sie immer süß reden und hinter Gittern ihre Unschuld beteuern.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-52.40, 7.63, 42.60, true, 15.00, -4.00, -30.00);
		break;
		
		case "guide_9": // на рынок
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "merchant", "mrcActive4", "Guide_market", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_10":
			dialog.text = "Dies ist der Marktplatz. Händler verkaufen und kaufen alles, was du brauchst. Ein Waffenschmied kann dir mit Klingen, Feuerwaffen, Rüstungen, Munition und so weiter versorgen. Gute Ausrüstung ist jedoch selten, also erwarte nicht, Meisterwerke einfach hier herumliegen zu finden. Solche Dinge kommen zu einem hohen Preis und Risiko, aber du kannst hier gute Klingen und Handfeuerwaffen finden, es sei denn, jemand kauft sie vor dir.\nEin Kräuterkenner kann Gesundheitspotionen, Antidote, Pflanzen, Zutaten, Flaschen anbieten, und wenn du Glück hast, Rezepte. Aber warum erzähle ich dir das überhaupt, du bist kein Alchemist, oder? Die Zigeuner bieten heidnische Amulette und nutzlosen Schrott wie Fledermausleichen an. Einige Leute behaupten, einen Nutzen für solche Dinge zu kennen, aber das ist alles Unsinn.\nMönche verkaufen Kerzen, heilige Talismane und andere gesegnete Nippes: Kreuze, Ringe, Schreibwerkzeuge. Und die Schrotthändler verkaufen Müll sowie verschiedene Gegenstände, aber wenn du die notwendigen Handwerksfähigkeiten hast, kannst du aus Schildkrötenkämmen, Nägeln und Seilen etwas Nützliches herstellen.";
			link.l1 = "";
			link.l1.go = "guide_19";
			locCameraFromToPos(-13.58, 4.11, 69.06, false, -45.00, -6.00, 52.00);
		break;
		
		case "guide_11": // к резиденции
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload3_1", "Guide_townhall", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_12":
			dialog.text = "Ach, betrachte den Gouverneurspalast! Dies ist das Zuhause und das Büro des wichtigsten Mannes in der Kolonie. Adlige besuchen den Palast für Bälle und Partys, Geschäftsleute und Kapitäne kommen hierher, um sowohl offizielle als auch persönliche Angelegenheiten zu klären. Es ist immer klug, auf der Freundesliste des Gouverneurs zu sein, er hat großen Einfluss auf die Bürger der Nation, die er vertritt.\nFreibeuter können auch gutes Geld verdienen, wenn sie für Gouverneure arbeiten, die Kriegsgefangene auslösen können. Wenn du wohlhabend bist und eine gute Beziehung zu Seiner Exzellenz aufbauen möchtest, könnte er dich sogar ehren, indem er mit dir um hohe Einsätze spielt.\nEs scheint, dass du ungeduldig bist, mein Freund. Hast du es eilig?";
			link.l1 = "Nun... ja. Monsieur, um ehrlich zu sein, ich bin hierher gekommen, um meinen Bruder zu finden, mir wurde gesagt, dass er hier sein muss, in Saint-Pierre. Er ist ein wichtiger Mann, der Gouverneur muss ihn kennen.";
			link.l1.go = "guide_13";
			locCameraFromToPos(3.14, 7.39, 37.55, false, 1.06, 9.00, 14.14);
		break;
		
		case "guide_13":
			dialog.text = "Aha, ich verstehe. Also möchten Sie Seiner Exzellenz einen Besuch abstatten und ihn nach Ihrem Bruder fragen? Nun, dann werde ich Sie nicht weiter aufhalten. Unser Gouverneur heißt Jacques Dille du Parquet, ich bin sicher, er wird tun, was er kann.";
			link.l1 = "Sag mir, wer könnte mir sonst noch helfen? Vielleicht ist es unklug, Seine Exzellenz wegen einer solchen Kleinigkeit zu belästigen?";
			link.l1.go = "guide_14";
		break;
		
		case "guide_14":
			dialog.text = "Du hast gesagt, dass dein Bruder hier bekannt ist. Frage auf den Straßen herum. Irgendwann wirst du jemanden finden, der helfen kann. Wie heißt dein Bruder?";
			link.l1 = "Michel de Monper.";
			link.l1.go = "guide_15";
		break;
		
		case "guide_15":
			dialog.text = "Michel de Monper... Ja, ich habe diesen Namen schon einmal gehört, aber ich wurde dem Mann nie vorgestellt, also kann ich Ihnen nicht helfen. Viel Glück, Monsieur, ich bin sicher, wir werden uns wieder treffen.";
			link.l1 = "Danke, "+GetFullName(npchar)+"!";
			link.l1.go = "guide_16";
		break;
		
		case "guide_16":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);//запрет диалога
			LAi_group_MoveCharacter(npchar, "FRANCE_CITIZENS"); // пока идем заниматься Мишелем
			chrDisableReloadToLocation = false;//открыть локацию
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_17": // к ростовщику
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload8_1", "Guide_bank", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_18":
			dialog.text = "Dies ist das Haus des Geldverleihers, oder Wucherers, Bankiers, ihre Sorte hat viele verschiedene Namen, oft sehr unhöfliche. Du kannst von ihnen halten, was du willst, aber ihre Dienste können dir sehr helfen. Du kannst Geld einzahlen, Dublonen und Pesos wechseln, Schmuck verkaufen oder kaufen. Wenn du eine positive Ehre hast, kannst du sogar einige Münzen leihen, aber sei vorsichtig.\nWucherer bieten die besten Preise für Edelsteine, Juwelen und andere wertvolle Kleinigkeiten, besuche sie immer, um solche Dinge zu verkaufen. Sie sind mächtige Leute, also stelle dich ihnen nicht in den Weg.";
			link.l1 = "";
			link.l1.go = "guide_11";
			locCameraFromToPos(3.07, 7.64, 51.99, false, 45.00, -8.30, 4.50);
		break;
		
		case "guide_19": // к борделю
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload9_1", "Guide_brothel", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_20":
			dialog.text = "Ach, ein Bordell. Jeder Mann besucht solche Orte, sonst wären sie längst pleite! Selbst die Adligen tun es, auf Kosten ihrer Ehre. Sei dir dessen bewusst. Sei nett zu den Mädchen und sie können dir interessante Dinge erzählen, manchmal neigen Männer dazu, ihnen fast alles zu erzählen, und das könnte dir nützlich sein.\nWenn du nicht nach den Geheimnissen anderer suchst, dann bedenke dies: es gibt kein besseres Heilmittel für deinen Geist und deinen Körper als die Liebe. Wenn deine Vitalität schlecht ist - besuche die Mädchen. Du kannst auch einen speziellen Trank trinken, um deine Vitalität zu verbessern, doch er ist selten und bei weitem nicht so spaßig. Oh, wenn ich von deiner 'Vitalität' spreche, meine ich nicht Kratzer auf deiner Haut. Du wirst getroffen, viel. Aber wenn sie dich hart und oft treffen oder wenn du zu viele starke Heiltränke trinkst, wirst du schließlich deinen Körper ruinieren. Achte auf deinen Zustand, ruhe dich aus, wenn nötig, oder leide unter den Konsequenzen.";
			link.l1 = "";
			link.l1.go = "guide_17";
			locCameraFromToPos(-2.75, 7.07, 61.10, false, 60.00, -6.60, 42.65);
		break;
		
		case "guide_21":
			dialog.text = "Oh, du schon wieder, mein Freund! Ich sehe, sie haben dich in den heiligen Ort Saint-Pierre gelassen - das Hauptquartier der Malteserritter! Du musst wichtig sein. Hast du deinen Bruder gefunden?";
			link.l1 = "Allerdings, das habe ich...";
			link.l1.go = "guide_22";
		break;
		
		case "guide_22":
			dialog.text = "Verzeihen Sie mir, Monsieur, aber Sie sehen ziemlich düster aus...";
			link.l1 = "Verdammte Scheiße! Ich hatte gehofft, aus diesem Drecksloch zu entkommen und zurück nach Frankreich zu kommen, doch es scheint, dass Gott andere Pläne hat. Es sieht so aus, als müsste ich hier für eine verdammt lange Zeit bleiben! Und das Schlimmste ist, dass ich ein gewöhnlicher Seemann werden muss.";
			link.l1.go = "guide_23";
		break;
		
		case "guide_23":
			dialog.text = "Das ist eine ziemlich plötzliche Veränderung in Ihrem Schicksal, Monsieur. Aber lassen Sie sich nicht entmutigen, Sie werden nicht irgendein Seemann sein. Kapitän Ihres eigenen Schiffes zu sein, ist eine sehr angesehene Position hier. Sie beabsichtigen doch, ein Schiff zu kaufen, oder?";
			link.l1 = "Ja, genau das muss ich tun... Alles, was ich brauche, ist so schnell wie möglich eine Werft und etwas Geld zu finden. Das Problem ist - ich habe keine Ahnung, wo zum Teufel man eine Werft findet, wie man ein Schiff segelt, oder wo man das Geld her bekommt! Das geht mir auf den Keks...";
			link.l1.go = "guide_24";
		break;
		
		case "guide_24":
			dialog.text = "Ich wünschte, ich könnte deine Taschen mit Gold füllen, aber ich bin genauso pleite wie du. Allerdings kann ich deinen Kopf mit dem Wissen füllen, das du so verzweifelt brauchst. Interessiert?";
			link.l1 = "Ja, das wäre großartig.";
			link.l1.go = "guide_25";
		break;
		
		case "guide_25":
			dialog.text = "Folgt mir dann. Beginnen wir mit dem Wichtigsten - den Schiffen.";
			link.l1 = "";
			link.l1.go = "guide_5";
		break;
		
		case "guide_26": // на верфь
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload5", "Guide_shipyard", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_27":
			dialog.text = "Die Werft. Jede Kolonie hat eine. Ein Ort, um ein Seeschiff zu verkaufen oder zu kaufen und auch um es zu reparieren. Seien Sie sich bewusst, dass unsere Werften nichts gemeinsam haben mit den großartigen Werften des guten alten Europas. Dies sind die Kolonien, sie bauen hier keine Galeonen oder Linienschiffe.\nLokale Meister können Ketschen, Schoner und Slups bauen. Sehr selten sieht man Brigs und Barkentinen. Aber manchmal bringen Freibeuter erbeutete Schiffe mit, die Schiffsbauer für wenig Geld kaufen, sie reparieren und mit Gewinn verkaufen.\nIch habe einmal eine Fregatte auf der Preisliste gesehen! Lokal gebaute Schiffe haben auch schlechte Eigenschaften. Machen Sie sich jedoch keine Sorgen, das Üben auf kleinen und billigen Schiffen wird es Ihnen ermöglichen, Fortschritte zu machen und schließlich etwas Besseres zu meistern.\nAch ja, die Werft ist auch der Ort, um Kanonen zu kaufen. Es gibt mehrere Arten von Kanonen, die Sie auf Ihrem Schiff installieren lassen können, vorausgesetzt natürlich, dass es sie tragen kann. Jedes Schiff hat seine Grenzen, Sie werden nie in der Lage sein, 24-Pfünder auf eine Ketsch zu setzen. Denken Sie daran, dass die großen Kaliber Kanonen selten und teuer sind. Auf der hellen Seite, solche Kanonen können buchstäblich die Besatzung des Feindes, die Segel und den Rumpf verdampfen.\nNoch eine letzte Sache. Werften bieten auch Dienstleistungen für Ästheten an: Sie können Ihre Segel und die Außenseite Ihrer Schiffe bemalen, Embleme oder Wappen zeichnen. Sie in Rot zu streichen, wird sie vielleicht nicht schneller machen, aber sie wird viel schicker aussehen.";
			link.l1 = "Interessant...";
			link.l1.go = "guide_28";
			locCameraFromToPos(-26.74, 5.77, 49.03, false, -70.00, -25.00, 150.00);
		break;
		
		case "guide_28": // в порт
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "quest", "quest1", "Guide_port", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_29":
			dialog.text = "Das ist der Pier, das Herz jedes Hafens. Ich war in der Vergangenheit Seemann, also lass mich dir mehr über das Segeln erzählen.\nErstens, merke dir das Wichtigste: Versuche nicht einmal, ein Schiff zu steuern, wenn du nicht genügend Punkte in deiner Navigationsskunst hast! Wenn die Anforderung nicht erfüllt ist, leiden auch deine anderen Fähigkeiten und die deiner Offiziere.\nDu wirst schlechter kämpfen, schlechter schießen, schlechter handeln und so weiter.\nDas bedeutet, dass wenn du versuchst, ein Kriegsschiff mit deiner aktuellen Navigationsskunst zu steuern, wirst du nicht weit kommen, tatsächlich wirst du vielleicht nicht einmal in der Lage sein, eine kleine Wendung zu machen.";
			link.l1 = "Wie lerne ich das, Navigation?";
			link.l1.go = "guide_30";
			locCameraFromToPos(-8.55, 4.06, 91.31, true, 40.00, -8.00, 0.00);
		break;
		
		case "guide_30":
			dialog.text = "Weißt du was, mein Freund? Hier ist diese kleine Notiz zum Betrieb eines Schiffes. Lies es, wenn du dein eigenes bekommst. Ein ziemlich nützliches Dokument - hat mir in meiner Zeit sehr geholfen.";
			link.l1 = "Sehr gut, Monsieur. Tatsächlich bin ich im Moment nicht wirklich bereit, so viel komplexes Wissen aufzunehmen.";
			link.l1.go = "guide_38";
			AddQuestRecordInfo("Guide_AtSea", "1");
		break;
		
		case "guide_31":
			dialog.text = "Der Rang des Schiffes bestimmt es. Zum Beispiel bin ich erfahren genug (45 Punkte), um ein Schiff der 4. Rangklasse ohne Strafen zu steuern. Briggs, Barkentinen, Fluiten. Xebecs und Korvetten erfordern mehr, also werde ich sie nicht richtig einsetzen können. Das sind noch nicht einmal Schiffe der zweiten Rangklasse wie Fregatten und schwere Galeonen.\nWas riesige Linienschiffe oder Man-o-War betrifft... nur Experten in der Navigation können solche Ungeheuer kontrollieren, es dauert Jahre, die Fertigkeit zu beherrschen und vergessen Sie nicht das Geld. Ein Schlachtschiff und ihre Besatzung können Ihre Börse in einem Monat leeren, wenn Sie nicht so reich sind wie König Louis selbst.";
			link.l1 = "Ich sehe...";
			link.l1.go = "guide_32";
		break;
		
		case "guide_32":
			dialog.text = "Achte auf die Positionen deiner Offiziere. Ein Bootsmann trainiert deine Besatzung und macht das Entern effektiver, ein Zahlmeister führt finanzielle Aktivitäten an deiner Stelle durch und befreit dein Schiff von Ratten. Ein Arzt heilt deine verwundeten Männer und senkt die Anzahl derer, die im Kampf sterben, ein Schiffszimmermann repariert Schäden am Schiff und Enteroffiziere retten deine Haut, wenn Piraten dein Deck stürmen. \nAchte auf die Fähigkeiten der Kandidaten und ihren Ruf.";
			link.l1 = "Ruf?";
			link.l1.go = "guide_33";
		break;
		
		case "guide_33":
			dialog.text = "Genau. Jeder Mann hat einen. Es zeigt einen Mann für das, was er wirklich ist.\nWenn du ein ehrenhafter Mann bist und immer versuchst, Gutes zu tun, dann suche nach Offizieren, die deine Ideale teilen. Und wenn du ein Pirat sein willst... nun, du verstehst die Idee.\nEhrliche Leute werden nicht für Abschaum arbeiten, das Gegenteil ist auch wahr.";
			link.l1 = "Habe es verstanden.";
			link.l1.go = "guide_34";
		break;
		
		case "guide_34":
			dialog.text = "Nun sprechen wir über Schiffstypen. Es gibt zwei Arten. Handelsschiffe und Kriegsschiffe. Handelsschiffe oder Handelsschiffe haben große Laderäume und neigen dazu, langsamer zu sein. Kriegsschiffe sind schnell und haben starke Kanonen, auf Kosten der Ladekapazität. Barken, Fluiten und Karacken sind gute, solide Handelsschiffe. Schaluppen, Brigs und Korvetten sind Kriegsschiffe. Es gibt natürlich auch Hybriden, Schiffe die sowohl für den Handel als auch für den Kampf geeignet sind: Schneeschiffe, Schoner und Galeonen.\nSchiffe haben auch unterschiedliche Takelungsanordnungen, einige sind hauptsächlich quadratisch getakelt und einige hauptsächlich Vor- und Achtergetakelt, was den besten Kurswinkel des Schiffes bildet.";
			link.l1 = "Kurswinkel?";
			link.l1.go = "guide_35";
		break;
		
		case "guide_35":
			dialog.text = "Ja. Es bestimmt, wie deine Takelage vom Wind beeinflusst wird und auf welchem Kurs dein Schiff die höchstmögliche Geschwindigkeit erreicht. Sobald du auf See bist, suche den Pfeil auf der Minikarte, das wird dein Kurswinkel sein.";
			link.l1 = "Das ist für mich etwas verwirrend. Aber ich schätze, ich werde es mit der Zeit lernen.";
			link.l1.go = "guide_36";
		break;
		
		case "guide_36":
			dialog.text = "Als nächstes, deine Crew. Du und dein Schiff sind nichts ohne die Männer, die es kontrollieren. Jeder Seemann muss drei Dinge wissen. Wie man mit der Takelage umgeht, wie man Kanonen bedient und wie man kämpft. Jede Nation ist nur in einer dieser drei Tätigkeiten herausragend. Zum Beispiel hat Spanien die besten Kämpfer der Welt und ihre Grenzgänger tragen Rüstungen, daher sind Traubenschüsse, Schneiden und Stechen gegen sie nicht ganz so wirksam. Ich spreche natürlich von Handfeuerwaffen, Kanonentraubenschüsse kümmern sich einen Dreck um Körperpanzer. \n Besuche die Tavernen von Spanien, England und Frankreich, wenn du eine Traumcrew zusammenstellen willst, oder wenn du es riskieren willst, stelle eine Piratencrew ein, so sehr ein Mann sie auch hassen mag, sie sind immer noch die tödlichste Crew, die man haben kann. Achte auf die Moral deiner Männer, versorge sie regelmäßig mit Rum, Huren und Münzen. Tu das und deine Männer werden für dich sterben. Versäume dies und sie werden eine Meuterei anzetteln. Ein motivierter Profi ist zehn Anfänger in einem Kampf wert. Vergiss auch nicht einen Arzt, oder entwickle deine eigenen medizinischen Fähigkeiten, um zusätzliche Verluste zu vermeiden.";
			link.l1 = "Ich werde mich daran erinnern...";
			link.l1.go = "guide_37";
		break;
		
		case "guide_37":
			dialog.text = "Nun ein paar Worte zu Seeschlachten. Die Karibik ist gefährlich, kriecht vor spanischen Patrouillen und Piraten, also wirst du sie schließlich auf offenem Meer engagieren. Schiffskanonen verwenden vier Arten von Munition. Kugeln, Traubenschüsse, Kettenschüsse und Bomben.\nKugeln sind Allzweck und am billigsten zu kaufen, sie haben auch die größte effektive Schussreichweite. Sie zerreißen die Segel des Feindes, zerstören ihren Rumpf und töten ihre Besatzung.\nKettenschüsse haben eine anständige Schussreichweite, ihre Aufgabe ist es, die Takelage eines Feindes zu eliminieren, um sie zu verlangsamen. Sie sind gut zu benutzen, wenn du jagen oder fliehen willst. Wenn du Glück hast, kannst du sogar einen ganzen Mast niederreißen.\nBomben. Benutze sie, wenn du das Schiff deines Gegners versenken willst. Bomben richten den größten Schaden am Rumpf an, aber sie haben die zweitkürzeste Schussreichweite, so dass du dich zuerst nähern musst, was tödlich sein kann. Sie kosten auch am meisten von allen Muscheln.\nTraubenschüsse sind deine beste Wahl, wenn du ein feindliches Schiff entern und erobern willst. Diese gemeinen kleinen Biester vernichten Menschen, aber die kürzeste Schussreichweite macht sie riskant zu benutzen. Aber es kann sich lohnen.\nHalte das Feuer zurück, wenn du dir nicht sicher bist, ob du genug Schaden anrichten kannst. Jeder Salve kostet Schießpulver, Zeit und Zustand der Kanonen. Sie können manchmal explodieren, besonders wenn du zu oft schießt. Manövriere immer, versuche eine bessere Position einzunehmen. Wenn der Feind zu gefährlich ist und du nicht fliehen kannst, versuche sie zu provozieren, dich ständig aus der Ferne zu beschießen, ohne Schaden zu nehmen. Dieser Trick wird schließlich ihre Schießpulvervorräte leeren. Das kann Tage dauern, also solltest du besser Deckung suchen wie Felsen oder eine Küstenlinie. Natürlich wird eine solche Taktik auf offenem Meer nicht funktionieren.\nMinen. Auch eine feine Art, sie alle zu versenken. Provoziere sie, dich zu verfolgen und Minen abzuwerfen. Jede Mine erfordert eine anständige Menge Pulver, aber selbst eine Mine kann einen Kutter zerstören.\nBesorge dir ein Fernglas und benutze es, um deinen Feind zu beobachten. Ein gutes Fernglas gibt dir einen guten taktischen Überblick, beispielsweise über die Anwesenheit von Musketiereinheiten auf dem Schiff deines Gegners. Feindliche Musketiere können viele deiner Männer an Deck mähen, also sei sicher, ihnen einen Hauch von Traubenschuss zu geben, bevor du an Bord gehst.";
			link.l1 = "Heiliger Jesus... das ist erschreckend... aber ich nehme an, ich muss auf alles vorbereitet sein.";
			link.l1.go = "guide_38";
		break;
		
		case "guide_38":
			dialog.text = "Du wirst lernen, daran habe ich keinen Zweifel. Da du Kapitän und Schiffseigner werden wirst, werde ich dir noch einen Ort von großer Bedeutung zeigen. Das Hafenbüro. Folge mir.";
			link.l1 = "";
			link.l1.go = "guide_39";
		break;
		
		case "guide_39": // к портовому управлению
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload10", "Guide_portoffice", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_40":
			dialog.text = "Da ist es. Im Hafenbüro kannst du Arbeitsangebote finden. Frachten für große Kaufmannsschiffe und Konvoischutz für Kriegsschiffe. Wenn du ein schnelles Paketschiff besitzt, könnten sie dir einen Kurierjob anbieten.\nIch empfehle, hier etwas Vertrauen zu verdienen. Wenn du deine Arbeit mehrmals gut machst, werden sie dir kompliziertere und viel besser bezahlte Verträge anvertrauen.\nDu kannst dich auch über andere Kapitäne erkundigen und deine überschüssigen Schiffe hier zur sicheren Aufbewahrung lagern. Offene Lagerung, vergiss einfach nicht zu bezahlen!";
			link.l1 = "Habs verstanden.";
			link.l1.go = "guide_41";
			locCameraFromToPos(48.38, 9.48, 43.95, true, -70.00, -55.00, 150.00);
		break;
		
		case "guide_41":
			dialog.text = "Nun, die Stadttore sind nah, also gibt es ein anderes Thema, über das ich dir erzählen möchte. Diese Tore führen in die Dschungel. Folge mir und ich werde dir über heimliche Aktionen und Fechten erzählen. Stört es dich?";
			link.l1 = "Ganz und gar nicht. Sie haben mir bereits sehr geholfen!";
			link.l1.go = "guide_42";
		break;
		
		case "guide_42":
			dialog.text = "Folge mir dann!";
			link.l1 = "";
			link.l1.go = "guide_43";
		break;
		
		case "guide_43": // к воротам
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "gate_back", "Guide_gate", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_44":
			dialog.text = "Also, hier haben wir ein Stadttor, das direkt in den Dschungel führt... Es ist mir peinlich, aber ich habe noch eine Notiz für dich zum späteren Studieren. Diesmal geht es um die Feinheiten unseres Landlebens. Nimm dir Zeit zum Lesen, denn es wird dir helfen, besser zu verstehen, wie man feindliche Städte infiltriert und wie man an Land kämpft. Aber jetzt schlage ich vor, dass wir das Tor verlassen und ein bisschen Spaß haben - lass uns das Fechten üben.";
			link.l1 = "Sie sind eine wahre Enzyklopädie, Monsieur. Los geht's! Üben klingt spaßig.";
			link.l1.go = "guide_48";
			locCameraFromToPos(50.58, 5.74, 23.21, false, 100.00, 0.00, 20.00);
			AddQuestRecordInfo("Guide_OnLand", "1");
		break;
		
		case "guide_45":
			dialog.text = "Eine Urkunde, die ihr bei der Hauptverwaltung der Niederländischen Westindien-Kompanie erhalten könnt. Ein Zeichen eurer friedlichen Absichten. Dieses Papier erlaubt euch, jeden Hafen zu betreten, bis die Bedingungen abgelaufen sind.\nAber es gibt einige Nachteile. Erstens hat die Kompanie spezielle Regeln und fordert, dass jeder Kapitän, der bereit ist, die Lizenz zu kaufen, diese befolgen muss. Zweitens kostet es viel. Und das Letzte und Schlimmste, ihr braucht immer noch eine 'Flagge hissen' Fähigkeit, um in Häfen anzulegen. Andernfalls werdet ihr sofort von den schweren Kanonen des Forts erschossen.";
			link.l1 = "Wo ist der Firmensitz?";
			link.l1.go = "guide_46";
		break;
		
		case "guide_46":
			dialog.text = "Willemstad auf Curacao. Wenn du eine Lizenz kaufen willst - geh dorthin, sie geben dir die Details.";
			link.l1 = "Die Dinge sind hier so durcheinander...";
			link.l1.go = "guide_47";
		break;
		
		case "guide_47":
			dialog.text = "Sei nicht verärgert, mein Freund. Du wirst lernen. Jetzt üben wir das Fechten.";
			link.l1 = "Klingt gut. Lasst uns loslegen!";
			link.l1.go = "guide_48";
		break;
		
		case "guide_48": // телепортируем за городские ворота
			DialogExit();
			LAi_SetActorType(npchar);
			DoQuestReloadToLocation("FortFrance_ExitTown", "goto", "goto19", "Guide_ExitTown");
		break;
		
		case "guide_49":
			dialog.text = "Mein Freund, ich glaube, du weißt, wie man ein Schwert hält?";
			link.l1 = "Ha! Natürlich weiß ich das. Ich wurde vom besten Fechtmeister in Paris unterrichtet!";
			link.l1.go = "guide_50";
		break;
		
		case "guide_50":
			dialog.text = "Gut für dich. Lass mich dir zunächst etwas Theorie beibringen.\nEs gibt drei Arten von Kaltstahl: leicht, mittel und schwer. Jeder Typ erfordert unterschiedliche Fähigkeiten und Fertigkeiten, um sie zu beherrschen, also musst du sie separat erlernen.\nJede Klasse hat ihre Vor- und Nachteile. Leichte Waffen umfassen Floretts und Rapiere, erfordern wenig Ausdauer, verursachen aber den geringsten Schaden. Eine schwere Waffe, wie eine Axt, kann mit einem einzigen Schlag töten, erschöpft aber deine Ausdauer sehr schnell und du musst dich möglicherweise zwischen den Schlägen ausruhen. Mittlere Waffen, Säbel oder Entermesser, sind der Mittelweg, sie kombinieren gutes Gewicht und Schadenspotential.\nEs stehen dir verschiedene Fechtbewegungen und -tricks zur Verfügung: Stichangriff, Hackangriff, schwerer Angriff und Gruppenangriff. Du kannst auch parieren, täuschen und blocken.\nDer Stichangriff ist die schnellste Bewegung, erfordert die geringste Menge an Ausdauer und eignet sich hervorragend für lange Rapiere. Für Äxte ist es weitgehend nutzlos. Der Hackangriff ist ziemlich vielseitig, hat eine anständige Geschwindigkeit, erheblichen Ausdauerverlust, ist gut für Säbel, Breitschwerter und Äxte, aber nicht so effektiv mit Rapiere. Der schwere Angriff wird von oben ausgeführt, eine ausgezeichnete Wahl für Äxte, funktioniert gut für kurze Säbel und Entermesser, doch Rapiere sind einfach nicht für solche Bewegungen konzipiert. Dieser Angriff wird eine riesige Menge an Ausdauer verbrauchen, er ist langsam, aber er wird verheerenden Schaden anrichten und die Blocks deines Gegners ignorieren.\nBlocken ist nutzlos gegen schwere Angriffe und erfahrene Gegner haben immer die Chance, deinen Block zu durchbrechen. Parieren ist viel besser, es öffnet deinen Gegner für Angriffe und zwingt ihn, Ausdauer zu verlieren. Mehrere erfolgreiche Paraden und dein Gegner verliert völlig seine Initiative und ist gezwungen, sich zu verteidigen, während du den vollen Vorteil hast.\nFinten sind knifflig und riskant. Deinen Gegner zu täuschen und ihm sofort einen schnellen Stich zu versetzen erfordert nur einen geringen Ausdauerverlust, aber du musst konzentriert, aufmerksam und im Rhythmus des Kampfes sein. Die Beherrschung dieser Bewegung wird viel Übung von dir verlangen, aber es lohnt sich - sogar professionelle Duellanten und Schwertmeister werden durch deine Hand fallen.\nUm den Schaden von jeder Art von Angriff zu maximieren, musst du für jeden die richtige Waffe verwenden. Der Stichangriff wird am besten mit langen, leichten, geraden Rapiere oder Schwertern mit einem Gleichgewicht von 0 bis 0,5 ausgeführt. Lange, kurvige Entermesser oder Säbel mit einem Gleichgewicht von 1 bis 2 sind ausgezeichnet für Hack- und schwere Angriffe. Eine schwere Axt mit einem Gleichgewicht von 2 ist perfekt für schwere Angriffe, aber solch eine Waffe wird viel Ausdauer und Geschicklichkeit erfordern. Der Gruppenangriff sollte nicht deine Hauptbewegung sein, er ist eher defensiv, aber ein gekrümmtes, leichtes, langes Entermesser mit einem Gleichgewicht von 0,75 bis 1,25 wird Wunder gegen Gruppen von Feinden um dich herum wirken.\nSchließlich ist die beste Waffe für eine Finte ein Dolch, erwäge, diese Bewegung zu deiner Spezialität zu machen. Das Gewicht einer Waffe bestimmt, wie viel Ausdauer sie für jede Angriffsbewegung benötigen wird und es beeinflusst auch den Schaden. Denke daran, dass das Finden deiner perfekten Waffe einige Zeit in Anspruch nehmen kann und das Arbeiten an deinem Kampfstil noch mehr.";
			link.l1 = "Und was, wenn es mehrere Feinde gibt?";
			link.l1.go = "guide_51";
		break;
		
		case "guide_51":
			dialog.text = "Das verkompliziert die Dinge. Ein anständiger Kämpfer kann ein paar schlecht trainierte Narren im Freien niederringen, aber wenn ein Dutzend Schurken auf dich zukommen - vermeide es um jeden Preis, umzingelt zu werden, renne weg, suche dir eine Ecke oder eine Treppe, Türen, was auch immer, zwing sie dazu, dich eins gegen eins oder zwei gegen eins zu bekämpfen. Sie werden dich in einer Sekunde aufschlitzen, wenn du einen Fehler machst, also zwing sie dazu, nach deinen Regeln zu spielen, verliere nicht die Initiative und achte auf deine Ausdauer.\nObwohl, ich habe von einem speziellen indischen Trank gehört, der Meistern des Schwertes und der Axt erlaubte, fünf oder sechs Feinde auf einmal mit ein paar Gruppenangriffen zu töten.";
			link.l1 = "Einen besonderen Trank?";
			link.l1.go = "guide_52";
		break;
		
		case "guide_52":
			dialog.text = "Ometochtli-Mischung oder wie auch immer sie es nennen. Ein altes indisches Rezept. Frag die Händler, vielleicht verkauft dir eines Tages jemand etwas. Aber du musst zuerst die Alchemie erlernen, um das Rezept verwenden zu können... Da wir schon über Tränke sprechen - lass mich dir von der Heilung erzählen.\nWenn du eine kleine Wunde heilen musst, verwende einen Heiltrank. Schwere Schläge können mit einem Elixier behandelt werden. Heilmixturen, Rum und Wein stellen ebenfalls deine Gesundheit wieder her.\nEin Antidot und eine Mischung reichen aus, wenn du vergiftet bist. Ich empfehle auch eine Ingwerwurzel, sie frischt deinen Atem wunderbar auf. Außerdem heilt sie ohne Nebenwirkungen, im Gegensatz zu Essenzen und Elixieren.";
			link.l1 = "Warte, Nebenwirkungen?";
			link.l1.go = "guide_53";
		break;
		
		case "guide_53":
			dialog.text = "Essenzen, Elixiere und Tränke schaden Ihrer Gesundheit. Wie ich am Anfang unserer kleinen Tour erwähnt habe, ist es schlecht. Schlechte Gesundheit führt zu Einbußen in Ihren Fähigkeiten, sie verringert die Gesamtzahl Ihrer Gesundheitspunkte und Ausdauer.\nSchlafen, Sex und ein seltener Trank namens 'Tränen von Ish-Chel' - ich bin mir nicht genau sicher, wie er heißt, alles was ich weiß, ist, dass er einige Tränen darin hat, so etwas wird die Gesundheit wiederherstellen, wenn sie nicht komplett ruiniert ist. Ist es zu spät, besuchen Sie einen Priester, sie helfen gegen eine Gebühr.";
			link.l1 = "Ich verstehe. Was können Sie mir über Handfeuerwaffen erzählen?";
			link.l1.go = "guide_54";
		break;
		
		case "guide_54":
			dialog.text = "Nicht viel zu sagen. Zielen und schießen! Verwende Traubenschrot, wenn es mehrere Feinde gibt. Besorge dir ein Musket oder ein Gewehr, sie verursachen tödlichen Schaden und du kannst immer Leute mit einem Gewehrkolben schlagen. Ich habe auch von einer Donnerbüchsenartigen Muskete gehört, die Granaten schießt, es ist eine ausgezeichnete Waffe und auch sehr schön... aber ich habe sie noch nie gesehen.";
			link.l1 = "Ich verstehe. Übungszeit?";
			if (FindCharacterItemByGroupWithout_knife_03(pchar, BLADE_ITEM_TYPE) == "") link.l1.go = "guide_55a";
			else link.l1.go = "guide_55";
		break;
		
		case "guide_55a":
			dialog.text = "Hm. Mir ist gerade aufgefallen. Wo ist dein Schwert? Ich fürchte, unsere Lektion muss verschoben werden. Wie bist du ohne Waffe gelandet, "+pchar.name+"?";
			link.l1 = "Ein königlicher Mistkerl in einem schicken Anzug hat es mir als Vorschuss auf die Schulden meines Bruders abgenommen... Hast du ein extra Schwert für mich? Ich gebe es zurück, wenn die Lektion vorbei ist...";
			link.l1.go = "guide_55b";
		break;
		
		case "guide_55b":
			GiveItem2Character(pchar, "blade_05");
			EquipCharacterByItem(Pchar, "blade_05");
			dialog.text = "Du hast Glück. Ich habe ein extra Schwert. Ich wollte es verkaufen, aber, Glück für dich, ich wurde aufgehalten.";
			link.l1 = "Danke. Sollen wir?";
			link.l1.go = "guide_55";
		break;
		
		case "guide_55":
			dialog.text = "Achtung! Und verschwende keine Tränke, die du hast, wir werden uns nicht gegenseitig umbringen.";
			link.l1 = "Wie du sagst.";
			link.l1.go = "guide_56";
			npchar.quest.guide_win = 0;
		break;
		
		case "guide_56": // махач
			LAi_SetPlayerType(pchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			if (MOD_SKILL_ENEMY_RATE <= 6)	// На первых трёх сложностях Валинье будет ослаблен
			{
				LAi_SetHP(npchar, LAi_GetCharacterMaxHP(npchar) * 0.7, LAi_GetCharacterMaxHP(npchar) * 0.7);
				npchar.rank = 1;
				SetSelfSkill(npchar, 1, 1, 1, 1, 1);
			}
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			// ставим проверяльщики
			LAi_SetCheckMinHP(pchar, 1, true, "Guide_HeroFail");
			LAi_SetCheckMinHP(npchar, 1, true, "Guide_HeroWin");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			DoQuestCheckDelay("GuideFight_tutorial", 1.0);
		break;
		
		case "guide_57": // побил гида с первого раза
			dialog.text = "Du... du bist ein Mann, der weiß, wie man sein Schwert hält. Gut gemacht, Monsieur. Du benötigst mehr Übung, aber du hast das Potential, ein wahrer Schwertmeister zu werden.";
			link.l1 = "Vielen Dank. Was jetzt?";
			link.l1.go = "guide_62"; // нода на выход
			if (MOD_SKILL_ENEMY_RATE >= 6)
			{
				link.l2 = "Mehr Übung sagst du? Bist du ernst? Ich bin dieses herablassende Ton seit ich Fuß in diesen elenden Ort gesetzt habe, leid!";				//Пасхалка Корсары 2 для сложности СФ и выше
				link.l2.go = "guide_64";
			}
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 80);
		break;
		
		case "guide_58": // побил гида со второго или третьего раза
			dialog.text = "Viel besser! Siehst du, du musst dich nur konzentrieren. Du brauchst mehr Übung, eines Tages wirst du ein anständiger Fechter werden.";
			link.l1 = "Vielen Dank. Was jetzt?";
			link.l1.go = "guide_62"; // нода на выход
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
		break;
		
		case "guide_59": // побили первый раз
			dialog.text = "Ich habe gewonnen, Monsieur. Beweg dich schneller, pariere meine Stiche, spring zurück. Eine Revanche?";
			link.l1 = "Ja! Keine Gnade, Monsieur!";
			link.l1.go = "guide_56";
			link.l2 = "Nein, ich habe genug. Lass uns die Lektion beenden. Was jetzt?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_60": // побили второй раз
			dialog.text = "Ich habe wieder gewonnen, "+pchar.name+"! Verliere nicht deine Initiative. Fang meine Schläge ab, täusche sie vor. Wenn du siehst, dass ich hart zuschlage - spring weg oder pariere, verteidige dich nicht nur. Wieder!";
			link.l1 = "Komm, Monsieur, diesmal werde ich dich verprügeln!";
			link.l1.go = "guide_56";
			link.l2 = "Nein, ich habe genug. Lassen wir die Lektion beenden. Was jetzt?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_61": // побили третий раз
			dialog.text = "Du hast viel zu lernen, "+pchar.name+". Mach dir keine Sorgen, du hast noch viel Zeit, um dein Fechten zu meistern. Aber sei vorsichtig, nimm keine Risiken auf dich, bis du weißt, wie man eine Waffe hält.";
			link.l1 = "Ich werde es in Betracht ziehen, Monsieur, aber ich muss sagen, dass Sie einfach zu viel Glück hatten! Diese verdammte Hitze... der einzige Grund, warum ich Sie nicht verprügelt habe. Merde, lass uns unsere Fechtstunde beenden. Was jetzt?";
			link.l1.go = "guide_62"; // нода на выход
		break;
		
		case "guide_62":
			dialog.text = "Nun ist es Zeit, Lebewohl zu sagen, Monsieur. Es war mir ein Vergnügen. Ich hoffe, dass meine Präsentation und Ausbildung Ihnen etwas Gutes getan haben und sich in der Zukunft als nützlich erweisen werden. Vielleicht treffen wir uns eines Tages wieder.\nUnd was das Geld betrifft, das Sie brauchen - sprechen Sie mit den wichtigen Leuten unserer Stadt. Besuchen Sie alle Orte, die ich Ihnen heute gezeigt habe und sprechen Sie mit ihren Besitzern. Fragen Sie herum. Machen Sie einen Spaziergang zum Dschungel und zum Fort. Finden Sie einen Job oder... nun, ich bin kein Priester oder Richter, schauen Sie in die Häuser der Leute und sehen Sie, welche Kostbarkeiten Sie in ihren unverschlossenen Kisten finden können. Machen Sie es nur, wenn sie nicht hinschauen oder die Wachen werden Sie erwischen.\nViel Glück, "+pchar.name+", Ich habe das starke Gefühl, dass in dir der Funke wahrer Größe steckt. Gib dein Bestes, um ihn zu einem lodernden Feuer zu entfachen!";
			link.l1 = "Danke, Monsieur. Das Vergnügen war meinerseits. Gott mit dir!";
			link.l1.go = "guide_63";
		break;
		
		case "guide_63":
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			DialogExit();
			chrDisableReloadToLocation = false;//открыть локацию
			npchar.lifeday = 0;
			DoQuestReloadToLocation("FortFrance_Town", "quest", "quest2", "");
		break;
		
		case "guide_64": // решили убить Валинье
			dialog.text = "Halten Sie Ihr Maul, Monsieur! Ich werde solche Unverschämtheit nicht weiter dulden. Allerdings verstehe ich Ihre Reaktion auf eine neue Umgebung, daher vergebe ich Ihren Ausbruch dieses Mal. Aber achten Sie von nun an auf Ihre Worte. Auf Wiedersehen, Monsieur de Maure.";
			link.l1 = "Keine Beleidigung, Monsieur Valinnie. Wären wir in diesem Moment im Louvre, würden Sie Ihren Ton mäßigen! Es ist Zeit, einer Provinz eine endgültige Lektion zu erteilen. Verteidige dich!";
			link.l1.go = "guide_65";
		break;
		
		case "guide_65":
			DialogExit();
			
			npchar.rank = 25;
			int iHp = MOD_SKILL_ENEMY_RATE*10+300;
			LAi_SetHP(npchar, iHp, iHp);
			SetSelfSkill(npchar, 80, 80, 80, 80, 50);
			SetShipSkill(npchar, 50, 80, 35, 30, 50, 20, 30, 20, 80);
			SetSPECIAL(npchar, 9, 5, 8, 6, 5, 10, 8);
			SetCharacterPerk(npchar, "Energaiser");
			SetCharacterPerk(npchar, "BasicDefense");
			SetCharacterPerk(npchar, "AdvancedDefense");
			SetCharacterPerk(npchar, "CriticalHit");
			SetCharacterPerk(npchar, "Tireless");
			SetCharacterPerk(npchar, "HardHitter");
			SetCharacterPerk(npchar, "Sliding");
			SetCharacterPerk(npchar, "BladeDancer");
			SetCharacterPerk(npchar, "SwordplayProfessional");
			SetCharacterPerk(npchar, "Gunman");
			SetCharacterPerk(npchar, "GunProfessional");
			GiveItem2Character(npchar, "blade_30");
			EquipCharacterbyItem(npchar, "blade_30");
			GiveItem2Character(npchar, "cirass7");
			GiveItem2Character(npchar, "obereg_7");
			GiveItem2Character(npchar, "talisman11");
			AddMoneyToCharacter(npchar, 10000);
			AddItems(npchar, "gold_dublon", 25);
			AddItems(npchar, "bullet", 5);
			AddItems(npchar, "grapeshot", 5);
			AddItems(npchar, "GunPowder", 10);
			TakeItemFromCharacter(npchar, "blade_12");
			npchar.cirassId = Items_FindItemIdx("cirass4");
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			npchar.SaveItemsForDead = true;
			npchar.DontClearDead = true;
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "Guide_HeroKill");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string FindCharacterItemByGroupWithout_knife_03(ref chref, string groupID)
{
	ref refItm;
    string resultItemId;

	resultItemId  = "";
	for(i=TOTAL_ITEMS-1; i>=0; i--)
	{
		refItm = &Items[i];
		if( !CheckAttribute(refItm,"groupID") ) continue;
		if(refItm.groupID!=groupID) continue;
		if( !CheckAttribute(chref,"items."+refItm.id) ) continue;
		if(refItm.id == "knife_03") continue;
		if (groupID == BLADE_ITEM_TYPE)
		{
			resultItemId  = refItm.id;
		}
	}
	
	if (resultItemId != "")
	{
        return resultItemId;
	}

	return "";
}