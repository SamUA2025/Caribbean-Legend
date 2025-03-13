// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres?","¿Qué te gustaría saber?"),"¿Qué es lo que necesitas, "+GetAddress_Form(NPChar)+"¿?","Esa es la tercera vez que intentas preguntarme...","¡Ya he tenido suficiente de ti, lárgate!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Lo siento, he cambiado de opinión.","No es nada, disculpas."),"Olvidé, mis disculpas...","La tercera es la vencida, ¿eh? Disculpa...","¡Lo siento, lo siento! Entonces me voy...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
