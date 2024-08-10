// Advanced Led Blink
// 2024-08-11 , 02:13 AM 
void setup() { Serial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
 Serial.println("Please Enter Your Name");
 while (Serial.available() == 0) {
  }
  

  String name = Serial.readString();
  Serial.println("Hi " + name);

}
void loop() {

  Serial.println("Would You like to turn on or off the light? Y,N");
   while (Serial.available() == 0) {
    
  }
  char state = Serial.read();
  if (state == 'Y'){
    Serial.println("Turning On the light ");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (state != 'Y'){
    Serial.println("Turning off the light ");
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(3000);
}
