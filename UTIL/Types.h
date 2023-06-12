#ifndef TYPES_H_
#define TYPES_H_


#define NULL (void*)(0x0)

typedef unsigned char           u8;
typedef signed   char           s8;
typedef unsigned short int      u16;
typedef signed   short int      s16;
typedef unsigned long  int      u32;
typedef signed   long  int      s32;
typedef unsigned long long int  u64;
typedef signed   long long int  s64;
typedef float                   f32;
typedef double                  f64;


typedef volatile unsigned char           v_u8;
typedef volatile signed   char           v_s8;
typedef volatile unsigned short int      v_u16;
typedef volatile signed   short int      v_s16;
typedef volatile unsigned long  int      v_u32;
typedef volatile signed   long  int      v_s32;
typedef volatile unsigned long long int  v_u64;
typedef volatile signed   long long int  v_s64;
typedef volatile float                   v_f32;
typedef volatile double                  v_f64;

typedef void (*PF)(void);

typedef enum
{
	OK,
	NOK,
	INDEX_OUT_OF_RANGE,
	NULL_POINTER
}
ERRORSTATUS;


#endif

