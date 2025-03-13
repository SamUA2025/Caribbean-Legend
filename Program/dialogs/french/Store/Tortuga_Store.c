// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser une question il n'y a pas longtemps...","Personne n'a posé de questions comme ça dans un magasin de Tortuga depuis longtemps...","Des questions, des questions, et encore des questions...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Où diable est passée ma mémoire...","D'accord, cela fait longtemps.","Pluuuuuus de questions, hein...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga2")
			{
				link.l1 = "Ecoute, il me faut retrouver un certain Gaius Marchais. On m'a dit qu'il s'est engagé dans la course et qu'il est devenu un bon négociateur, raflant un excellent galion aux Espagnols. A-t-il acheté chez vous quelque marchandise pour le commerce ?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Gaius Marchais ? Oh oui, bien sûr que je me souviens de lui ! Mais il n'a rien acheté. Il a offert son navire pour le fret. Il se trouve que j'avais besoin d'un navire avec une cale spacieuse - un grand lot de peaux brutes.";
			link.l1 = "Et quel était le point de déchargement ?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Philipsburg, Saint Maarten.";
			link.l1 = "D'accord. Merci, vous m'avez beaucoup aidé !";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Quand vous voulez, capitaine. Passez à ma boutique quand cela vous chante !";
			link.l1 = "Got it. Please provide the dialogues you need translated.";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "10");
			pchar.questTemp.Guardoftruth = "maarten";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
