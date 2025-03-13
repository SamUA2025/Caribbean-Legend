// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("mon fils","mafille")+"?","Demandez donc, je vous écoute..."),"Je vous écoute, parlez maintenant, "+GetSexPhrase("mon fils","ma fille")+"... ","Pour la troisième fois, "+GetSexPhrase("mon fils","ma fille")+", demandez ce dont vous avez besoin.","Un homme d'église a beaucoup de travail et vous me distraisez, "+GetSexPhrase("mon fils","mafille")+"... ","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Pas pour le moment, padre..."),"Je n'ai rien à dire, mes excuses.","Je demanderai, mais plus tard. Pardonnez-moi, mon père.","Pardonnez-moi, saint père...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";		
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "utensil" && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "Je viens vous voir pour une affaire inhabituelle, saint père. Un corsaire du nom de Guy Marchais a offert un objet très précieux à votre paroisse il n'y a pas longtemps. C'était une croix pectorale en or incrustée de lazurite. Est-ce vrai ?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Ah oui, mon fils ! C'est le meilleur objet de notre paroisse. Je n'ai jamais vu une telle magnificence de toute ma vie ! Mais pourquoi demandes-tu, mon fils ? Pourquoi t'intéresses-tu à cette croix ?";
			link.l1 = "Saint père, je sais que cela ne vous plaira pas, mais cette croix a été volée dans une autre paroisse et le prêtre a été assassiné pendant le méfait. Cet homme qui vous a présenté cet objet est un meurtrier.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Nous péchons tous, mon fils, et tuer un homme d'église est une accusation grave. Avez-vous des preuves? De quelle paroisse cette croix a-t-elle été volée?";
			link.l1 = "Ma parole ne suffit-elle pas comme preuve ? Cette croix a été volée de la paroisse à Santiago et elle doit être rendue.";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Santiago ? N'est-ce pas une ville espagnole ? Mon fils, tu me surprends...";
			link.l1 = "Saint père, tout le monde est égal devant Dieu. Les Espagnols sont des chrétiens comme nous, et les désaccords entre les nations ne doivent pas affecter les sentiments des croyants. Je vous supplie de rendre cette croix à la paroisse de Santiago.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Mon fils, ne comprends-tu pas que cette croix est un don des chrétiens bienveillants pour notre paroisse ?! Non, mon fils, je ne peux pas faire ce que tu demandes.";
			link.l1 = "Ne te soucies-tu pas que du sang ait été versé pour cette croix ? Le sang d'un ecclésiastique, espagnol ou pas, cela n'a pas d'importance.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "Mon fils, tu n'as présenté aucune preuve et je ne peux pas aveuglément te croire sur parole. La croix restera dans notre paroisse. C'est ma décision finale. De plus, ton effort pour aider les Espagnols dans cette affaire m'inquiète grandement.";
			link.l1 = "Ainsi soit-il, Adieu alors, saint père...";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			DialogExit();
			npchar.quest.utensil = "true";
			pchar.questTemp.Guardoftruth.Baster_church = "seek";
			AddQuestRecord("Guardoftruth", "27");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
