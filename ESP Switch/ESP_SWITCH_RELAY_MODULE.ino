/**************

Techeonics

ESP Switch ( Use the ESP 8266/32 KIT APP ) FOR RELAY MODULE
ESP 8266/32 KIT APP Download the From Google Play Store - https://play.google.com/store/apps/details?id=appinventor.ai_99gauravbhardwaj.ESP_82

ESP Switch IS TO CONTROLL THE RELAY OR ANY DEIVE ON/OFF FUNCTION WITH THE 
HELP OF ESP 8266/32 KIT APP ( Avalible on Google Play Store ).

By Gaurav Kumar (Techeonics) 
<thetecheonics@gmail.com>
Youtube- https://www.youtube.com/c/THETECHEONICS
See <http://www.techeonics.com> for details.

********************/


#include <ESP8266WiFi.h>

#define RELAY1 D1
#define RELAY2 D2
#define RELAY3 D3
#define RELAY4 D4
const char* ssid = "WIFI NAME";//YOU CAN ALSO CONNECT TO YOUR MOBILE WIFI HOTSPOT
const char* password = "PASSWORD";
 

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200); //Default Baud Rate for NodeMCU
  delay(10);
 
 
  pinMode(RELAY1, OUTPUT);  // Connect Relay to NodeMCU's D4 Pin
  pinMode(RELAY2, OUTPUT);  // Connect Relay to NodeMCU's D4 Pin0
  pinMode(RELAY3, OUTPUT);  // Connect Relay to NodeMCU's D4 Pin
  pinMode(RELAY4, OUTPUT);  // Connect Relay to NodeMCU's D4 Pin
  
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.println("ESP 8266/32 KIT APP");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.println(WiFi.localIP());
  Serial.println("POWERED BY TECHEONICS");
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  int val;
  if (req.indexOf("GET /OFF1 HTTP/1.1") != -1)
    digitalWrite(RELAY1, HIGH);
  else if (req.indexOf("GET /ON1 HTTP/1.1") != -1)
    digitalWrite(RELAY1, LOW);
  else if (req.indexOf("GET /OFF2 HTTP/1.1") != -1)
    digitalWrite(RELAY2, HIGH);
  else if (req.indexOf("GET /ON2 HTTP/1.1") != -1)
    digitalWrite(RELAY2, LOW);
  else if (req.indexOf("GET /OFF3 HTTP/1.1") != -1)
    digitalWrite(RELAY3, HIGH);
  else if (req.indexOf("GET /ON3 HTTP/1.1") != -1)
    digitalWrite(RELAY3, LOW);
  else if (req.indexOf("GET /OFF4 HTTP/1.1") != -1)
    digitalWrite(RELAY4, HIGH);
  else if (req.indexOf("GET /ON4 HTTP/1.1") != -1)
    digitalWrite(RELAY4, LOW);
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
  
}
 
