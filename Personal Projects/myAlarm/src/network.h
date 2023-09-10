#pragma once

#include <main.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>


// #define WIFI_SSID "SunnyVilleHome"
// #define WIFI_PASSWORD "SunnyVilleHome0803"
// #define WIFI_SSIDh "MARYAGUSSOLO@CelcomFibre"
// #define WIFI_PASSWORDh "ASFAMILY"
// #define WIFI_SSIDp "POCOM4Pro5G"
// #define WIFI_PASSWORDp "ke70ke30"
 

class WifiInitialize
{
 
   public:

  //  IPAddress local_IP{192, 168, 0, 88};
  //  IPAddress gateway{192, 168, 0, 254};
  //  IPAddress subnet{255, 255, 255, 0};
  //  IPAddress primaryDNS{8, 8, 8, 8};
  //  IPAddress secondaryDNS{8, 8, 4, 4};

   WifiInitialize()
   {
     
   }

  //  void setupWifi()
  //  {
    
  //   Serial.println("Connecting to WIFI");
  //   WiFi.mode(WIFI_STA);
  //   WiFi.persistent(false);
  //   WiFi.setAutoReconnect(true);
  //   WiFi.setSleep(false);
  //   WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  //   while (WiFi.status() != WL_CONNECTED)
  //   {
  //      Serial.print(".");
  //      delay(200);
  //      unsigned long currentTime = millis();
  //      unsigned long elapsedTime = currentTime - wifiRetry;
  //      if (elapsedTime >= interval)
  //      {
  //        WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  //        delay(100);
  //        wifiRetry = millis();
  //        currentTime = 0;
  //        elapsedTime - 0;
  //      }
  //   }
  //   Serial.println("Connected to IP:");
  //   delay(10);
  //   Serial.println(WiFi.localIP());
  //   delay(10);
  //  }


  void setupWifi(const char* SSID, const char* PASS)
   {
    
    restart = millis();
    wifiRetry = millis();
    Serial.println("Connecting to WIFI");
    WiFi.mode(WIFI_STA);
    WiFi.persistent(false);
    WiFi.setAutoReconnect(true);
    WiFi.setSleep(false);
    WiFi.begin(SSID, PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
       Serial.print(".");
       delay(200);
       unsigned long currentTime = millis();
       unsigned long elapsedTime = currentTime - wifiRetry;
       unsigned long elapsedTime2 = currentTime - restart;
       if (elapsedTime2 >= restart_interval)
       {
          esp_restart();
       }

       if (elapsedTime >= interval)
       {
         WiFi.begin(SSID, PASS);
         delay(100);
         wifiRetry = millis();
         currentTime = 0;
         elapsedTime = 0;
       }
    
    }
    Serial.println("Connected to IP:");
    delay(10);
    Serial.println(WiFi.localIP());
    delay(10);
   }

   String getIP()
   {
     
     String IP = WiFi.localIP().toString();
     return IP;

   }

  //  bool checkstatus()
  //  {
  //    if(WiFi.status() == WL_CONNECTED)
  //    {
  //      return true;
  //    }
  //    else if (WiFi.status() != WL_CONNECTED)
  //    {
  //      Serial.println("Retrying to connect WIFI");
  //      WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  //      while (WiFi.status() != WL_CONNECTED)
  //      {
  //          Serial.print(".");
  //          delay(200);
  //      }
  //      Serial.println("Connected to IP:");
  //      delay(10);
  //      Serial.println(WiFi.localIP());
  //      delay(10);

  //    }
     
  //    return false;

  //  }

   bool connectWifiRequest(bool on)
   {
     if (on == true)
     {
      return true;
     }
     else return false;
   }
   
   bool isConnected()
   {
     if (WiFi.status() == WL_CONNECTED)
     {
      return true;
     }
     else return false;
   }

   private:
   unsigned long wifiRetry;
   unsigned long interval = 20000;
   unsigned long restart;
   unsigned long restart_interval = 40000;
 
  
};

class getWhether

{

  public:

  getWhether()
  {
    startTime = millis();
  }
   
