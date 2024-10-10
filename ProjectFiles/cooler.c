#include <TM4C129.h>
#include "cooler.h"
#include <stdbool.h>
#include "driverlib/sysctl.h"


void Cooler_init (void) {

  SYSCTL->RCGCGPIO |= (1UL << 12) | (1UL << 5);
	
	GPIOP->DIR |=  0x20; //Ativa porta P5
	GPIOP->DEN |=  0x20; 

}

void Cooler_on (uint16_t pwmOpt) {
	
	GPIOP->DATA &= ~0x20; //Liga porta P5
	
	//pwmOpt = 1 sera 100%, pwmOpt = 2 sera 80% e pwmOpt = 3 sera 60%.
	if(pwmOpt == 1)
	{
		GPIOP->DATA &= ~0x20;
	}
	else if(pwmOpt == 2)
	{
		GPIOP->DATA &= ~0x20;
		SysCtlDelay(336000); //SysCtlDelays(420000) = 10ms
		Cooler_off();
		SysCtlDelay(84000);
	}
	else if(pwmOpt == 3)
	{
		GPIOP->DATA &= ~0x20;
		SysCtlDelay(252000);
		Cooler_off();
		SysCtlDelay(168000);
	}
	
}

void Cooler_off () {
	
	GPIOP->DATA |= 0x20; //Desliga porta P5
	
}
