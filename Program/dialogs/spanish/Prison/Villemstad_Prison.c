// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Habla, estoy escuchando";
			link.l1 = "Me equivoqué. Adiós.";
			link.l1.go = "Exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "PortugalInPrison")
            {
                link.l1 = "Oficial, usted tiene prisionero aquí a un tal Bartolomeo el Portugués...";
                link.l1.go = "Portugal";
            }
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Lo tenemos. ¿Y por qué te importa? Solo los emisarios de la Compañía Holandesa de las Indias Occidentales tienen permiso para verlo y solo con la orden escrita del gobernador. Uno de los oficiales de la Compañía está interrogando a este pirata en este momento. Así que si has venido aquí solo para verlo, será mejor que te vayas, lo verás cuando lo cuelguen, ahora vete.";
			link.l1 = "He venido aquí no para verlo.";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "¿Por qué entonces, si se me permite preguntar?";
			link.l1 = "¡He venido aquí... para liberarlo!";
			link.l1.go = "fight";
			chrDisableReloadToLocation = true;
			//pchar.quest.InMarigoResidenceOver.over = "yes"; //снять таймер
			InterfaceStates.Buttons.Save.enable = false;//запретить сохраняться
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
