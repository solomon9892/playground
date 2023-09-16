#pragma once

//========LIBRARIES========
#include <Arduino.h>
#include <stdlib.h>
#include <vector>
#include <array>
#include <algorithm>
#include <ESPmDNS.h>
#include <MedianFilterLib.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <time.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <EEPROM.h>
#include <esp_task_wdt.h>


//====GLOBALDECLARATIONS====

enum STATE 
{
   ON = 0, OFF = 1
};


//========CLASS========

//#include <Firebase.h>
#include <network.h>
#include <senseEngine.h>
#include <horn.h>


using namespace std;

GSM sim;
WifiInitialize wifi;
//FirebaseInitialization firebase; //NOT IN USE
getWhether whether;
sensorInitialization<int> sensorFR {19, 18, STATE::OFF}; // {TRIGGERPIN, ECHOPIN, STATE}
TaskHandle_t background_task;
TaskHandle_t main_task;
SemaphoreHandle_t classMutex;
AsyncWebServer server(80);
horn pressMe {13}; 
GPS GP;
DOPPLER dopp1;
StaticJsonDocument<512> jsonDoc;


///////////////////////////////////////////////GLOBAL DECLARATION/////////////////////////////////////////////////////////////
 
bool isConnected = false;

 //////////////////////////////////////////////STATIC_EEPROM_ADRESSES/////////////////////////////////////////////////////////

const int APPON_ADRRESS = 5;
const int WIFI_ENABLE_ADRRESS = 28;


const int GPSLAT_ADRRESS = 51;
const int GPSLONG_ADRRESS = 52;
// const int LOWERANGE= 53;
// const int UPPERANGE = 54;
// const int BEEPS = 55;
// const int ARMED = 56;
// const int SENSORSTATEFL = 57;
// const int SENSORSTATEFR = 58;
// const int SENSORSTATEBL = 59;
// const int SENSORSTATEBR = 60;
// const int MODES = 61;
// const int ALARMONOFF = 62;
// const int SENSITIVITY = 63;



