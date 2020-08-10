#include "Stepper.h"
#include "Servo.h"
#include"Motors.h"

	int angle = 0;
	int pin = 0;
	
	Servo servo;
	void Servo_Control::set_angle(int e)
	{
		angle = e;
	}
	void Servo_Control::set_pin(int e)
	{
		pin = e;
	}
	
	void Servo_Control::attach()
	{
		servo.attach(pin);
	}
	
	void Servo_Control::Write()
	{
		servo.write(angle);
	}
	
	void Servo_Control::Write(int angle)
	{
		servo.write(angle);
	}
	
	void Servo_Control::Write(int angle, int pin)
	{
		servo.attach(pin);
		servo.write(angle);
	}

	
	int steps = 0;
	int count = 0;
	
	int pin_A = 1;
	int pin_B = 2;
	int pin_C = 3;
	int pin_D = 4;
	int pin_E = 5;
	
	int speed = 10;
	
	void Stepper_Control::Set_Steps(int e)
	{
		steps = e;
	}
	
	void Stepper_Control::Set_Pin(int A, int B)
	{
		pin_A = A;
		pin_B = B;
	}
	
	void Stepper_Control::Set_Pin(int A, int B, int C, int D)
	{
		pin_A = A;
		pin_B = B;
		pin_C = C;
		pin_D = D;
	}
	
	void Stepper_Control::Set_Pin(int A, int B, int C, int D, int E)
	{
		pin_A = A;
		pin_B = B;
		pin_C = C;
		pin_D = D;
		pin_E = E;
	}
	
	void Stepper_Control::Set_Speed(int e)
	{
		speed = e;
	}
	
	void Stepper_Control::for_2_pin()
	{
		Stepper myStepper(steps, pin_A, pin_B);
		myStepper.setSpeed(speed);
		myStepper.step(steps/100);
	}
	
	void Stepper_Control::for_4_pin()
	{
		Stepper myStepper(steps, pin_A, pin_B, pin_C, pin_D);
		myStepper.setSpeed(speed);
		myStepper.step(steps/100);
	}
	
	void Stepper_Control::for_5_pin()
	{
		Stepper myStepper(steps, pin_A, pin_B, pin_C, pin_D, pin_E);
		myStepper.setSpeed(speed);
		myStepper.step(steps/100);
	}
	
