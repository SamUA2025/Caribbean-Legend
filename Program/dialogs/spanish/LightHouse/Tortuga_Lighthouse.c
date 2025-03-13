// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres?","¿Qué le gustaría saber?"),"¿Qué necesitas, "+GetAddress_Form(NPChar)+"¿?","Esa es la tercera vez que intentas preguntarme...","¡He tenido suficiente de ti, piérdete!","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Lo siento, he cambiado de opinión."," No es nada, disculpas."),"Lo olvidé, mis disculpas...","Tercera vez es la vencida, ¿eh? Disculpa...","¡Lo siento, lo siento! Entonces me iré...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
