/* 
* Author : Arun CS
* Github : https://github.com/aruncs31/
* URL : https://github.com/aruncs31s/ESP32_MeshNet_For_Node_To_Gateway_Communication 
sources : https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/

 */


#include <esp_now.h>
#include <WiFi.h>

// Replace it with Router IP
const char* ssid = "802.11";
const char* password = "12345678p";


WiFiServer server(80);

String header;

// Structure example to receive data
// Must match the sender structure
typedef struct Data {
    char a[32];
    int b;
    float c;
    bool d;
} Data;
Data received_data;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {

  // Copy the value from source to destination
  memcpy(&received_data, incomingData, sizeof(received_data));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(received_data.a);
  Serial.print("Int: ");
  Serial.println(received_data.b);
  Serial.print("Float: ");
  Serial.println(received_data.c);
  Serial.print("Bool: ");
  Serial.println(received_data.d);
  Serial.println();
}
 
void setup() {
  Serial.begin(9600);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  // FIX: Implement Reconnection
  WiFi.begin(ssid,password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));

  server.begin();
}
 
void loop() {
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
            
            if (header.indexOf("GET /02/on") >= 0) {
              Serial.println("GPIO 02 on");
              current_led_status = "on";
              digitalWrite(LED_BUILTIN, HIGH);
            } else if(header.indexOf("GET /02/off") >= 0) {
              Serial.println("GPIO 02 off");
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
              client.println("<p><a href=\"/02/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/02/off\"><button class=\"button button2\">OFF</button></a></p>");
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
