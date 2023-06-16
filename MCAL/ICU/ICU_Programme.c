#include<stdio.h>
#include "../Common/Utility.h"
#include "ICU_Interface.h"


#define   TIM1_BaseAddress    0X40010000
#define   TIM2_BaseAddress    0x40000000
#define   TIM3_BaseAddress    0x40000400
#define   TIM4_BaseAddress    0x40000800
#define   TIM5_BaseAddress    0x40001200



typedef struct
{
	 uint32_t CR1;
	 uint32_t CR2;
	 uint32_t SMCR;
	 uint32_t DIER;
	 uint32_t SR;
	 uint32_t EGR;
	 uint32_t CCMR1;
	 uint32_t CCMR2;
	 uint32_t CCER;
	 uint32_t CNT;
	 uint32_t PSC;
	 uint32_t ARR;
	 uint32_t RES1;
	 uint32_t CCR1;
	 uint32_t CCR2;
	 uint32_t CCR3;
	 uint32_t CCR4;
	 uint32_t RES2;
	 uint32_t DCR;
	 uint32_t DMAR;
	 uint32_t TIM2_OR;
	 uint32_t TIM5_OR;


}TIM_t;


#define TIM1    ((volatile TIM_t*) TIM1_BaseAddress)
#define TIM2    ((volatile TIM_t*) TIM2_BaseAddress)
#define TIM3    ((volatile TIM_t*) TIM3_BaseAddress)
#define TIM4    ((volatile TIM_t*) TIM4_BaseAddress)
#define TIM5    ((volatile TIM_t*) TIM5_BaseAddress)



