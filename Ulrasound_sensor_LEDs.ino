/***********************************************************
File name:   Ultrasound_sensor_LEDs
Description: LED blinks ON and OFF when the HRC-04 detects an object within 10 cm

***********************************************************/

const int trigPin = 9;
const int echoPin = 10;
int pc = 3;
int pi[] = {13,2,3};
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
for ( int i = 0 ; i<pc;i++)
{
   pinMode(pi[i],OUTPUT);
}
Serial.begin(9600); 
}


void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(1);


digitalWrite(trigPin, HIGH);
delayMicroseconds(1);
digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 10){  
  for (int i=pc-1; i>0; i=i-1){   
    digitalWrite(pi[i], HIGH);        
    delay(35);                          
    digitalWrite(pi[i], LOW);          
  }
   for (int i=0; i<pc; i=i+1){    
    digitalWrite(pi[i], HIGH);       
    delay(35);                          
    digitalWrite(pi[i], LOW);          
  }
 
}
else{
 

}


}
