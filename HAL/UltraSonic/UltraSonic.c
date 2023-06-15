#include<stdio.h>
#include"UltraSonic.h"
#include"UltraSonic_cfg.h"
#include "../../MCAL/ICU/ICU_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/RCC/RCC_Interface.h"

#define SPEED_OF_SOUND 343.0f

/*Timer choices*/
#define TIM2   0
#define TIM3   1
#define TIM4   2
#define TIM5   3

/*Channel choices*/
#define CHANNEL1   0
#define CHANNEL2   1
#define CHANNEL3   2
#define CHANNEL4   3





static float GetDistance(uint32_t time);
static void GetCaptureValues(uint32_t*x1,uint32_t*y1);


void UltraSonic_voidInit(void)
{
	MRCC_Res_tSetPeripheralState(Peri_Enable,Bus_AHB1,AHB1_GPIOA);
	MRCC_Res_tSetPeripheralState(Peri_Enable,Bus_APB1,APB1_TIM2);
	MRCC_Res_tSetPeripheralState(Peri_Enable,Bus_APB1,APB1_TIM3);
	MGPIO_Res_tSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_MODE_OUTPUT);
	TIM_Res_tSetPrescaler(TIM_2,15);
	TIM_Res_tSetPreloadValue(TIM_2,0xffffffff);

#if ULTRA_CHANNEL==CHANNEL1

	MGPIO_Res_tSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_ALTERNATIVE_FUN);
	MGPIO_Res_tSetAlternativeFunction(GPIO_PORTA,GPIO_PIN0,AF_1);
	TIM_Res_tSetChannelState(TIM_2,CHANNEL_1,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_1,CAPTURE_COMPARE_STATE_ENABLE);

#elif ULTRA_CHANNEL==CHANNEL2
	MGPIO_Res_tSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_ALTERNATIVE_FUN);
	MGPIO_Res_tSetAlternativeFunction(GPIO_PORTA,GPIO_PIN1,AF_1);
	TIM_Res_tSetChannelState(TIM_2,CHANNEL_2,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_2,CAPTURE_COMPARE_STATE_ENABLE);

#elif ULTRA_CHANNEL==CHANNEL3
	MGPIO_Res_tSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_ALTERNATIVE_FUN);
	MGPIO_Res_tSetAlternativeFunction(GPIO_PORTA,GPIO_PIN2,AF_1);
	TIM_Res_tSetChannelState(TIM_2,CHANNEL_3,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_3,CAPTURE_COMPARE_STATE_ENABLE);

#elif ULTRA_CHANNEL==CHANNEL4
	MGPIO_Res_tSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_MODE_ALTERNATIVE_FUN);
	MGPIO_Res_tSetAlternativeFunction(GPIO_PORTA,GPIO_PIN3,AF_1);
	TIM_Res_tSetChannelState(TIM_2,CHANNEL_4,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_4,CAPTURE_COMPARE_STATE_ENABLE);
#endif
}

float UltraSonic_floatGetDistance(void)
{
	uint32_t Captutre_1,Capture_2;
	float Distance;
	MGPIO_Res_tSetAtomicState(GPIO_PORTA,GPIO_PIN4,ATOMIC_STATE_SET);
	delay15us();
	MGPIO_Res_tSetAtomicState(GPIO_PORTA,GPIO_PIN4,ATOMIC_STATE_RESET);
	GetCaptureValues(&Captutre_1,&Capture_2);
	Distance=GetDistance((Capture_2-Captutre_1));
	return Distance;
}




static float GetDistance(uint32_t time)
{
    return (SPEED_OF_SOUND * time) / (2.0f * 10000.0f);
}

static void GetCaptureValues(uint32_t*x1,uint32_t*y1)
{
#if ULTRA_CHANNEL==CHANNEL1

	while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_1));

	*x1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_1);
	TIM_voidSet_EGR_UG(TIM_2);
	TIM_Res_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
	TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_1,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);


	while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_1));
	*y1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_1);
	TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_1,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
	TIM_Res_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
	TIM_voidClearCounterFlag(TIM_2);
	TIM_voidSetCounterValue(TIM_2,0);

#elif ULTRA_CHANNEL==CHANNEL2
	while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_2));

		*x1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_2);
		TIM_voidSet_EGR_UG(TIM_2);
		TIM_Res_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
		TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_2,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);


		while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_2));
		*y1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_2);
		TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_2,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
		TIM_Res_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
		TIM_voidClearCounterFlag(TIM_2);
		TIM_voidSetCounterValue(TIM_2,0);

#elif ULTRA_CHANNEL==CHANNEL3
		while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_3));

		*x1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_3);
		TIM_voidSet_EGR_UG(TIM_2);
		TIM_Res_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
		TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_3,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);


		while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_3));
		*y1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_3);
		TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_3,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
		TIM_Res_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
		TIM_voidClearCounterFlag(TIM_2);
		TIM_voidSetCounterValue(TIM_2,0);

#elif ULTRA_CHANNEL==CHANNEL4
		while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_4));

		*x1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_4);
		TIM_voidSet_EGR_UG(TIM_2);
	    TIM_Res_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
		TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_4,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);


		while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_4));
		*y1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_4);
		TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_4,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
		TIM_Res_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
		TIM_voidClearCounterFlag(TIM_2);
		TIM_voidSetCounterValue(TIM_2,0);
#endif

}






