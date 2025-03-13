// boal 25/04/04 общий диалог горожан
#include "DIALOGS\%language%\Rumours\Common_rumours.c"  //homo 25/06/06
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // вызов диалога по городам -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Citizen\" + NPChar.City + "_Citizen.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // вызов диалога по городам <--
    ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 16/06/06
    int iTest, iTemp;
    iTest = FindColony(NPChar.City); // город
    ref rColony;
    string sTemp, sCity;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
	String attrLoc = Dialog.CurrentNode;
	
	if(HasSubStr(attrLoc, "RumourAboutOwners_"))
	{
		NPChar.RumourOwnerType = FindStringAfterChar(attrLoc, "_");
		Dialog.CurrentNode = "RumourAboutOwners_TakeRumour";
	}
	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "fight":
            LAi_group_Attack(NPChar, Pchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
            /*if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
				dialog.text = RandPhraseSimple("Un espion? Gardes!","Alarme! Il y a un intrus!");
				link.l1 = "Taisez-vous. Je m'en vais.";
				link.l1.go = "fight";
				break;
			}*/
			
			if (sti(NPChar.nation) == PIRATE)
			{
				if (sti(rColony.HeroOwn) == true) // наш горожанин
				{
				    dialog.text = RandPhraseSimple("On dit que tu es celui qui gouverne cette ville, "+GetSexPhrase("monsieur","mademoiselle")+".","Quelle rencontre agréable, le chef de la ville s'est adressé à moi avec une question.");
					link.l1 = RandPhraseSimple("J'ai changé d'avis.","Je suis simplement en train d'explorer cette ville. Au revoir.");
					link.l1.go = "exit";
					link.l2 = RandPhraseSimple("J'ai une question pour toi.","J'ai besoin d'informations.");
					link.l2.go = "quests";//(перессылка в файл города)
					if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
		            {
		                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
		                {
							link.l3 = RandPhraseSimple("Je veux discuter affaires.","Concernant les finances...");
							link.l3.go = "LoanForAll";//(перессылка в кредитный генератор)
						}
					}
					break;
				}
				else
				{ // пираты, не наши
				    dialog.text = RandPhraseSimple("Que voulez-vous ? Passez votre chemin.","Ne reste pas dans le chemin, va-t'en !");
					link.l1 = RandPhraseSimple("Eh, arrête d'aboyer, tu ne le feras pas?","Calme-toi, ou tu pourrais le regretter!");
					link.l1.go = "exit";
					link.l2 = RandPhraseSimple("J'ai une question pour toi.","Un moment de votre attention, s'il vous plaît. J'ai une question.");
					link.l2.go = "quests";//(перессылка в файл города)
					if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
		            {
		                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
		                {
							link.l3 = RandPhraseSimple("Je veux discuter affaires.","Au sujet des finances...");
							link.l3.go = "LoanForAll";//(перессылка в кредитный генератор)
						}
					}
					break;
				}
			}
            if(NPChar.quest.meeting == "0")
			{
				NPChar.quest.meeting = "1";

                // homo 05/08/06
				dialog.Text = NPCharRepPhrase(npchar,LinkRandPhrase("Mon nom est ","Mon nom est ","Vous pouvez m'appeler ")+GetFullName(npchar)+LinkRandPhrase(". Que voulez-vous?",". Je n'ai pas "+NPCharSexPhrase(NPChar,"vous avez déjà vu ici avant","vu là-bas avant toi")+", qui êtes-vous?",". Qui êtes-vous et que voulez-vous de moi?"),LinkRandPhrase("Salutations, "+GetAddress_Form(NPChar)+". Mon nom est "+GetFullName(npchar)+". Quel est le tien?","Bonjour, "+GetAddress_Form(NPChar)+"! Je suis "+GetFullName(npchar)+". Puis-je avoir votre nom?","Oui, "+GetAddress_Form(NPChar)+". Que voulez-vous ? Au fait, mon nom est "+GetFullName(npchar)+". Et vous êtes?"));

				Link.l1 = pcharrepphrase(LinkRandPhrase("Par le tonnerre ! ","Sacrebleu !","Mauvaise peste sur toi ! ")+"Oui, je suis le Capitaine "+GetFullName(Pchar)+LinkRandPhrase(", vous n'avez vraiment pas entendu parler de moi"+NPCharSexPhrase(NPChar,", fripouille?","?")," et "+GetSexPhrase("le pirate le plus notoire","la femme pirate la plus notoire")+" dans ces eaux ! "," et que je brûle en Enfer si ce n'est pas vrai!"),LinkRandPhrase("Je suis Capitaine"+GetFullName(Pchar)+".","Mon nom est "+GetFullName(Pchar)+".","Vous pouvez m'appeler Capitaine "+GetFullName(Pchar)));

                //LinkRandPhrase("I am Captain" + GetFullName(Pchar) + ".", "My name is " + GetFullName(Pchar) + ".", "You may call me Captain " + GetFullName(Pchar));
				Link.l1.go = "Meeting";
				
				//==> прибыла инспекция на Святом Милосердии
				if (pchar.location == pchar.questTemp.SantaMisericordia.ColonyZapret + "_town")
				{
					dialog.Text = LinkRandPhrase(LinkRandPhrase("Toute la ville est sur le qui-vive - don Fernando de Alamida, l'inspecteur royal, est arrivé. Vous savez, j'ai vu beaucoup de choses ici, mais ça... Ce n'est pas le chagrin qui change les gens, mais comment ils le gèrent. Ils disent qu'il est devenu un homme différent après la mort de son père. Maintenant, vous ne trouverez pas un serviteur de la Couronne plus incorruptible et... impitoyable dans tout l'Archipel.","Regardez seulement le 'Sainte Miséricorde' ! On dit que le roi lui-même l'a fait construire selon des plans spéciaux. Et remarquez - pas une seule égratignure. Comme si la Vierge Marie elle-même la protégeait. Quoique j'ai entendu des rumeurs... peut-être que ce n'est pas la Vierge du tout.","Savez-vous combien de fois ils ont essayé de tuer don Fernando ? Douze attaques en eaux libres - et c'est seulement l'année dernière ! Eh bien, avec un équipage aussi loyal et bien entraîné, et sous la protection du Seigneur - il survivra aussi à la treizième !"),LinkRandPhrase("Avez-vous entendu? Don Fernando de Alamida est arrivé dans notre ville, et ils disent qu'il est quelque part dans les rues en ce moment. J'aimerais le voir de mes propres yeux...","Un homme compliqué, ce don Fernando. Certains disent qu'il est un sauveur, nettoyant la Mère Patrie de la saleté. D'autres murmurent que quelque chose a cassé en lui après la mort de son père et bientôt nous pleurerons tous. Mais je vais vous dire ceci : ne le craignez pas. Craignez ceux qui ont fait de lui ce qu'il est.","Un si bel homme, ce don Fernando! Mais tu sais ce qui est étrange? C'est comme s'il ne remarquait personne. Tout n'est que devoir et service. J'ai entendu dire qu'il y avait une fille... mais après avoir rencontré un prêtre, il a complètement rejeté les plaisirs du monde. Comme s'il avait fait un voeu."),RandPhraseSimple(RandPhraseSimple("Sacre inspecteur ! Tant qu'il est là, la ville est comme morte. Pas de commerce, pas de plaisir. Même respirer, on dirait, doit être plus silencieux. Et vous savez ce qui est le plus effrayant ? C'est la même chose dans chaque port. Comme une horloge. Sa Majesté Royale n'aurait pas pu inventer volontairement cette torture pour nous tous !","Don Fernando a visité l'orphelinat de nouveau. Il fait des dons généreusement, prie pendant des heures. Un homme aussi digne devrait être présenté comme un exemple à ces maudits escrocs!"),RandPhraseSimple("Ha ! 'Saint' Fernando a encore fermé tous les bordels. Eh bien, peu importe, il s'en ira bientôt et ils ouvriront tout de suite.","L'insp... inspecteur est arrivé, c'est ça! Don Fernando de Almeyda, ou, comment s'appelle-t-il, Alamida! Tellement important que le gouverneur lui-même marche sur la pointe des pieds autour de lui. On dit qu'il regarde dans tes yeux et voit tous tes péchés tout de suite. Terrifiant!")));
					link.l1 = "...";
					link.l1.go = "exit";
				}
				//<== прибыла инспекция на Святом Милосердии
			}
			else
			{
				if(rand(5) == 1 && NPChar.sex == "woman" && !CheckAttribute(NPChar, "CitizenFindItem.NoQuest") && !CheckAttribute(PChar, "GenQuest.CitizenFindItem.StartQuest") && CheckAttribute(NPChar, "City"))
				{
					dialog.Text = "Capitaine, pourriez-vous m'aider, s'il vous plaît?";
					link.l1 = LinkRandPhrase("Désolé, non. J'ai peu de temps à perdre.","Désolé, je ne peux pas. Trop occupé.","Non, je ne peux pas. J'ai des affaires urgentes qui requièrent mon attention.");
					link.l1.go = "CitizenFindItem_NoQuest";
					link.l2 = LinkRandPhrase("Bien sûr que je peux. Quel est le problème?","Oui, je vais t'aider. Dis-moi en plus sur cette affaire à toi.","Parlez-moi davantage de cette affaire à vous...");
					link.l2.go = "CitizenFindItem_1";
					NextDiag.TempNode = "First time";
					break;
				}
				
				if(CheckAttribute(PChar, "GenQuest.CitizenFindItem.CitizenID") && PChar.GenQuest.CitizenFindItem.CitizenID == NPChar.ID && CheckCharacterItem(PChar, "DOjeronRing"))
				{
					dialog.Text = "Oui, Capitaine, je vous écoute.";
					link.l1 = NPChar.name+", j'ai trouvé votre bague de mariage.";
					link.l1.go = "CitizenFindItem_Complete_1";
					break;
				}
			
				link.l1 = PCharRepPhrase("Je veux en savoir plus sur cette ville.","Parlez-moi de cette ville.");
				link.l1.go = "new question";
 				link.l2 = RandPhraseSimple("J'ai une question pour toi.","J'ai besoin d'informations.");
				if (CheckCharacterItem(pchar, "CaptainBook"))				
				{
					if((pchar.questTemp.different.GiveShipLetters.city == npchar.city) && CheckAttribute(pchar, "questTemp.different.GiveShipLetters"))
					{
						link.l2.go = "ShipLetters_7";// генератор  "Найденные документы"
					}
					else
					{
						link.l2.go = "quests";
					}	
				}
				else
				{
					link.l2.go = "quests";//(перессылка в файл города)
				}	
				if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
	            {
	                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
	                {
						link.l3 = RandPhraseSimple("Je veux discuter affaires.","Concernant les finances...");
						link.l3.go = "LoanForAll";//(перессылка в кредитный генератор)
					}
				}
				// --> квестовый генератор мэра, поиск шпиёна на улице. eddy
				if (CheckAttribute(pchar, "GenQuest.SeekSpy.City") && pchar.location == (npchar.city + "_town"))
	            {
					link.l4 = NPCharSexPhrase(npchar,LinkRandPhrase("Attendez! Dites-moi qui vous êtes - tout de suite! Je recherche un espion ennemi à la demande du gouverneur de "+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gen")+"!","Arrêtez-vous! J'agis dans l'intérêt de la ville "+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gén")+"par ordre du gouverneur. Je fouille la ville à la recherche d'un agent hostile.","Arrête, ami ! Le gouverneur local "+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].lastname+" veut trouver un espion dans la ville."),LinkRandPhrase("Attendez, madame! Dites-moi qui vous êtes - tout de suite! Je recherche un espion ennemi à la demande du gouverneur de "+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gén")+"!","Femme, je dois vous arrêter! J'agis dans l'intérêt de la ville "+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gén")+" par ordre du gouverneur. Je fouille la ville à la recherche d'un agent hostile","Reste immobile, beauté! Un gouverneur local "+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].lastname+" veut trouver un espion dans la ville..."));
					link.l4.go = "SitySpy";
				}
				// <-- квестовый генератор мэра, поиск шпиёна на улице
				
				//Jason --> генератор Неудачливый вор
				if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_town" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
				{
					link.l16 = "Peut-être pouvez-vous me donner des conseils. Je veux acheter "+pchar.GenQuest.Device.Shipyarder.Type+", et on m'a dit qu'il était vendu dans votre ville. Eh bien, quelqu'un le vendait dans les rues. Savez-vous quelque chose à ce sujet?";
					link.l16.go = "Device_Citizen";
				}
				// <-- генератор Неудачливый вор
				
				// Квестовый генератор священника. Квест №2. Warship -->
				if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskPeople") && !CheckAttribute(NPChar, "GenQuest.ChurchQuest_2.AskedPeople") && NPChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_town")
	            {
					link.l5 = LinkRandPhrase("Êtes-vous conscient","Saviez-vous","Tu as entendu")+" qu'une église locale a été pillée récemment?");
					link.l5.go = "Citiz_GenQuest_Church_2_1";
				}
				// <-- Квестовый генератор священника. Квест №2.
				
                dialog.Text = NPCharRepPhrase(npchar,PCharRepPhrase(LinkRandPhrase("Oh, c'est toi, "+GetFullName(Pchar)+" "+GetSexPhrase(", vieux scélérat","- dame audacieuse")+"","Heureux de vous revoir, "+GetSexPhrase("vieux camarade","beauté")+" "+Pchar.name,"Oh, c'est le bon vieux "+GetSexPhrase("Capitaine","demoiselle")+" "+GetFullName(Pchar))+LinkRandPhrase(". Je pensais que tu étais mort !",". Et, certainement, "+GetSexPhrase("ivre comme d'habitude.","déjà sous le mauvais temps.")+"",". Et, comme je vois, toujours en liberté !")+LinkRandPhrase("Alors, exprimez-vous - de quoi avez-vous besoin?"," De quoi as-tu besoin cette fois ?","Tu me déranges encore pour rien?"),LinkRandPhrase(TimeGreeting()+", Capitaine ","Bonjour, "+GetAddress_Form(NPChar)+" ","Je vous salue, Capitaine ")+GetFullName(Pchar)+LinkRandPhrase(". Qu'est-ce que pourrait "+GetSexPhrase("un si galant gentleman","une dame si audacieuse")+", comme? Pourriez-vous éventuellement avoir besoin de quelque chose de moi?",". Pourquoi êtes-vous venu?",". Qu'est-ce que tu veux savoir cette fois?")),PCharRepPhrase(LinkRandPhrase("Bonjour, Capitaine ","Bonjour. Oh, c'est toi "+GetAddress_Form(NPChar)+" ","Oh, Capitaine ")+GetFullName(Pchar)+LinkRandPhrase(", je pensais"+NPCharSexPhrase(NPChar," "," ")+"nous ne nous reverrions jamais,",", je ne peux pas dire que je suis ravi"+NPCharSexPhrase(NPChar," "," ")+"pour te voir, mais",", Je vois, tu es toujours en vie. Regrettable. Alors,")+LinkRandPhrase(" de quoi avez-vous besoin?","Pourquoi êtes-vous venu?"," que puis-je "+NPCharSexPhrase(NPChar,"puis-je vous aider?","puis-je vous aider?")),LinkRandPhrase(TimeGreeting()+", Capitaine "+GetFullName(Pchar)+". Qu'est-ce que je peux vous aider?","Oh, si ce n'est pas"+GetSexPhrase("","")+" Capitaine "+GetFullName(Pchar)+"! Que voulez-vous savoir cette fois ?","Bonjour, "+GetAddress_Form(NPChar)+" "+Pchar.lastname+". Vouliez-vous quelque chose?")));                         
	   			link.l6 = PCharRepPhrase(RandPhraseSimple("Non, tu entends des choses. Je m'en vais maintenant.","Non, rien - je partais juste"+GetSexPhrase("","")+" à la taverne."),RandPhraseSimple("Non, rien. Bonne chance à toi !","Juste en train de regarder autour. Au revoir."));
				link.l6.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "ShipLetters_7":
			dialog.text = "Quelles questions?";
			link.l1 = "Le nom dans ces papiers vous dit quelque chose ?";
			link.l1.go = "ShipLetters_8";
		break;
		
		case "ShipLetters_8":
			dialog.text = LinkRandPhrase("Je me soucie pas des papiers inconnus. De plus, je ne sais pas lire. Va voir l'usurier, ce diable sait sûrement lire et écrire.","Je n'ai aucune idée de ce dont vous parlez. Demandez aux habitants de la ville, Capitaine "+GetFullName(Pchar)+".","Je n'ai vraiment aucune idée de comment vous aider, Capitaine "+GetFullName(Pchar)+". Essayez de demander à l'usurier - peut-être qu'il pourrait savoir.");
			link.l1 = "Je suivrai volontiers votre conseil!";
			link.l1.go = "exit";
		break;
		
		case "Meeting":
		    dialog.Text = NPCharRepPhrase(npchar,LinkRandPhrase("Mais ne mentez-vous pas, Capitaine "+GetFullName(Pchar)+"?","Et alors, "+PChar.name+"?","Je me souviendrai de toi, "+GetFullName(Pchar)+".")+"Et maintenant, qu'est-ce que vous avez besoin?",LinkRandPhrase("Un plaisir de vous rencontrer, Capitaine "+PChar.name,"Heureux"+NPCharSexPhrase(NPChar," "," ")+" de vous rencontrer, "+GetAddress_Form(NPChar)+" "+PChar.lastname,"Ravi de vous rencontrer, Capitaine "+PChar.name)+". Mais, je suppose, tu es venu ici pour plus que simplement apprendre mon nom?");

            link.l1 = PCharRepPhrase("Je voulais"+GetSexPhrase("","")+" en savoir quelque chose sur ce trou que vous appelez la ville!","Je voulais"+GetSexPhrase("","")+" pour savoir quelque chose sur cette ville.");
			link.l1.go = "new question";
            Link.l2 = RandPhraseSimple("J'ai une question pour toi.","J'ai besoin d'informations.");
			if (CheckCharacterItem(pchar, "CaptainBook"))				
			{
				if((pchar.questTemp.different.GiveShipLetters.city == npchar.city) && CheckAttribute(pchar, "questTemp.different.GiveShipLetters"))
				{
					link.l2.go = "ShipLetters_7";// генератор  "Найденные документы"
				}
				else
				{
					Link.l2.go = "quests";
				}	
			}
			else
			{
					link.l2.go = "quests";//(перессылка в файл города)
			}			
			if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
            {
                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
                {
					link.l3 = RandPhraseSimple("Je veux discuter affaires.","Concernant les finances...");
					link.l3.go = "LoanForAll";//(перессылка в кредитный генератор)
				}
			}
			
			//Jason --> генератор Неудачливый вор
			if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_town" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
			{
   				link.l16 = "Peut-être pouvez-vous me donner des conseils. Je veux acheter "+pchar.GenQuest.Device.Shipyarder.Type+", et on m'a dit qu'il était vendu dans votre ville. Eh bien, quelqu'un le vendait dans les rues. Savez-vous quelque chose à ce sujet?";
				link.l16.go = "Device_Citizen";
			}
			// <-- генератор Неудачливый вор
			
			// --> квестовый генератор мэра, поиск шпиёна на улице. eddy
			if (CheckAttribute(pchar, "GenQuest.SeekSpy.City") && pchar.location == (npchar.city + "_town"))
	        {
				link.l4 = NPCharSexPhrase(npchar,LinkRandPhrase("Attends! Dis-moi qui tu es - tout de suite! Je cherche un espion ennemi à la demande du gouverneur de "+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gen")+"!","Arrêtez! J'agis dans l'intérêt de"+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gen")+"par ordre du gouverneur. Je fouille la ville à la recherche d'un agent hostile.","Arrête, ami ! Le gouverneur local "+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].lastname+" veut trouver un espion dans la ville."),LinkRandPhrase("Attendez, madame! Dites-moi qui vous êtes - tout de suite! Je recherche un espion ennemi à la demande du gouverneur de "+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gén")+"!","Femme, je dois vous retenir ! J'agis dans l'intérêt de la ville "+XI_ConvertString("Colonie"+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].city+"Gén")+" par ordre du gouverneur. Je fouille la ville à la recherche d'un agent hostile.","Arretez, belle femme! Gouverneur local "+characters[GetCharacterIndex(pchar.GenQuest.SeekSpy.MayorId)].lastname+" veut chercher un espion dans la ville..."));
				link.l4.go = "SitySpy";
			}
			// <-- квестовый генератор мэра, поиск шпиёна на улице
			// Квестовый генератор священника. Квест №2. Warship -->
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskPeople") && !CheckAttribute(NPChar, "GenQuest.ChurchQuest_2.AskedPeople") && NPChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_town")
	        {
				link.l5 = LinkRandPhrase("Êtes-vous au courant","Tu as entendu","Avez-vous entendu")+" qu'une église locale a été récemment pillée?");
				link.l5.go = "Citiz_GenQuest_Church_2_1";
			}
			// <-- Квестовый генератор священника. Квест №2.
			
			Link.l6 = PCharRepPhrase(RandPhraseSimple("Non, tu entends des choses. Je m'en vais maintenant.","Non, rien - je me dirigeais juste vers la taverne."),RandPhraseSimple("Non, rien. Bonne chance à toi !","Juste en train de regarder autour. Au revoir."));
			Link.l6.go = "exit";
		break;
		
		case "new question":
            dialog.text = NPCharRepPhrase(npchar,PCharRepPhrase(LinkRandPhrase("Oh oui, je suis presque aussi content"+NPCharSexPhrase(NPChar," "," ")+" de te voir comme une coupe de tafia. Demande ce que tu veux.","Vous aimez parler, Capitaine? Eh bien, moi aussi... Surtout autour d'une tasse de rhum.","Oui, "+PChar.name+"?"),LinkRandPhrase("De quoi avez-vous besoin?","Je vois, Capitaine "+PChar.name+". Vous êtes"+GetSexPhrase("","")+" assez bavard. ","Tu m'as épuisé"+GetSexPhrase("","")+" avec vos questions, Capitaine. Mieux vaut m'aider avec le rhum.")),PCharRepPhrase(LinkRandPhrase("Que voulez-vous savoir "+GetAddress_Form(NPChar)+"?","Je vous écoute, Capitaine.","Je dois partir, alors faites vite, Capitaine."),LinkRandPhrase("Toujours content"+NPCharSexPhrase(NPChar," "," ")+"  pour avoir une bonne compagnie, "+GetAddress_Form(NPChar)+" "+PChar.lastname+". Parle franchement.","Oui, "+GetAddress_Form(NPChar)+"?","Vous aimez bavarder, Capitaine ? Eh bien, moi aussi...")));

            // homo 25/06/06
			link.l1 = LinkRandPhrase("Quels sont les potins populaires dans la taverne locale?","Qu'est-ce qui se passe dans ces contrées?","Quoi de neuf à terre ici?");
			link.l1.go = "rumours_citizen";
			link.l2 = LinkRandPhrase("Pouvez-vous me diriger là-bas?","Je ne peux pas trouver un chemin vers un certain endroit...","Pourriez-vous montrer le chemin...?");
			link.l2.go = "town";  //(перессылка в файл города)
			if(Rand(1)==0)
			{
				link.l3 = LinkRandPhrase("Je veux savoir ce que les gens disent à propos d'une certaine personne.","Ne sais-tu pas ce que les gens disent sur une certaine personne?","J'aimerais apprendre quelque chose sur les gens du pays.");
				if(rand(1) == 0 || PChar.location == "LaVega_Town" || PChar.location == "PuertoPrincipe_town"
				|| PChar.location == "Pirates_town" || PChar.location == "Panama_town" || !CheckAttribute(NPChar, "City"))
				{
					link.l3.go = "info"; //(перессылка в файл города)
				}
				else
				{
					link.l3.go = "RumourAboutOwners"; // Warship. Сделал по-другому - у жителя каждого города будет свой диалог.
				}
			}
			else
			{
				link.l3 = "S'il vous plaît, parlez-moi davantage de votre colonie.";
				link.l3.go = "colony";
			}
            link.l4 = RandPhraseSimple("J'ai des affaires importantes!","J'ai des affaires avec toi.");
			link.l4.go = "quests";  //(перессылка в файл города)
			link.l5 = PCharRepPhrase(RandPhraseSimple("Non, tu entends des choses. Je m'en vais maintenant.","Non, rien - je me dirigeais juste vers la taverne."),RandPhraseSimple("Non, rien. Bonne chance à toi!","Juste en train de regarder autour. Au revoir."));
			link.l5.go = "exit";
		break;
		
		case "RumourAboutOwners":
			Dialog.Text = "De qui voulez-vous savoir?";
			if(GetCharacterIndex(NPChar.city + "_Mayor") != -1)
			{
				link.l1 = "A propos du gouverneur.";
				link.l1.go = "RumourAboutOwners_Mayor";
			}
			if(GetCharacterIndex(NPChar.city + "_TavernKeeper") != -1)
			{
				link.l2 = "A propos du proprietaire de la taverne locale.";
				link.l2.go = "RumourAboutOwners_TavernKeeper";
			}
			if(GetCharacterIndex(NPChar.city + "_ShipYarder") != -1)
			{
				link.l3 = "Au sujet du maitre du port.";
				link.l3.go = "RumourAboutOwners_ShipYarder";
			}
			if(GetCharacterIndex(NPChar.city + "_Trader") != -1)
			{
				link.l4 = "A propos du propriétaire du magasin local.";
				link.l4.go = "RumourAboutOwners_Trader";
			}
			link.l9 = "Peu importe, oublie-le.";
			link.l9.go = "exit";
			break;
			
		case "RumourAboutOwners_TakeRumour":
			sTemp = sRumourAboutOwners_CityRumour(NPChar.City, NPChar.RumourOwnerType);
			Dialog.Text = sTemp;
			link.l1 = "Merci.";
			link.l1.go = "exit";
			// Здесь можно делать проверка по квестам, какой слух выпал
			DeleteAttribute(PChar, "QuestTemp.RumoursAboutOwners");
			break;
		
		case "colony":
			dialog.text = LinkRandPhrase("Honnêtement, je n'en sais pas grand-chose, mais je peux quand même vous en dire un mot ou deux.","Et qu'est-ce qui vous intéresse dans notre colonie?","D'accord. Que voudriez-vous savoir?");
            switch(Rand(1))
			{
				case 0:
					link.l1 = "Quel genre de ville est-ce ?";
					link.l1.go = "colony_town";
				break;

				case 1:
					link.l1 = "Que savez-vous sur le fort qui défend la ville?";
					link.l1.go = "fort";
				break;
            }
			link.l2 = "Changeons de sujet.";
			link.l2.go = "new question";
		break;
	  // to_do
		case "colony_town":
            dialog.text = "Tu plaisantes ? Ou tu blagues ? Regarde le coin droit de ton écran.";
			link.l1 = "Ouais, ma faute.";
		    link.l1.go = "exit";
		break;
		
		case "fort":
            dialog.text = "Je ne sais rien à ce sujet.";
			link.l1 = "Dommage.";
		    link.l1.go = "exit";
		break;
		
		//Jason --> генератор Неудачливый вор
		case "Device_Citizen":
           dialog.text = "Hmm, "+pchar.GenQuest.Device.Shipyarder.Type+"? Jamais entendu parler auparavant... Qu'est-ce que c'est, en fait? Je n'ai jamais entendu parler d'une telle chose de toute ma vie"+NPCharSexPhrase(npchar,"","")+".";
			link.l1 = "Eh bien, c'est un outil de charpentier de marine, "+pchar.GenQuest.Device.Shipyarder.Describe+". Quelqu'un aurait-il vendu une telle chose en ville ? Peut-être. Vous avez remarqué que quelqu'un avait une telle chose sur lui ?";
			link.l1.go = "Device_Citizen_1";
			npchar.quest.Device = "true";
		break;
		
		case "Device_Citizen_1":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) > 3 && sti(pchar.GenQuest.Device.Shipyarder.Chance1) < 6 && npchar.sex != "woman")
			{
				dialog.text = "Hmm... Oui, je suppose que j'ai vu une personne avec un objet qui ressemblait. Il se promenait la-bas avec plusieurs heures auparavant. Un dispositif interessant, certainement.";
				link.l1 = "Et à quoi ressemblait-il et où est-il allé? J'ai vraiment besoin de cet instrument.";
				link.l1.go = "Device_Common";
			}
			else
			{
				dialog.text = "Non, je n'ai rien vu de tel.";
				link.l1 = "Je vois. Eh bien - il est temps de poser des questions!";
				link.l1.go = "exit";
			}
		break;
		
		//============================ Генератор мэра. Квест по розыску шпиона на улице ============================
		case "SitySpy":
			dialog.text = NPCStringReactionRepeat(NPCharSexPhrase(npchar,"Et qu'est-ce que ça a à voir avec moi? Je suis un local!","Eh bien, pourquoi me dérangez-vous avec ça? Je vis dans cette ville et je ne sais rien de telles choses!"),NPCharSexPhrase(npchar,"Que voulez-vous de moi encore? N'ai-je pas déjà dit que je ne suis pas l'espion?!","Ne t'ai-je pas déjà dit que je suis du coin?!"),NPCharSexPhrase(npchar,"Mon cher, c'est toi encore! Laisse-moi tranquille - Je suis un local!","Pourquoi me déranges-tu encore avec tes questions stupides ?"),NPCharSexPhrase(npchar,"Encore ! C'est maintenant un scandale !","Écoute, laisse-moi tranquille, d'accord? S'il te plaît!"),"block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Qui peut confirmer votre déclaration?","Oh, je suis désolé - Je vous avais déjà demandé...","Je suis désolé, il y a tellement de gens...","D'accord, d'accord...",npchar,Dialog.CurrentNode);
		    link.l1.go = DialogGoNodeRepeat("SitySpy_1", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
			// ==> выбираем подтверждателя
			int num = FindNearCharacters(npchar, 20.0, -1.0, -1.0, 1.0, false, true);
			if(num > 0)
			{
				for(i = 0; i < num; i++)
				{
					iTemp = chrFindNearCharacters[i].index;
					if (CheckAttribute(&characters[iTemp], "CityType"))
					{
						if(characters[iTemp].CityType == "soldier" || characters[iTemp].CityType == "citizen")
						{
							break;
						}
					}
				}
				pchar.GenQuest.SeekSpy.Idx = chrFindNearCharacters[i].index; //индекс выбранного
				pchar.GenQuest.SeekSpy.Type = characters[sti(pchar.GenQuest.SeekSpy.Idx)].chr_ai.type; //тип кто помог
				pchar.GenQuest.SeekSpy.BaseIdx = npchar.index; //индекс
			}
		break;
		case "SitySpy_1":
			if (sti(pchar.GenQuest.SeekSpy.Idx) == -1 || sti(pchar.GenQuest.SeekSpy.Idx) == 1) //на всякий случай
			{
				dialog.text = "N'importe qui peut le faire! Écoute, pourquoi tu continues à me harceler?! Si tu as un problème, va voir le gouverneur et règle tout ça!",link.l1 ="Hmm... Il est probablement préférable de ne pas le déranger pour une si petite chose. Je te crois.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "Quelqu'un dans cette ville ! "+NPCharSexPhrase(npchar,GetFullName(&characters[sti(pchar.GenQuest.SeekSpy.Idx)])+" peut le faire, par exemple, maintenant que "+NPCharSexPhrase(&characters[sti(pchar.GenQuest.SeekSpy.Idx)],"il","elle")+" est juste là.","Oh, Seigneur, bien, par exemple, "+NPCharSexPhrase(&characters[sti(pchar.GenQuest.SeekSpy.Idx)],GetAddress_FormToNPC(NPChar)+" "+characters[sti(pchar.GenQuest.SeekSpy.Idx)].lastname,GetFullName(&characters[sti(pchar.GenQuest.SeekSpy.Idx)]))+" peut le faire.");				
			link.l1 = "D'accord, voyons voir, alors.";
		    link.l1.go = "SitySpy_2";
			sld = &characters[sti(pchar.GenQuest.SeekSpy.Idx)];
			sld.dialog.currentnode = "SeekSpy_Checking";
			pchar.GenQuest.SeekSpy.time = 4.0; //время на подбежать
			if (sld.chr_ai.type == "merchant") pchar.GenQuest.SeekSpy.time = 0.0; //мерчант базарит сразу
            LAi_SetActorTypeNoGroup(sld);
		break;
		case "SitySpy_2":
			sld = &characters[sti(pchar.GenQuest.SeekSpy.Idx)];
			LAi_SetActorTypeNoGroup(npchar);
			LAi_ActorTurnToCharacter(npchar, sld);
			LAi_ActorDialog(sld, pchar, "", stf(pchar.GenQuest.SeekSpy.time), 0); 
			DialogExit();
		break;
		//=================== ноды квеста мэра. поиск шпиона на улице, опрос свидетеля ==================
		case "SeekSpy_Checking":
			dialog.text = "Oui, "+NPCharSexPhrase(&characters[sti(pchar.GenQuest.SeekSpy.BaseIdx)]," est en effet un local.","elle est en effet une locale.");
			link.l1 = RandPhraseSimple("Je vois"+GetSexPhrase("","")+". Merci pour l'aide.","Tout est clair. Merci pour l'aide.");
			link.l1.go = "SeekSpy_Checking_1";
		break;
		case "SeekSpy_Checking_1":
			switch (pchar.GenQuest.SeekSpy.Type)
			{
				case "guardian": LAi_SetGuardianTypeNoGroup(npchar); break;
				case "patrol":   LAi_SetPatrolTypeNoGroup(npchar);   break;
				case "citizen":  LAi_SetCitizenTypeNoGroup(npchar);  break;
				case "merchant": LAi_SetMerchantTypeNoGroup(npchar); break;
			}
			LAi_SetCitizenTypeNoGroup(&characters[sti(pchar.GenQuest.SeekSpy.BaseIdx)]);
			NextDiag.CurrentNode = "First Time";
			DialogExit();
		break;
		
		// Мини квест на поиск обручального кольца -->
		case "CitizenFindItem_1":
			dialog.text = "Vous voyez, hier, j'étais hors de la ville, faisant une promenade, et j'ai perdu mon alliance..."+GetSexPhrase("Capitaine, pourriez-vous s'il vous plaît le chercher ?","Madame, s'il vous plaît, aidez-moi à le trouver !")+"";
			link.l1 = "Bien sûr "+GetSexPhrase("Je peux! Pour une fille aussi belle que toi, je peux tout faire!","Je vais t'aider. L'Eglise nous enseigne à aider ceux qui sont dans le besoin.")+"";
			link.l1.go = "CitizenFindItem_2";
			link.l2 = LinkRandPhrase("Non, je ne peux pas. Je suis désolé. J'ai trop à faire.","Je suis désolé, je ne peux pas. Je viens de me souvenir"+GetSexPhrase("","")+", que j'ai encore des affaires inachevées...","Je n'ai que très peu de temps, donc je ne peux pas t'aider avec quoi que ce soit...");
			link.l2.go = "CitizenFindItem_NoQuest";
			break;
			
		case "CitizenFindItem_2":
			dialog.text = ""+GetSexPhrase("Capitaine","Dame")+", c'est vraiment génial! S'il vous plaît, trouvez cette bague pour moi, mon mari arrive juste "+sti(NPChar.LifeDay)+" jours, et je ne voudrais pas qu'il me voie sans ma bague de mariage.";
			link.l1 = RandPhraseSimple("Où l'avez-vous perdu, dites-vous ?","Alors, où l'avez-vous réellement perdu ?");
			link.l1.go = "CitizenFindItem_3";
		break;
			
		case "CitizenFindItem_3":
			dialog.text = "Juste après les portes de la ville...";
			link.l1 = "Eh bien, alors je pars à sa recherche...";
			link.l1.go = "CitizenFindItem_4";
		break;
			
		case "CitizenFindItem_4":
			dialog.text = "Oui, s'il vous plaît. Et dépêchez-vous - rappelez-vous que vous avez seulement "+sti(NPChar.LifeDay)+" jours.";
			link.l1 = "Je me souviens.";
			link.l1.go = "exit";
			PChar.GenQuest.CitizenFindItem.StartQuest = true;
			PChar.GenQuest.CitizenFindItem.City = NPChar.City;
			PChar.GenQuest.CitizenFindItem.CitizenID = NPChar.ID;
				
			sCity = NPChar.City + "_ExitTown";
				
			//sTemp = "randitem" + (rand(1)+1); // Т.е. может получиться, что его вовсе найти не удастся. И это гуд.
			sTemp = "randitem1";
			Log_TestInfo("The ring shall be in the locator - " + sTemp);
			PChar.GenQuest.CitizenFindItem.ItemLocator = sTemp;
			ChangeItemDescribe("DOjeronRing", "itmdescr_WeddingRing");			
			items[FindItem("DOjeronRing")].Name = "itmname_WeddingRing";
			items[FindItem("DOjeronRing")].City = XI_ConvertString("Colony" + NPChar.City + "Gen");
			SetFunctionTimerCondition("CitizenFindItemMiniQuest_Timer", 0, 0, sti(NPChar.LifeDay), false);
			PChar.GenQuestRandItem.(sCity).(sTemp) = "DOjeronRing";
			SetGameModeCondition("CitizenFindItemMiniQuest_CheckItem");			
		break;
			
		case "CitizenFindItem_NoQuest":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			NPChar.CitizenFindItem.NoQuest = true; // Эта девушка квест больше не даст
		break;
			
		case "CitizenFindItem_Complete_1":
			dialog.text = ""+GetSexPhrase("Capitaine","jeune dame")+"! Je suis si heureux ! Comment puis-je vous remercier?";
			link.l1 = "Oh, pas de remerciements nécessaires - je l'ai fait tout à fait désintéressé.";
			link.l1.go = "CitizenFindItem_Complete_2";
			link.l2 = "Quelques centaines de pesos ne feraient certainement pas de mal...";
			link.l2.go = "CitizenFindItem_Complete_3";
			RemoveItems(PChar, "DOjeronRing", 1);
			DeleteAttribute(PChar, "GenQuest.CitizenFindItem");
			NPChar.CitizenFindItem.NoQuest = true;
			PChar.Quest.CitizenFindItemMiniQuest_Timer.over = "yes";
			BackItemDescribe("DOjeronRing");
			items[FindItem("DOjeronRing")].Name = "itmname_DOjeronRing";
			DeleteAttribute(&items[FindItem("DOjeronRing")], "City");
		break;
			
		case "CitizenFindItem_Complete_2":
			dialog.text = "Oh, "+GetSexPhrase("Capitaine, vous êtes une personne si noble","madame, vous êtes si noble")+"! Je prierai certainement pour vous à l'église! Adieu...";
			link.l1 = "Adieu, "+NPChar.name+".";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(PChar,"nobility" ,1);
			AddCharacterExpToSkill(PChar, "Leadership", 10);
			AddCharacterExpToSkill(PChar, "Fortune", 10);
		break;
			
		case "CitizenFindItem_Complete_3":
			iTemp = (rand(3)+1)*50;
			dialog.text = "Oh, mais bien sûr. Voici -"+FindRussianMoneyString(iTemp)+". C'est tout ce que j'ai. Prenez cet argent... Et adieu.";
			link.l1 = "Au revoir, "+GetFullName(NPChar)+".";
			link.l1.go = "exit";
			AddMoneyToCharacter(PChar, iTemp);
		break;
		// <-- Мини квест на поиск обручального кольца
		
		//=================== ноды квеста священника. поиск грабителей (квест №2)==================
		case "Citiz_GenQuest_Church_2_1":
			if(rand(3) != 1)
			{
				dialog.text = LinkRandPhrase("Non, je ne sais rien à ce sujet.","Je ne sais rien à ce sujet.","Je ne sais rien.");
					link.l1 = LinkRandPhrase("D'accord, merci.","Je vois, merci.","D'accord, veuillez m'excuser.");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = LinkRandPhrase("Je ne sais rien à ce sujet, mais vous pouvez demander aux clients de la taverne - ils sont sûrs de vous dire une chose ou deux.","Je ne peux rien vous dire. Demandez autour de vous à la taverne.","Je ne sais rien de particulier, mais j'ai entendu dire qu'il y avait des ragots à la taverne.");
				link.l1 = "Eh bien, c'est quelque chose au moins.";
				link.l1.go = "exit";
			}
			
			NPChar.GenQuest.ChurchQuest_2.AskedPeople = true;
		break;		
		
		//замечение по обнажённому оружию
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar,"Écoutez - en tant que citoyen de cette ville, je dois vous demander de vous abstenir de vous promener avec une lame dégainée.","Écoutez - en tant que citoyen de cette ville, je dois vous demander de ne pas vous promener avec une lame nue.");
				link.l1 = LinkRandPhrase("D'accord.","D'accord.","Comme vous dites...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar,"Retiens tes chevaux "+GetSexPhrase("camarade","lass")+" quand tu te promènes avec une arme à la main. Ça me rend nerveux...","Je n'aime pas quand "+GetSexPhrase("hommes","quelqu'un")+" vous promenez avec des armes prêtes. Cela me fait peur...");
				link.l1 = RandPhraseSimple("Compris.","Je le rangerai.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;

	}
}
