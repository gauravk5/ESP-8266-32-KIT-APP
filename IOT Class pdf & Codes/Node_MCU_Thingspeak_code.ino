#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <Adafruit_BMP280.h>
#include <DHT.h>

const char* ssid = "xxxxxxxxxx"; // Name of the Network.
const char* password = "xxxxxxxxxx"; // Password of the Network.

WiFiClient client; // Create a Wi-Fi client to connect to ThingSpeak.

unsigned long myChannelNumber = 1; // Channel No
const char * myWriteAPIKey = "xxxxxxxxxx"; // API write key.


#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password); // This will connect the Node MCU with WiFi.
  WiFi.mode(WIFI_STA); // Set the Node MCU as a Wi-Fi station.
  ThingSpeak.begin(client); // Initialize ThingSpeak.

  dht.begin();
}

void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  float h = dht.readHumidity();
  Serial.println("\nConnected. ");
  ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
  //the channel number.
  //the field number (in our case, we just have one field).
  //the value you want to publish (x).
  //your write API key.
}
