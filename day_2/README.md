## Day 2

Day 2 is all about the built in Wifi In the `ESP32` and what can we do with it

1. Connecting `ESP32` to wifi

```c
#include <WiFi.h>

// put your WiFi credentials (SSID and Password) here
const char *ssid = "802.11";
const char *psswd = "12345678p";
void setup()
{
  Serial.begin(9600);

  // Connecting to Wi-Fi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, psswd);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.println("Connected!");


}

void loop()
{
delay(1000);
}
```

![](./Images/wifi_ip.png?raw=true)

2. Controlling Builtin LED through Web

```c
// source : https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
#include <WiFi.h>

// change the credential according to your needs
const char *ssid = "802.11";
const char *psswd = "12345678p";

// Set portnumber to 80
WiFiServer server(80);

String header;

String current_led_status = "off";
int LED_BUILTIN = 2;

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup()
{
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  // Connecting to Wi-Fi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, psswd);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.println("Connected!");

  server.begin();

}

void loop(){
  WiFiClient client = server.available();
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


if (client) {
 currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {
      char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              current_led_status = "on";
              digitalWrite(LED_BUILTIN, HIGH);
            } else if(header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              current_led_status = "off";
              digitalWrite(LED_BUILTIN, LOW);
            }
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            client.println("<body><h1>BUILTIN Led Control</h1>");

            client.println("<p>BUILTIN LED  - State " + current_led_status + "</p>");
            if (current_led_status=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("</body></html>");

            client.println();
            break;
          } else {
          currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
  delay(1000);
}
```

![](./Images/led_server.png?raw=true)
