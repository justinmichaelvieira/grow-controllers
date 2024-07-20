/*

aero_hydro_pump_saver_root_maximizer.c

HARDWARE PLATFORM: arduino nano (https://store-usa.arduino.cc/products/arduino-nano/?selectedStore=us)
or any other arduino compatible board. Note: you may need to change the OUTPUT_PIN
below to match your board.

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

There's a demo simulator here: https://wokwi.com/projects/403891674345275393
Note: The demo has OUTPUT_PIN to LED_BUILTIN, which is the onboard LED on the arduino nano.
When you run the code on an actual arduino nano, you will want OUTPUT_PIN to be the GPIO pin
Connected to your relay that turns the water or air pump on and off... Wokwi/Simulator 
just turns the onboard LED of the simulated arduino nano on and off during the on and off intervals.

*/

#include <stdbool.h>

// NOTE: OUTPUT_PIN can be set to LED_BUILTIN to blink the onboard LED
const byte OUTPUT_PIN = 13;

unsigned long ON_INTERVAL = 10000;   // 10 seconds
unsigned long OFF_INTERVAL = 120000; // 2 minutes

unsigned long INTERVAL_TOTAL;
bool pinActive = false;

void setup() {
  INTERVAL_TOTAL = ON_INTERVAL + OFF_INTERVAL;
  pinMode(OUTPUT_PIN, OUTPUT);      // Set OUTPUT_PIN to output mode
}

void loop() {
  if (millis() % INTERVAL_TOTAL <= ON_INTERVAL)
  {
    if(!pinActive) {
      pinActive = true;
      digitalWrite(OUTPUT_PIN, HIGH);
    }
  } else {
    if(pinActive) {
      pinActive = false;
      digitalWrite(OUTPUT_PIN, LOW);
    }
  }
}
