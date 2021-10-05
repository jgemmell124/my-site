#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;
#include "SevenSegment.h"
#include "DE1SoCfpga.h"


//  Initializes the private data members so the board displays all zeros
SevenSegment::SevenSegment() {   
    reg0_hexValue = 0;
    reg1_hexValue = 0;
    
}

//  Turns off all the 7-segment displays 
void SevenSegment::Hex_ClearAll() {
    // set both indexes to 0
    DE1SoCfpga::RegisterWrite(HEX3_HEX0_BASE, 0x0);
    DE1SoCfpga::RegisterWrite(HEX5_HEX4_BASE, 0x0);
}

//  Clears all the displays
SevenSegment::~SevenSegment() {
    // clear all
    this->Hex_ClearAll();
}

//  Turns off a the 7-segment display specified by the index (0 to 5)
void SevenSegment::Hex_ClearSpecific(int index) {   
    // check which segemnt to put it on
    if(index <= 3) {
        // mask new value and set it to the hex value
        reg0_hexValue = (DE1SoCfpga::RegisterRead(HEX3_HEX0_BASE) & ~(127<<(8*index)));
        DE1SoCfpga::RegisterWrite(HEX3_HEX0_BASE, reg0_hexValue);
    }
    else {   
        reg1_hexValue = (DE1SoCfpga::RegisterRead(HEX5_HEX4_BASE) & ~(127<<(8*(index -4))));
        DE1SoCfpga::RegisterWrite(HEX5_HEX4_BASE, reg1_hexValue); 
    }
}
/*  Displays the hexdecimal digit, specified by a decimal value (0 to 15)
    to the 7-segment display specified by display__id which represents
    one of the 6 displays (0 to 5).
*/
void SevenSegment::Hex_WriteSpecific(int display_id, int value) {
    // check which segment to write to
    if(display_id <= 3) {   
        // mask new value
        reg0_hexValue = (DE1SoCfpga::RegisterRead(HEX3_HEX0_BASE) | (bit_values[value]<<(8*display_id)));
        DE1SoCfpga::RegisterWrite(HEX3_HEX0_BASE, reg0_hexValue);
    }
    else {
        reg1_hexValue = (DE1SoCfpga::RegisterRead(HEX5_HEX4_BASE) | (bit_values[value]<<(8*(display_id - 4))));
        DE1SoCfpga::RegisterWrite(HEX5_HEX4_BASE, reg1_hexValue);
    }
}
/*  Writes the hex decimal value of a positive or 
    negative number on the sic 7-segemnt displays 
*/
void SevenSegment::Hex_WriteNumber(int number) {
    //clear all
    this->Hex_ClearAll();
    int id = 0;
    // if the number is negative
    if (number < 0) {
        // make positive
        number *= -1;
        do { 
            // write the led
            this->Hex_WriteSpecific(id, number%10);
            number /= 10;
            // increase index
            id++;   
        } while (number != 0);

        // add the negative sign
        if(id <= 3) {   
            reg0_hexValue = (DE1SoCfpga::RegisterRead(HEX3_HEX0_BASE) | (64<<(8*id)));
            DE1SoCfpga::RegisterWrite(HEX3_HEX0_BASE, reg0_hexValue);
        }
        else {
            reg1_hexValue = (DE1SoCfpga::RegisterRead(HEX5_HEX4_BASE) | (64<<(8*(id - 4))));
            DE1SoCfpga::RegisterWrite(HEX5_HEX4_BASE, reg1_hexValue);
        }
    }
    // if the number is positive
    else {
        do { 
            this->Hex_WriteSpecific(id, number%10);
            number /= 10;
            id++;   
        } while (number != 0);
    }

}
