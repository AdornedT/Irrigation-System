#include <stdio.h>
#include "Lib.h"

//Sensores
uint16_t LDR_num = 0, Umidade_num = 0;
float Temperature_num = 0;

//Menu
uint8_t menuOpt = 1, menuState = 0;
uint16_t opt = 1, clearScreen = 0;

//Planta
InfPlanta plantaCuidar;
bool CuidadoIniciado = false;

osMutexId id_buff_mutex;
osMutexDef(buff_mutex);

void init_system()
{
		BombaDeAgua_off();
		Cooler_off();
}


/*----------------------------------------------------------------------------
 * Menu inicial
 *---------------------------------------------------------------------------*/
void init_sidelong_menu(){
		uint8_t i;
		GrContextInit(&sContext, &g_sCfaf128x128x16); //sContext is used to print to screen, g_sCfaf128x128x16 is the display.
		
		GrFlush(&sContext);
		GrContextFontSet(&sContext, g_psFontFixed6x8);
		
		GrContextForegroundSet(&sContext, ClrWhite);
		GrContextBackgroundSet(&sContext, ClrBlack);
		
		GrStringDraw(&sContext,"Sistema de irrigacao", -1, 0, (sContext.psFont->ui8Height+2)*0, true);
		GrStringDraw(&sContext,"para cultivo urbano", -1, 0, (sContext.psFont->ui8Height+2)*1, true);
		GrStringDraw(&sContext,"---------------------", -1, 0, (sContext.psFont->ui8Height+2)*2, true);
		GrContextForegroundSet(&sContext, ClrYellow);
		GrStringDraw(&sContext,"Iniciar Cuidado", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
		GrContextForegroundSet(&sContext, ClrWhite);
		GrStringDraw(&sContext,"Selecionar Planta", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
		GrStringDraw(&sContext,"Opcoes", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
		GrStringDraw(&sContext,"Debug", -1, 0, (sContext.psFont->ui8Height+2)*6, true);

}

//Tratamento da selecao do menu
void Main_Menu (){
		uint16_t x, y;
		char pbufx[10], pbufy[10], pbufz[10];
		bool center;
	
		/*  Joystick		*/		
		x = joy_read_x();
		y = joy_read_y();
	
		if(clearScreen != 0)
		{
			Clear_Screen();
			clearScreen = 0;
			menuOpt = 1;
			
			init_sidelong_menu();
			
			intToString(plantaCuidar.umidade, pbufx, 10, 10, 3);
			intToString(plantaCuidar.tempMax, pbufy, 10, 10, 3);
			floatToString(plantaCuidar.tempMin, pbufz, 10, 10, 2, 3);
			
			GrContextForegroundSet(&sContext, ClrWhite);
			GrStringDraw(&sContext, pbufx, -1, 0, (sContext.psFont->ui8Height+2)*8, true);
			GrStringDraw(&sContext, pbufy, -1, 0, (sContext.psFont->ui8Height+2)*9, true);
			GrStringDraw(&sContext, pbufz, -1, 0, (sContext.psFont->ui8Height+2)*10, true);
		}
		
		
		if(y*200/0xFFF-100 <= -90)
		{
			if(menuOpt < 4)
			{
				menuOpt++;
			}
			if(menuOpt == 1)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Iniciar Cuidado", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 2)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Selecionar Planta", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Iniciar Cuidado", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 3)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Opcoes", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Selecionar Planta", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
			}
			else if(menuOpt == 4)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Debug", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Opcoes", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
			}
		}
		if(y*200/0xFFF-100 >= 90)
		{
			if(menuOpt > 1)
			{
				menuOpt--;
			}
			if(menuOpt == 1)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Iniciar Cuidado", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Selecionar Planta", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
			}
			else if(menuOpt == 2)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Selecionar Planta", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Opcoes", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
			}
			else if(menuOpt == 3)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Opcoes", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Debug", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
			}
			else if(menuOpt == 4)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Debug", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
			}
		}
		if(joy_read_center())
		{
			menuState = menuOpt;
		}

}

