// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Tous les rumeurs de "+GetCityName(npchar.city)+" à votre service. Que souhaitez-vous savoir ?","Nous en parlions justement. Vous devez avoir oublié...","C'est la troisième fois aujourd'hui que tu parles d'une question...","Tu répètes tout comme un perroquet...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+", peut-être la prochaine fois.","Bon, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Oui...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "portprince")
			{
				link.l1 = "Dis-moi, un galion du nom de 'Santa Margarita' s'est-il arrêté récemment à ta colonie ? Peut-être comme prise d'un corsaire ?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Matelot, c'est plutôt rare que quelqu'un s'arrête à notre colonie avec des prises, et nous n'avons pas vu de galion avec un nom pareil. Hispaniola est une île sauvage et nous sommes une petite colonie. C'est calme ici. Nous commerçons avec les boucaniers des hautes terres pour des peaux de vache et du boeuf séché. Les corsaires ne traînent pas souvent, nous n'avons pas de bordels ici et les Espagnols sont à proximité. Allez chercher votre galion ailleurs.";
			link.l1 = "Je vois. Merci pour le conseil !";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "7");
			pchar.questTemp.Guardoftruth = "tortuga";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
