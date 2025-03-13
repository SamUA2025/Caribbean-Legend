// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Tous les bruits de "+GetCityName(npchar.city)+"à votre service. Que souhaitez-vous savoir ?","Nous en parlions justement. Vous devez avoir oublié...","C'est la troisième fois que tu m'importunes...","Vous répétez tout comme un perroquet...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+" , peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Oui...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if(CheckAttribute(pchar, "questTemp.Saga") && pchar.questTemp.Saga == "cartahena" && !CheckAttribute(npchar, "quest.gonsales"))
			{
				link.l1 = "Je cherche Enrique Gonzales. Pourriez-vous me dire comment le trouver ?";
				link.l1.go = "saga";				
			}
		break;
			
		case "saga":
			dialog.text = "Tout le monde connaît Senor Gonzales ! Sa maison est à côté de l'autorité portuaire.";
			link.l1 = "Quel âge a-t-il ?";
			link.l1.go = "saga_1";
		break;
		
		case "saga_1":
			dialog.text = "Eh bien, je ne sais pas vraiment, mais il semble avoir au moins cinquante ans. Il vit dans cette maison depuis un bon moment. Il aime raconter toutes sortes de balivernes sur les pirates qu'il a probablement croisés seulement dans ses rêves.";
			link.l1 = "On dirait que c'est l'homme qu'il me faut. Merci, "+npchar.name+"Tu as été d'une grande aide !";
			link.l1.go = "saga_2";
		break;
		
		case "saga_2":
			DialogExit();
			npchar.quest.gonsales = "true";
			pchar.questTemp.Saga.Gonsales = "true";
			pchar.quest.Saga_Gonsales1.win_condition.l1 = "location";
			pchar.quest.Saga_Gonsales1.win_condition.l1.location = "Cartahena_houseF2";
			pchar.quest.Saga_Gonsales1.function = "Saga_CreateGonsalesA";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