void Iniciar_Cuidado_Menu()
{
	char pLDR[10], pTemperature[10], pUmidade[10], pData[10]; //pData PLACEHOLDER
	
	
	if(clearScreen != 1)
	{
		Clear_Screen();
		clearScreen = 1;
		menuOpt = 1;
		CuidadoIniciado = true;
		
		GrContextForegroundSet(&sContext, ClrWhite);
		GrContextBackgroundSet(&sContext, ClrBlack);
		
		GrStringDraw(&sContext,"Iniciar Cuidado", -1, 0, (sContext.psFont->ui8Height+2)*0, true);
		GrStringDraw(&sContext,"---------------------", -1, 0, (sContext.psFont->ui8Height+2)*1, true);
		GrContextForegroundSet(&sContext, ClrYellow);
		GrStringDraw(&sContext, "Voltar", -1, 0, (sContext.psFont->ui8Height+2)*12, true);
		
	}
	
	intToString(LDR_num, pLDR, 10, 10, 3);
	intToString(Umidade_num, pUmidade, 10, 10, 3);
	floatToString(Temperature_num, pTemperature, 10, 10, 2, 3);
	
	GrContextForegroundSet(&sContext, ClrWhite);
	GrStringDraw(&sContext, "LED:", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
	GrStringDraw(&sContext, "Umidade:", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
	GrStringDraw(&sContext, "Temperatura:", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
	
	GrStringDraw(&sContext,"Desligado", -1,  (sContext.psFont->ui8MaxWidth)*5, (sContext.psFont->ui8Height+2)*4, true); //PLACEHOLDER
	GrStringDraw(&sContext,(char*)pUmidade, -1,  (sContext.psFont->ui8MaxWidth)*9, (sContext.psFont->ui8Height+2)*5, true);
	GrStringDraw(&sContext,(char*)pTemperature, -1,  (sContext.psFont->ui8MaxWidth)*13, (sContext.psFont->ui8Height+2)*6, true);
	
	if(joy_read_center())
	{
		CuidadoIniciado = false;
		menuState = 0;
	}
}

void SelecinarPlanta_Menu()
{
	uint16_t x, y;
	
	
	if(clearScreen != 2)
	{
		Clear_Screen();
		clearScreen = 2;
		menuOpt = 1;
		
		GrContextForegroundSet(&sContext, ClrWhite);
		GrContextBackgroundSet(&sContext, ClrBlack);
		
		GrStringDraw(&sContext,"Selecionar Planta", -1, 0, (sContext.psFont->ui8Height+2)*0, true);
		GrStringDraw(&sContext,"---------------------", -1, 0, (sContext.psFont->ui8Height+2)*1, true);
		GrContextForegroundSet(&sContext, ClrYellow);
		GrStringDraw(&sContext, Planta0, -1, 0, (sContext.psFont->ui8Height+2)*2, true);
		GrContextForegroundSet(&sContext, ClrWhite);
		GrStringDraw(&sContext, Planta1, -1, 0, (sContext.psFont->ui8Height+2)*3, true);
		GrStringDraw(&sContext, Planta2, -1, 0, (sContext.psFont->ui8Height+2)*4, true);
		GrStringDraw(&sContext, Planta3, -1, 0, (sContext.psFont->ui8Height+2)*5, true);
		GrStringDraw(&sContext, Planta4, -1, 0, (sContext.psFont->ui8Height+2)*6, true);
		GrStringDraw(&sContext, Planta5, -1, 0, (sContext.psFont->ui8Height+2)*7, true);
		GrStringDraw(&sContext, Planta6, -1, 0, (sContext.psFont->ui8Height+2)*8, true);
		GrStringDraw(&sContext, Planta7, -1, 0, (sContext.psFont->ui8Height+2)*9, true);
		GrStringDraw(&sContext, Planta8, -1, 0, (sContext.psFont->ui8Height+2)*10, true);
		GrStringDraw(&sContext, Planta9, -1, 0, (sContext.psFont->ui8Height+2)*11, true);
		GrStringDraw(&sContext, Planta10, -1, 0, (sContext.psFont->ui8Height+2)*12, true);
		GrStringDraw(&sContext, Planta11, -1, 0, (sContext.psFont->ui8Height+2)*13, true);
		GrStringDraw(&sContext, Planta12, -1, 0, (sContext.psFont->ui8Height+2)*14, true);
		GrStringDraw(&sContext, "Voltar", -1, 0, (sContext.psFont->ui8Height+2)*15, true);
	}
	
	/*  Joystick		*/		
	x = joy_read_x();
	y = joy_read_y();
	
	if(y*200/0xFFF-100 <= -90)
		{
			if(menuOpt < 14)
			{
				menuOpt++;
				DrawSelecionarMenu(menuOpt, true, sContext);
			}
		}
		
	if(y*200/0xFFF-100 >= 90)
		{
			if(menuOpt > 1)
			{
				menuOpt--;
				DrawSelecionarMenu(menuOpt, false, sContext);
			}
		}
		
	if(joy_read_center())
		{
			if(menuOpt > 1)
			{
				menuState = 0;
				plantaCuidar = SelecionarPlanta(menuOpt);
			}
			else if(menuOpt == 1)
			{
				menuState = 21;
			}
		}
	
}

void SelecinarPlanta_Menu_Cuidado_Automatico()
{
	uint16_t x, y;
	
	if(clearScreen != 21)
	{
		Clear_Screen();
		//Mutex
		clearScreen = 21;
		menuOpt = 1;
		
		GrContextForegroundSet(&sContext, ClrWhite);
		GrContextBackgroundSet(&sContext, ClrBlack);
		
		GrStringDraw(&sContext,"Cuidado Automatico", -1, 0, (sContext.psFont->ui8Height+2)*0, true);
		GrStringDraw(&sContext,"---------------------", -1, 0, (sContext.psFont->ui8Height+2)*1, true);
		GrContextForegroundSet(&sContext, ClrWhite);
		GrStringDraw(&sContext, "Este modo pode nao ", -1, 0, (sContext.psFont->ui8Height+2)*2, true);
		GrStringDraw(&sContext, "ser o melhor para a ", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
		GrStringDraw(&sContext, "sua planta.", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
		
		GrStringDraw(&sContext, "Continuar?", -1, 0, (sContext.psFont->ui8Height+2)*7, true);
		GrContextForegroundSet(&sContext, ClrYellow);
		GrStringDraw(&sContext, "Nao", -1, 0, (sContext.psFont->ui8Height+2)*9, true); //Nao vem primeiro pois resolve problemas de duplo clique
		GrContextForegroundSet(&sContext, ClrWhite);
		GrStringDraw(&sContext, "Sim", -1, 0, (sContext.psFont->ui8Height+2)*10, true);
	}
	
	/*  Joystick		*/
	x = joy_read_x();
	y = joy_read_y();
	
	if(y*200/0xFFF-100 <= -90)
		{
			if(menuOpt < 2)
			{
				menuOpt++;
			}
			if(menuOpt == 1)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext, "Nao", -1, 0, (sContext.psFont->ui8Height+2)*9, true);
			}
			if(menuOpt == 2)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext, "Sim", -1, 0, (sContext.psFont->ui8Height+2)*10, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext, "Nao", -1, 0, (sContext.psFont->ui8Height+2)*9, true);
			}
		}
	if(y*200/0xFFF-100 >= 90)
	{
		if(menuOpt > 1)
		{
			menuOpt--;
		}
		if(menuOpt == 1)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext, "Nao", -1, 0, (sContext.psFont->ui8Height+2)*9, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext, "Sim", -1, 0, (sContext.psFont->ui8Height+2)*10, true);
			}
			if(menuOpt == 2)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext, "Sim", -1, 0, (sContext.psFont->ui8Height+2)*10, true);
			}
	}
	
	if(joy_read_center())
	{
		if(menuOpt == 1)
		{
			menuState = 2; //Menu Selecionar Planta
		}
		if(menuOpt == 2)
		{
			plantaCuidar.umidade = 100; //PLACEHOLDER
			plantaCuidar.tempMax = 99;
			plantaCuidar.tempMin = -99;
			menuState = 2; //Menu Selecionar Planta
		}
	}
}

