#include "PWM.h"

static void TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE); 

	/* PA0(TIM2_CH1) PA1(TIM5_CH2) PA6(TIM3_CH1) */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // �����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* PB6(TIM4_CH1) */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // �����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

static void TIM2_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM2 ����ʱ�� */
	//PCLK1����2��Ƶ����ΪTIM2��ʱ��Դ����72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 

  /* TIM2�������� */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//����ʱ�ӷ�Ƶϵ��������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//���ϼ���ģʽ

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
  /* PWM2ģʽͨ��1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//����ΪPWMģʽ2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//ʹ�ܱȽ����
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ

  TIM_OC1Init(TIM2, &TIM_OCInitStructure);	 											//ʹ��ͨ��1

  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM2, ENABLE);			 												// ʹ��TIM3���ؼĴ���ARR
	
  TIM_Cmd(TIM2, DISABLE);																					//ʹ��TIM3
}

static void TIM3_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM3 ����ʱ�� */
	//PCLK1����2��Ƶ����ΪTIM3��ʱ��Դ����72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

  /* TIM3�������� */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//����ʱ�ӷ�Ƶϵ��������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//���ϼ���ģʽ

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
  /* PWM2ģʽͨ��1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//����ΪPWMģʽ2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//ʹ�ܱȽ����
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ

  TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 											//ʹ��ͨ��1

  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM3, ENABLE);			 												// ʹ��TIM3���ؼĴ���ARR
	
  TIM_Cmd(TIM3, DISABLE);																					//ʹ��TIM3
}

static void TIM4_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM4 ����ʱ�� */
	//PCLK1����2��Ƶ����ΪTIM3��ʱ��Դ����72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); 

  /* TIM4�������� */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//����ʱ�ӷ�Ƶϵ��������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//���ϼ���ģʽ

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
  /* PWM2ģʽͨ��1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//����ΪPWMģʽ2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//ʹ�ܱȽ����
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ

  TIM_OC1Init(TIM4, &TIM_OCInitStructure);	 											//ʹ��ͨ��1

  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM4, ENABLE);			 												// ʹ��TIM4���ؼĴ���ARR
	
  TIM_Cmd(TIM4, DISABLE);																					//ʹ��TIM4
}

static void TIM5_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM5 ����ʱ�� */
	//PCLK1����2��Ƶ����ΪTIM3��ʱ��Դ����72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); 

  /* TIM5�������� */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//����ʱ�ӷ�Ƶϵ��������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//���ϼ���ģʽ

  TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	
  /* PWM2ģʽͨ��1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//����ΪPWMģʽ2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//ʹ�ܱȽ����
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ

  TIM_OC2Init(TIM5, &TIM_OCInitStructure);	 											//ʹ��ͨ��1

  TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM5, ENABLE);			 												//ʹ��TIM5���ؼĴ���ARR

  TIM_Cmd(TIM5, DISABLE);																					//ʹ��TIM5
}

void TIM_Config(void)
{
	TIM_GPIO_Config();
	TIM2_Mode_Config();
	TIM3_Mode_Config();
	TIM4_Mode_Config();
	TIM5_Mode_Config();
}

