#ifndef LED_H
#define LED_H

/* LED Definitions */
#define LED_NUM     4                        /* Number of user LEDs          */

extern void led_init(void);
extern void led_on        (uint8_t num);
extern void led_off       (uint8_t num);
extern void led_write			(uint8_t value);

#endif
