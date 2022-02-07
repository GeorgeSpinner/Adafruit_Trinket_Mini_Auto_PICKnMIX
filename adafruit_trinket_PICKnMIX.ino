// Adafruit Trinket Mini 3v/5v Auto PICKnMIX for MVS 161 in 1 (Banana Cart)
//
// Start button will be held for 5 seconds with POWER ON
// 
// If any button wired to pin 1 is held during POWER ON sequence, the regular 161 in 1 menu will be displayed
//
// How to setup:
//  PWR - JAMMA PIN 3
//  GND - JAMMA PIN 1
//  0   - JAMMA PIN 17
//  1   - JAMMA PIN 25
//
// In the above setup - The Holding the D button during POWER ON will skip PICKnMIX
//
// Does NOT work with standard Adafruit Trinket Mini 3v/5v bootloader (takes more than 2 seconds before code executes)
// Must use Bootloader found here: https://forums.adafruit.com/download/file.php?id=34218 (trinketloader_skippow25.zip) 

#include <avr/sleep.h>

// define pin settings

int START = 0;                            // Start button connected to this pin (JAMMA pin 17) 
int PNM_DISABLE = 1;                      // button that will disable PICKnMIX connected to this pin (JAMMA pin 22=A 23=B 24=C 25=D)
int SKIP;

void setup() {
  sleep_disable();                        // disable sleep mode 
  

  pinMode(START, OUTPUT);                 // sets the digital pin 0 connected to Start button as OUTPUT
  pinMode(PNM_DISABLE, INPUT);            // sets the digital pin 1 connected to PNM_DISABLE button as INPUT
  digitalWrite(START, HIGH);                                        
  SKIP =digitalRead(PNM_DISABLE);         // check the PNM_DISABLE button state
  if (SKIP == HIGH) {                     // If PNM_DISABLE button is NOT pressed (still in HIGH state)
    digitalWrite(START, LOW);             // sets the digital pin 0 to GND (Hold Start button)
    delay(5000);                          // waits for 5 seconds to enable PICKnMIX
  }
  pinMode(START, INPUT);                  // sets the digital pin 0 as INPUT (Release Start button) 
}

void loop() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // set sleep mode
  sleep_enable();                         // enable sleep
  sleep_cpu();                            // put the cpu to sleep
}
