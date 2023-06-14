#include "NVIC.h"


/*System control block-->Application interrupt and reset control register address(To set grouping style)*/
#define   SCB_AIRCR_REG       (*(volatile u32*)(0xE000ED0C))

/*NVIC base memory address */
#define   NVIC_BaseAddress    0xE000E100

/* ISER-ICER START/END Macros */
#define ISER0_START   0
#define ISER0_END     31
#define ISER1_START   32
#define ISER1_END     63
#define ISER2_START   64
#define ISER2_END     84

#define ICER0_START   ISER0_START
#define ICER0_END     ISER0_END
#define ICER1_START   ISER1_START
#define ICER1_END     ISER1_END
#define ICER2_START   ISER2_START
#define ICER2_END     ISER2_END

/* Dividing on NVIC register length*/
#define NVIC_REG_LENGTH 	32

typedef struct
{
	volatile u32 ISER[8];
	volatile u32 Res_1[24];
	volatile u32 ICER[8];
	volatile u32 Res_2[24];
	volatile u32 ISPR[8];
	volatile u32 Res_3[24];
	volatile u32 ICPR[8];
	volatile u32 Res_4[24];
	volatile u32 IABR[8];
	volatile u32 Res_5[56];
	volatile u8  IPR[240];
	volatile u32 Res_6[580];
	volatile u32 STIR;

}NVIC_t;


/* NVIC base address */

static volatile NVIC_t * const NVIC_REGS = ((volatile NVIC_t * const)NVIC_BaseAddress);


/* Setting pri_groubing value */
void MNVIC_voidSetInterruptPrioretyGroupingStyle(void)
{
#if PRI_GROUPING_STYLE==GROUP_16__SUBGROUP_0

	SCB_AIRCR_REG=GROUP_16__SUBGROUP_0;

	for (u8 i=0;i<240;i++)
		{
			NVIC_REGS->IPR[i]=	;
		}

#elif PRI_GROUPING_STYLE==GROUP_8__SUBGROUP_2

	SCB_AIRCR_REG=GROUP_8__SUBGROUP_2;

	for (u8 i=0;i<240;i++)
	{
		NVIC_REGS->IPR[i]=0;
	}

#elif PRI_GROUPING_STYLE==GROUP_4__SUBGROUP_4

	SCB_AIRCR_REG=GROUP_4__SUBGROUP_4;
	for (u8 i=0;i<240;i++)
	{
		NVIC_REGS->IPR[i]=0;
	}


#elif PRI_GROUPING_STYLE==GROUP_2__SUBGROUP_8

	SCB_AIRCR_REG=GROUP_2__SUBGROUP_8;

	for (u8 i=0;i<240;i++)
	{
		NVIC_REGS->IPR[i]=0;
	}


#elif PRI_GROUPING_STYLE==GROUP_16__SUBGROUP_0

	SCB_AIRCR_REG=GROUP_0__SUBGROUP_16;

	for (u8 i=0;i<240;i++)
	{
		NVIC_REGS->IPR[i]=0;
	}


#else
#error "error"

#endif

}
void MNVIC_voidSetPeripheralInterruptPriorety(u8 Peripheral_ID,u8 Group_Priorety,u8 SubGroup_Priorety)
{
#if PRI_GROUPING_STYLE==GROUP_16__SUBGROUP_0

	NVIC_REGS->IPR[Peripheral_ID]=Group_Priorety<<4;

#elif PRI_GROUPING_STYLE==GROUP_8__SUBGROUP_2

	NVIC_REGS->IPR[Peripheral_ID]= (Group_Priorety<<5 | SubGroup_Priorety<<4);


#elif PRI_GROUPING_STYLE==GROUP_4__SUBGROUP_4

	NVIC_REGS->IPR[Peripheral_ID]=(Group_Priorety<<6 | SubGroup_Priorety<<4);


#elif PRI_GROUPING_STYLE==GROUP_2__SUBGROUP_8

	NVIC_REGS->IPR[Peripheral_ID]=(Group_Priorety<<7 | SubGroup_Priorety<<4);

#elif PRI_GROUPING_STYLE==GROUP_0__SUBGROUP_16

	NVIC_REGS->IPR[Peripheral_ID]=SubGroup_Priorety<<4;


#else

#error "error"

#endif

}
Error_t MNVIC_Error_tSetPeripheralInterruptEnableState(u8 Interrupt_State,u8 Peripheral_ID)
{
	Error_t Error_State = NoError;

	if(Interrupt_State==INTERRUPT_ENABLE)
	{
		NVIC_REGS->ISER[Peripheral_ID/NVIC_REG_LENGTH]=1<<(Peripheral_ID % NVIC_REG_LENGTH);
	}
	else if(Interrupt_State==INTERRUPT_DISABLE)
	{
		NVIC_REGS->ICER[Peripheral_ID/NVIC_REG_LENGTH]=1<<(Peripheral_ID % NVIC_REG_LENGTH);
	}
	else
	{
		Error_State= Error;
	}
	return Error_State;
}

Error_t MNVIC_Error_tSetPeripheralPendingState(u8 Interrupt_State,u8 Peripheral_ID)
{
	Error_t Error_State = NoError;

	if(Interrupt_State==INTERRUPT_ENABLE)
	{
		if((Peripheral_ID>=ISER0_START) && (Peripheral_ID<=ISER0_END))
		{
			NVIC_REGS->ISPR[0]=1<<(Peripheral_ID);

			//NVIC_REGS->ISER[Peripheral_ID/31]=1<<(Peripheral_ID % 31);
		}
		else if((Peripheral_ID>=ISER1_START) && (Peripheral_ID<=ISER1_END))
		{
			NVIC_REGS->ISPR[1]=1<<(Peripheral_ID-ISER1_START);
		}
		else if((Peripheral_ID>=ISER2_START) && (Peripheral_ID<=ISER2_END))
		{
			NVIC_REGS->ISPR[2]=1<<(Peripheral_ID-ISER2_START);
		}
		else
		{
			Error_State=Error;
		}
	}
	else if(Interrupt_State==INTERRUPT_DISABLE)
	{
		if((Peripheral_ID>=ICER0_START) && (Peripheral_ID<=ICER0_END))
		{
			NVIC_REGS->ICPR[0]=1<<Peripheral_ID;
		}
		else if((Peripheral_ID>=ICER1_START) && (Peripheral_ID<=ICER1_END))
		{
			NVIC_REGS->ICPR[1]=1<<(Peripheral_ID-ICER1_START);
		}
		else if((Peripheral_ID>=ICER2_START) && (Peripheral_ID<=ICER2_END))
		{
			NVIC_REGS->ICPR[2]=1<<(Peripheral_ID-ICER2_START);
		}
		else
		{
			Error_State=Error;
		}
	}
	else
	{
		Error_State=Error;
	}
	return Error_State;
}

u8 MNVIC_u8GetPeripheralActiveState(u8 Peripheral_ID)
{
	u8 res;


	res=( ((NVIC_REGS->IABR[Peripheral_ID/NVIC_REG_LENGTH])>>(Peripheral_ID % NVIC_REG_LENGTH)) & 0x1) ;

	return res;

}
Error_t NVIC_SWTriggerInterrupt(u8 Peripheral_ID)
{
	Error_t ErrorState = NoError;

	if(Peripheral_ID >=0 && Peripheral_ID<=239)
		NVIC_REGS->STIR=(Peripheral_ID);
	else
		ErrorState=Error;

	return ErrorState;
}










