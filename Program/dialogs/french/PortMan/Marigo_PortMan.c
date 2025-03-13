// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Tu as déjà essayé de me poser une question "+GetAddress_Form(NPChar)+"...","Tu parles de cette question pour la troisième fois aujourd'hui...","Ecoutez, si vous n'avez rien à me dire sur les affaires du port, alors ne me dérangez pas avec vos questions.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire."),"Peu importe.","En effet, déjà la troisième fois...","Désolé, mais je ne suis pas intéressé par les affaires du port pour l'instant.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "maarten1")
			{
				link.l1 = "Je cherche un galion nommé 'Admirable' sous pavillon français. Son capitaine s'appelait Gaius Marchais. Pouvez-vous me dire où il a mis le cap ensuite ? Peut-être s'est-il enregistré ici ?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Hmmm, 'Admirable'? Galion? Je m'en souviens. Voyons voir... nous l'avons affrété pour livrer du paprika à Bridgetown sur la Barbade. Quelque chose s'est passé?";
			link.l1 = "Non, mais Gaius est mon ami et j'ai hâte de le rencontrer.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Alors, naviguez vers la Barbade. Mais je doute que vous le trouviez là-bas, cela fait longtemps. Au moins, vous pouvez demander au maître de port local de vous aider.";
			link.l1 = "Je repars, je suppose.";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			DialogExit();
			AddQuestRecord("Guardoftruth", "12");
			pchar.questTemp.Guardoftruth = "barbados";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
