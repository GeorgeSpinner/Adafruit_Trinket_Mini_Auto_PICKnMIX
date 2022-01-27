// Adafruit Tricket Mini 3v/5v Auto PICKnMIX for MVS 161 in 1 (Bananna Cart)
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

int button;                  // to track D button status (HIGH or LOW)

void setup() {
  pinMode(0, OUTPUT);        // sets the digital pin 0 as OUTPUT
  pinMode(1, INPUT);         // sets the digital pin 1 ( D button)
  button = digitalRead(1);   // read the input pin (is D button pressed - in LOW state)
  if (button == HIGH) {      // If D button is NOT pressed (still in HIGH state)
    digitalWrite(0, LOW);    // sets the digital pin 0 to GND (Hold Start)
    delay(5000);             // waits for 5 seconds
  }
  pinMode(0, INPUT);         // sets the digital pin 0 as INPUT (Release Start) 
}

void loop() {
}