void Debug_Menu()
{
	char pLDR[10], pTemperature[10], pUmidade[10];
	uint16_t x, y;
	
	if(clearScreen != 4)
	{
		Clear_Screen();
		clearScreen = 4;
		menuOpt = 1;
		
		GrContextForegroundSet(&sContext, ClrWhite);
		GrContextBackgroundSet(&sContext, ClrBlack);
		
		GrStringDraw(&sContext,"Debug", -1, 0, (sContext.psFont->ui8Height+2)*0, true);
		GrStringDraw(&sContext,"---------------------", -1, 0, (sContext.psFont->ui8Height+2)*1, true);
		GrContextForegroundSet(&sContext, ClrYellow);
		GrStringDraw(&sContext,"Ligar Cooler:", -1, 0, (sContext.psFont->ui8Height+2)*2, true);
		GrContextForegroundSet(&sContext, ClrWhite);
		GrStringDraw(&sContext,"Ligar LED:", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
		GrStringDraw(&sContext,"Ligar Agua:", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
		GrStringDraw(&sContext,"Luminosidade:", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
		GrStringDraw(&sContext,"Umidade:", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
		GrStringDraw(&sContext,"Temperatura:", -1, 0, (sContext.psFont->ui8Height+2)*7, true);
		GrStringDraw(&sContext,"Data:", -1, 0, (sContext.psFont->ui8Height+2)*8, true);
		GrStringDraw(&sContext,"Voltar", -1, 0, (sContext.psFont->ui8Height+2)*12, true);
	}
	
	/*  Joystick		*/		
	x = joy_read_x();
	y = joy_read_y();
	
	intToString(LDR_num, pLDR, 10, 10, 3);
	intToString(Umidade_num, pUmidade, 10, 10, 3);
	floatToString(Temperature_num, pTemperature, 10, 10, 2, 3);
	

	//Desenha dado dos sensores e estados do led, cooler e bomba de agua.
	GrFlush(&sContext);
	GrContextBackgroundSet(&sContext, ClrBlack);
	GrContextForegroundSet(&sContext, ClrWhite);
	GrStringDraw(&sContext,(char*)pLDR, -1,  (sContext.psFont->ui8MaxWidth)*14, (sContext.psFont->ui8Height+2)*5, true);
	GrStringDraw(&sContext,(char*)pUmidade, -1,  (sContext.psFont->ui8MaxWidth)*9, (sContext.psFont->ui8Height+2)*6, true);
	GrStringDraw(&sContext,(char*)pTemperature, -1,  (sContext.psFont->ui8MaxWidth)*13, (sContext.psFont->ui8Height+2)*7, true);
	
	if(y*200/0xFFF-100 <= -90)
		{
			if(menuOpt < 8)
			{
				menuOpt++;
			}
			if(menuOpt == 1)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Ligar Cooler:", -1, 0, (sContext.psFont->ui8Height+2)*2, true);
			}
			else if(menuOpt == 2)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Ligar LED:", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Ligar Cooler:", -1, 0, (sContext.psFont->ui8Height+2)*2, true);
			}
			else if(menuOpt == 3)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Ligar Agua:", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Ligar LED:", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 4)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Luminosidade:", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Ligar Agua:", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
			}
			else if(menuOpt == 5)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Umidade:", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Luminosidade:", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
			}
			else if(menuOpt == 6)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Temperatura:", -1, 0, (sContext.psFont->ui8Height+2)*7, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Umidade:", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
			}
			else if(menuOpt == 7)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Data:", -1, 0, (sContext.psFont->ui8Height+2)*8, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Temperatura:", -1, 0, (sContext.psFont->ui8Height+2)*7, true);
			}
			else if(menuOpt == 8)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Voltar", -1, 0, (sContext.psFont->ui8Height+2)*12, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Data:", -1, 0, (sContext.psFont->ui8Height+2)*8, true);
			}
		}
		if(y*200/0xFFF-100 >= 90)
		{
			if(menuOpt > 1)
			{
				menuOpt--;
			}
			if(menuOpt == 1)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Ligar Cooler:", -1, 0, (sContext.psFont->ui8Height+2)*2, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Ligar LED:", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
			}
			else if(menuOpt == 2)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Ligar LED:", -1, 0, (sContext.psFont->ui8Height+2)*3, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Ligar Agua:", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
			}
			else if(menuOpt == 3)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Ligar Agua:", -1, 0, (sContext.psFont->ui8Height+2)*4, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Luminosidade:", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
			}
			else if(menuOpt == 4)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Luminosidade:", -1, 0, (sContext.psFont->ui8Height+2)*5, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Umidade:", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
			}
			else if(menuOpt == 5)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Umidade:", -1, 0, (sContext.psFont->ui8Height+2)*6, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Temperatura:", -1, 0, (sContext.psFont->ui8Height+2)*7, true);
			}
			else if(menuOpt == 6)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Temperatura:", -1, 0, (sContext.psFont->ui8Height+2)*7, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Data:", -1, 0, (sContext.psFont->ui8Height+2)*8, true);
			}
			else if(menuOpt == 7)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Data:", -1, 0, (sContext.psFont->ui8Height+2)*8, true);
				GrContextForegroundSet(&sContext, ClrWhite);
				GrStringDraw(&sContext,"Voltar", -1, 0, (sContext.psFont->ui8Height+2)*12, true);
			}
			else if(menuOpt == 8)
			{
				GrContextForegroundSet(&sContext, ClrYellow);
				GrStringDraw(&sContext,"Voltar", -1, 0, (sContext.psFont->ui8Height+2)*12, true);
			}
	
		}
		if(joy_read_center() && menuOpt == 8)
		{
			menuState = 0;
		}
		
}

