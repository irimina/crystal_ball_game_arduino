
//A sketch to demonstrate the tone() function
// first line of the happy birthday song

/*
 * 
Sample notes
 
NOTE_C4 262
NOTE_D4 294
NOTE_E4 330
NOTE_F4 349
NOTE_G4 392
NOTE_A4 440
NOTE_B4 494
NOTE_C5 523
 */

 
//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int piezoPin = 8;
 
void setup() {
 
}//close setup
 
void loop() {
 
  /*Tone needs 2 arguments, but can take three
    1) Pin#
    2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
    3) Duration - how long teh tone plays
  */
  
  tone(piezoPin, 262, 500); //C4 - 1 beat
  delay(500);
  tone(piezoPin, 262, 500); //C4 . - 1 beat
  delay(500);
  tone(piezoPin, 294, 1000); //D4 - 2 beats
  delay(1000); 
  tone(piezoPin, 262, 1000);// C4 - 2 beats
  delay(1000);
  tone(piezoPin, 349, 1000); //note F4 - 2 beats
  delay(1000);
  tone(piezoPin, 330, 2000); // note E4 - 4 beats
  delay(2000);
 
}
