#include <ThingerESP8266.h>
#include <ESP8266WiFi.h>

//konfigurasi Thinger.IO
#define USERNAME "rydwan"
#define DEVICE_ID "esp8266"
#define DEVICE_CREDENTIAL "DQ9FZA2CMc6o08D%"

//variabel untuk thinger.io
ThingerESP8266 thing (USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

//konfigurasi wifi 
#define ssid "PayNiece"
#define password "AsampekJ"

#define TRIGGERPIN 15
#define ECHOPIN 13

long duration, distance;

void setup() {
  Serial.begin(9600);
  thing.add_wifi(ssid, password);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  thing["ultrasonic"] >> [] (pson & out){
    digitalWrite(TRIGGERPIN, LOW);
    delayMicroseconds(2000);

    digitalWrite(TRIGGERPIN, HIGH);
    delayMicroseconds(10000);

    digitalWrite(TRIGGERPIN, LOW);
    duration = pulseIn(ECHOPIN, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print(distance);
    Serial.println("Cm");
    out = distance;
  };
}

void loop() {
  thing.handle();
    digitalWrite(TRIGGERPIN, LOW);
    delayMicroseconds(2000);

    digitalWrite(TRIGGERPIN, HIGH);
    delayMicroseconds(10000);

    digitalWrite(TRIGGERPIN, LOW);
    duration = pulseIn (ECHOPIN, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print(distance);
    Serial.println("Cm");
}
