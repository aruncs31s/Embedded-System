// Source : https://lastminuteengineers.com/handling-esp32-gpio-interrupts-tutorial/
const uint8_t button_pin= 13;
long int press_count = 0;

void IRAM_ATTR ISR(){
press_count +=1;
}
void setup(){
Serial.begin(9600);
pinMode(button_pin,INPUT_PULLUP);
attachInterrupt(button_pin,ISR,FALLING); // 
}
void loop(){
  Serial.print("Press count is " + String(press_count));
  delay(100);
}

