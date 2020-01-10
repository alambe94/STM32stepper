#include"EXTI.h"
#include"NVIC.h"

#include<stdarg.h>





void EXTI_Config(void)
{	
	/*����һ��EXTI_InitTypeDef ���͵Ľṹ�壬���ֽ�EXTI_InitStructure*/
	EXTI_InitTypeDef EXTI_InitStructure;

	/*��ʼ���ж���������*/
	NVIC_Config();	

	/* ����IO�ڵ��ж��� */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource7);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource9);
	/*�ж���*/
	EXTI_InitStructure.EXTI_Line = EXTI_Line5|EXTI_Line6|EXTI_Line7|EXTI_Line9; 
	/*����ģʽ*/
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

	/*�����ź�*/
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���

	/*ʹ���ж���*/
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	/*���ÿ⺯������ʼ��EXTI*/
	EXTI_Init(&EXTI_InitStructure);

}

void EXTI9_5_IRQHandler(void)			   //�����жϺ���
{   
	if(EXTI_GetITStatus(EXTI_Line5) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line9);

		Delay();						 									 						
	}
	if(EXTI_GetITStatus(EXTI_Line6) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line9);

		Delay();						 									 						
	}
	if(EXTI_GetITStatus(EXTI_Line7) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line9);

		Delay();						 									 						
	}
	if(EXTI_GetITStatus(EXTI_Line9) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line9);

	
		Delay();						 									 						
	}	
}

void Delay(void)
{	u32 i,j;
	for(i=0;i<2000;i++)
	for(j=0;j<3000;j++);
}
