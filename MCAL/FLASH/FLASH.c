#include "FLASH.h"


/*************************************************Flash interface Base Address******************************************/
#define FLASH_BaseAddress     							0x40023C00

/***********************************************Sector Erase Bits Masking***********************************************/
#define SECTOR_ERASE_MASK								0xF
#define SECTOR_ERASE_SHIFTBITS							3
/***********************************************Program size Parallelism masking****************************************/
#define PROGRAM_SIZE_MASK								0x3
#define PROGRAM_SIZE_SHIFTBITS							8
/************************************************Register Bits*********************************************************/
#define BSY_BIT											16
#define LOCK_BIT										31
#define	SER_BIT											1
#define STRT_BIT										16
#define EOP_BIT											0
#define PG_BIT											0
/***********************************************Unlock Keys to access flash control register***************************/
#define KEY1  		 									0x45670123
#define	KEY2 											0xCDEF89AB
/***********************************************typedefs***************************************************************/
typedef struct
{
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_OPTCR;

}FLASH_REGS;
/****************************************************Variables**********************************************************/
static volatile FLASH_REGS * const FLASH = (volatile FLASH_REGS * const) FLASH_BaseAddress ;
/*********************************Static function to unlock FLASH_KEYR register****************************************/
static void FlashUnlock(void);
/**************************************************Flash Interface Functions*******************************************/
void MFLASH_voidAreaErase(void)
{
	u8 LoopCounter;

	for(LoopCounter = START_SECTOR; LoopCounter < END_SECTOR; LoopCounter++)
	{
		MFLASH_voidSectorErase(LoopCounter);
	}
}

void MFLASH_voidSectorErase(u8 SectorNum )
{

	u32 temp;
	while(GET_BIT(FLASH-> FLASH_SR, BSY_BIT) == 1);

	FlashUnlock();

	SET_BIT(FLASH->FLASH_CR, SER_BIT);

	//FLASH->FLASH_AR =  (FLASH_PAGE0_ADDRESS) + (u32) (Copy_u8PageNum * PageSize);

	/*sector erase*/
	temp = FLASH->FLASH_CR;
	temp &= ~(SECTOR_ERASE_MASK<<SECTOR_ERASE_SHIFTBITS);
	temp |= (SectorNum<<SECTOR_ERASE_SHIFTBITS);
	FLASH->FLASH_CR = temp;

	FLASH->FLASH_CR |= (1 << STRT_BIT);

	while((FLASH-> FLASH_SR >> BSY_BIT) & 1);

	FLASH->FLASH_SR |= (1 << EOP_BIT);

	FLASH->FLASH_CR &= ~(1 << SER_BIT);

}

void MFLASH_voidWrite(u32 Address, u16 * Data, u8 Length)
{
	u8 LoopCounter;
	u32 temp;
	while((FLASH-> FLASH_SR >> BSY_BIT) & 1);

	FlashUnlock();

	/*set the program size to half word*/
	for (LoopCounter = 0; LoopCounter< Length; LoopCounter++)
	{
		/*Write Flash Programming*/
		FLASH->FLASH_CR |= (1 << PG_BIT);
		temp = FLASH->FLASH_CR;
		temp &= ~(PROGRAM_SIZE_MASK << PROGRAM_SIZE_SHIFTBITS);
		temp |= (1<<PROGRAM_SIZE_SHIFTBITS);
		/*check the location of the equality*/
		FLASH->FLASH_CR=temp;


		/* Half word operation */
		*((volatile u16*)Address) = Data[LoopCounter];
		Address += 2 ;

		/* Wait Busy Flag */
		while ((FLASH->FLASH_SR >> BSY_BIT) & 1);

		/* EOP */
		FLASH->FLASH_SR |= (1 << EOP_BIT);
		FLASH->FLASH_CR &= ~(1 << PG_BIT);
	}
}

static void FlashUnlock(void)
{
	if(GET_BIT(FLASH->FLASH_CR, LOCK_BIT) == 1)
	{
		FLASH->FLASH_KEYR = KEY1;
		FLASH->FLASH_KEYR = KEY2;
	}
}


