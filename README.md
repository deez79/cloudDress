cloudDress
==========

arduino code for physical computing project.  This code will control the LED's that will be sewn into a dress to simulate a cloud in a thunderstorm.

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
