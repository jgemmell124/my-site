#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

#include "DE1SoCfpga.h"
#include "SevenSegment.h"
#include "LEDControl.h"

using namespace std;



int val;// defines status for switch
int prev_btn = -1; // defines counter
int led_val = 0; // current values of leds

int main(void)
{
    // Create a pointer object of type LEDControl class
    LEDControl *led = new LEDControl;
    // Create a pointer object of the SevenSegment class
    SevenSegment *display = new SevenSegment;
    
    // initialize the values to the switches
    // read all the switches
    led_val = led->ReadAllSwitches();
    
    // write the value to the led display
    led->WriteAllLeds(led_val);
    // read led again to prevent numbers not between 0-1023
    led_val = led->RegisterRead(LEDR_BASE);
    // write the values to seven segemnt display
    display->Hex_WriteNumber(led_val);
    // if it is the same as prev_btn then exit the function

    cout << "Push a button: " << endl;
     // get button push
     while (true) {
        // get value from the pushbutton
        val = led->PushButtonGet();

        // check if it is the sam button as last
        if (val == prev_btn) {
            continue;
        }
        else {
        // int bit_count = RegisterRead(pBase, LEDR_BASE);
            switch (val) {
                // Key0 pressed
                case -1:
                    prev_btn = val;
                    break;
                case 0:
                    prev_btn = val;
                    led_val = led->RegisterRead(LEDR_BASE)-1;
                    break;
                // Key1 pressed
                case 1:
                    led_val = led->RegisterRead(LEDR_BASE)+1;
                    prev_btn = val;
                    break;
                // Key2 pressed
                case 2:
                    // shift to left
                    led_val = led->RegisterRead(LEDR_BASE)>>1;
                    prev_btn = val;
                    break;
                // Key3 pressed
                case 3:
                    // shift to right
                    led_val = led->RegisterRead(LEDR_BASE)<<1;
                    prev_btn = val;
                    break;
                // Multiple pressed
                case 4:
                    // set bitcount to switches
                    led_val = led->ReadAllSwitches();
                    prev_btn = val;
                    break;
                // no buttons / same button pressed
                default:
                    break;
                }
                
            // write the value to the led display
            led->WriteAllLeds(led_val);
            // read led again to prevent numbers not between 0-1023
            led_val = led->RegisterRead(LEDR_BASE);
            // write the values to seven segemnt display
            display->Hex_WriteNumber(led_val);
            // if it is the same as prev_btn then exit the function
        }

           
    }
    delete led; // delete class object
    delete display;  // delete class object
}