void Activate_Cooler()
{
	bool s1_press = button_read_s1();
	bool s2_press = button_read_s2();
	char pCooler[10], pCoolerOpt[10];
	
	if (s1_press)
		intToString(1, pCooler, 10, 10, 1);
	else
		intToString(0, pCooler, 10, 10, 1);
	if (s2_press)
	{
		opt++;
		if(opt > 3)
		{
			opt = 1;
		}
		intToString(opt, pCoolerOpt, 10, 10, 1);
	}	
	else
		intToString(opt, pCoolerOpt, 10, 10, 1);
	
	//GrFlush(&sContext);
	//GrContextBackgroundSet(&sContext, ClrBlack);
	//GrContextForegroundSet(&sContext, ClrWhite);
	//GrStringDraw(&sContext,(char*)pCooler, -1,  (sContext.psFont->ui8MaxWidth)*14, (sContext.psFont->ui8Height+2)*6, true);
	//GrStringDraw(&sContext,(char*)pCoolerOpt, -1,  (sContext.psFont->ui8MaxWidth)*16, (sContext.psFont->ui8Height+2)*6, true);
	
//	while(s1_press)
//	{
//		Cooler_on(opt);
//		s1_press = button_read_s1();
//	}
//	while(s2_press)
//	{
//		BombaDeAgua_on();
//		s2_press = button_read_s2();
//	}
//	
//	BombaDeAgua_off();
//	Cooler_off();

}

