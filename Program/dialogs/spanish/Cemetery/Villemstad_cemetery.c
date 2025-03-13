// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Cómo puedo asistirte?","¿Qué puedo hacer por ti?"),"Dime, ¿qué te preocupa, "+GetAddress_Form(NPChar)+"¿?","Por tercera vez, "+GetAddress_Form(NPChar)+", ¿qué necesitas?","Estoy harto de ti. ¡Fuera!","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, mis disculpas.","No es nada, discúlpame."),"Perdóname, no es nada.","Tienes razón, es la tercera vez ya. Discúlpame...","Disculpas.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
