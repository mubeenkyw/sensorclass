
/*                                                                             HEARTBEAT MEASURING DEVICE BY
                                                                                        MUBINUN AWAISU 
                                                                                          6217000141
                                                                                SENSOR AND SENSING TECHNOLOGY                                                                                 */
#define PROCESSING_VISUALIZER 1
#define SERIAL_PLOTTER 2
int ledPin = 6;
int sensorPin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;
//double minval = 0.0;
void setup ()
{
  Serial.begin (9600);
}
void loop ()
{
    static double oldValue = 0;
    static double oldChange = 0;
    
    int rawValue = analogRead(sensorPin);
    //double value = alpha * oldValue + (1 - alpha) * rawValue;
    int value = alpha * oldValue + (1 - alpha) * rawValue;
    static int outputType = PROCESSING_VISUALIZER ;
 
    Serial.print (rawValue);
    Serial.print (",");
    Serial.println (value);
    oldValue = value;
    
    delay (1000);
}


