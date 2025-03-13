// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Tous les rumeurs de "+GetCityName(npchar.city)+" à votre service. Que désirez-vous savoir?","Nous en parlions justement. Vous devez avoir oublié...","C'est la troisième fois aujourd'hui que tu parles d'une question...","Tu répètes tout comme un perroquet...","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+" , peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Oui...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Sauriez-vous par hasard où je peux trouver Francois Gontier ?";
                link.l1.go = "Jamaica_ratP_1";
            }
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "Ecoutez, un alchimiste est-il arrivé ici dans cette ville, un médecin? Il est italien, environ trente ans, il s'appelle Gino Gvineili. Avez-vous entendu quelque chose à ce sujet?";
				link.l1.go = "guardoftruth";
			}
		break;

		case "Jamaica_ratP_1":
			dialog.text = NPCStringReactionRepeat("Je n'en ai pas la moindre idée. Je n'ai jamais entendu ce nom auparavant.","Tu as déjà posé cette question et je t'ai répondu.","Je t'ai dit, tu as déjà demandé à propos de ce Gontier.","Ecoute, va-t'en et cesse de m'importuner ! As-tu complètement perdu la tête ?","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Eh bien, je continuerai à chercher.","Hm, je suppose que oui...","Oui, c'est ça, j'ai demandé cela...","Désolé, "+npchar.name+"...",npchar,Dialog.CurrentNode);
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Non, je n'ai pas entendu parler de lui. Nous avons des herboristes et des médecins, mais aucun avec un nom comme ça.","C'est la première fois que j'entends un nom aussi étrange. Non, nous n'avons jamais reçu la visite de l'homme dont vous parlez.","Nous n'avons même pas d'alchimistes ici du tout. Nous avons des médecins, mais aucun avec un nom bizarre comme ça.");
			link.l1 = "Je vois. C'est bien dommage. Je vais continuer à chercher !";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
