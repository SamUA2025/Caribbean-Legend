// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Allez-y, que voulez-vous ?","Nous en parlions justement. Vous avez dû oublier...","C'est la troisième fois aujourd'hui que vous parlez d'une certaine question...","Ecoute, c'est une boutique. Les gens achètent des choses ici. Ne me dérange pas !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+", peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Hm, je ne vais pas...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Dis-moi, le nom Juan te dit-il quelque chose ?";
				link.l1.go = "Consumption";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "En avril 1654, une frégate a accosté à votre port sous le commandement du capitaine Miguel Dichoso après quoi il a disparu. Ce nom vous dit quelque chose ? Peut-être a-t-il acheté de la marchandise chez vous ou dit quelque chose...";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Oh, allons, capitaine ! J'ai déjà eu deux Juans dans ma boutique aujourd'hui, et un autre hier. Quoi, suis-je censé me souvenir de chacun ?";
			link.l1 = "D'accord. Désolé de vous déranger...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "Oh, capitaine, j'ai vu tant de frégates et de galions aller et venir ici pendant ce temps, des Miguels et des Carlos...";
			link.l1 = "Je vois. Donc, vous ne pouvez être d'aucune aide...";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
