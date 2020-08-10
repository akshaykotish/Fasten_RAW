#include"Sensor.h"
#include "VL53L0X.h"
#include <Wire.h>

	int Echo;
	int Trig;
	long  duration, inches, cm;

		void Ultrasonic::set_Echo(int e)
		{
			Echo = e;
		}
		
		void Ultrasonic::set_Trig(int e)
		{
			Trig = e;
		}
		
		String Ultrasonic::get_duration()
		{
			return String(duration);
		}
		
		String Ultrasonic::get_inches()
		{
			return String(inches);
		}
   
		long microsecondsToInches(long microseconds) 
		{
      return microseconds / 74 / 2;
    }

    long microsecondsToCentimeters(long microseconds) 
    {
      return microseconds / 29 / 2;
    }
		String Ultrasonic::get_cm()
		{
			return String(cm);
		}
		
		void Ultrasonic::Run()
		{
			   digitalWrite(Trig, LOW);
			   delayMicroseconds(2);
			   digitalWrite(Trig, HIGH);
			   delayMicroseconds(10);
			   digitalWrite(Trig, LOW);
			   pinMode(Echo, INPUT);
			   duration = pulseIn(Echo, HIGH);
			   inches = microsecondsToInches(duration);
			   cm = microsecondsToCentimeters(duration);	   
			   delay(100);
		}

	int pirPin = 2;
	int pirState = 0;

	
	void IR::set_pirPin(int e)
	{
		pirPin = e;
	}
	
	void IR::set_pirState(int e)
	{
		pirState = e;
	}
	
	bool IR::Install()
	{   
		 pinMode(pirPin, INPUT);
		 return true;   

	}
	
	bool IR::Run()
	{   
		pirState = LOW;
		pirState = digitalRead(pirPin); 
		 if (pirState == HIGH) {
		  	return true;
		 } 
		return false;
	}
	String mm;
  VL53L0X lox;
	String Laser::Get_mm()
	{
		return mm;
	}
	
	bool Laser::Install()
	{
		Wire.begin();
		 lox.setTimeout(500);
		  if (!lox.init())
		  {
		    return false;
		  }
		  lox.startContinuous();
	}
	
	String Laser::Read_Ranger()
	{
		return String(lox.readRangeContinuousMillimeters());
	}
	
	bool Laser::Run()
	{
		  mm = lox.readRangeContinuousMillimeters();
		  
  		if (lox.timeoutOccurred()) {return false; }
		  
		  delay(100);  
		  return true;
	}
