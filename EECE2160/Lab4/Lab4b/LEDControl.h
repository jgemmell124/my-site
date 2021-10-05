#include "DE1SoCfpga.h"

#ifndef LEDCONTROL_H
#define LEDCONTROL_H


class LEDControl: public DE1SoCfpga {
    private:
        unsigned int leds_regvalue;

    public:

    // to keep track of previous button
        int prev_btn;

        // constructor
        LEDControl();

        // destructor
        ~LEDControl();

        // write to one LED
        void Write1Led(int ledNum, int state);
        

        /** Set the state of the LEDswith the given value.
        * @param value  Value between 0 and 1023 written to the LEDs
        */
        void WriteAllLeds(int value);

        // read 1 switch
        int Read1Switch(int switchNum);


        /** Reads all the switches and returns their value in a single integer.
        * @param pBase  Base address for general-purpose I/O
        * @return       A value that represents the value of the switches
        */
        int ReadAllSwitches();

        // get value of pushbutton
        int PushButtonGet();

        // keys to led 
        void KeyToLed();  

}; // end class
#endif