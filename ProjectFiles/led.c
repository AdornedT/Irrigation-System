#include <TM4C129.h>
#include "led.h"

const uint32_t led_mask[] = { 1UL << 1, 1UL << 0, 1UL << 4, 1UL << 0  };

/*----------------------------------------------------------------------------
  initialize LED Pins (GPION1, GPION0, GPIOF0, GPIOF4)
 *----------------------------------------------------------------------------*/
void led_init (void) {

  /* Enable clock and init GPIO outputs */
  SYSCTL->RCGCGPIO |= (1UL << 12) | (1UL << 5);  /* enable clock for GPIOs    */
  GPION->DIR     |= led_mask[0] | led_mask[1];   /* PN1, PN0 is output        */
  GPION->DEN     |= led_mask[0] | led_mask[1];   /* PN1, PN0 is digital func. */
  GPIOF_AHB->DIR |= led_mask[2] | led_mask[3];   /* PF4, PF0 is output        */
  GPIOF_AHB->DEN |= led_mask[2] | led_mask[3];   /* PF4, PF0 is digital func. */
	
	//GPIOB_AHB->DIR = GPIOB_AHB->DIR | 0x10;
	//GPIOB_AHB->DEN = GPIOB_AHB->DEN | 0x10;
	//GPIOB_AHB->DATA = GPIOB_AHB->DATA | 0x10;

}

/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void led_on (uint8_t num) {

  if (num < LED_NUM) {
    switch (num) {
      case 0: GPION->DATA     |=  led_mask[num]; break;
      case 1: GPION->DATA     |=  led_mask[num]; break;
      case 2: GPIOF_AHB->DATA |=  led_mask[num]; break;
      case 3: GPIOF_AHB->DATA |=  led_mask[num]; break;
    }
  }
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void led_off (uint8_t num) {

  if (num < LED_NUM) {
    switch (num) {
      case 0: GPION->DATA     &= ~led_mask[num]; break;
      case 1: GPION->DATA     &= ~led_mask[num]; break;
      case 2: GPIOF_AHB->DATA &= ~led_mask[num]; break;
      case 3: GPIOF_AHB->DATA &= ~led_mask[num]; break;
    }
  }
}

/*----------------------------------------------------------------------------
  Function that outputs value to LEDs
 *----------------------------------------------------------------------------*/
void led_write(uint8_t value) {
  int i;

  for (i = 0; i < LED_NUM; i++) {
    if (value & (1<<i)) {
      led_on (i);
    } else {
      led_off(i);
    }
  }
}
