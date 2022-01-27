# Adafruit_Trinket_Mini_Auto_PICKnMIX
Auto-start PICKnMIX with Adafruit Trinket Mini 3v/5v PCB
## Adafruit Tricket Mini 3v/5v Auto PICKnMIX for MVS 161 in 1 (Bananna Cart)

Start button will be held for 5 seconds with POWER ON

If any button wired to pin 1 is held during POWER ON sequence, the regular 161 in 1 menu will be displayed

How to setup:
  PWR - JAMMA PIN 3
  GND - JAMMA PIN 1
  0   - JAMMA PIN 17
  1   - JAMMA PIN 25

In the above setup - The Holding the D button during POWER ON will skip PICKnMIX

Does NOT work with standard Adafruit Trinket Mini 3v/5v bootloader (takes more than 2 seconds before code executes)
Must use Bootloader found here: https://forums.adafruit.com/download/file.php?id=34218 (trinketloader_skippow25.zip) 
