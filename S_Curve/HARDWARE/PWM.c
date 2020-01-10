#include "PWM.h"

static void TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE); 

	/* PA0(TIM2_CH1) PA1(TIM5_CH2) PA6(TIM3_CH1) */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // 复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* PB6(TIM4_CH1) */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // 复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

static void TIM2_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM2 开启时钟 */
	//PCLK1经过2倍频后作为TIM2的时钟源等于72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 

  /* TIM2基本配置 */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//设置预分频：不预分频，即为72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//设置时钟分频系数：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//向上计数模式

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
  /* PWM2模式通道1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//配置为PWM模式2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//使能比较输出
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//当定时器计数值小于CCR1_Val时为高电平

  TIM_OC1Init(TIM2, &TIM_OCInitStructure);	 											//使能通道1

  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM2, ENABLE);			 												// 使能TIM3重载寄存器ARR
	
  TIM_Cmd(TIM2, DISABLE);																					//使能TIM3
}

static void TIM3_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM3 开启时钟 */
	//PCLK1经过2倍频后作为TIM3的时钟源等于72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

  /* TIM3基本配置 */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//设置预分频：不预分频，即为72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//设置时钟分频系数：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//向上计数模式

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
  /* PWM2模式通道1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//配置为PWM模式2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//使能比较输出
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//当定时器计数值小于CCR1_Val时为高电平

  TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 											//使能通道1

  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM3, ENABLE);			 												// 使能TIM3重载寄存器ARR
	
  TIM_Cmd(TIM3, DISABLE);																					//使能TIM3
}

static void TIM4_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM4 开启时钟 */
	//PCLK1经过2倍频后作为TIM3的时钟源等于72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); 

  /* TIM4基本配置 */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//设置预分频：不预分频，即为72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//设置时钟分频系数：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//向上计数模式

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
  /* PWM2模式通道1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//配置为PWM模式2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//使能比较输出
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//当定时器计数值小于CCR1_Val时为高电平

  TIM_OC1Init(TIM4, &TIM_OCInitStructure);	 											//使能通道1

  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM4, ENABLE);			 												// 使能TIM4重载寄存器ARR
	
  TIM_Cmd(TIM4, DISABLE);																					//使能TIM4
}

static void TIM5_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	/* TIM5 开启时钟 */
	//PCLK1经过2倍频后作为TIM3的时钟源等于72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); 

  /* TIM5基本配置 */		 
  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;	    									//设置预分频：不预分频，即为72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;				//设置时钟分频系数：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  		//向上计数模式

  TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	
  /* PWM2模式通道1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;	    					//配置为PWM模式2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;		//使能比较输出
  TIM_OCInitStructure.TIM_Pulse = 200;	   												//设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  			//当定时器计数值小于CCR1_Val时为高电平

  TIM_OC2Init(TIM5, &TIM_OCInitStructure);	 											//使能通道1

  TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM5, ENABLE);			 												//使能TIM5重载寄存器ARR

  TIM_Cmd(TIM5, DISABLE);																					//使能TIM5
}

void TIM_Config(void)
{
	TIM_GPIO_Config();
	TIM2_Mode_Config();
	TIM3_Mode_Config();
	TIM4_Mode_Config();
	TIM5_Mode_Config();
}

