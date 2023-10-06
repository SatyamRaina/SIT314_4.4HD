#include <DHT.h>
#define DHTPIN 2 // Replace with the appropriate pin number connected to the DHT11 sensor
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600); // Set the baud rate to match the JavaScript code
  dht.begin();
}
void loop() {
  delay(2000); // Delay for 2 seconds between readings
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read data from DHT sensor");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
