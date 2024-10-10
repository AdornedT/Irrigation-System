#ifndef __JOY_H__
#define __JOY_H__

//..............................................................................
//Normalize read value using ADC resolution 4096
//..............................................................................
#define joy_read_norm_x() (joy_read_x()/(float)0xFFF)
#define joy_read_norm_y() (joy_read_y()/(float)0xFFF)
#define test_read_norm() (test_read()/(float)0xFFF)

extern void joy_init(void);
extern uint16_t joy_read_x(void);
extern uint16_t test_read(void);
extern uint16_t joy_read_y(void);
extern bool joy_read_center();

#endif // __JOY_H__
