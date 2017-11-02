/*                                                                                         HEARTBEAT MEARSURING DEVICE 
                                                                                                 MUBINUN AWAISU 
                                                                                                   6217000141
                                                                                          SENSOR AND SENSING TECHNOGY
                                             This program is write to measure the frequency of a beating heart and multiply by 60 to get the number of beats per minute*/


#define PROCESSING_VISUALIZER 1                                                                                          
#include <FreqMeasure.h>

const int sensorPin = A0;
int sensorVal;
float frequency;
float BMP;

void setup()
{
  Serial.begin(9600);
   FreqMeasure.begin();
  
}
double sum=0;
int count=0;

void loop()
{
  //creates a timer variable to keep track of time
  unsigned long timer = millis();
  
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
     if (count >= 10) {
      frequency = FreqMeasure.countToFrequency(sum / count);
      BMP = (frequency*60);
      sum = 0;
      count = 0;
     }
   }
  
  sensorVal = analogRead(sensorPin);
  
  double voltage = convertToVoltage(sensorVal);
  
  double absorbance = calculateAbsorbance(voltage);
    
  displayPulseInPROCESSING_VISUALIZER(absorbance, BMP);
  
  //small delay to change our sampling rate
  //and stabilize our signal
  delay(250);  
}

void displayPulseInPROCESSING_VISUALIZER(double absorbance, float BMP)
{
  //Serial.print(absorbance,5);
  Serial.print("\t");
  Serial.print(BMP,2);
  Serial.println();
}

double convertToVoltage(double ADC_Val)
{
  double volt = 0;
  
  volt = 5*(ADC_Val/1023);
  
  //return volt;
}

double calculateAbsorbance(double volt)
{
  double absorbance = 0;
  
  absorbance = log10(5/volt);
  
  return absorbance;  
}
