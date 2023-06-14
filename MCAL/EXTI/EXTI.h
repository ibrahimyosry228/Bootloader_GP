#include "../STM32F401C8T6/STM32F401C8T6.h"

#define NULL (void*)0

#define EXTI_line0            (u32)0x1
#define EXTI_line1            (u32)0x2
#define EXTI_line2            (u32)0x4
#define EXTI_line3            (u32)0x8
#define EXTI_line4            (u32)0x10
#define EXTI_line5            (u32)0x20
#define EXTI_line6            (u32)0x40
#define EXTI_line7            (u32)0x80
#define EXTI_line8            (u32)0x100
#define EXTI_line9            (u32)0x200
#define EXTI_line10           (u32)0x400
#define EXTI_line11           (u32)0x800
#define EXTI_line12           (u32)0x1000
#define EXTI_line13           (u32)0x2000
#define EXTI_line14           (u32)0x4000
#define EXTI_line15           (u32)0x8000
#define EXTI_line16           (u32)0x10000
#define EXTI_line17           (u32)0x20000
#define EXTI_line18           (u32)0x40000
#define EXTI_line21           (u32)0x200000
#define EXTI_line22           (u32)0x400000

#define EXTI_ModeRE           (u8)0
#define EXTI_ModeFE           (u8)1
#define EXTI_ModeRF           (u8)2

#define EXTI_StateEnable      (u8)1
#define EXTI_StateDisable     (u8)0

#define EXTI0                 (u8)0
#define EXTI1                 (u8)4
#define EXTI2                 (u8)8
#define EXTI3                 (u8)12

#define EXTIsrcA              (u8)0x0
#define EXTIsrcB              (u8)0x1
#define EXTIsrcC              (u8)0x2
#define EXTIsrcD              (u8)0x3
#define EXTIsrcE              (u8)0x4
#define EXTIsrcH              (u8)0x7



void MEXTI_LineInterruptMusk(u8 EXTI_lineNumber, u8 EXTI_State);

void MEXTI_LineEventMusk(u8 EXTI_lineNumber, u8 EXTI_State);

void MEXTI_LineTriggerMode(u8 EXTI_lineNumber, u8 EXTI_Mode);

void MEXTI_LineSwTrigger(u8 EXTI_lineNumber);

void MEXTIxSource(u8 EXTIx, u8 EXITsrc);

void MEXTI0_SetCallbackFun(void (*ptr)(void));

void MEXTI1_SetCallbackFun(void (*ptr)(void));
