#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "grlib/grlib.h"

#include "selecionar_planta_menu.h"


void DrawSelecionarMenu(uint8_t menuOpt, bool cima, tContext sameContext)
{
	
			if(menuOpt == 1 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta0, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
			}
			else if(menuOpt == 2 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta1, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta0, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
			}
			else if(menuOpt == 3 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta2, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta1, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 4 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta2, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
			}
			else if(menuOpt == 5 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
			}
			else if(menuOpt == 6 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
			}
			else if(menuOpt == 7 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
			}
			else if(menuOpt == 8 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
			}
			else if(menuOpt == 9 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
			}
			else if(menuOpt == 10 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
			}
			else if(menuOpt == 11 && cima == true)//Limite da tela
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
			}
			else if(menuOpt == 12 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta1, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
				GrStringDraw(&sameContext, Planta2, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta11, -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
			}
			else if(menuOpt == 13 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta2, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta12, -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta11, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
			}
			else if(menuOpt == 14 && cima == true)
			{
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrStringDraw(&sameContext, Planta11, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, "Voltar               ", -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta12, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
				
			}
			
			
			if(menuOpt == 1 && cima == false)
			{
				GrStringDraw(&sameContext, Planta2, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
				
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta0, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta1, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 2 && cima == false)
			{
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
				GrStringDraw(&sameContext, Planta11, -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
				
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta1, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta2, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 3 && cima == false)
			{
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				GrStringDraw(&sameContext, Planta11, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
				GrStringDraw(&sameContext, Planta12, -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
				
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta2, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 4 && cima == false)//Limite da tela
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta3, -1, 0, (sameContext.psFont->ui8Height+2)*2, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 5 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta4, -1, 0, (sameContext.psFont->ui8Height+2)*3, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
			}
			else if(menuOpt == 6 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta5, -1, 0, (sameContext.psFont->ui8Height+2)*4, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
			}
			else if(menuOpt == 7 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta6, -1, 0, (sameContext.psFont->ui8Height+2)*5, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
			}
			else if(menuOpt == 8 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta7, -1, 0, (sameContext.psFont->ui8Height+2)*6, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
			}
			else if(menuOpt == 9 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta8, -1, 0, (sameContext.psFont->ui8Height+2)*7, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
			}
			else if(menuOpt == 10 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta9, -1, 0, (sameContext.psFont->ui8Height+2)*8, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
			}
			else if(menuOpt == 11 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta10, -1, 0, (sameContext.psFont->ui8Height+2)*9, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta11, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
			}
			else if(menuOpt == 12 && cima == false)
			{			
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta11, -1, 0, (sameContext.psFont->ui8Height+2)*10, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, Planta12, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
			}
			else if(menuOpt == 13 && cima == false)
			{	
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, Planta12, -1, 0, (sameContext.psFont->ui8Height+2)*11, true);
				GrContextForegroundSet(&sameContext, ClrWhite);
				GrStringDraw(&sameContext, "Voltar               ", -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
			}
			else if(menuOpt == 14 && cima == false)
			{
				GrContextForegroundSet(&sameContext, ClrYellow);
				GrStringDraw(&sameContext, "Voltar               ", -1, 0, (sameContext.psFont->ui8Height+2)*12, true);
			}
}

InfPlanta SelecionarPlanta(uint8_t menuOpt)
{
	InfPlanta plantaSelecionada;
	
	//Default
	plantaSelecionada.umidade = 100;
	plantaSelecionada.tempMax = 30;
	plantaSelecionada.tempMin = 20;
	
	if(menuOpt == 2) //Alecrim
	{
		plantaSelecionada.umidade = 57;
		plantaSelecionada.tempMax = 99;
		plantaSelecionada.tempMin = -99;
	}
	if(menuOpt == 3) //Amor Perfeito
	{
		plantaSelecionada.umidade = 77;
		plantaSelecionada.tempMax = 25;
		plantaSelecionada.tempMin = 15;
	}
	if(menuOpt == 4) //Arruda
	{
		plantaSelecionada.umidade = 46;
		plantaSelecionada.tempMax = 30;
		plantaSelecionada.tempMin = 4;
	}
	if(menuOpt == 5) //Citronela
	{
		plantaSelecionada.umidade = 42;
		plantaSelecionada.tempMax = 28;
		plantaSelecionada.tempMin = 23;
	}
	if(menuOpt == 6) //Cravina
	{
		plantaSelecionada.umidade = 74;
		plantaSelecionada.tempMax = 20;
		plantaSelecionada.tempMin = -10;
	}
	if(menuOpt == 7) //Espada de Sao Jorge
	{
		plantaSelecionada.umidade = 67;
		plantaSelecionada.tempMax = 29;
		plantaSelecionada.tempMin = 7;
	}
	if(menuOpt == 8) //Flor de mel
	{
		plantaSelecionada.umidade = 35;
		plantaSelecionada.tempMax = 30;
		plantaSelecionada.tempMin = 0;
	}
	if(menuOpt == 9) //Ixora mini
	{
		plantaSelecionada.umidade = 74;
		plantaSelecionada.tempMax = 25;
		plantaSelecionada.tempMin = 15;
	}
	if(menuOpt == 10) //Kalanchoe
	{
		plantaSelecionada.umidade = 67;
		plantaSelecionada.tempMax = 29;
		plantaSelecionada.tempMin = 13;
	}
	if(menuOpt == 11) //Lavanda
	{
		plantaSelecionada.umidade = 71;
		plantaSelecionada.tempMax = 30;
		plantaSelecionada.tempMin = 20;
	}
	if(menuOpt == 12) //Pimenta Cumari
	{
		plantaSelecionada.umidade = 54;
		plantaSelecionada.tempMax = 30;
		plantaSelecionada.tempMin = 21;
	}
	if(menuOpt == 13) //Suculenta
	{
		plantaSelecionada.umidade = 93;
		plantaSelecionada.tempMax = 29;
		plantaSelecionada.tempMin = 10;
	}
	
	return plantaSelecionada;
		
}