/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								6 June,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: USART Configuration                                                        						              *
* ! File Name	: USART_Config.h                                                       							              	  *
* ! Description : This file has the USART Configuration setting      	          		  										  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: MCAL -Driver Layer-                  						                            			  		      *
**********************************************************************************************************************************/
#ifndef USART_USART_CONFIG_H_
#define USART_USART_CONFIG_H_

/*********************************************************************************************************************************/
/**************************************************ENABLE-DISABLE CONFIG**********************************************************/
/*********************************************************************************************************************************/
														/*CR1*/
/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable UART 																			         		  *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			USART_EN		ENABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable Transmission 																			          *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			T_EN			ENABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable Receiving 																			          *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			R_EN			ENABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable Parity Control 																			      *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			PARITY_EN		DISABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable Peripheral INT 																			      *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			PEINT_EN		DISABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable TX INT 																			         	  *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			TX_INT_EN		DISABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable RX INT 																			         	  *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			RX_INT_EN		DISABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable Peripheral Transmission complete (TC) INT 													  *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define				TCINT_EN		DISABLE

/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable IDLE INT 																			         	  *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			IDLE_INT_EN		DISABLE
														/*CR2*/
/**********************************************************************************************************************************
* MACRO		: 	To Enable/Disable CLOCK (Synch.) 																			      *
* options	:	ENABLE 		/		DISABLE																		  				  *
***********************************************************************************************************************************/
#define 			CLK_EN			DISABLE



/*********************************************************************************************************************************/
/**************************************************SETTING CONFIG*****************************************************************/
/*********************************************************************************************************************************/
														/*CR1*/
/**********************************************************************************************************************************
* MACRO		: 	To Select Parity type 																			         		  *
* options	:	EVEN 		/		ODD																		  					  *
***********************************************************************************************************************************/
#define 			PARITY_SELECTION	EVEN

/**********************************************************************************************************************************
* MACRO		: 	To Select OverSampling 																			         		  *
* options	:	OVER_SAMPLE_8 		/		OVER_SAMPLE_16																		  *
***********************************************************************************************************************************/
#define 			OVER_SAMPLE			OVER_SAMPLE_16

/**********************************************************************************************************************************
* MACRO		: 	To Select WORD DATA LENGHT  																			          *
* options	:	WORD_LENGHT_D8 		/		WORD_LENGHT_D9																		  *
***********************************************************************************************************************************/
#define 			WORD_LENGHT			WORD_LENGHT_D8

/**********************************************************************************************************************************
* MACRO		: 	To Send Break Char  																			          		  *
* options	:	YES 		/		NO																		  					  *
***********************************************************************************************************************************/
#define 			SEND_BREAK			NO

/**********************************************************************************************************************************
* MACRO		: 	Receiver Mute Mode  																			          		  *
* options	:	YES 		/		NO																		  					  *
***********************************************************************************************************************************/
#define 			RECEIVE_WAKEUP		NO
														/*CR2*/
/**********************************************************************************************************************************
* MACRO		: 	To Select STOP bit Config  																			          	  *
* options	:	STOP0_5 		/		STOP1		/		STOP1_5		/		STOP2											  *
***********************************************************************************************************************************/
#define 			STOP_BIT			STOP1

/**********************************************************************************************************************************
* MACRO		: 	To Select clock polarity  																			          	  *
* options	:	CLK_LOW_VALUE 		/		CLK_HIGH_VALUE																		  *
***********************************************************************************************************************************/
#define 			CLK_POLARITY	CLK_LOW_VALUE

/**********************************************************************************************************************************
* MACRO		: 	To Select clock polarity  																			          	  *
* options	:	FirstCLK_FirstCapture 		/		SecondCLK_FirstCapture														  *
***********************************************************************************************************************************/
#define 			CLK_PHASE		FirstCLK_FirstCapture



/*********************************************************************************************************************************/
/**************************************************** BUDE RATE ******************************************************************/
/*********************************************************************************************************************************/
/*
 *###########################################################################
 *for 9600 	  & OVER8=0	& 16 MHZ -> BUDE_RATE value = 0x683  				#
 *for 115200  & OVER8=0	& 16 MHZ -> BUDE_RATE value = 0x					#
 *###########################################################################
 */
#define BUDE_RATE		0x683



#endif /* USART_USART_CONFIG_H_ */