Res_t TIM_Res_tSetCounterState(COUNTER_STATE_t COUNTER_STATE,TIM_NUMBER_t TIM)
{
	Res_t Error_State=NoError;

	if(COUNTER_STATE==COUNTER_STATE_ENABLE)
	{
		switch(TIM)
		{
		case TIM_1: TIM1->CR1|=(1<<0); break;
		case TIM_2: TIM2->CR1|=(1<<0); break;
		case TIM_3: TIM3->CR1|=(1<<0); break;
		case TIM_4: TIM4->CR1|=(1<<0); break;
		default:Error_State=Error;
		}
	}
	else if(COUNTER_STATE==COUNTER_STATE_DISABLE)
	{
		switch(TIM)
	    {
		case TIM_1: TIM1->CR1&=~(1<<0); break;
		case TIM_2: TIM2->CR1&=~(1<<0); break;
		case TIM_3: TIM3->CR1&=~(1<<0); break;
		case TIM_4: TIM4->CR1&=~(1<<0); break;
		default:Error_State=Error;
		}
	}
	else
	{
		Error_State=Error;
	}
	return Error_State;
}
Res_t TIM_Res_tSetCapture_CompareInterruptState(CAPTURE_COMPARE_INTERRUPT_State_t CAPTURE_COMPARE_INTERRUPT_State,TIM_NUMBER_t TIM,CHANNEL_t CHANNEL)
{
	Res_t Error_State=NoError;
	if(CAPTURE_COMPARE_INTERRUPT_State==CAPTURE_COMPARE_INTERRUPT_ENABLE)
	{
		switch(TIM)
		{
		case TIM_1:
				TIM1->DIER|=(1<<CHANNEL);
			break;
		case TIM_2:
				TIM2->DIER|=(1<<CHANNEL);
			break;
		case TIM_3:
				TIM3->DIER|=(1<<CHANNEL);
			break;
		case TIM_4:
				TIM4->DIER|=(1<<CHANNEL);
			break;
		default:Error_State=Error;
		}
	}
	else if(CAPTURE_COMPARE_INTERRUPT_State==CAPTURE_COMPARE_INTERRUPT_DISABLE)
	{
		switch(TIM)
		{
		case TIM_1:
				TIM1->DIER&=~(1<<CHANNEL);
			break;
		case TIM_2:
				TIM2->DIER&=~(1<<CHANNEL);
			break;
		case TIM_3:
				TIM3->DIER&=~(1<<CHANNEL);
			break;
		case TIM_4:
				TIM4->DIER&=~(1<<CHANNEL);
			break;
		default:Error_State=Error;
		}
	}
	else
	{
		Error_State=Error;
	}
	return Error_State;
}
Res_t TIM_Res_tSetTriggerInterruptState(TRIGGER_INTERRUPT_STATE_t TRIGGER_INTERRUPT_STATE,TIM_NUMBER_t TIM)
{
	Res_t Error_State=NoError;
	if(TRIGGER_INTERRUPT_STATE==TRIGGER_INTERRUPT_STATE_ENABLE)
	{
		switch(TIM)
	    {
		case TIM_1: TIM1->DIER|=(1<<6); break;
		case TIM_2: TIM2->DIER|=(1<<6); break;
		case TIM_3: TIM3->DIER|=(1<<6); break;
		case TIM_4: TIM4->DIER|=(1<<6); break;
		default:Error_State=Error;
		}
	}
	else if(TRIGGER_INTERRUPT_STATE==TRIGGER_INTERRUPT_STATE_DISABLE)
	{
		switch(TIM)
		{
		case TIM_1: TIM1->DIER&=~(1<<6); break;
		case TIM_2: TIM2->DIER&=~(1<<6); break;
		case TIM_3: TIM3->DIER&=~(1<<6); break;
		case TIM_4: TIM4->DIER&=~(1<<6); break;
		default:Error_State=Error;
		}
	}
	else
	{
		Error_State=Error;
	}
	return Error_State;
}
Res_t TIM_Res_tSetChannelState(TIM_NUMBER_t TIM,CHANNEL_t CHANNEL,CHANNEL_STATE_t CHANNEL_STATE)
{
	Res_t Error_State=NoError;
	//uint32_t temp;

		switch(TIM)
		{
		case TIM_1:
			switch(CHANNEL)
			{
			case CHANNEL_1: TIM1->CCMR1&=~(0x3<<0); TIM1->CCMR1|=(CHANNEL_STATE<<0);break;
			case CHANNEL_2: TIM1->CCMR1&=~(0x3<<8); TIM1->CCMR1|=(CHANNEL_STATE<<8);break;
			case CHANNEL_3: TIM1->CCMR2&=~(0x3<<0); TIM1->CCMR2|=(CHANNEL_STATE<<0);break;
			case CHANNEL_4: TIM1->CCMR2&=~(0x3<<8); TIM1->CCMR2|=(CHANNEL_STATE<<8);break;
			default:Error_State=Error;
			}
			break;
		case TIM_2:
			switch(CHANNEL)
			{
			case CHANNEL_1: TIM2->CCMR1&=~(0x3<<0); TIM2->CCMR1|=(CHANNEL_STATE<<0);break;
			case CHANNEL_2: TIM2->CCMR1&=~(0x3<<8); TIM2->CCMR1|=(CHANNEL_STATE<<8);break;
			case CHANNEL_3: TIM2->CCMR2&=~(0x3<<0); TIM2->CCMR2|=(CHANNEL_STATE<<0);break;
			case CHANNEL_4: TIM2->CCMR2&=~(0x3<<8); TIM2->CCMR2|=(CHANNEL_STATE<<8);break;
			default:Error_State=Error;
			}
			break;
		case TIM_3:
			switch(CHANNEL)
			{
			case CHANNEL_1: TIM3->CCMR1&=~(0x3<<0); TIM3->CCMR1|=(CHANNEL_STATE<<0);break;
			case CHANNEL_2: TIM3->CCMR1&=~(0x3<<8); TIM3->CCMR1|=(CHANNEL_STATE<<8);break;
			case CHANNEL_3: TIM3->CCMR2&=~(0x3<<0); TIM3->CCMR2|=(CHANNEL_STATE<<0);break;
			case CHANNEL_4: TIM3->CCMR2&=~(0x3<<8); TIM3->CCMR2|=(CHANNEL_STATE<<8);break;
			default:Error_State=Error;
			}
			break;
	    case TIM_4:
			switch(CHANNEL)
			{
			case CHANNEL_1: TIM4->CCMR1&=~(0x3<<0); TIM4->CCMR1|=(CHANNEL_STATE<<0);break;
    		case CHANNEL_2: TIM4->CCMR1&=~(0x3<<8); TIM4->CCMR1|=(CHANNEL_STATE<<8);break;
			case CHANNEL_3: TIM4->CCMR2&=~(0x3<<0); TIM4->CCMR2|=(CHANNEL_STATE<<0);break;
			case CHANNEL_4: TIM4->CCMR2&=~(0x3<<8); TIM4->CCMR2|=(CHANNEL_STATE<<8);break;
			default:Error_State=Error;
			}
			break;
		}
		return Error_State;
}
Res_t TIM_Res_tSetCapture_CompareState(TIM_NUMBER_t TIM,CHANNEL_t CHANNEL,CAPTURE_COMPARE_STATE_t CAPTURE_COMPARE_STATE)
{
	Res_t Error_State=NoError;
	if(CAPTURE_COMPARE_STATE==CAPTURE_COMPARE_STATE_ENABLE)
	{
		switch(TIM)
		{
		case TIM_1:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM1->CCER|=(1<<0);break;
			case CHANNEL_2:TIM1->CCER|=(1<<4);break;
			case CHANNEL_3:TIM1->CCER|=(1<<8);break;
			case CHANNEL_4:TIM1->CCER|=(1<<12);break;
			default:Error_State=Error;
			}
			break;
		case TIM_2:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM2->CCER|=(1<<0);break;
			case CHANNEL_2:TIM2->CCER|=(1<<4);break;
			case CHANNEL_3:TIM2->CCER|=(1<<8);break;
			case CHANNEL_4:TIM2->CCER|=(1<<12);break;
			default:Error_State=Error;
			}
			break;
	    case TIM_3:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM3->CCER|=(1<<0);break;
			case CHANNEL_2:TIM3->CCER|=(1<<4);break;
			case CHANNEL_3:TIM3->CCER|=(1<<8);break;
			case CHANNEL_4:TIM3->CCER|=(1<<12);break;
			default:Error_State=Error;
			}
		    break;
		case TIM_4:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM4->CCER|=(1<<0);break;
			case CHANNEL_2:TIM4->CCER|=(1<<4);break;
			case CHANNEL_3:TIM4->CCER|=(1<<8);break;
			case CHANNEL_4:TIM4->CCER|=(1<<12);break;
			default:Error_State=Error;
			}
		    break;
		default:Error_State=Error; break;
		}
	}
	else if(CAPTURE_COMPARE_STATE==CAPTURE_COMPARE_STATE_DISABLE)
	{
		switch(TIM)
		{
		case TIM_1:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM1->CCER&=~(1<<0);break;
			case CHANNEL_2:TIM1->CCER&=~(1<<4);break;
			case CHANNEL_3:TIM1->CCER&=~(1<<8);break;
			case CHANNEL_4:TIM1->CCER&=~(1<<12);break;
			default:Error_State=Error;
			}
			break;
		case TIM_2:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM2->CCER&=~(1<<0);break;
			case CHANNEL_2:TIM2->CCER&=~(1<<4);break;
			case CHANNEL_3:TIM2->CCER&=~(1<<8);break;
			case CHANNEL_4:TIM2->CCER&=~(1<<12);break;
			default:Error_State=Error;
			}
			break;
	    case TIM_3:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM3->CCER&=~(1<<0);break;
			case CHANNEL_2:TIM3->CCER&=~(1<<4);break;
			case CHANNEL_3:TIM3->CCER&=~(1<<8);break;
			case CHANNEL_4:TIM3->CCER&=~(1<<12);break;
			default:Error_State=Error;
			}
		    break;
		case TIM_4:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM4->CCER&=~(1<<0);break;
			case CHANNEL_2:TIM4->CCER&=~(1<<4);break;
			case CHANNEL_3:TIM4->CCER&=~(1<<8);break;
			case CHANNEL_4:TIM4->CCER&=~(1<<12);break;
			default:Error_State=Error;
			}
		    break;
		default:Error_State=Error; break;
		}
	}
	else
	{
		Error_State=Error;
	}
    return Error_State;
}
Res_t TIM_Res_tSetInputCaptureEdgeTrigger(TIM_NUMBER_t TIM,CHANNEL_t CHANNEL,INPUT_CAPTURE_TRIGGER_t INPUT_CAPTURE_TRIGGER)
{
	Res_t Error_State=NoError;

	if(INPUT_CAPTURE_TRIGGER==INPUT_CAPTURE_TRIGGER_RISING_EDGE)
	{
		switch(TIM)
		{
		case TIM_2:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM2->CCER&=~(1<<1);TIM2->CCER&=~(1<<3);break;
			case CHANNEL_2:TIM2->CCER&=~(1<<5);TIM2->CCER&=~(1<<7);break;
			case CHANNEL_3:TIM2->CCER&=~(1<<9);TIM2->CCER&=~(1<<10);break;
			case CHANNEL_4:TIM2->CCER&=~(1<<13);TIM2->CCER&=~(1<<15);break;
			default:Error_State=Error;
			}
			break;
		case TIM_3:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM3->CCER&=~(1<<1);TIM3->CCER&=~(1<<3);break;
			case CHANNEL_2:TIM3->CCER&=~(1<<5);TIM3->CCER&=~(1<<7);break;
			case CHANNEL_3:TIM3->CCER&=~(1<<9);TIM3->CCER&=~(1<<10);break;
			case CHANNEL_4:TIM2->CCER&=~(1<<13);TIM3->CCER&=~(1<<15);break;
			default:Error_State=Error;
			}
			break;
		case TIM_4:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM4->CCER&=~(1<<1);TIM4->CCER&=~(1<<3);break;
			case CHANNEL_2:TIM4->CCER&=~(1<<5);TIM4->CCER&=~(1<<7);break;
			case CHANNEL_3:TIM4->CCER&=~(1<<9);TIM4->CCER&=~(1<<10);break;
			case CHANNEL_4:TIM4->CCER&=~(1<<13);TIM4->CCER&=~(1<<15);break;
			default:Error_State=Error;
			}
			break;
		default:Error_State=NoError;
		}
	}
	else if(INPUT_CAPTURE_TRIGGER==INPUT_CAPTURE_TRIGGER_FALLING_EDGE)
	{
		switch(TIM)
		{
		case TIM_2:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM2->CCER|=(1<<1);TIM2->CCER&=~(1<<3);break;
			case CHANNEL_2:TIM2->CCER|=(1<<5);TIM2->CCER&=~(1<<7);break;
			case CHANNEL_3:TIM2->CCER|=(1<<9);TIM2->CCER&=~(1<<10);break;
			case CHANNEL_4:TIM2->CCER|=(1<<13);TIM2->CCER&=~(1<<15);break;
			default:Error_State=Error;
			}
			break;
	    case TIM_3:
			switch(CHANNEL)
			{
			case CHANNEL_1:TIM3->CCER|=(1<<1);TIM3->CCER&=~(1<<3);break;
			case CHANNEL_2:TIM3->CCER|=(1<<5);TIM3->CCER&=~(1<<7);break;
			case CHANNEL_3:TIM3->CCER|=(1<<9);TIM3->CCER&=~(1<<10);break;
			case CHANNEL_4:TIM3->CCER|=(1<<13);TIM3->CCER&=~(1<<15);break;
			default:Error_State=Error;
			}
			break;
			case TIM_4:
		    switch(CHANNEL)
			{
			case CHANNEL_1:TIM4->CCER|=(1<<1);TIM4->CCER&=~(1<<3);break;
			case CHANNEL_2:TIM4->CCER|=(1<<5);TIM4->CCER&=~(1<<7);break;
			case CHANNEL_3:TIM4->CCER|=(1<<9);TIM4->CCER&=~(1<<10);break;
			case CHANNEL_4:TIM4->CCER|=(1<<13);TIM4->CCER&=~(1<<15);break;
			default:Error_State=Error;
			}
			break;
		default:Error_State=Error;
		}
	}
	else if(INPUT_CAPTURE_TRIGGER==INPUT_CAPTURE_TRIGGER_RISING_FALLING)
	{
		TIM2->CCER|=(1<<1);
		TIM2->CCER|=(1<<3);
	}
	else
	{
		Error_State=Error;
	}
    return Error_State;
}


