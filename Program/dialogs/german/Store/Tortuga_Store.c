// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen...","Schon lange hat niemand mehr solche Fragen in einem Laden in Tortuga gestellt...","Fragen, Fragen und noch mehr Fragen...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Hmm, wo ist nur mein Gedächtnis hin...","In Ordnung, es ist eine lange Zeit her.","Noch mehr Fragen, ja...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga2")
			{
				link.l1 = "Hör zu, ich muss einen Gaius Marchais finden. Wie mir gesagt wurde, hat er sich mit Kaperfahrten beschäftigt und ist ein anständiger Verhandler geworden, der eine ausgezeichnete Galeone von den Spaniern abgegriffen hat. Hat er zufällig irgendeine Art von Ware bei Ihnen für den Handel gekauft?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Gaius Marchais? Oh ja, natürlich erinnere ich mich an ihn! Aber er hat nichts gekauft. Er bot sein Schiff für Fracht an. Ich brauchte gerade ein Schiff mit einem geräumigen Laderaum - eine große Menge Rohfelle.";
			link.l1 = "Und wo war der Entladungspunkt?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Philipsburg, Sankt Maarten.";
			link.l1 = "Gut. Danke, du hast mir sehr geholfen!";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Jederzeit, Kapitän. Kommen Sie jederzeit in meinen Laden!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "10");
			pchar.questTemp.Guardoftruth = "maarten";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
