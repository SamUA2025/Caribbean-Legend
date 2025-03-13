// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider?"),"Vous avez essayé de me poser cette question il n'y a pas longtemps...","Oui, laissez-moi deviner... Encore une fois à tourner en rond ?","Ecoutez, je gère les finances ici, je ne réponds pas aux questions...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, où est donc passée ma mémoire...","Vous avez deviné, je suis désolé...","Je comprends...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "utensil" && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "Monsieur, j'ai une affaire quelque peu inhabituelle. Je sais qu'un corsaire français du nom de Gaius Marchais vous a récemment vendu deux objets uniques : un ostensoir en or et un encensoir en or. J'aimerais vous les acheter.";
                link.l1.go = "guardoftruth";
			}
			if (CheckAttribute(npchar, "quest.GOT_chest") && CheckCharacterItem(pchar, "chest"))
			{
				link.l1 = "Je vous ai apporté un petit coffre de doublons.";
                link.l1.go = "guardoftruth_3";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Oh, oui ! Je m'en souviens bien sûr ! Oui, c'étaient vraiment des pièces originales, et plus important encore, coûteuses. Mais vous arrivez trop tard, capitaine, je ne les ai plus. Je les ai déjà vendues.";
			link.l1 = "Inouï ! Et qui s'intéressait à ces objets d'église ? Mynheer, à qui les avez-vous vendus ? J'aimerais essayer de les racheter...";
			link.l1.go = "guardoftruth_1";
			npchar.quest.utensil = "true";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Hm, et pourquoi devrais-je vous donner les noms de mes clients ?";
			if (CheckAttribute(pchar, "questTemp.HWIC.Detector") && pchar.questTemp.HWIC.Detector == "self_win")
			{
				link.l1 = "Peut-être, parce que je suis un bon ami aux yeux du gouverneur Matthias Beck et je peux lui demander une sanction correspondante pour vous ?";
				link.l1.go = "guardoftruth_2_1";
			}
			else
			{
				if (CheckAttribute(pchar, "questTemp.HWIC.Detector") && pchar.questTemp.HWIC.Detector == "holl_win")
				{
					link.l1 = "Peut-être, parce que j'entretiens d'excellentes relations avec la Compagnie néerlandaise des Indes occidentales et que j'ai rendu de grands services à de nombreux colons néerlandais de l'archipel ?";
					link.l1.go = "guardoftruth_2_2";
				}	
				else
				{
					link.l1 = "Peut-être parce que je vais le payer ?";
					link.l1.go = "guardoftruth_2_3";
					npchar.quest.GOT_chest = "true";
				}
			}
		break;
		
		case "guardoftruth_2_1":
			dialog.text = "Ah, bien sûr vous êtes "+GetFullName(pchar)+", un ami du gouverneur lui-même qui a révélé la conspiration criminelle de Lucas Rodenburg... Comment pourrais-je oublier cela ? Bien sûr, je vais vous le dire.";
			link.l1 = "Alors, je suis tout ouïe.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_2_2":
			dialog.text = "Ah,  bien, vous êtes "+GetFullName(pchar)+", le grand conquérant du 'bateau fantôme' pirate. Comment pourrais-je oublier cela ? Bien sûr, je vais vous le dire.";
			link.l1 = "Alors, je suis tout ouïe.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_2_3":
			dialog.text = "D'accord, alors. Pour un coffre rempli jusqu'au sommet de doublons d'or, je suppose que je vous parlerai de ceux qui vous ont devancé pour faire l'achat.";
			if (CheckCharacterItem(pchar, "chest"))
			{
				link.l1 = "Voici, vous allez. Ce sont des objets très chers pour moi...";
				link.l1.go = "guardoftruth_3";
			}
			else
			{
				link.l1 = "D'accord, je vous apporterai ce que vous demandez. Ce sont des objets très chers à mes yeux...";
				link.l1.go = "exit";
			}
		break;
		
		case "guardoftruth_3":
			RemoveItems(pchar, "chest", 1);
			Log_Info("You've given a chest of doubloons");
			PlaySound("interface\important_item.wav");
			dialog.text = "Magnifique. Dans ce cas, je suis prêt à partager quelques informations avec vous.";
			link.l1 = "Je suis tout ouïe.";
			link.l1.go = "guardoftruth_4";
			DeleteAttribute(npchar, "quest.GOT_chest");
		break;
		
		case "guardoftruth_4":
			dialog.text = "L'encensoir en or a été acheté par un homme nommé Rolande Moses, mieux connu sous le nom de Rollie le Cap. Pourquoi ce boucher avait-il besoin d'un objet d'église précieux, je ne peux pas le comprendre, mais pour une raison quelconque, il en était indescriptiblement ravi... Au fait, je doute que vous rencontriez Rollie lui-même.";
			link.l1 = "Pourquoi donc ?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "Parce que ce voleur avide de marchands anglais isolés est récemment tombé avec son schooner directement dans les griffes du Colonel Fox. Savez-vous qui c'est ? ";
			link.l1 = "Tu paries ! Le commandant des 'renards de mer' à St. Jones sur Antigua...";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "Eh bien, alors vous comprenez pourquoi nous ne reverrons jamais notre pauvre Rolande. Le colonel a saisi sa goélette avec tous les survivants de son équipage et les a livrés à St. Jones où on leur a probablement déjà passé une corde autour du cou.";
			link.l1 = "Je vois. Et l'ostensoir ?";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "L'ostensoir a été acquis très récemment par Senora Belinda de Ribero de Cumana. Une senora très notable, une parente de Fernando de Villegas lui-même, gouverneur de Cumana. Je suppose qu'elle voulait l'apporter comme un cadeau à l'église.";
			link.l1 = "Señora Belinda de Ribero ? Je peux la trouver à Cumana, n'est-ce pas ?";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			dialog.text = "Absolument. Elle a dit elle-même qu'elle rentrait directement chez elle depuis Willemstad.";
			link.l1 = "D'accord. Merci, "+npchar.name+", tu as été d'une grande aide !";
			link.l1.go = "guardoftruth_9";
		break;
		
		case "guardoftruth_9":
			dialog.text = "À tout moment, monsieur. Rendez-moi visite de temps en temps !";
			link.l1 = "Je vous souhaite des clients riches avec des bourses pleines et des cervelles vides... Ha-ha !";
			link.l1.go = "guardoftruth_10";
		break;
		
		case "guardoftruth_10":
			DialogExit();
			AddQuestRecord("Guardoftruth", "23");
			pchar.questTemp.Guardoftruth.Usurer = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
