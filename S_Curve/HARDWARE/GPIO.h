#ifndef __GPIO_H
#define __GPIO_H

#include "STM32F1.h"

/* »»ÏòÒý½Å */
#define	DIR1	PCout(9)
#define	DIR2	PCout(8)
#define	DIR3	PCout(7)
#define DIR4 	PCout(6)

void GPIO_Config(void);

#endif
