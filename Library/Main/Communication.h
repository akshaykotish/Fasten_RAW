#ifndef COMUMNICATION_H
#define COMUMNICATION_H
	
#include<String.h>
//#include "BluetoothSerial.h"
//#include <ESP8266WiFi.h>
#include <SPI.h>
#include <WiFi.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#endif
	
	class Bluetooth{
		public:
			char Get_Incoming_Value();
			void set_bluetooth_pin(int e);
			bool Install();
			bool Run();
	};
	
	class ESP_Bluetooth{
		public:
			char get_Incoming_Value();
			void set_bluetooth_name(String e);
			bool Install();
			bool Run();
	};

	class WifiESP{
		public:
			void set_ssid(char e);
			void set_password(char e);
			String Get_IP();
			String Get_Data();
			bool Install();
			bool Run();
	};
	
	class wifi{
		public:
			void set_ssid(String e);
			void set_password(String e);
			String get_Signal_Strength();
			String get_ip();
			String get_data();
			bool Install();
			bool Write_to_Client(String e);
			bool Run();
	};

	class serial{
		public:
			void Install();
			void Write(int data);
			int Read();
	};
#endif
