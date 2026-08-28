#include <Arduino.h>
#include <WiFi.h>
#include "Audio.h" // schreibfaul1 kitabxanası

const char* ssid = "Ruhin";
const char* password = "0557407742e";

// Sənin MAX98357A pinlərin
#define SPK_LRC 16
#define SPK_BCLK 17
#define SPK_DIN 18
#define SPK_SD 15

Audio audio;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Dinamiki (MAX98357A) məcburi aktiv edirik
  pinMode(SPK_SD, OUTPUT);
  digitalWrite(SPK_SD, HIGH); 

  Serial.print("Wi-Fi-a qoşulur");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi Qoşuldu!");

  // I2S pinlərini təyin edirik
  audio.setPinout(SPK_BCLK, SPK_LRC, SPK_DIN);
  audio.setVolume(21); // Səsi kifayət qədər qaldırdım

  Serial.println("Canlı HTTP MP3 axınına qoşulur...");
  // Bu HTTP linkinin heç bir SSL və ya Bot bloku yoxdur!
  audio.connecttohost("http://stream.srg-ssr.ch/m/rsj/mp3_128");
}

void loop() {
  audio.loop();
}

// Məlumatı izləmək üçün
void audio_info(const char *info){
    Serial.print("audio_info: "); Serial.println(info);
}