void LDR_sensor_treat()
{
	osMutexWait(id_buff_mutex, osWaitForever); //Secao critica, pois esta modificando variavel compartilhada
	
	LDR_num = (LDR_read()*100/4096); //Atualiza valor do LDR
																	 //0004 -> Luz direto no sensor, 0023 -> Iluminacao media, de uma lampada por exemplo e 0099 -> extremamente escuro
	
	osMutexRelease(id_buff_mutex);
}

void Umidade_sensor_treat()
{
	osMutexWait(id_buff_mutex, osWaitForever); //Secao critica, pois esta modificando variavel compartilhada
	
	Umidade_num = (Umidade_read()*100/4096);

	osMutexRelease(id_buff_mutex);
}

void Temperature_sensor_treat()
{
	osMutexWait(id_buff_mutex, osWaitForever); //Secao critica, pois esta modificando variavel compartilhada
	
	Temperature_num = temp_read_celsius();
	
	osMutexRelease(id_buff_mutex);
	
	Activate_Cooler();
}

/*----------------------------------------------------------------------------
 *      Threads
 *---------------------------------------------------------------------------*/
void MENU_thread(void const *args) {
    while (1) {
				if(menuState == 0)
				{
					Main_Menu();
				}
				else if(menuState == 1)
				{
					Iniciar_Cuidado_Menu();
				}
				else if(menuState == 2)
				{
					SelecinarPlanta_Menu();
				}
				else if(menuState == 21)
				{
					SelecinarPlanta_Menu_Cuidado_Automatico();
				}
				else if(menuState == 4)
				{
					Debug_Menu();
				}
				else
				{

				}
        osDelay(1000);
    }
}
osThreadDef(MENU_thread, osPriorityNormal, 1, 0);
	
