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
