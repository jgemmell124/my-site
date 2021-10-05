#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;

#include "DE1SoCfpga.h"
#include "LEDControl.h"

// constructor
LEDControl::LEDControl() {
    // LED Register
    leds_regvalue = 0;    
    // keep track of prev button
    prev_btn = -1;
}

// destructor
LEDControl::~LEDControl() {
    cout<<"Closing LEDs, Switches, & Buttons..."<<endl;
}

// write to one LED
void LEDControl::Write1Led(int ledNum, int state) {
    // if state is one
    if (state == 1) {
        // turn the led on
        leds_regvalue = this->RegisterRead(LEDR_BASE) | (1<<ledNum);
        this->RegisterWrite(LEDR_BASE, leds_regvalue);
    }
    else {
        // turn it off
        leds_regvalue = this->RegisterRead(LEDR_BASE) & ~(1<<ledNum);
        // read current bits and flip bits of bit to turn off
        this->RegisterWrite(LEDR_BASE, leds_regvalue);
    }
}
        

/** Set the state of the LEDswith the given value.
* @param value  Value between 0 and 1023 written to the LEDs
*/
void LEDControl::WriteAllLeds(int value) {
     this->RegisterWrite(LEDR_BASE, value);
}

// read 1 switch
int LEDControl::Read1Switch(int switchNum) {
    int val = (this->RegisterRead(SW_BASE) & 1<<switchNum);
    // if the switch is 'on'
    if (val != 0) {
        return 1;
    }
    else {
        return 0;
    }
}


 /** Reads all the switches and returns their value in a single integer.
* @param pBase  Base address for general-purpose I/O
* @return       A value that represents the value of the switches
*/
int LEDControl::ReadAllSwitches() {
    return this->RegisterRead(SW_BASE);
}


// get value of pushbutton
int LEDControl::PushButtonGet() {
    // read value from key_base
    int val = this->RegisterRead(KEY_BASE);
    // if button is same as last button or not pressed
    if (val == 0) {
        //btn = 0;
        return -1;
    }
    // if 0 button is pressed (2^0 = 1)
    else if (val == 1) {
         // if button is 0
        return 0;
    }
    // if 1st button is pressed (2^1 = 2)
    else if (val == 2) {
        return 1;
    }
    //if 2nd button is pressed (2^2 = 4)
    else if (val == 4) {
        return 2;
    }
    // if 3rd button is pressed (2^3 = 8)
    else if (val == 8) {
        return 3;
    }
    // if multiple buttons are pressed
    else {
        return 4;
    }
}
        