    /* Melody
     * (cleft) 2005 D. Cuartielles for K3
     *
     * This example uses a piezo speaker to play melodies.  It sends
     * a square wave of the appropriate frequency to the piezo, generating
     * the corresponding tone.
     *
     * The calculation of the tones is made following the mathematical
     * operation:
     *
     *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
     *
     * where the different tones are described as in the table:
     *
     * note         frequency       period  timeHigh
     * c            261 Hz          3830    1915    
     * d            294 Hz          3400    1700    
     * e            329 Hz          3038    1519    
     * f            349 Hz          2864    1432    
     * g            392 Hz          2550    1275    
     * a            440 Hz          2272    1136    
     * b            493 Hz          2028    1014   
     * C            523 Hz          1912    956
     *
     * http://www.arduino.cc/en/Tutorial/Melody
     */
     
    #include <Servo.h>
    int speakerPin = 9;
    int colorLEDs[] = {4,5,6,7}; 
    //int length = 15; // the number of notes
    //char notes[] = "ccggaagffeeddc "; // a space represents a rest
    //int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
    //int tempo = 300;
    //campana sobre campana
    // G, D, G
    // G, D, G ,
    // G, C, G, C, G,
    // D, G
    // G, D, A7, D, G
    // G, D, A7, D, G
    // G, C, G, C, G,
    // D, G
    //int length = 38;
    //char notes [] = "gdg gdg gcgcg dg gdadg gcgcg dg ";
    //int beats [] = {3,3,1,1,3,3,1,1,2,2,2,2,1,1,3,2,1,3,3,2,1,3,2,3,3,1,1,1,2,3,1,2};
    int tempo = 300;
    //fail muy dificil
    //int length = 71;
    //char notes[] = "cfffgagavCavafggfcfffgagavCavafggffaCDCvagfgavCcfagfccfffgagavCavafggf ";
    //int beats[] = { 2,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,2,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,1,1,3,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,4,4,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,2};
     
    //While Shephards Watched
    //int length = 29;
    //char notes[] = "faagfvvagaCCbCaDCvagfeagffef ";
    //int beats[] = { 2,3,1,2,2,2,2,2,2,2,2,2,2,6,2,3,1,2,2,2,2,2,2,2,2,2,2,6,2 };
     
    //Ding Dong Merrily on High
    int length = 73;
    char notes[] = "ggagsed deggsgg ggagsed deggsgg DCbCDbCbabCabagabgagsgasgsesgeseddeggsgg "; // a space represents a rest
    int beats[] = { 2,2,1,1,1,1,4,2,2,2,2,2,2,4,2,2,2,2,1,1,1,1,4,2,2,2,2,2,2,4,2,2,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,2,2,2,2,2,2,4,2,2 };
     
    // Sweep
    // by BARRAGAN <http://barraganstudio.com>
    // This example code is in the public domain.
     
     
     
    Servo myservo;  // create servo object to control a servo
                    // a maximum of eight servo objects can be created
     
    int pos = 0;    // variable to store the servo position
     
     
     
    void playTone(int tone, int duration) {
      for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(speakerPin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(tone);
      }
    }
     
    void playNote(char note, int duration) {
      char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
      int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
     
      // play the tone corresponding to the note name
      for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
          playTone(tones[i], duration);
        }
      }
    }
     
    void setup() {
      pinMode(speakerPin, OUTPUT);
      myservo.attach(10);  // attaches the servo on pin 10 to the servo object 
    }
     
    /*
     Fading
     
     This example shows how to fade an LED using the analogWrite() function.
     
     The circuit:
     * LED attached from digital pin 9 to ground.
     
     Created 1 Nov 2008
     By David A. Mellis
     modified 30 Aug 2011
     By Tom Igoe
     
     http://arduino.cc/en/Tutorial/Fading
     
     This example code is in the public domain.
     
     */
     
     
    int ledPin = 11;    // LED connected to digital pin 11
     
     
    void loop()  {
      // fade in from min to max in increments of 5 points:
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
        // sets the value (range from 0 to 255):
        analogWrite(ledPin, fadeValue);        
        // wait for 30 milliseconds to see the dimming effect    
        delay(100);                            
      }
     
      // fade out from max to min in increments of 5 points:
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
        // sets the value (range from 0 to 255):
        analogWrite(ledPin, fadeValue);        
        // wait for 30 milliseconds to see the dimming effect    
        delay(100);                            
      }
       for (int i = 0; i < length; i++) {
        if (notes[i] == ' ') {
          delay(beats[i] * tempo); // rest
        } 
        else {
          playNote(notes[i], beats[i] * tempo);
          pos = beats[i]*5;
          myservo.write(pos);
            if (notes[i] == 'a'){
            digitalWrite(colorLEDs[0],HIGH);
            delay (beats[i]);
            digitalWrite(colorLEDs[0],LOW);
            }
            if (notes[i] == 'b'){
            digitalWrite(colorLEDs[1],HIGH);
            delay (beats[i]);
            digitalWrite(colorLEDs[1],LOW);
            }
            if (notes[i] == 'g'){
            digitalWrite(colorLEDs[2],HIGH);
            delay (beats[i]);
            digitalWrite(colorLEDs[2],LOW);
            }
            else {
            digitalWrite(colorLEDs[3],HIGH);
            delay (beats[i]);
            digitalWrite(colorLEDs[3],LOW);
            }
           
          }
        }
        // pause between notes
        delay(tempo / 2);
      }
    /*    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
      {                                  // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
     */
    
     
    //campana sobre campana
    // G, D, G
    // G, D, G ,
    // G, C, G, C, G,
    // D, G
    // G, D, A7, D, G
    // G, D, A7, D, G
    // G, C, G, C, G,
    // D, G
     
    //http://www.liubo.us/use-arduino-to-play-melody-songs/
    //O Little Town of Bethlehem
    //Code:
    //int length = 71; char notes[] = "cfffgagavCavafggfcfffgagavCavafggffaCDCvagfgavCcfagfccfffgagavCavafggf "; int beats[] = { 2,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,2,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,1,1,3,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,4,4,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,2 };


