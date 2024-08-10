# Arduino Programs

##### Led Blink

```c

// Blink Program
// Source : Arduino/Examples

// Execute only Once
void setup() {
// initialize digital pin LED_BUILTIN as an output.
pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
delay(1000); // wait for a second
digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
delay(1000); // wait for a second
}
```

##### Delay Control

> 2.ino

```c
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
```

#### Serial Monitor

```c
//  Serial Monitor

void setup(){
Serial.begin(9600);
// Output Text to Serial Monitor
Serial.println("Hello World");
}
void loop(){

}

```

#### 4 Advanced Led Blink

```c
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
```
