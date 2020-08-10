#include<"Sensor.h">

	int Echo;
	int Trig;
	long duration, inches, cm;
	
	public:
		void Ultrasonic::set_Echo(int e)
		{
			Echo = e;
		}
		
		void Ultrasonic::set_Trig(int e)
		{
			Trig = e;
		}
		
		long Ultrasonic::get_duration()
		{
			return duration;
		}
		
		long Ultrasonic::get_inches()
		{
			return inches;
		}
		
		long Ultrasonic::get_cm()
		{
			return cm;
		}
		
		void Ultrasonic::Run()
		{
			   digitalWrite(pingPin, LOW);
			   delayMicroseconds(2);
			   digitalWrite(pingPin, HIGH);
			   delayMicroseconds(10);
			   digitalWrite(pingPin, LOW);
			   pinMode(echoPin, INPUT);
			   duration = pulseIn(echoPin, HIGH);
			   inches = microsecondsToInches(duration);
			   cm = microsecondsToCentimeters(duration);	   
			   delay(100);
		}

	int pirPin = 2;
	int pirStat = 0;
	
	public:
	
	void IR::set_pirPin(int e)
	{
		pirPin = e;
	}
	
	void IR::set_pirStat(int e)
	{
		pirStat = e;
	}
	
	bool IR::Install()
	{   
		 pinMode(pirPin, INPUT);
		 return true;   

	}
	
	bool IR::Run()
	{   
		pirState = LOW;
		pirStat = digitalRead(pirPin); 
		 if (pirStat == HIGH) {
		  	return true;
		 } 
		return false;
	}
	
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
long mm;

public:
	long Laser::Get_mm()
	{
		return mm;
	}
	
	bool Laser::Install()
	{
		if (!lox.begin()) {
		   return false;
		  }
	}
	
	long Laser::Read_Ranger()
	{
		return (long)vl.readRange();
	}
	
	bool Laser::Run()
	{
		 VL53L0X_RangingMeasurementData_t measure;
    
		  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
		
		  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
		    Serial.print("Distance (mm): "); 
		    mm = (long)measure.RangeMilliMeter;
		  	return true;
		  } 	
		  
		  delay(100);  
		  return false;
	}
