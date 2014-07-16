
boolean debug = true; // true for debugging statements to serial out

int tempPin = 0;
int lightPin = 1;
int soilPin = 2;

int voltage = 0; 
float degreesC = 0;
float degreesF = 0;

//int telemetryDelay = 350000; // 5 minutes
//int telemetryDelay = 15000; // 15 seconds
int telemetryDelay = 5000; // 5 seconds

float lightVal = 0;
float tempVal = 0;
float soilVal = 0;

void setup() {
   Serial.begin(9600); 
   delay(5000); // 5 second delay to allow radios to initialize
   Serial.println("");
   Serial.println("=====================================");
   Serial.println("giMultiAnalogSensor v.0.1 initiatited");
   Serial.println("=====================================");
   Serial.println("");
//   for {i == 0; i <3; i++} Serial.println("");
}

void loop() {
//  tempVal = analogRead(tempPin);
//  lightVal = analogRead(lightPin);
//  soilVal = analogRead(soilPin);

// check and convert temperature sensor reading
voltage = getVoltage(tempPin);  
tempVal = voltage; // for debug
degreesC = (voltage - 0.5) * 100.0; // future use
degreesF = degreesC * (9.0/5.0) + 32.0;

// check and convert light sensor reading
lightVal = getVoltage(lightPin);  

// check and convert temperature
soilVal = getVoltage(soilPin);  
  
if (debug) {
  Serial.print("voltage: ");
  Serial.println(tempVal);
  Serial.print("degreesF: ");
  Serial.println(degreesF);
  Serial.print("light: ");
  Serial.println(lightVal);
  Serial.print("soil: ");
  Serial.println(soilVal);
  Serial.println("");
} else {
  Serial.print(degreesF);
  Serial.print(", ");  
  Serial.print(lightVal);
  Serial.print(", ");  
  Serial.println(soilVal);
}
// { "SensorHV": sensorHV, "SensorLV": sensorLV, 
//     {"eventTime": eventTime, 
//     "temp": tempVal, 
//     "light": lightVal, 
//     "soil": soilVal }
// }

  delay(telemetryDelay);
 
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
  // return analogRead(pin); return raw pin reading - for debug
  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
}
