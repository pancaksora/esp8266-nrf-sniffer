// ESP8266 + NRF24L01 + OLED Sniffer
// By Bro Ali & ChatGPT 

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// NRF24L01 settings
#define CE_PIN D2
#define CSN_PIN D8
RF24 radio(CE_PIN, CSN_PIN);

char receivedMessage[32] = "";

#ifdef ARDUINO
  #warning "Arduino defined"
#endif

#ifdef RF24_h
  #warning "RF24 found!"
#endif

void setup() {
  Serial.begin(115200);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED failed"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("NRF24 Sniffer v1"));
  display.display();
  delay(1000);

  // NRF24 init
  if (!radio.begin()) {
    display.println("NRF init failed");
    display.display();
    while (true);
  }

  radio.setChannel(100);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);
  radio.openReadingPipe(1, 0xE8E8F0F0E1LL);
  radio.startListening();

  display.println("Sniffing...");
  display.display();
}

void loop() {
  if (radio.available()) {
    radio.read(&receivedMessage, sizeof(receivedMessage));

    Serial.print("Received: ");
    Serial.println(receivedMessage);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("NRF24 Sniffer v1"));
    display.setCursor(0, 16);
    display.println("Received:");
    display.setCursor(0, 28);
    display.println(receivedMessage);
    display.display();
  }
}
