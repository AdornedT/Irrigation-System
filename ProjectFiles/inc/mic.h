#ifndef __MIC_H__
#define __MIC_H__

//..............................................................................
//Normalize read value using ADC resolution 4096
//..............................................................................
#define mic_norm() (mic_read()/(float)0xFFF)

extern void mic_init(void);
extern uint16_t mic_read(void);

#endif //__MIC_H__