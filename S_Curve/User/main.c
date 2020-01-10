#include "STM32F1.h"

int main(void)
{
	delay_init();	    	 																	//Systick精确延时初始化  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 	 		//设置NVIC中断分组
	GPIO_Config();																				//IO初始化
	TIM_Config();																					//定时器配置
	PWM_Ctrl(ENABLE);																			//开启定时器
	while(1)
	{	
		Speed_up();																					//加速
		delay_ms(5000);
		Speed_down();																				//减速
		delay_ms(10);
		DIR();																							//换向
	}
}
