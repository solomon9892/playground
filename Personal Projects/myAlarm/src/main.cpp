#include <main.h>

//============================================FUNCTIONS==================================================

void startServer()
{
server.onNotFound(
    [](AsyncWebServerRequest *request)
    {
      request->send(404, "NOT FOUND");
    });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    
    AsyncResponseStream *response = request->beginResponseStream("text/html");

    response->printf(R"(
      <html>
        <head>
          <title>Landing Page</title>
          <style>
            body {
              background-color: white;
              font-family: Arial, Sans-Serif;
            }
          </style>
        </head>
        <body>
          <h1>MY_ALARM</h1>
          <p>
            IF YOU ABLE TO SEE THIS MSG, IT MEANS YOU ARE CONNECTED TO YOUR ALARM SYSTEM (yourIP)/update
          </p>
        </body>
      </html>
    )");

    request->send(response);

  });
  AsyncElegantOTA.begin(&server);
  server.begin();
    
}

bool localCheck(int address, int expect)
{
  int check;
  EEPROM.get(address, check);
  if (check == expect)
  {
    return true;
  }
  else return false;
  
}

void putCommit(int address, const int data)
{
   EEPROM.put(address, data);
   EEPROM.commit();
}

void putCommit(int address, const float data)
{
   EEPROM.put(address, data);
   EEPROM.commit();
}

String removeDots(String input) {
  String result = "";

  for (int i = 0; i < input.length(); i++) {
    char c = input.charAt(i);
    if (c != '.') {
      result += c;
    }
  }

  return result;
}

void parseJsonResponse(String jsonResponse) {

jsonDoc.clear();
jsonResponse.trim();
jsonResponse.replace("+HTTPREAD:","");
jsonResponse.replace("OK", "");
jsonResponse.trim();
String x = jsonResponse.substring(4);

DeserializationError error = deserializeJson(jsonDoc, x);
if (error) {
   Serial.print("Error parsing JSON: ");
   Serial.println(error.c_str());
  return;
}

//Serial.println(x);

}

String removeCurly(String response) 
  {
  int valueStart = response.indexOf("{") + 1;
  int valueEnd = response.indexOf("}", valueStart);
  String value = response.substring(valueStart, valueEnd);
  return value;
  }

void preset()
{
  parseJsonResponse(sim.getRawStringData("PRESETS"));
  int  PRESET_LOWERANGE_VAL   = removeCurly(jsonDoc["SETDETECTIONRANGE"]["LOWERANGE"].as<String>()).toInt();
  int  PRESET_UPPERANGE_VAL   = removeCurly(jsonDoc["SETDETECTIONRANGE"]["UPPERANGE"].as<String>()).toInt();
  int  PRESET_ARMED_VAL       = removeCurly(jsonDoc["ARMED"].as<String>()).toInt();
  int  PRESET_ALARMONOFF_VAL  = removeCurly(jsonDoc["ALARMONOFF"].as<String>()).toInt();
  int  PRESET_BEEPCOUNT       = removeCurly(jsonDoc["BEEPCOUNT"].as<String>()).toInt();
  int  PRESET_MODE_GEAR       = removeCurly(jsonDoc["MODEGEAR"].as<String>()).toInt();
  int  PRESET_SENSITIVITY_VAL = removeCurly(jsonDoc["SENSORSENSITIVITY"].as<String>()).toInt();
  int  PRESET_FLSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEFL"].as<String>()).toInt();
  int  PRESET_FRSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEFR"].as<String>()).toInt();
  int  PRESET_BLSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEBL"].as<String>()).toInt();
  int  PRESET_BRSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEBR"].as<String>()).toInt();

  //PRESET OPERATIONS
  //sensorFR.setRange(PRESET_LOWERANGE_VAL, PRESET_UPPERANGE_VAL);

}

