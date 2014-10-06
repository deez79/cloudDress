/* ##############################################################################

    cloudDress.ino v1
    Three seperate groups of pins are used to run multimple LEDs. 
        They are broken into Top, Middle, and Bottom.  
        They flash in order of Bottom, Top, then Middle in an attempt 
          to mimic clouds.
            
    Wireing
        LED Anodes are connected to 5v rail while 
        LED Cathodes are connected to the I/O pins.
        
    Schematic
        ________________
        |   Arduino     |
        |               |
        |          5.0v |-----------------------o----------------------------o----------------------------------------o
        |               |                       |                            |                                        |   
        |           GND |-            top LEDS  |                            |                                        |     
        |               |                       |                            |                                        |           
        |       pin 12  |-----------o-----|<----o                            |                                        |
        |               |                       |                            |                                        |           
        |       pin 11  |-----------o-----|<----o                            |                                        |
        |               |                       |                            |                                        |
        |       pin 10  |-----------o-----|<----o                            |                                        |
        |               |                                       middle LEDs  |                                        |
        |       pin 09  |----------------------------------------o-----|<----o                                        |
        |               |                                                    |                                        |
        |       pin 08  |----------------------------------------o-----|<----o                                        |
        |               |                                                    |                                        |
        |       pin 07  |----------------------------------------o-----|<----o                                        |
        |               |                                                    |                                        |
        |       pin 06  |----------------------------------------o-----|<----o                                        |
        |               |                                                                                 bottom LED  |
        |       pin 05  |---------------------------------------------------------------------------------o-----|<----o
        |               |                                                                                             |
        |       pin 04  |---------------------------------------------------------------------------------o-----|<----o
        |               |                                                                                             |
        |       pin 03  |---------------------------------------------------------------------------------o-----|<----o
        |               |                                                                                             |
        |       pin 02  |---------------------------------------------------------------------------------o-----|<----o
        |               |                                                   
        |_______________|
            
    Future itterations:
        Attach flashing to outside event.  Maybe cellphone alert.
        Use multiple I/O pins flashing at seperate random intervals. 
        
                                                Create Date:        10/05/2014
################################################################################# */

 


//set led pins in sections
int top[] = {13, 12, 11, 10};
int middle[] = {9, 8, 7, 6};
int bottom[] = {5, 4, 3, 2};
int sectionCount = 4;

//set flash variables
int flashT = 100;
//set delay between strikes
int delayPeriod;

// the setup routine runs once when you press reset:
void setup() {                

  for(int p=0; p<sectionCount; p++)
  {
    pinMode(top[p], OUTPUT); // Set the mode to OUTPUT
    pinMode(middle[p], OUTPUT); // Set the mode to OUTPUT
    pinMode(bottom[p], OUTPUT); // Set the mode to OUTPUT
  }
}    // end SETUP


// the loop routine runs over and over again forever:
void loop() {
    delayPeriod = (rand() % 10 + 1) * 1000;       //create random interval between flashes
    
// RESET and turn off all LEDs
    OffApp(top);
    OffApp(middle);
    OffApp(bottom);
    
    delay(delayPeriod);       // Wait for random period between flashes. (1000mS = 1 second)

//bottom flash on
    FlashOnApp(bottom);

//top flash on 
    FlashOnApp(top);

//bottom off; middle on
    delay(flashT);    
    OnApp(middle);
    OffApp(bottom);

//top off; middle off
    delay(flashT);    
    OffApp(top);
    OffApp(middle);
    
}   //end LOOP

// ////////////////////////////////////////////
//
// create functions that flash LEDs
//
// ////////////////////////////////////////////


void FlashOnApp(int ledPins[]){
    delay(flashT);
    OnApp(ledPins);      

    delay(flashT);
    OffApp(ledPins);

    delay(flashT);
    OnApp(ledPins);
}

void OnApp(int ledPins[]){
    for(int t=0; t<sectionCount; t++) //Flash on
    {
      digitalWrite(ledPins[t], LOW);   //Turn ON the bottom LEDs  
    }
}

void OffApp(int ledPins[]){
    for(int t=0; t<sectionCount; t++) //Flash off
    {
      digitalWrite(ledPins[t], HIGH);   //Turn OFF the bottom LEDs   
    }
}