  void getResponseWIFI(float LAT, float LONG)
  {
     
     http.begin(URL + "lat=" + LAT + "&lon=" + LONG + "&units=metric&appid=" + WHEATHERKEY);
     httpCode = http.GET();

     if (httpCode > 0) {

      String JSON_Data = http.getString();

      DynamicJsonDocument doc(2048); 
      deserializeJson(doc, JSON_Data);
      JsonObject obj = doc.as<JsonObject>(); 

      const char* description = obj["weather"][0]["description"].as<const char*>();
      const float temp = obj["main"]["temp"].as<float>();
      const float humidity = obj["main"]["humidity"].as<float>();

      Serial.println(description);
      Serial.println(temp);
      Serial.println(humidity);
      delay(100);
  }

  else 
  {
      Serial.println("Error!");
  
  }
  http.end();

  }


  void getTime()
  {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - startTime;
    
    if (elapsedTime >= interval)
    {
    if (httpCode > 0) 
    {
      
      String JSON_Data = http.getString();

      DynamicJsonDocument doc(2048); 
      deserializeJson(doc, JSON_Data);
      JsonObject obj = doc.as<JsonObject>(); 

      const long timezoneOffset = obj["timezone"].as<long>();
      const long currentTime = obj["dt"].as<long>();

      const long currentLocalTime = currentTime + timezoneOffset;

      struct tm timeinfo;
      gmtime_r(&currentLocalTime, &timeinfo);
      char timeString[30];
      strftime(timeString, sizeof(timeString), "%A, %B %d %Y %H:%M:%S", &timeinfo);
      delay(100);
      Serial.println(timeString);
    }
    startTime = millis();
    currentTime = 0;
    elapsedTime = 0;
    }

  }


  void getRealTime()
  {
     
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - startTime;
    
    if (elapsedTime >= interval)
    {
     http.begin(URL + "lat=" + latitude + "&lon=" + longtitude + "&units=metric&appid=" + WHEATHERKEY);
     httpCode = http.GET();

     if (httpCode > 0)
     {

      String JSON_Data = http.getString();

      DynamicJsonDocument doc(2048); 
      deserializeJson(doc, JSON_Data);
      JsonObject obj = doc.as<JsonObject>(); 

      const long timezoneOffset = obj["timezone"].as<long>();
      const long currentTime = obj["dt"].as<long>();
      const long currentLocalTime = currentTime + timezoneOffset;
      delay(100);

      struct tm timeinfo;
      gmtime_r(&currentLocalTime, &timeinfo);
      char timeString[30];
      strftime(timeString, sizeof(timeString), "%A, %B %d %Y %H:%M:%S", &timeinfo);
      delay(100);
      Serial.println(timeString);
     }
    else 
    {
      Serial.println("Error!");
    }
    startTime = millis();
    currentTime = 0;
    elapsedTime = 0;
    }
    
  http.end();

  }

  

  private:

  HTTPClient http;
  int httpCode;
  unsigned long startTime;
  unsigned long interval = 20000;
  String URL = "https://api.openweathermap.org/data/2.5/weather?";
  String WHEATHERKEY = "d55e167341b2fbcee5eac620f2854cf1";
  String latitude = "5.320078266477039";
  String longtitude = "100.47410605598543";
  

};

class GSM 
{

  protected:
  SoftwareSerial sim800{19, 21};
  
  public:
  