void loopMain (void * parameter)
{

  for(;;)
  {
  
 
  ///////////////////////////////////////////////////APPON_STATE///////////////////////////////////////////////////////////////
  
  // if (localCheck(APPON_ADRRESS, 1) == true || sim.AppOn() == true )
  // {

  // xSemaphoreTake(classMutex, portMAX_DELAY); 
  //  Serial.println("IM ON"); 
  //  putCommit(APPON_ADRRESS, 1);
   
   
  // ///////////////////////////////////////////////////WIFI_CHECK///////////////////////////////////////////////////////////////////////
  // if(localCheck(WIFI_ENABLE_ADRRESS, 1) == true || wifi.connectWifiRequest(sim.getBoolData("APP/WIFI/CONNECT"))  == true)
  //    {
    
  //     putCommit(WIFI_ENABLE_ADRRESS, 1);
  //     parseJsonResponse(sim.getRawStringData("APP/WIFI"));
      
  //     //FEATURE ADD ON: STATUS BAR TO SHOW CONNECTING TO WIFI
  //     /*{

  //      }*/

  //     if (wifi.isConnected() == false)
  //       {

  //       String WIFISSID = removeCurly(jsonDoc["SSID"].as<String>());
  //       String WIFIPASS = removeCurly(jsonDoc["PASS"].as<String>());

  //       const char *WIFISSIDCONVERT = WIFISSID.c_str();
  //       const char *WIFIPASSCONVERT = WIFIPASS.c_str();

  //       wifi.setupWifi(WIFISSIDCONVERT,WIFIPASSCONVERT);

  //       String IP = removeDots(wifi.getIP());
        
  //       sim.postStringData(IP, "IP");

  //       if (wifi.isConnected() == true)
  //       {
  //         startServer();
  //       }

  //       for(;;)
  //       {
  //         if (sim.getBoolData("APP/WIFI/DISCONNECT") == true)
  //         {
  //           WiFi.disconnect(true);
  //           putCommit(WIFI_ENABLE_ADRRESS, 0);
  //           break;
  //         }
  //       }

  //         //FEATURE ADD ON: STATUS BAR TO SHOW PROGRAM MODE
  //         /*{

  //          }*/
  //        }
     
  //    //TURN OF APP AFTER OPERATION
  //    putCommit(APPON_ADRRESS, 0);
  //    }

  // //////////////////////////////////////////GET_DATA//////////////////////////////////////////////////////////////////////////
  
  // if (sim.getBoolData("APP/GETDATA/GETALLOWED") == true)
  // {
  //   Serial.print("HAD ENTER HERE TO PROGRAM");

  //   parseJsonResponse(sim.getRawStringData("APP/GETDATA"));

  //   //String appState = jsonDoc["APPSTATE"].as<String>();
  //   int  LOWERANGE_VAL   = removeCurly(jsonDoc["SETDETECTIONRANGE"]["LOWERANGE"].as<String>()).toInt();
  //   int  UPPERANGE_VAL   = removeCurly(jsonDoc["SETDETECTIONRANGE"]["UPPERANGE"].as<String>()).toInt();
  //   int  ARMED_VAL       = removeCurly(jsonDoc["ARMED"].as<String>()).toInt();
  //   int  ALARMONOFF_VAL  = removeCurly(jsonDoc["ALARMONOFF"].as<String>()).toInt();
  //   int  BEEPCOUNT       = removeCurly(jsonDoc["BEEPCOUNT"].as<String>()).toInt();
  //   int  MODE_GEAR       = removeCurly(jsonDoc["MODEGEAR"].as<String>()).toInt();
  //   int  SENSITIVITY_VAL = removeCurly(jsonDoc["SENSORSENSITIVITY"].as<String>()).toInt();
  //   int  FLSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEFL"].as<String>()).toInt();
  //   int  FRSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEFR"].as<String>()).toInt();
  //   int  BLSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEBL"].as<String>()).toInt();
  //   int  BRSTATE         = removeCurly(jsonDoc["SENSORSTATE"]["SENSORSTATEBR"].as<String>()).toInt();

  //   //Serial.println("LOWERANGE IS " + String(LOWERANGE));

  //   // putCommit(LOWERANGE, LOWERANGE_VAL);
  //   // putCommit(UPPERANGE, UPPERANGE_VAL);
  //   // putCommit(ARMED, ARMED_VAL);
  //   // putCommit(ALARMONOFF, ALARMONOFF_VAL);
  //   // putCommit(BEEPS, BEEPCOUNT);
  //   // putCommit(MODES, MODE_GEAR);
  //   // putCommit(SENSITIVITY, SENSITIVITY_VAL);
  //   // putCommit(SENSORSTATEFL, FLSTATE);
  //   // putCommit(SENSORSTATEFR, FRSTATE);
  //   // putCommit(SENSORSTATEBL, BLSTATE);
  //   // putCommit(SENSORSTATEBR, BRSTATE);


  //   //HANDLE OPERATIONS
  //   if (ARMED_VAL == 1)
  //   {
  //     putCommit(GPSLAT_ADRRESS, GP.getLat());
  //     putCommit(GPSLONG_ADRRESS, GP.getLng());
  //   }
    
  // }

  // ///////////////////////////////////////////POST_DATA////////////////////////////////////////////////////////////////////////
  
  // String AND = "&";
  // String FRDATA = "SENSORFR=" + String(sensorFR.getData());

  // sim.postMultiData(FRDATA);

  

  // //TURN OF APP AFTER OPERATION
  // putCommit(APPON_ADRRESS, 0);
  // xSemaphoreGive(classMutex);

  // }

  // //PARAMETERS BASED ON EEPROM


  }


}

