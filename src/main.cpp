/**
* @file main.cpp
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author Purendra Ranjan [ranjanjs09]
 * @date 19/02/2026
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 **/
#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 Sensor Initialized");
}

void loop() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
    delay(2000);
}