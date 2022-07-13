#include <DHT.h>

#define DHTPIN D5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
    float h = dht.readHumidity();
    Serial.println(h);
    

}