//===========================================================================================================================

//This loop is for internet/GSM activities
void loop_background(void * parameter)
{
 
 for(;;)
 {
 
 xSemaphoreTake(classMutex, portMAX_DELAY);
 digitalWrite(LED_BUILTIN, HIGH);
//  bool xxx = true;
//  if (xxx == false)
//  {
    
//    if (main_task != NULL)
//    {
//       vTaskDelete(main_task);
//       main_task = NULL;
//    }
   
//    sim.stopHttp();
//    sim.postSingleData(23, "BUCKER");

//    xTaskCreatePinnedToCore
//     (
//     loopMain,
//     "main_task",
//     8000,
//     NULL,
//     1,
//     &main_task,
//     1
//     );

if (dopp1.dopplerTrue())
{
 Serial.println("BRO IS HIGH");
}

   
//  }

 //CREATE AND USE TASK then SUSPEND TASK IN EITHER CORE
 
 xSemaphoreGive(classMutex);
 vTaskDelay(100 / portTICK_PERIOD_MS);
 digitalWrite(LED_BUILTIN, LOW);
 vTaskDelay(100 / portTICK_PERIOD_MS);

 }

}





//====================================================SETUPCODES=====================================================================
void setup() 
{
  
  Serial.begin(115200);
  esp_task_wdt_init(40, true);
  classMutex = xSemaphoreCreateMutex();
  Serial.println("GPS Start");
  GP.GPSInit();
  sim.initGSM();
  dopp1.DOPPLERinit(34);
 
  //sim.onBootUp();
  //preset();
  //FEATURE ADD ON: STATUS BAR TO SHOW ONLINE
      /*{

      }*/

  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreatePinnedToCore
  (
    loop_background,
    "TASK0",
    4096,
    NULL,
    10,
    &background_task,
    0
  );

  xTaskCreatePinnedToCore
  (
    loopMain,
    "main_task",
    8000,
    NULL,
    1,
    &main_task,
    1
  );


 EEPROM.begin(512);

}


 //====================================================LOOPCODES=====================================================================
 
 
 void loop() 
 {
  
  vTaskDelay(100);
   
 }
 
 





//===========================================================================================================================


//OBSOLUTE
// void loop()
// {
//  if(firebase.isReady() && firebase.signUpOK && wifi.checkstatus() == true)
//   {


//   }
// }