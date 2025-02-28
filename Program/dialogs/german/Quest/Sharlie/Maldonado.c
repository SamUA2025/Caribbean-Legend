// Алонсо де Мальдонадо
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Gibt es etwas, das Sie benötigen?";
			link.l1 = "Nein, nichts.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "ksochitam":
			dialog.text = "Halt, Kapitän "+GetFullName(pchar)+"...";
			link.l1 = "Irgendwie bin ich nicht einmal überrascht über die Anwesenheit der spanischen Soldaten hier... Ich nehme an, ich habe mich einfach daran gewöhnt, dass immer jemand hinter mir her ist. Was suchst du auf dieser gottverlassenen Insel, Kastilier? Suchst du einen schnellen Weg, um deine Hacken hochzuschlagen?";
			link.l1.go = "ksochitam_1";
		break;
		
		case "ksochitam_1":
			dialog.text = "Mein Name ist Alonso de Maldonado. Das mag dir nichts sagen, aber Diego de Montoya könnte ein paar Glocken läuten. Er war mein bester Freund. Er hat mein Leben gerettet und jetzt ist sein Blut an deinen Händen.";
			link.l1 = "Ich nehme an, du hast mir hierher gefolgt, um Rache zu suchen?";
			link.l1.go = "ksochitam_2";
		break;
		
		case "ksochitam_2":
			dialog.text = "Ich suche nicht nur nach Rache. Soweit ich verstehe, hast du die Maske von Kukulcan?";
			link.l1 = "Nun, ich werde verdammt sein! Ein weiterer Schatzsucher! Kommst du, um unvollendete Geschäfte von Don Diego zu erledigen?";
			link.l1.go = "ksochitam_3";
		break;
		
		case "ksochitam_3":
			dialog.text = "Ich interessiere mich nicht für Schätze. Ich habe die Reichtümer in Tayasal gesehen. Miguel Dichoso konnte nicht viel mehr als einen Bissen herausziehen. Die Maske ist es, was ich will.";
			link.l1 = "Sie waren in Tayasal? Das ist schwer zu glauben. Soweit ich mich erinnere, war Dichoso der einzige Überlebende der Expedition.";
			link.l1.go = "ksochitam_4";
		break;
		
		case "ksochitam_4":
			dialog.text = "Ich war zwanzig Jahre vor Dichoso in Tayasal. Genau zu der Zeit, als dieser verrückte Zauberer Kanek dieses verabscheuungswürdige Menschenopfer-Ritual benutzte, um die Maske auf dieser Insel zu verstecken.";
			link.l1 = "Ich kann kaum glauben, was ich höre! Du kommst aus derselben Schar von Konquistadoren, die dorthin gebracht wurde, um geopfert zu werden, als der Wächter der Wahrheit erschaffen wurde? Ihr seid alle tot!";
			link.l1.go = "ksochitam_5";
		break;
		
		case "ksochitam_5":
			dialog.text = "Nicht alle von uns. Ich habe überlebt.";
			link.l1 = "Warum haben die Itza sich entschieden, dich zu verschonen? Was macht dich so anders?";
			link.l1.go = "ksochitam_6";
		break;
		
		case "ksochitam_6":
			dialog.text = "Du würdest es nicht verstehen. Verdammt, ich habe es auch nicht verstanden. Niemand hat mich verschont. Ich erinnere mich daran, als wäre es gestern gewesen... Gleich nachdem dieser Wilde ein Messer nahm und ein Stück Haut von Cascos Rücken filetierte, bevor er ihn tötete und anfing wie ein Wahnsinniger zu heulen, glaube ich, wurde ich in das Idol hineingesogen. Ich wachte zwanzig Jahre später weit entfernt von Tayasal auf, in dem, was sich wie ein bloßer Moment anfühlte!";
			link.l1 = "Ein Raum-Zeit-Trichter... Verdammt noch mal, alles, was Ksatl Cha gesagt hat, war genau richtig! Wie hast du von der Maske erfahren? Wofür brauchst du sie?";
			link.l1.go = "ksochitam_7";
		break;
		
		case "ksochitam_7":
			dialog.text = "Ich muss die Brut der Hölle aufhalten, beschworen von einem wahnsinnigen indischen Zauberer. Diese Abscheulichkeit zielt darauf ab, aus unserer Welt ein Feuermeer zu machen!";
			link.l1 = "Hmm... Du hast mit Vater Vincento gesprochen, nicht wahr? Der Inquisitor hält mit dem Hasen und rennt mit den Hunden. Überraschung, Überraschung. Er hat dich ausgesandt, um mich für eine royale Schlacht aufzuspüren? Gut gemacht! Du hast deine Mission erfüllt, Don Alonso!";
			link.l1.go = "ksochitam_8";
		break;
		
		case "ksochitam_8":
			dialog.text = "Der Herr stärkt meine Hand im Kampf gegen das Böse. Ich werde nach Tayasal zurückkehren und die Maske benutzen, um die Tore für immer zu versiegeln. Und kein Dämon in menschlicher Gestalt wird jemals in unsere Welt eindringen.";
			link.l1 = "Es gibt nur ein kleines Problem in Ihrem Plan, Don Alonso. Der Dämon ist BEREITS unter uns. Alles, was wir tun müssen, ist, ihn NICHT durch diese Tore gehen zu lassen. Solange Sie die Maske von ihm fernhalten, wird er das nicht können.  ";
			link.l1.go = "ksochitam_9";
		break;
		
		case "ksochitam_9":
			dialog.text = "Es wird mehr dazu benötigen. Egal wer von uns Recht hat, eines ist sicher: die Tore müssen für immer geschlossen bleiben. Und es gibt nur einen Weg, das zu tun: Zerstöre die Maske auf dem Altar von Tayasal. Dadurch wird der Dämon all seiner Macht beraubt.";
			link.l1 = "Hm. Ich stimme zu, dass es unsere beste Wette ist... Wie planst du nach Tayasal zu kommen? Kennst du den Weg dorthin?";
			link.l1.go = "ksochitam_10";
		break;
		
		case "ksochitam_10":
			dialog.text = "Der einfache Weg, den wir damals benutzten, existiert nicht mehr. Die Straßen sind mit Steinen bedeckt und im Dschungel verloren. Es gibt einen anderen Weg in die Stadt, aber er ist lang und gefährlich. Der Weg beginnt in der nördlichsten Bucht von Yucatan.\nMit der Hilfe von Vater Vincento und Don Ramon de Mendoza werde ich eine Truppe von Elite-Soldaten zusammenstellen und wir werden uns durch den von den Itza-Savagen geschützten Selva kämpfen. Es wird nicht einfach sein, aber Gott wird uns Stärke und Tapferkeit für unseren Kampf im Namen unseres Glaubens gewähren.";
			link.l1 = "Don Alonso, meine Bestrebungen stimmen zufällig mit Ihren überein. Ist es nicht an der Zeit, für einen Moment die Groll beiseite zu legen und unsere Kräfte zu bündeln? Gemeinsam haben wir eine bessere Chance, diesen Kreuzzug erfolgreich abzuschließen.";
			link.l1.go = "ksochitam_11";
		break;
		
		case "ksochitam_11":
			dialog.text = "Ich bin ein spanischer Soldat. Ich schließe keine Bündnisse mit Ketzern und mache keine Geschäfte mit Franzosen. Außerdem habe ich Ihnen bereits meine Vendetta für Don Diego erklärt. Ein Leben für ein Leben!";
			link.l1 = "Du bist so stur wie ein Ochse, Don Alonso! Da stehst du und predigst, dass die Welt von einem großen Übel bedroht ist, und doch lehnst du meine Hilfe ab, um eine so astronomische Aufgabe zu bewältigen!";
			link.l1.go = "ksochitam_12";
		break;
		
		case "ksochitam_12":
			dialog.text = "Ich treffe jetzt die Entscheidungen, nicht Vater Vincento! Sag deine Gebete und bereite dich darauf vor zu sterben, französischer Kapitän!..";
			link.l1 = "Ach, das habe ich in den letzten Monaten so oft gehört! En garde, starrköpfiger Caballero!";
			link.l1.go = "ksochitam_13";
		break;
		
		case "ksochitam_13":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("Maldonado_soldier_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("Maldonado_mushketer_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Ksochitam_MaldonadoDie");
			AddDialogExitQuest("MainHeroFightModeOn");
			if (MOD_SKILL_ENEMY_RATE > 4) Ksochitam_CreateMaldonadoHelpers();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
