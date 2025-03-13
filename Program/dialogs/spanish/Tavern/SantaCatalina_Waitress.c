// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Preguntas, "+GetAddress_Form(NPChar)+"¿?","¿Cómo puedo ayudarte, "+GetAddress_Form(NPChar)+"¿?"),""+GetSexPhrase("Mm, ¿cuál es la gran idea, "+GetAddress_Form(NPChar)+"¿ ","¿Otra vez con las preguntas extrañas? Chiquilla, ve a tomar un poco de ron o algo...")+"Hola, Amigo.","Durante todo este día, esta es la tercera vez que hablas de alguna pregunta..."+GetSexPhrase(" ¿Son estas algunas señales de atención?","Hola, Amigo.")+"Entendido. Предоставьте текст для перевода.","Más preguntas, supongo, "+GetAddress_Form(NPChar)+"¿?","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión","No tengo nada de qué hablar en este momento."),"No, no hermosa...","De ninguna manera, querida...","No, ¿qué preguntas?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

		case "helendrinking":
			dialog.text = "¿Cómo durmió, monsieur? ¡La señorita MacArthur nos ordenó asegurarle el máximo confort!";
			link.l1 = "Tuve un sueño muy extraño...";
			link.l1.go = "helendrinking_1";
		break;

		case "helendrinking_1":
			dialog.text = "¡Ah!...";
			link.l1 = "¿Qué pasa, mademoiselle? ¿Puedo ayudarle con algo?";
			link.l1.go = "helendrinking_2";
		break;

		case "helendrinking_2":
			dialog.text = "Lo siento, Capitán... Es un pecado, ¡pero no puedo resistir! No tengo mucha experiencia, ¡pero no rechaces a la chica, Capitán! ¡Eres tan apuesto! Quiero complacerte, tocarte...";
			link.l1 = "En verdad, pleno confort... ¡También eres muy hermosa! Vamos, no seas tímida.";
			link.l1.go = "helendrinking_sex";
			link.l2 = "Es mejor no tocarme ahora, mademoiselle, apesto a ron. ¡Pero puedes complacerme, un desayuno sería muy bienvenido!";
			link.l2.go = "helendrinking_nosex";
		break;
		
		case "helendrinking_sex":
			dialog.text = "¡Oh cielos, oh cielos!";
			link.l1 = "Entendido, переводите строки в кавычках, без дополнительных пояснений или изменений в структуре текста.";
			link.l1.go = "exit";
			
			NextDiag.TempNode = "exit";
			
			pchar.questTemp.Saga.HelenRelation = sti(pchar.questTemp.Saga.HelenRelation) - 1;
			notification("Helen disapproves", "Helena");
			AddDialogExitQuestFunction("HelenDrinking_WaitressSex");
		break;

		case "helendrinking_nosex":
			dialog.text = "¡Grosero!";
			link.l1 = "¿Entonces no hay desayuno?";
			link.l1.go = "exit";
			
			NextDiag.TempNode = "exit";
			
			pchar.questTemp.Saga.HelenRelation = sti(pchar.questTemp.Saga.HelenRelation) + 1;
			notification("Helen approves", "Helena");
			AddDialogExitQuestFunction("HelenDrinking_WaitressNoSex");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