uint32_t TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_NUMBER_t TIM,CHANNEL_t CHANNEL)
{
	uint32_t Capture_Value;

	if(TIM==TIM_2)
	{
		switch(CHANNEL)
		{
		case CHANNEL_1: Capture_Value=TIM2->CCR1;break;
		case CHANNEL_2: Capture_Value=TIM2->CCR2;break;
		case CHANNEL_3: Capture_Value=TIM2->CCR3;break;
		case CHANNEL_4: Capture_Value=TIM2->CCR4;break;
		//default:
			//do nothing
		}
	}
	else if(TIM==TIM_5)
	{
		//do nothing
	}
	return Capture_Value;
}
uint16_t TIM_uint16_tGetCaptureValue(TIM_NUMBER_t TIM,CHANNEL_t CHANNEL)
{
	uint16_t Capture_Value;

	switch(TIM)
	{
	case TIM_1:
		switch(CHANNEL)
		{
		case CHANNEL_1: Capture_Value=TIM1->CCR1;break;
		case CHANNEL_2: Capture_Value=TIM1->CCR2;break;
		case CHANNEL_3: Capture_Value=TIM1->CCR3;break;
		case CHANNEL_4: Capture_Value=TIM1->CCR4;break;
		//default://do nothing
		}
	    break;
	case TIM_3:
		switch(CHANNEL)
		{
		case CHANNEL_1: Capture_Value=TIM3->CCR1;break;
		case CHANNEL_2: Capture_Value=TIM3->CCR2;break;
		case CHANNEL_3: Capture_Value=TIM3->CCR3;break;
		case CHANNEL_4: Capture_Value=TIM3->CCR4;break;
		//default://do nothing
		}
	    break;
	case TIM_4:
		switch(CHANNEL)
		{
		case CHANNEL_1: Capture_Value=TIM4->CCR1;break;
		case CHANNEL_2: Capture_Value=TIM4->CCR2;break;
		case CHANNEL_3: Capture_Value=TIM4->CCR3;break;
		case CHANNEL_4: Capture_Value=TIM4->CCR4;break;
		//default://do nothing
		}
	    break;
	//default://do nothing
	}
	return Capture_Value;
}
Res_t TIM_Res_tSetPrescaler(TIM_NUMBER_t TIM,uint16_t PRESCALER)
{
	Res_t Error_State=NoError;

	switch(TIM)
	{
	case TIM_1: TIM1->PSC=PRESCALER; break;
	case TIM_2: TIM2->PSC=PRESCALER; break;
	case TIM_3: TIM3->PSC=PRESCALER; break;
	case TIM_4:	TIM4->PSC=PRESCALER; break;
	default: Error_State=Error;
	}
	return Error_State;
}
Res_t TIM_Res_tSetPreloadValue(TIM_NUMBER_t TIM,uint32_t PRELOAD)
{
	Res_t Error_State=NoError;

	switch(TIM)
	{
	case TIM_1: TIM1->ARR=PRELOAD; break;
	case TIM_2: TIM2->ARR=PRELOAD; /*TIM2->EGR|=(1<<0);*/ break;
	case TIM_3: TIM3->ARR=PRELOAD; break;
	case TIM_4:	TIM4->ARR=PRELOAD; break;
	default: Error_State=Error;
	}
	return Error_State;
}
uint8_t TIM_uint8_tGetFlag(TIM_NUMBER_t TIM,CHANNEL_t CHANNEL)
{
	uint8_t Flag=0;

	switch(TIM)
	{
	case TIM_2:
		switch(CHANNEL)
		{
		case CHANNEL_1:Flag=(TIM2->SR>>CHANNEL)&1; break;
		case CHANNEL_2:Flag=(TIM2->SR>>CHANNEL)&1; break;
		case CHANNEL_3:Flag=(TIM2->SR>>CHANNEL)&1; break;
		case CHANNEL_4:Flag=(TIM2->SR>>CHANNEL)&1; break;
		}
		break;
	case TIM_3:
		switch(CHANNEL)
		{
		case CHANNEL_1:Flag=(TIM3->SR>>CHANNEL)&1; break;
		case CHANNEL_2:Flag=(TIM3->SR>>CHANNEL)&1; break;
		case CHANNEL_3:Flag=(TIM3->SR>>CHANNEL)&1; break;
		case CHANNEL_4:Flag=(TIM3->SR>>CHANNEL)&1; break;
		}
		break;
	case TIM_4:
		switch(CHANNEL)
		{
		case CHANNEL_1:Flag=(TIM4->SR>>CHANNEL)&1; break;
		case CHANNEL_2:Flag=(TIM4->SR>>CHANNEL)&1; break;
		case CHANNEL_3:Flag=(TIM4->SR>>CHANNEL)&1; break;
		case CHANNEL_4:Flag=(TIM4->SR>>CHANNEL)&1; break;
		}
		break;
	}
	return Flag;
}
void TIM_voidSetCounterValue(TIM_NUMBER_t TIM,uint32_t COUNTER_VALUE)
{
	switch(TIM)
	{
	case TIM_2: TIM2->CNT=COUNTER_VALUE;break;
	case TIM_3: TIM3->CNT=COUNTER_VALUE;break;
	case TIM_4: TIM4->CNT=COUNTER_VALUE;break;
	case TIM_5: TIM5->CNT=COUNTER_VALUE;break;
	}
}
void TIM_voidClearCounterFlag(TIM_NUMBER_t TIM)
{
	switch(TIM)
		{
		case TIM_2: TIM2->SR&=~(1<<0); break;
		case TIM_3: TIM3->SR&=~(1<<0); break;
		case TIM_4: TIM4->SR&=~(1<<0); break;
		case TIM_5: TIM5->SR&=~(1<<0); break;
		}
}
void TIM_voidSet_EGR_UG(TIM_NUMBER_t TIM)
{
	switch(TIM)
		{
		case TIM_2: TIM2->EGR|=(1<<0); break;
		case TIM_3: TIM3->EGR|=(1<<0); break;
		case TIM_4: TIM4->EGR|=(1<<0); break;
		case TIM_5: TIM5->EGR|=(1<<0); break;
		}
}


