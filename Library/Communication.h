#ifndef COMUMNICATION_H
#define COMUMNICATION_H
	
#include<iostream>
#include<string.h>
#include "BluetoothSerial.h"
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <WiFi.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
	
	class Bluetooth{
		public:
			char Get_Incoming_Value();
			void bluetooth_pin(int e);
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
			string Get_IP();
			string Get_Data();
			bool Install();
			bool Run();
	};
	
	class wifi{
		public:
			void set_ssid(char e[]);
			void set_password(char e[]);
			long get_Signal_Strength();
			string get_ip();
			string data();
			bool Install();
			bool Write_to_Client(string e);
			bool Run();
	};

	class serial{
		public:
			void Install();
			void Write(int data);
			int Read();
	}
#endif

