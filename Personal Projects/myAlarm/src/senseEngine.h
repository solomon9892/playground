#pragma once
#include <main.h>



template<typename p>
class sensorInitialization 
{
  int triggerpin;
  int echopin;
  p lowerrange;
  p upperrange;

  public:

  sensorInitialization(const int TRIGGERPIN, const int ECHOPIN, STATE g)
  {
    
    if (g == STATE::ON)
    {
    pinMode(ECHOPIN,INPUT_PULLUP);
    pinMode(TRIGGERPIN, OUTPUT);
    digitalWrite(ECHOPIN, HIGH);
    triggerpin = TRIGGERPIN;
    echopin = ECHOPIN;
    state = g;
    }

  }
  
  p getDistance()
  {
   
   if (state == STATE::ON)
   {
    digitalWrite(triggerpin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerpin, HIGH);
    delayMicroseconds(15);
    digitalWrite(triggerpin, LOW);
    p distance = pulseIn(echopin, HIGH, 26000); 
    distance = distance/58;
    return distance;
   }
   else return 0;

  }

  p filterDistance()
  {
   
     medianFilter.AddValue(getDistance());
     return medianFilter.GetFiltered();

  }

  p getData()
  {
  
  if (offtrue != 0)
  {
    p capturedDistance = filterDistance();
    if (capturedDistance >= lowerrange && capturedDistance <= upperrange)
       {
        
        return capturedDistance;
        
       }
    delay(5); 
    if (capturedDistance <= lowerrange || capturedDistance >= upperrange)
        {
        
          return 0;

        }
    }
    else
    return 0;  
  }
 
  void setRange(p LOWERRANGE, p UPPERRANGE)
  {
   
    lowerrange = LOWERRANGE;
    upperrange = UPPERRANGE;

  }
  
  p isOff(p off)
  {
    return offtrue = off;
  }
  

  p offtrue;

  private:

  int state;
  MedianFilter<int> medianFilter {30};
  
};


struct GPS
{

SoftwareSerial serial_connection {20, 22};
TinyGPSPlus gps;

void GPSInit()
{
  serial_connection.begin(115200);
}

float getLat()
{
  while(serial_connection.available() > 0)
  {
    gps.encode(serial_connection.read());
    
  }
  if(gps.location.isUpdated())
  {
    return gps.location.lat();
  }

}

float getLng()
{
  while(serial_connection.available())
  {
    gps.encode(serial_connection.read());
    
  }
  if(gps.location.isUpdated())
  {
    return gps.location.lng();
   
  }
  
}

};


struct DOPPLER 
{
 
  uint8_t triggerPin;

  void DOPPLERinit(uint8_t outPin)
  {
    
    triggerPin = outPin;
    pinMode(triggerPin, INPUT);

  }

  bool dopplerTrue()
  {
    
    if (analogRead(triggerPin) >= 400)
    {
      return true;
    }
    else return false;
  }

};








// switch (id)
          // {
          //    case 1 :
          //    Serial.println("FR OUT OF RANGE !");
          //    break;

          //    case 2 :
          //    Serial.println("FL OUT OF RANGE !");
          //    break;

          //    case 3 :
          //    Serial.println("BR OUT OF RANGE !");
          //    break;

          //    case 4 :
          //    Serial.println("BL OUT OF RANGE !");
          //    break;

          //    capturedDistance = 0;