void delay15us(void)
{

	TIM3->PSC=15;
	TIM3->ARR=15;
	TIM3->CNT=0;
	TIM3->CR1|=(1<<0);

	while(!((TIM3->SR)&1));

	TIM3->CR1&=~(1<<0);
	TIM3->SR&=~(1<<0);
	TIM3->CR1|=(1<<0);

}
/*
void GetValue(uint32_t*x1,uint32_t*y1)
{
	//while(!((TIM2->SR>>1)&1));
	while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_1));
	//*x1= TIM2->CCR1;
	*x1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_1);
	TIM2->EGR|=(1<<0);
	//TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_1,CAPTURE_COMPARE_STATE_DISABLE);
	TIM_Res_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
	TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_1,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);
	//TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_1,CAPTURE_COMPARE_STATE_ENABLE);


	//while(!((TIM2->SR>>1)&1));
	while(!TIM_uint8_tGetFlag(TIM_2,CHANNEL_1));

	//TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_1,CAPTURE_COMPARE_STATE_DISABLE);
	//*y1= TIM2->CCR1;
	*y1=TIM_uint32_tGetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_1);
	TIM_Res_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_1,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
	TIM_Res_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
	//TIM2->SR&=~(1<<0);
	TIM2->CNT=0;
	//TIM_Res_tSetCapture_CompareState(TIM_2,CHANNEL_1,CAPTURE_COMPARE_STATE_ENABLE);

}*/




