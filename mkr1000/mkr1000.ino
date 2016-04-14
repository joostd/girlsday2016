#define BLYNK_PRINT Serial
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

char auth[] = "yourtokenhere";

WidgetLED led1(V1);

const int buttonPin = D2;
int triggerDetected=0;
bool ledOn = true;

static void pushedButtonEvent() {
  triggerDetected=1;
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "yourssid", "yourpassword");
  pinMode(buttonPin, INPUT);
  attachInterrupt(buttonPin,pushedButtonEvent,FALLING);
}

void loop()
{
  Blynk.run();
  if (triggerDetected) {
    ledOn = !ledOn;
    triggerDetected=0;
    if( ledOn ) led1.on(); else led1.off();
  }
}

