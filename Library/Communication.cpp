#include<"Communication.h">


	char Incoming_value = 0;  
	int bluetooth_pin;
	
	char Bluetooth::Get_Incoming_Value()
	{
		return Incoming_value;
	}
	
	void Bluetooth::bluetooth_pin(int e)
	{
		bluetooth_pin = e;
	}
	
	bool Bluetooth::Install()
	{
  		Serial.begin(9600);  
		 pinMode(bluetooth_pin;, OUTPUT); 
	}
	
	bool Bluetooth::Run()
	{
		if(Serial.available() > 0)  
		  {
		    Incoming_value = Serial.read();
		    Serial.print(Incoming_value);
		    Serial.print("\n");
		 		return true;
		 }         
		 return false;
	}


	char Incoming_value = 0; 
	string bluetooth_Name;
	
	char ESP_Bluetooth::get_Incoming_Value()
	{
		return Incoming_value;
	}
	
	void ESP_Bluetooth::set_bluetooth_name(String e)
	{
		bluetooth_Name = e;
	}
	
	
	BluetoothSerial SerialBT;

	bool ESP_Bluetooth::Install()
	{
		SerialBT.begin(bluetooth_Name); 
	}
	
	bool ESP_Bluetooth::Run()
	{
		if (SerialBT.available()) {
    		Incoming_value = (char)SerialBT.read();
    		delay(100);
    		return true;
    	}
		 return false;
	}

	const char* ssid = "SSID";
	const char* password = "PASSWORD";
	
	string Ip = "";
	string data = "";
	
	WiFiServer server(80);
	
	
	void WifiESP::set_ssid(char e)
	{
		ssid = e;
	}
	
	void WifiESP::set_password(char e)
	{
		password = e;
	}
	
	string WifiESP::Get_IP()
	{
		return Ip;
	}
	
	string WifiESP::Get_Data()
	{
		return data;
	}
		
	bool WifiESP::Install()
	{
		WiFi.begin(ssid, password); 
		while (WiFi.status() != WL_CONNECTED) {
			delay(500);
		}
		
	  	Ip = String(WiFi.localIP());
		return true;
	}
	
	bool WifiESP::Run()
	{
		if(Serial.available>0){
		    data = Serial.read();
		    return true;
		}
		 return false;
	}


	char ssid[] = "yourNetwork"; 
	char pass[] = "secretPassword";
	int keyIndex = 0;
	int status = WL_IDLE_STATUS;
	char server[] = "www.fasten.com";
	WiFiClient client;
	long signal_strength;
	string ip;
	int port;
	string data;
	
		
	void wifi::set_ssid(char e[])
	{
		ssid=  e;
	}
	
	void wifi::set_password(char e[])
	{
		pass = e;
	}
	
	long wifi::get_Signal_Strength()
	{
		return signal_strength;
	}
		
	string wifi::get_ip()
	{
		return ip;
	}
	
	string wifi::data()
	{
		return data;
	}
		
	bool wifi::Install()
	{
		if (WiFi.status() == WL_NO_SHIELD) {
		    return false;
		  }
		  
		  String fv = WiFi.firmwareVersion();
		  
		  while (status != WL_CONNECTED) {
		    status = WiFi.begin(ssid, pass);
		    delay(10000);
		  }
		ip = String(WiFi.localIP());
		signal_strength = WiFi.RSSI();
		if (!client.connect(server, port)) {
			return false;
		}
		return true;
	}
	
	bool wifi::Write_to_Client(string e)
	{
		if (client.available()) {
			client.println(e);
			return true;
		}
		return false;
	}
	
	bool wifi::Run()
	{
		while (client.available()) {
		    char c = client.read();
		    data = data + c;
		  }
		  
		if (!client.connected()) {
				client.stop();
				return false;
		}
		  return true;
	}
	

	int baud_rate = 9600;
	int pin;
	int inByte;
	
	public:
		void serial::Install()
		{
			Serial.begin(baud_rate);
			pinMode(pin, OUTPUT);
		}
		
		void serial::Write(int data)
		{
			if(Serial.available() > 0)
			{
				Serial.write(data);
			}
		}
		
		int serial::Read()
		{
			if(Serial.available() > 0)
			{
				inByte = Serial.read();
			}
			return inByte;
		}
