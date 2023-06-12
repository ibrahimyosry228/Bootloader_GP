/*********************includes*********************/
#include "../../UTIL/Types.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "Servo_Motor.h"
#include "Servo_Motor_Config.h"

void HServo_Init(void)
{
	/*set the output speed of the servo control pin to be low*/
	GPIO_PinConfig_t PinConfig;
	PinConfig.OutputSpeed = Speed_Low;

	/*set the servo control pin to be Alternate function output push pull*/
	PinConfig.PinMode = Mode_OutputAFPP;

	/*set the servo control pin number according to the config file*/
	PinConfig.PinNumber = Servo_ControlPin;
	MGPIO_Init(Servo_ControlPort, &PinConfig);
}

void HServo_Rotate(u16 Angle)
{
	/*set the servo control pin to be driven by PWM signal of frequency = Servo_Frequency, and duty cycle corresponding to the desired angle*/
	MTimer3_PWMInit(Servo_Frequency, Angle, Servo_ControlPort, Servo_ControlPin);
}