void LDR_thread(void const *args) {
    while (1) {
				LDR_sensor_treat();
        osDelay(500);
    }
}
osThreadDef(LDR_thread, osPriorityNormal, 1, 0);

void Humidade_thread(void const *args) {
    while (1) {
        Umidade_sensor_treat();
        osDelay(500);
    }
}
osThreadDef(Humidade_thread, osPriorityNormal, 1, 0);

void Temperature_thread(void const *args) {
    while (1) {
        Temperature_sensor_treat();
        osDelay(500);
    }
}
osThreadDef(Temperature_thread, osPriorityNormal, 1, 0);

void Logica_thread(void const *args) {
    while (1) 
		{
			if(CuidadoIniciado)
			{
					if(plantaCuidar.umidade < Umidade_num)
				{
					BombaDeAgua_on();
					osDelay(15000);
					BombaDeAgua_off();
				}
				if(plantaCuidar.tempMax > Temperature_num)
				{
					Cooler_off();
				}
				if(plantaCuidar.tempMax < Temperature_num)
				{
					if(Temperature_num - plantaCuidar.tempMax >= 1.5 )
					{
						Cooler_on(1);
					}
					else if(Temperature_num - plantaCuidar.tempMax < 1.5 && Temperature_num - plantaCuidar.tempMax > 1)
					{
						Cooler_on(2);
					}
					else if(Temperature_num - plantaCuidar.tempMax <= 1)
					{
						Cooler_on(3);
					}
					//LED PLACEHOLDER
				}
			}
			osDelay(600000);
    }
}
osThreadDef(Logica_thread, osPriorityHigh, 1, 0);

/*----------------------------------------------------------------------------
 *      Main
 *---------------------------------------------------------------------------*/
int main (void) {
	
	osKernelInitialize();  // Inicializa o Kernel
  	init_all();						 // Inicializa os perif�ricos
	init_system();				 // Inicializa o sistema
	init_sidelong_menu();  // Carrega o menu inicial no OLED
 
	// Cria as threads
	osThreadCreate(osThread(MENU_thread), NULL);
	osThreadCreate(osThread(LDR_thread), NULL);
	osThreadCreate(osThread(Humidade_thread), NULL);
	osThreadCreate(osThread(Temperature_thread), NULL);
	osThreadCreate(osThread(Logica_thread), NULL);
	
	// Cria o Mutex
	id_buff_mutex = osMutexCreate(osMutex(buff_mutex));

	// Liga o Kernel
	osKernelStart();
	
	// Coloca a fun��o Main em estado de espera "eternamente"
	osDelay(osWaitForever);  
}
