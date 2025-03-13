// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("jeune homme","jeune demoiselle")+"?","Que désirez-vous, "+GetSexPhrase("beau","jolie créature")+"Demande donc."),"Encore des questions?","Tee-hee, si cela vous est égal - des questions...",""+GetSexPhrase("Hum, pourquoi ne pas choisir une beauté pour vous-même ? Je commence à avoir des soupçons à votre sujet...","Hm, pourquoi ne choisis-tu pas une beauté pour toi-même ? Nous n'avons pas de garçons ici, j'en ai peur, hi-hi...")+"","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, excusez-moi.","En fait, peu importe..."),"Je... mes excuses, je n'ai pas de questions, pour l'instant.","Vous avez raison, c'est déjà la troisième fois. Pardonnez-moi.","Peut-être la prochaine fois, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "GotoBridgetown" && !CheckAttribute(npchar, "quest.HWICTalked"))
            {
                link.l1 = "J'ai acheté une cargaison d'acajou à échanger et je me dirige vers Blueweld. C'est encore un long chemin, et mes hommes sont peu nombreux et impatients... Combien cela coûterait-il pour laisser cinquante marins se reposer ici pour la nuit ?";
                link.l1.go = "BrothelDone";
            }
		break;
		
		case "BrothelDone":
			dialog.text = "Cinquante marins - quinze mille.";
			link.l1 = "Une somme importante... Je dois y réfléchir.";
			link.l1.go = "exit";	
			npchar.quest.HWICTalked = "true";
			pchar.questTemp.HWIC.Eng.BridgeCounter = sti(pchar.questTemp.HWIC.Eng.BridgeCounter)+1;
			AddQuestRecord("Holl_Gambit", "2-7");
			DelLandQuestMark(npchar);
			if (sti(pchar.questTemp.HWIC.Eng.BridgeCounter) == 7) 
			{
			AddQuestRecord("Holl_Gambit", "2-6");
			pchar.quest.GotoBridgetownOver.over = "yes";//снять таймер
			DelMapQuestMarkCity("Bridgetown");
			pchar.questTemp.HWIC.Eng = "SeekVanBerg";
				pchar.quest.VanBergAttack_Check.win_condition.l1 = "MapEnter";
				pchar.quest.VanBergAttack_Check.function = "VanBergAttackCheck";
				//if(sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_VALCIRIA || GetCompanionQuantity(pchar) > 1) AddDialogExitQuestFunction("FailVanBergInWorld");
				//else AddDialogExitQuestFunction("CreateVanBergInWorld");
			}
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
