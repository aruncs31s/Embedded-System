// Change the delay_time to make the LED Blink faster or slower
int delay_time=1000;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(delay_time);                 
  digitalWrite(LED_BUILTIN, LOW);    
  delay(delay_time);                 
}


