#define IN4  4
const int trigPin = 5;
const int echoPin = 6;
// defines variables
long duration;
int distance = 0;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(4, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
if ((distance <20)&&(distance > 0)) //if the distance of the sensor is greater than 20cm and less than 0cm turn the buzzer on
  {
  digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
}
else if ((distance > 21)&&(distance < 120))
  {
  digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10*(distance-20));  
  digitalWrite(IN4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10*(distance-20));// wait for a set time
  }
else if ((distance > 121)&&(distance < 150)) {
  digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  digitalWrite(IN4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
}
else if (distance > 150){
  digitalWrite(IN4, LOW);
}
delayMicroseconds(10);
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance); //distance is the returned integer, it is the distance in cm
}