  void initGSM()
  {
    
    sim800.begin(4800);
    
    sendATCommand("AT+CSQ");
    updateSerial();
    sendATCommand("AT+CCID");
    updateSerial();
    sendATCommand("AT+CREG?");
    updateSerial();
    sendATCommand("AT+SAPBR=3,1,CONTYPE,GPRS");
    updateSerial();
    sendATCommand("AT+SAPBR=3,1,APN,XOX");
    updateSerial();
    sendATCommand("AT+SAPBR=1,1");
    updateSerial();
    sendATCommand("AT+SAPBR=2,1");
    updateSerial();
  }

  
  void postSingleData(int val, String path)
  {
  
   int maxRetries = 5;
   for (int retry = 0; retry < maxRetries; retry++)
   {
   sendATCommand("AT+HTTPTERM");
   updateSerial();
   sendATCommand("AT+HTTPINIT");
   updateSerial();
   sendATCommand("AT+HTTPPARA=CID,1");
   updateSerial();
   String val_ = String(val);
   String URL = "https://us-central1-myalarm-66cd2.cloudfunctions.net/upload?" + path + "=" + val_;
   sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
   updateSerial();
   sendATCommand("AT+HTTPPARA=REDIR,1");
   updateSerial();
   sendATCommand("AT+HTTPSSL=1");
   updateSerial();

   sim800.setTimeout(7000);
   sendATCommand("AT+HTTPACTION=1"); // USE GET AS FUNCTION IS PROGRAM LIKE THAT
  
  if (verifyReq("200", 6000) == true) 
  {
    sim800.setTimeout(500);
    break; 
  } 
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  }

  }

  void onBootUp()
  {
  
   int maxRetries = 5;
   for (int retry = 0; retry < maxRetries; retry++)
   {
   sendATCommand("AT+HTTPTERM");
   updateSerial();
   sendATCommand("AT+HTTPINIT");
   updateSerial();
   sendATCommand("AT+HTTPPARA=CID,1");
   updateSerial();
   String URL = "https://us-central1-myalarm-66cd2.cloudfunctions.net/upload?APP>ONBOOTUP=1";
   sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
   updateSerial();
   sendATCommand("AT+HTTPPARA=REDIR,1");
   updateSerial();
   sendATCommand("AT+HTTPSSL=1");
   updateSerial();

   sim800.setTimeout(7000);
   sendATCommand("AT+HTTPACTION=1"); // USE POST AS FUNCTION IS PROGRAM LIKE THAT
  
  if (verifyReq("200", 6000) == true) 
  {
    sim800.setTimeout(500);
    break; 
  } 
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  }

  }


  void postMultiData(String path)
  {
  
   int maxRetries = 5;
   for (int retry = 0; retry < maxRetries; retry++)
   {
   sendATCommand("AT+HTTPTERM");
   updateSerial();
   sendATCommand("AT+HTTPINIT");
   updateSerial();
   sendATCommand("AT+HTTPPARA=CID,1");
   updateSerial();
   String URL = "https://us-central1-myalarm-66cd2.cloudfunctions.net/upload?" + path;
   sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
   updateSerial();
   sendATCommand("AT+HTTPPARA=REDIR,1");
   updateSerial();
   sendATCommand("AT+HTTPSSL=1");
   updateSerial();

   sim800.setTimeout(7000);
   sendATCommand("AT+HTTPACTION=1"); // USE GET AS FUNCTION IS PROGRAM LIKE THAT
  
  if (verifyReq("200", 6000) == true) 
  {
    sim800.setTimeout(500);
    break; 
  } 
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  }

  }

  void postStringData(String val, String path)
  {
  
   int maxRetries = 5;
   for (int retry = 0; retry < maxRetries; retry++)
   {
   sendATCommand("AT+HTTPTERM");
   updateSerial();
   sendATCommand("AT+HTTPINIT");
   updateSerial();
   sendATCommand("AT+HTTPPARA=CID,1");
   updateSerial();
   String URL = "https://us-central1-myalarm-66cd2.cloudfunctions.net/upload/" + path + "=" + val;
   sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
   updateSerial();
   sendATCommand("AT+HTTPPARA=REDIR,1");
   updateSerial();
   sendATCommand("AT+HTTPSSL=1");
   updateSerial();

   sim800.setTimeout(7000);
   sendATCommand("AT+HTTPACTION=0"); // USE GET AS FUNCTION IS PROGRAM LIKE THAT

  if (verifyReq("200", 6000) == true) 
  {
    sim800.setTimeout(500);
    break; 
  } 
  sendATCommand("AT+HTTPTERM");
  updateSerial();
  }

  }


  
  void end()
  {
    sim800.end();
  }

  void stopHttp()
  {
    sendATCommand("AT+HTTPTERM");
    delay(1000);
  }
  
