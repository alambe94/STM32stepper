#include "stm32f10x.h"
#include "SteppingMotor.h"

static uint32_t KeyAndJostickValue;	

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

void KyeAndJoystickScan(void)
{
	/*
	if(!GPIO_ReadInputDataBit( IO_KEY_ARRAY, IO_KEY1))KeyAndJostickValue = KEY1_VALUE;
	if(!GPIO_ReadInputDataBit( IO_KEY_ARRAY, IO_KEY2))KeyAndJostickValue = KEY2_VALUE;
	if(!GPIO_ReadInputDataBit( IO_KEY_ARRAY, IO_KEY3))KeyAndJostickValue = KEY3_VALUE;
	*/
	
	if(!GPIO_ReadInputDataBit( IO_JOYSTICK_ARRAY, IO_JOYSTICK_A))KeyAndJostickValue = JOYSTICK_A_VALUE;
	if(!GPIO_ReadInputDataBit( IO_JOYSTICK_ARRAY, IO_JOYSTICK_B))KeyAndJostickValue = JOYSTICK_B_VALUE;
	if(!GPIO_ReadInputDataBit( IO_JOYSTICK_ARRAY, IO_JOYSTICK_C))KeyAndJostickValue = JOYSTICK_C_VALUE;
	if(!GPIO_ReadInputDataBit( IO_JOYSTICK_ARRAY, IO_JOYSTICK_D))KeyAndJostickValue = JOYSTICK_D_VALUE;
	if(!GPIO_ReadInputDataBit( IO_JOYSTICK_ARRAY, IO_JOYSTICK_P))KeyAndJostickValue = JOYSTICK_P_VALUE;
}
void JoystickGpioConfiguration(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_IO_JOYSTICK, ENABLE);

  GPIO_InitStructure.GPIO_Pin = IO_JOYSTICK_A | IO_JOYSTICK_B | IO_JOYSTICK_C | IO_JOYSTICK_D | IO_JOYSTICK_P;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init( IO_JOYSTICK_ARRAY, &GPIO_InitStructure);
}

void SteppingMotor_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = IO_PWM_CH2 | IO_PWM_CH3 | IO_PWM_CH4; //TIM2��CH2,CH3,CH4���PWM
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//����GPIO���츴��ģʽ
		//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;//����GPIO��©����ģʽ��Ҫ����������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(IO_PWM_ARRAY,&GPIO_InitStructure);

	/*
	GPIO_Mode_AIN = 0x0,     //ģ������
  GPIO_Mode_IN_FLOATING = 0x04, //��������
  GPIO_Mode_IPD = 0x28,    //��������
  GPIO_Mode_IPU = 0x48,    //��������
  GPIO_Mode_Out_OD = 0x14, //��©���
  GPIO_Mode_Out_PP = 0x10,  //�������
  GPIO_Mode_AF_OD = 0x1C,   //��©����
  GPIO_Mode_AF_PP = 0x18    //���츴��
	*/

    GPIO_InitStructure.GPIO_Pin = IO_DirectionX | IO_DirectionY | IO_DirectionZ; //���Ʋ����������ת
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(IO_Direction_ARRAY,&GPIO_InitStructure);
		GPIO_ResetBits(IO_Direction_ARRAY,IO_DirectionX);
		GPIO_ResetBits(IO_Direction_ARRAY,IO_DirectionY);
		GPIO_ResetBits(IO_Direction_ARRAY,IO_DirectionZ);

    //����PWMƵ��
    TIM_TimeBaseStructure.TIM_Prescaler =719;                    //Ԥ��Ƶֵ
    TIM_TimeBaseStructure.TIM_Period =99;                   //��װֵ������pwm���Ƶ��1KHZ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//����TIM������ʱ��Դ����Ƶ��Ϊ72MHz
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);          //ʱ����Ԫ����
                                                                      
    //�趨ռ�ձ�
    TIM_OCStructInit(& TIM_OCInitStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������PWM
    TIM_OCInitStructure.TIM_Pulse =25;                      //ռ�ձ�50%
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //���øߵ�ƽΪPWM��Ч�����ƽ
		
		//TIM_ARRPreloadConfig(TIM2,ENABLE);//ʹ��TIMx ��ARRԤװ�ؼĴ���
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);	
		TIM_OC3Init(TIM2, &TIM_OCInitStructure);	
		TIM_OC4Init(TIM2, &TIM_OCInitStructure);	
    //TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);//CH2Ԥװ��ʹ��
		

    //TIM_CtrlPWMOutputs(TIM2, ENABLE); 
    //TIM_Cmd(TIM2, ENABLE);	
		
}

void Run(void)
{
		if(KeyAndJostickValue == JOYSTICK_A_VALUE)
    {
        GPIO_ResetBits(IO_Direction_ARRAY,IO_DirectionX);     //��ת			
    }
    else if(KeyAndJostickValue == JOYSTICK_D_VALUE)
    {
        GPIO_SetBits(IO_Direction_ARRAY,IO_DirectionX);         //����
    }
		else if(KeyAndJostickValue == JOYSTICK_B_VALUE)
    {
        TIM_Cmd(TIM2, ENABLE); 
    }
		else if(KeyAndJostickValue == JOYSTICK_C_VALUE)
    {
        TIM_Cmd(TIM2, DISABLE); 
    }
		else
		{
			;
		}
}






/*
void EnableSteppingMotor(void)
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void DisableSteppingMotor(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_2);
}
*/
