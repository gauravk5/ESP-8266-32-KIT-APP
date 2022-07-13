#include <ESP8266WiFi.h>
const char* ssid = "xxxxxxxxxx"; // Name of the Network.
const char* password = "xxxxxxxxxx"; // Password of the Network.
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password); // This will connect the Node MCU with WiFi.
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP()); //This will print the Local IP address of the Network.
}

void loop() {
  // put your main code here, to run repeatedly:

}
