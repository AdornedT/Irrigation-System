#include <TM4C129.h>
#include "bomba_agua.h"
#include <stdbool.h>
#include "driverlib/sysctl.h"


void BombaDeAgua_init (void) {

  SYSCTL->RCGCGPIO |= (1UL << 12) | (1UL << 5);
	
	GPIOP->DIR |=  0x10; //Ativa porta P4
	GPIOP->DEN |=  0x10; 

}

void BombaDeAgua_on () {
	
	GPIOP->DATA &= ~0x10; //Liga porta P4
	
}

void BombaDeAgua_off () {
	
	GPIOP->DATA |= 0x10; //Desliga porta P4
	
}
