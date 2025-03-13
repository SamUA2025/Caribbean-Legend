// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Tous les rumeurs de "+GetCityName(npchar.city)+" à votre service. Que voulez-vous savoir ?","Nous en parlions justement. Tu dois avoir oublié...","C'est la troisième fois aujourd'hui que tu parles d'une question...","Vous répétez tout comme un perroquet...","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+", peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Oui...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlave_Villemstad")
            {
                link.l1 = "J'ai entendu dire qu'il y avait un sacré bazar sur l'île... Des esclaves ?";
                link.l1.go = "EscapeSlaveVillemstad_T1";
            }
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "SeekPortVillemstad")
            {
                link.l1 = "J'ai entendu dire que ce misérable vaurien Bart le Portugais a enfin rencontré la justice ! Est-il en prison ? Quand aura lieu son exécution, savez-vous ? Je veux venir voir, j'ai un compte à régler avec cette vermine...";
                link.l1.go = "Portugal";
            }
 		break;

		//работорговец
		case "EscapeSlaveVillemstad_T1":
			dialog.text = "Eh bien, il n'y a jamais eu un tel désordre... Plus de mille nègres se sont révoltés. Deux plantations ont été réduites en cendres et chacun de leurs maîtres a été assassiné. Le commandant craint que les esclaves ne viennent attaquer la ville, alors il a instauré la loi martiale. Et tout a commencé à cause de deux nègres, un bouc nommé Tamango et une biche nommée Isauri...";
			link.l1 = "Ça semble assez dramatique. Raconte-moi toute l'histoire, qui sont ces nègres ?";
			link.l1.go = "EscapeSlaveVillemstad_T2";
		break;
		
		case "EscapeSlaveVillemstad_T2":
				dialog.text = "Tamango et Izaura - des esclaves à la plantation de Blenheim, la première plantation brûlée. Ces deux nègres s'aimaient. Mais un fils de planteur, Leonsio, arriva d'Europe et s'éprit de la biche. Il voulait faire d'Izaura sa concubine personnelle. Le bouc noir Tamango n'était pas d'accord avec cette idée, et Izaura non plus, elle aimait vraiment le diable noir. Ce Tamango était une sorte de chef ou quelque chose en Afrique... Un bouc géant - plus noir que le péché et mortel avec une hache, les autres nègres le craignaient et le respectaient. Alors ce nègre a mené les autres esclaves dans une révolte. Ils ont attaqué les gardes la nuit, tué tous les blancs à l'extérieur de la grande maison, les mulâtres aussi. Puis Izaura a ouvert les portes de la plantation et les singes sauvages ont tué tout le monde à l'intérieur. Blenburg a été réduit en cendres. Ensuite, les esclaves ont fui dans les jungles et ont disparu...";
			link.l1 = "Eh bien, quelle histoire, on dirait l'intrigue d'un roman ! Une vraie révolte d'esclaves, tout comme la Rome antique. Comment as-tu découvert tout ça, d'ailleurs ?";
			link.l1.go = "EscapeSlaveVillemstad_T3";
		break;
		
		case "EscapeSlaveVillemstad_T3":
			dialog.text = "Des rumeurs, mon cher, la terre en regorge. Le rhum délie les langues, tout ce que vous avez à faire est d'écouter...";
			link.l1 = "Et comment tout cela s'est-il terminé ? Ont-ils trouvé ces nègres ?";
			link.l1.go = "EscapeSlaveVillemstad_T4";
		break;
		
		case "EscapeSlaveVillemstad_T4":
				dialog.text = "Ha, pas une chance ! Jusqu'à ce que les renforts parviennent enfin à arriver, personne n'a mis un pied dans la jungle. Puis un vaisseau de la Compagnie est arrivé avec une unité de soldats et ils ont fouillé l'île. Ils n'ont pas trouvé de peau noire ni de cheveux crépus d'un seul nègre en fuite.";
			link.l1 = "Eh bien, comment ça se fait ! Un millier de noirauds se sont tous évaporés dans la nature ?";
			link.l1.go = "EscapeSlaveVillemstad_T5";
		break;
		
		case "EscapeSlaveVillemstad_T5":
			dialog.text = "En fait, dans l'eau.";
			link.l1 = "De quoi parles-tu, "+npchar.name+"? Tu sais aussi bien que moi que les negres ne savent pas nager.";
			link.l1.go = "EscapeSlaveVillemstad_T6";
		break;
		
		case "EscapeSlaveVillemstad_T6":
			dialog.text = "Hi-hi... oh non, ces noirs ne sont pas si vite devenus appât pour requins. Le fait est que la nuit suivant la mutinerie, une barque a disparu des quais. Peignez-moi en noir et je jouerai du banjo et danserai pour vous si ce n'était pas par la main de ce gredin Tamango et de ses nègres ! C'est pourquoi ils ne sont plus sur l'île.";
			link.l1 = "Ha, maintenant j'ai tout entendu, "+npchar.name+". Tu t'attends à ce que je croie qu'une bande de négros à moitié sauvages puisse manier les voiles et naviguer ? Je m'attendrais plutôt à ce qu'un navire de singes débarque de Guinée.";
			link.l1.go = "EscapeSlaveVillemstad_T7";
		break;
		
		case "EscapeSlaveVillemstad_T7":
			dialog.text = "Je ne l'ai pas cru non plus, monsieur, mais la preuve est dans le navire disparu. Peut-être que l'un de ces nègres a servi comme intendant sur un navire et a appris quelques techniques de navigation. Peut-être ont-ils utilisé de la magie noire, qui sait ! Passez me voir à nouveau, "+pchar.name+", je vous raconterai d'autres histoires la prochaine fois.";
			link.l1 = "Merci ! Eh bien, il est temps pour moi de m'en aller.";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "22_2");
			pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_P";
		break;						

		case "Portugal":
			dialog.text = "Oui, c'est exact. Ils ont attrapé ce pirate. Et pouvez-vous croire comment ? Il a été ramassé seul sur une chaloupe au milieu de la mer. Il n'a même pas bronché avant d'être envoyé dans la cale pour les rats. C'est vraiment amusant, vous savez, un pirate si dangereux attrapé comme un tel novice !";
			link.l1 = "Et pourquoi était-il tout seul en mer ?";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Il a probablement décidé de se séparer de ses sbires, sans aucun doute... Ils n'ont pas pu partager le butin équitablement. Maintenant, il est entre les mains de la Compagnie elle-même et ces gars-là ne prennent pas bien les plaisanteries. On dit qu'il s'est emparé d'un des navires de la Compagnie avec quelque chose de précieux. Apparemment, c'est juste parce qu'ils veulent lui soutirer des informations, il ne pend pas encore au bout d'une corde.";
			link.l1 = "Alors, quand aura lieu son exécution, savez-vous?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Personne ne sait. Je pense qu'une fois que la Compagnie découvrira ce qu'elle veut, ils lui passeront une cravate de chanvre autour du cou. Le Portugais est en prison en ce moment sous une garde fiable\nRécemment, ils ont amené son maître d'équipage ici aussi. Son histoire était encore plus surprenante, il s'est rendu aux Hollandais à Philipsburg. Alors, ils l'ont installé dans une cellule juste à côté de son ancien capitaine, donc ils sont voisins maintenant, hé-he...";
			link.l1 = "Les miracles arrivent ! Très bien, je guetterai les nouvelles. Je ne veux pas manquer cette pendaison. Adieu, "+npchar.name+" !";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			DialogExit();
			pchar.questTemp.Portugal = "PortugalInPrison";
			AddQuestRecord("Portugal", "32");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