  int getData(String path)
  {
   
  int value = 0;
  sendATCommand("AT+HTTPTERM");
  updateSerial();
  sendATCommand("AT+HTTPINIT");
  updateSerial();
  sendATCommand("AT+HTTPPARA=CID,1");
  updateSerial();
  String URL = "https://myalarm-66cd2-default-rtdb.asia-southeast1.firebasedatabase.app/" + path + ".json";
  sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
  updateSerial();
  sendATCommand("AT+HTTPPARA=\"REDIR\",1");
  updateSerial();
  sendATCommand("AT+HTTPSSL=1");
  updateSerial();

  sim800.setTimeout(5000);
  sendATCommand("AT+HTTPACTION=0");
  if (verifyReq("200", 6000) == true)
  {
   sim800.println("AT+HTTPREAD");
    if (verifyReq("+HTTPREAD", 1000) == true)
    {
      //Serial.println("YES WE ENTERED");
      String get = sim800.readString();
      String val = extractValue(getString());
      value = val.toInt();
      //Serial.println("HERE VAL IS :" + val);
      sim800.setTimeout(10);
    }
  }
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  return value;

  }
  
  bool getBoolData(String path)
  {
   
  int value = 0;
  sendATCommand("AT+HTTPTERM");
  updateSerial();
  sendATCommand("AT+HTTPINIT");
  updateSerial();
  sendATCommand("AT+HTTPPARA=CID,1");
  updateSerial();
  String URL = "https://myalarm-66cd2-default-rtdb.asia-southeast1.firebasedatabase.app/" + path + ".json";
  sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
  updateSerial();
  sendATCommand("AT+HTTPPARA=\"REDIR\",1");
  updateSerial();
  sendATCommand("AT+HTTPSSL=1");
  updateSerial();
  
  sim800.setTimeout(5000);
  sendATCommand("AT+HTTPACTION=0");
  if (verifyReq("200", 6000) == true)
  {
   sim800.println("AT+HTTPREAD");
    if (verifyReq("+HTTPREAD", 1000) == true)
    {
      //Serial.println("YES WE ENTERED");
      String get = sim800.readString();
      String val = extractValue(getString());
      value = val.toInt();
      if (value == 1)
      {
        return true;
      }
       if (value == 0)
      {
        return false;
      }
      //Serial.println("HERE VAL IS :" + val);
      sim800.setTimeout(10);
    }
  }
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  }
  
  
  bool setAllowed()
  {
   
  int value = 0;
  sendATCommand("AT+HTTPTERM");
  updateSerial();
  sendATCommand("AT+HTTPINIT");
  updateSerial();
  sendATCommand("AT+HTTPPARA=CID,1");
  updateSerial();
  String URL = "https://myalarm-66cd2-default-rtdb.asia-southeast1.firebasedatabase.app/APP/POSTDATA/POSTALLOWED.json";
  sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
  updateSerial();
  sendATCommand("AT+HTTPPARA=\"REDIR\",1");
  updateSerial();
  sendATCommand("AT+HTTPSSL=1");
  updateSerial();
  sim800.setTimeout(5000);
  sendATCommand("AT+HTTPACTION=0");
  if (verifyReq("200", 6000) == true)
  {
   sim800.println("AT+HTTPREAD");
    if (verifyReq("+HTTPREAD", 1000) == true)
    {
      //Serial.println("YES WE ENTERED");
      String get = sim800.readString();
      String val = extractValue(getString());
      value = val.toInt();
      if (value == 1)
      {
        return true;
      }
       if (value == 0)
      {
        return false;
      }
      //Serial.println("HERE VAL IS :" + val);
      sim800.setTimeout(10);
    }
  }
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  }


