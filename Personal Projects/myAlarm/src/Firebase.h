#pragma once

//14/8/23 TEMPORARY NOT IN USE, SINCE WE ARE USING FULLY GSM BASED

#include <main.h>
#include <network.h>
#include <Firebase_Client_Version.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"


class FirebaseInitialization
{

  public:
  FirebaseData fbdo;
  FirebaseAuth auth;
  FirebaseConfig config;
 
  bool signUpOK = false;

  void toInitialize()
  {
   
    config.api_key = WEB_KEY;
    config.database_url = DATABASE_URL;
    if (Firebase.signUp(&config, &auth, "",""))
    {
      
      delay(10);
      Serial.print("signUp OK");
      signUpOK = true;
 
    }
    else if (signUpOK == false)
    {
      Serial.printf("%s\n", config.signer.signupError.message.c_str());
      ESP.restart();
    }
    delay(10);
    config.token_status_callback = tokenStatusCallback;
    delay(10);
    Firebase.begin(&config, &auth);
    delay(10);
    Firebase.reconnectWiFi(true);

  }

  bool isReady()
  {
    
     return Firebase.ready();

  }

  void setData(int val, std::string path)
  {
    Firebase.RTDB.setInt(&fbdo, path, val);
  }

  void setData(float val, std::string path)
  {
    Firebase.RTDB.setFloat(&fbdo, path, val);
  }

  void setData(bool val, std::string path)
  {
    Firebase.RTDB.setBool(&fbdo, path, val);
  }

  void setData(std::string val, std::string path)
  {
    Firebase.RTDB.setString(&fbdo, path, val);
  }

  int getInt(std::string path)
  {
   if ( wifi.checkstatus() == true && isReady() )
   {
    if (Firebase.RTDB.getInt(&fbdo, path))
    {

      if(fbdo.dataType() == "int")
      {
        return fbdo.intData();
      }

    }
   }
   else return 0;
  }

  float getFloat(std::string path)
  {
  if(Firebase.RTDB.getFloat(&fbdo, path))
    {
    
     if(fbdo.dataType() == "float")
       {
          return fbdo.floatData();
       }

    }
    
  }

  bool getBool(std::string path)
  {
  if(Firebase.RTDB.getBool(&fbdo, path))
    {

      if(fbdo.dataType() == "boolean")
        {
          return fbdo.boolData();
        }

    }
    
  }




private:

WifiInitialize wifi;
std::string WEB_KEY = "AIzaSyDJ4CMg_uFZU0dOP2sjxXwNPpLPWeI4o9U";
std::string DATABASE_URL = "https://myalarm-66cd2-default-rtdb.asia-southeast1.firebasedatabase.app/";

};