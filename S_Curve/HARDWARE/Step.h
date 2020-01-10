#ifndef __Step_h
#define __Step_h

#include "STM32F1.h"

void Speed_up(void);
void Speed_down(void);
void DIR(void);
void PWM_Ctrl(FunctionalState NewState);

#endif