  String getStringData(String path)
  {

  String val; 
  sendATCommand("AT+HTTPTERM");
  updateSerial();
  sendATCommand("AT+HTTPINIT");
  updateSerial();
  sendATCommand("AT+HTTPPARA=CID,1");
  updateSerial();
  String URL = "https://myalarm-66cd2-default-rtdb.asia-southeast1.firebasedatabase.app/" + path + ".json";
  sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
  updateSerial();
  sendATCommand("AT+HTTPPARA=\"REDIR\",1");
  updateSerial();
  sendATCommand("AT+HTTPSSL=1");
  updateSerial();

  sim800.setTimeout(5000);
  sendATCommand("AT+HTTPACTION=0");
  if (verifyReq("200", 6000) == true)
  {
   sim800.println("AT+HTTPREAD");
    if (verifyReq("+HTTPREAD", 1000) == true)
    {
      //Serial.println("YES WE ENTERED");
      String get = sim800.readString();
      val = extractValue(getString());
      //Serial.println("HERE VAL IS :" + val);
      sim800.setTimeout(10);
    }
  }
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  return val;

  }

  String getRawStringData(String path)
  {

  String get;
  sendATCommand("AT+HTTPTERM");
  updateSerial();
  sendATCommand("AT+HTTPINIT");
  updateSerial();
  sendATCommand("AT+HTTPPARA=CID,1");
  updateSerial();
  String URL = "https://myalarm-66cd2-default-rtdb.asia-southeast1.firebasedatabase.app/" + path + ".json";
  sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
  updateSerial();
  sendATCommand("AT+HTTPPARA=\"REDIR\",1");
  updateSerial();
  sendATCommand("AT+HTTPSSL=1");
  updateSerial();
  sim800.setTimeout(5000);
  sendATCommand("AT+HTTPACTION=0");
  if (verifyReq("200", 6000) == true)
  {
   sim800.println("AT+HTTPREAD");
    if (verifyReq("+HTTPREAD", 1000) == true)
    {
      get = getString();
      sim800.setTimeout(10);
      
    }
  }
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  return get;

  }

  bool AppOn()
  {
  
  
  int value = 0;
  sendATCommand("AT+HTTPTERM");
  updateSerial();
  sendATCommand("AT+HTTPINIT");
  updateSerial();
  sendATCommand("AT+HTTPPARA=CID,1");
  updateSerial();
  String URL = "https://myalarm-66cd2-default-rtdb.asia-southeast1.firebasedatabase.app/APP/APPSTATE.json";
  sendATCommand("AT+HTTPPARA=\"URL\",\"" + URL + "\"");
  updateSerial();
  sendATCommand("AT+HTTPPARA=\"REDIR\",1");
  updateSerial();
  sendATCommand("AT+HTTPSSL=1");
  updateSerial();
  sim800.setTimeout(5000);
  sendATCommand("AT+HTTPACTION=0");
  if (verifyReq("200", 6000) == true)
  {
   sim800.println("AT+HTTPREAD");
    if (verifyReq("+HTTPREAD", 1000) == true)
    {
      String get = sim800.readString();
      String val = extractValue(getString());
      value = val.toInt();
      if (value == 1)
      {
        return true;
      }
      else return false;
      sim800.setTimeout(10);
    }
  }
  sendATCommand("AT+HTTPTERM");
  updateSerial();

  }

   
  protected:
  String GLOBALSTRING;

  String getString() 
  {
  return GLOBALSTRING;
  }


  private:

  void sendATCommand(String command) 
  {
  sim800.println(command);
  }

  bool verifyReq(String findWhat, unsigned long timeout)

 {
  unsigned long time = millis();
  String c;
  while (!sim800.available())
  {  
  c = sim800.readString();
  int index = c.indexOf(findWhat);
  if (index != -1)
  {
    storeString(c);
    //Serial.print("We found the command :");
    Serial.println(c);
    return true;
  }
  if (millis() - time >= timeout)
  {
    //Serial.print("NOT FOUND");
    return false;
  }
  }
 }

  void updateSerial() 
 {
 vTaskDelay(500);
 while (sim800.available()) 
 {
  Serial.write(sim800.read());
 }
 }

  String extractValue(String response) 
  {
  int valueStart = response.indexOf("{") + 1;
  int valueEnd = response.indexOf("}", valueStart);
  String value = response.substring(valueStart, valueEnd);
  return value;
  }

  void storeString(const String &str) 
  {
  GLOBALSTRING = str;
  }
  
  
};





