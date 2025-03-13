// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Questions, "+GetAddress_Form(NPChar)+"?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Got it, please provide the text you need translated."+GetSexPhrase("Hm, quelle est la grande idée, "+GetAddress_Form(NPChar)+"? ","Encore avec les questions étranges ? Ma jolie, va prendre du rhum ou quelque chose...")+"","Tout au long de cette journée, c'est la troisième fois que tu parles d'une question..."+GetSexPhrase(" Sont-ce là des signes d'attention ?","")+"","Encore des questions, je présume, "+GetAddress_Form(NPChar)+"?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis","Je n'ai rien à dire pour le moment."),"Non, non ma belle...","Pas question, ma chère...","Non, quelles questions?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica_W")
            {
                link.l1 = "Ecoute femme, on dit que tu étais proche de mon ancien compagnon Francois Gontier. Vraiment proche...";
                link.l1.go = "Jamaica_ratW_1";
            }
			
			if (pchar.questTemp.Slavetrader == "FindRatJamaica_WP")
            {
				if (CheckCharacterItem(pchar, "jewelry43"))
				{
					link.l1 = "J'ai apporté ton collier avec des pierres précieuses. Le voilà. Que Dieu me protège des femmes avides comme toi à l'avenir.";
					link.l1.go = "Jamaica_ratW_5";
				}
				else
				{
					link.l1 = "Rien pour le moment. Je cherche ton collier.";
					link.l1.go = "exit";
				}
            }
			
		break;
		
		case "Jamaica_ratW_1":
            dialog.text = "Oui, nous l'étions. Et alors ? Je ne suis pas une femme mariée et je passe du temps avec qui je veux. Francois est un marin très respectable, pas comme nos pêcheurs et fermiers locaux. Il est si... Oh ! Et il m'a offert de si beaux cadeaux !";
            link.l1 = "D'accord, ça suffit ! Je sais quelles qualités possède mon compagnon, tu n'as pas besoin de me les énumérer. Je m'en moque de ce qui s'est passé entre vous deux. Vous pouvez même vous marier, je m'en contrefiche. Je dois le trouver tout de suite, tu comprends ? Sais-tu où il est parti ?";
            link.l1.go = "Jamaica_ratW_2";
        break;
		
		case "Jamaica_ratW_2":
            dialog.text = "Tee hee... Tu es son camarade de bord, et tu ne sais pas où il est parti. C'est drôle !";
            link.l1 = "Ce n'est pas drôle, femme. Nous avions convenu de nous rencontrer en Jamaïque et ensuite un voyage conjoint nous attendait... si tu me comprends. Je ne pourrai pas le faire seul et il est parti on ne sait où !";
            link.l1.go = "Jamaica_ratW_3";
        break;
		
		case "Jamaica_ratW_3":
            dialog.text = "Je vois. Eh bien, si un tel voyage lucratif est à votre porte, étant donné que vous et Francois êtes amis... Je vous dirai où il est parti, mais pour une petite récompense.";
            link.l1 = "Oui, je connais la situation. Combien veux-tu?";
            link.l1.go = "Jamaica_ratW_4";
        break;
		
		case "Jamaica_ratW_4":
            dialog.text = "Oh, que c'est vénal ! Je n'ai pas besoin d'argent. Non, je veux quelque chose de spécial. François m'a promis de me donner un joli collier avec des pierres précieuses. Je m'en suis déjà vantée auprès de mes amis et il s'est enfui... Apporte-moi le pendentif et je te dirai où il est parti, hé-hé !";
            link.l1 = "Espèce de garce impertinente ! Vous, les filles néerlandaises, êtes aussi avides qu'elles viennent ! D'accord, tu auras ton collier.";
            link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_5");
			pchar.questTemp.Slavetrader = "FindRatJamaica_WP";
        break;
		
		case "Jamaica_ratW_5":
            dialog.text = "Ah, c'est magnifique ! Maintenant, mes amis pourront devenir verts de jalousie !";
            link.l1 = "Transmets-leur mes condoléances. Maintenant, commence à parler. Où est-ce que François est parti?";
            link.l1.go = "Jamaica_ratW_6";
			RemoveItems(PChar, "jewelry43", 1);
        break;
		
		case "Jamaica_ratW_6":
            dialog.text = "Oui, bien sûr, monsieur. Francois a mis les voiles vers Cuba, à La Havane.";
            link.l1 = "Merci pour le tuyau coûteux, garce. C'est tout ce que je voulais.";
            link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_6");
			pchar.questTemp.Slavetrader = "FindRatHavana";
        break;
		
		
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
