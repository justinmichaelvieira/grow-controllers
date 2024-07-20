/*

aero_hydro_pump_saver_root_maximizer.c

HARDWARE PLATFORM: arduino & compatible boards, ATMEGA and compatible chips.
Note(s): - You may need to change the OUTPUT_PIN in code below to match your board/desires. 
         - OUTPUT_PIN should be wired to your relay (which the pump is plugged to). 

PURPOSE: Save $$$ by saving electricity and extending water/air pump life... While stimulating root growth.

DETAILED DESCRIPTION: Drives an aeroponic cloner, water, or air pump by writing high for onInterval, 
and then low for offInterval. Fundamentally, roots in aeroponics will expand if they are 
allowed to dry out a bit between mistings. On the opposite spectrum, in hydroponics, 
one may desire to cycle our pump if we think it is oversized for our reservoir.

Also, it saves electricity, and extends pump life greatly to run the pump only a small 
fraction of the time. Both of these factors lower total cost of owning and maintaining
a hydroponic or aeroponic system.

Sensible defaults are provided for ON_INTERVAL and OFF_INTERVAL; However, intervals 
should ideally be adjusted based on your pump, misters, and the size of your cloner.
Best to experiment and observe the results.

The arduino built-in LED is used to indicate when the pump is on. This can be useful for
troubleshooting setup... Or debugging.

There's a demo simulator here: https://wokwi.com/projects/403891674345275393

*/

#include <stdbool.h>

const byte OUTPUT_PIN = 12;

unsigned long ON_INTERVAL = 10000;   // 10 seconds
unsigned long OFF_INTERVAL = 120000; // 2 minutes

unsigned long INTERVAL_TOTAL;
bool pinActive = false;

void setup() {
  INTERVAL_TOTAL = ON_INTERVAL + OFF_INTERVAL;
  pinMode(OUTPUT_PIN, OUTPUT);      // Set OUTPUT_PIN to output mode
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (millis() % INTERVAL_TOTAL <= ON_INTERVAL)
  {
    if(!pinActive) {
      pinActive = true;
      digitalWrite(OUTPUT_PIN, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
  } else {
    if(pinActive) {
      pinActive = false;
      digitalWrite(OUTPUT_PIN, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
