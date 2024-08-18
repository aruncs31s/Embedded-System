
const int pin = A0;
const int tilt_threshold = 500;
void setup() {
  Serial.begin(9600);
  pinMode(pin,INPUT);

}

void loop() {

int sensor_reading = analogRead(pin) ;
if (sensor_reading <= tilt_threshold){
  Serial.println("Tilt Happened");
}
delay(100);
}
