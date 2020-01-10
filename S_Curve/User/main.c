#include "STM32F1.h"

int main(void)
{
	delay_init();	    	 																	//Systick��ȷ��ʱ��ʼ��  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 	 		//����NVIC�жϷ���
	GPIO_Config();																				//IO��ʼ��
	TIM_Config();																					//��ʱ������
	PWM_Ctrl(ENABLE);																			//������ʱ��
	while(1)
	{	
		Speed_up();																					//����
		delay_ms(5000);
		Speed_down();																				//����
		delay_ms(10);
		DIR();																							//����
	}
}
