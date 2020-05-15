#include "SoftwareSerial.h"
#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define DHTPIN 12       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define ONE_WIRE_BUS 13 // Data wire is plugged into port 13 on the Arduino

OneWire oneWire(ONE_WIRE_BUS);  // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire);  // Pass our oneWire reference to Dallas Temperature. 
DHT dht(DHTPIN, DHTTYPE);

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
 Serial.begin(9600); 
 sensors.begin();
 dht.begin();
 
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}

void loop() { 
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  
  sensors.requestTemperatures(); // Send the command to get temperatures
  float t = sensors.getTempCByIndex(0);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  } else {
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println("%");
  }
  
  if (t == -127) {
    Serial.println(F("Failed to read from DS18B20 sensor!"));
    //return;
  } else {
    Serial.print(F("Temperature: "));
    Serial.print(t); 
    Serial.println("°C");
  }
  
  //if (t > 25)
  turnOnA();

  //if (h > 50)
  turnOnB();
}
