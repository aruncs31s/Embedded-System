
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
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ", + String(WiFi.localIP().to_string));
  delay(1000);
}
