========================================================================
            ESP32 & MAX98357A I2S Internet Radio Streamer
========================================================================

1. HAQQINDA (OVERVIEW)
------------------------------------------------------------------------
Bu layihə ESP32 mikrokontrolleri və MAX98357A I2S dekoder/amplituda 
modulundan istifadə edərək real vaxt rejimində (Live HTTP MP3 Stream) 
internet radio axınlarını səsləndirmək üçün nəzərdə tutulub.

Səs siqnalları raqəmsal I2S protokolu ilə daxili audio buferlənməsi 
olunaraq MAX98357A daxili gücləndiricisinə göndərilir.

------------------------------------------------------------------------
2. APARAT BİRƏŞMƏLƏRİ (PINOUT & WIRING)
------------------------------------------------------------------------
- ESP32 Pin      <--->   MAX98357A Module Pin
  * GPIO 16     <--->   LRC / LCK  (Left/Right Clock)
  * GPIO 17     <--->   BCLK / BCK (Bit Clock)
  * GPIO 18     <--->   DIN / DATA (Data In)
  * GPIO 15     <--->   SD (Shutdown - Active HIGH)
  * GND         <--->   GND
  * 5V və ya 3.3V <---> VCC / VIN

* Qeyd: GPIO 15 pini HIGH vəziyyətinə gətirilərək MAX98357A çipi 
  məcburi şəkildə aktivləşdirilir (Shutdown rejimindən çıxarılır).

------------------------------------------------------------------------
3. PROQRAM TƏLƏBLƏRİ VƏ KİTABXANALAR (REQUIREMENTS)
------------------------------------------------------------------------
- Platina Framework: Arduino IDE (ESP32 Board Support v2.x və ya v3.x)
- Tələb olunan kitabxana:
  * Audio.h (schreibfaul1 tərəfindən yazılmış ESP32-AudioI2S kitabxanası)
    GitHub: https://github.com/schreibfaul1/ESP32-AudioI2S
  * WiFi.h (ESP32 daxili)

------------------------------------------------------------------------
4. QURULUM VƏ İSTİFADƏ (SETUP & USAGE)
------------------------------------------------------------------------
1. "Audio.h" kitabxanasını Arduino IDE-yə yükləyin.
2. Kod daxilindəki məlumatları öz şəbəkənizə uyğun dəyişin:
   - const char* ssid = "YOUR_WIFI_NAME";
   - const char* password = "YOUR_WIFI_PASSWORD";
3. Serial Monitoru 115200 baud sürətinə tənzimləyin.
4. Kodu ESP32-yə yükləyin. Qoşulma tamamlandıqdan sonra canlı radio 
   avtomatik səslənməyə başlayacaq.

------------------------------------------------------------------------
5. DİQQƏT MƏQAMLARI (NOTES)
------------------------------------------------------------------------
- `audio.loop()` funksiyası `void loop()` daxilində fasiləsiz çağırılmalıdır.
  Dövrəyə `delay()` əlavə etmək səs kəsilmələrinə (stuttering) səbəb ola bilər.
- HTTP URL-lər istifadə edildikdə SSL sertifikatı tələb olunmur, daha stabil 
  və sürətli axın təmin edilir.
========================================================================
