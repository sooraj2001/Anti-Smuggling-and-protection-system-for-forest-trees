
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2);

#include <SimpleDHT.h>
unsigned long prevTime = millis();
int viberation_sensor = 8;
int tilt_sensor = 12; // titlt sensor and all other sensors re-sarts again after 20 sec after detecting the smuggling 
int pinDHT11 = 10;
SimpleDHT11 dht11(pinDHT11);
const int touchPin = 9;

int vib=0 , t=0 , metal=0;
int ct,pt=0,smugglingMessageCount = 0,tempMessageCount = 0;

void setup() {
Serial.begin(9600);
smugglingMessageCount = 0;
tempMessageCount = 0;
vib=0;
t=0;
metal=0;
}

void loop() {
viberation();
tilt();
temp();
Metal();

if( vib==1 && t==1 && metal==1 ) // checks if all sensors detect together 
{
  if( smugglingMessageCount != -1 ) {
  Serial.println("Tree is Being Smuggled");
  send_sms("Tree is Being Smuggled"); // Send's SMS to phone 
  smugglingMessageCount = -1 ;
  //return;
  }
}

ct = millis();
if(ct-pt >= 20000) { //If touch or tilt is not detected within 20sec of vibration then set all values of sensors to zero
  pt = 0;
  vib=0 ; t=0 ; metal=0;
  smugglingMessageCount = 0;
  //tempMessageCount = 0;
}
}

void viberation() { 
int viberation_sensor_state = digitalRead(viberation_sensor);
if(viberation_sensor_state == 1)
{
vib = 1;
pt = millis();
//Serial.println("Vibration Sensed");
}
}

void temp() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
   // Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    //Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }

  if((int)temperature>5 && (int)humidity<400 && tempMessageCount != -1) {
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  Serial.println(" Forest under fire !!!! ");
  send_sms(" Forest under fire !!!! ");
  tempMessageCount = -1;
  //return;
  }
  // DHT11 sampling rate is 1HZ.
//  delay(500); 

while( true ) { //delay of 1 sec in DHT11 Sensor
unsigned long currentTime = millis();
viberation();
tilt();
Metal();
if(currentTime - prevTime > 1000) {
prevTime = currentTime;  
break;
} 
}
}

void tilt() {
  int tilt_sensor_state = digitalRead(tilt_sensor);
  if(tilt_sensor_state == 1) {
    t = 1;
    pt = millis();
//    Serial.println("Tilt Sensed");
  }
}

void Metal() {
  int touchState = digitalRead(touchPin);
  if(touchState == 1){
    metal = 1;
    pt = millis();
//    Serial.println("Metal Detected");
  }
  }

void send_sms(String txt) { //GSM code
  
  Serial.begin(9600);
  
 
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT");
  updateSerial();

  mySerial.println("AT+CMGF=1"); 
  updateSerial();
  mySerial.println("AT+CMGS=\"+916360473123\""); // enter your phone number here (prefix country code)
  updateSerial();
  mySerial.println(txt); // enter your message here
  updateSerial();
  mySerial.write(26);
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
