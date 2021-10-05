#include <iostream>
#include "SevenSegment.h"
using namespace std;

//  Initializes the private data members so the board displays all zeros
SevenSegment::SevenSegment() {   
    // set values to 0
    reg0_hexValue = 0;
    reg1_hexValue = 0;
    
    // set all to displays to '0'
    for (int i = 0; i < 4; i++) {
        this->reg0_hexValue = reg0_hexValue | bit_values[0]<<(8*i);
    }

    for (int i = 0; i < 2; i++) {
        this->reg1_hexValue = reg1_hexValue | bit_values[0]<<(8*i);
    }
    for (int i = 0; i < 8; i++) {
        this->Hex_WriteSpecific(i, bit_values[0]);
    }
    
    
}

//  Turns off all the 7-segment displays 
void SevenSegment::Hex_ClearAll() {
    // set both indexes to 0
    this->RegisterWrite(HEX3_HEX0_BASE, 0);
    this->RegisterWrite(HEX5_HEX4_BASE, 0);
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
        reg0_hexValue = (this->RegisterRead(HEX3_HEX0_BASE) & ~(127<<(8*index)));
        this->RegisterWrite(HEX3_HEX0_BASE, reg0_hexValue);
    }
    else {   
        reg1_hexValue = (this->RegisterRead(HEX5_HEX4_BASE) & ~(127<<(8*(index -4))));
        this->RegisterWrite(HEX5_HEX4_BASE, reg1_hexValue); 
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
        reg0_hexValue = (this->RegisterRead(HEX3_HEX0_BASE) | (bit_values[value]<<(8*display_id)));
        this->RegisterWrite(HEX3_HEX0_BASE, reg0_hexValue);
    }
    else {
        reg1_hexValue = (this->RegisterRead(HEX5_HEX4_BASE) | (bit_values[value]<<(8*(display_id - 4))));
        this->RegisterWrite(HEX5_HEX4_BASE, reg1_hexValue);
    }
}
/*  Writes the hex decimal value of a positive or 
    negative number on the sic 7-segemnt displays 
*/
void SevenSegment::Hex_WriteNumber(int number) {
    //clear all
    this->Hex_ClearAll();
    // keep track of index
    int index = 0;
    // if the number is negative
    if (number < 0) {
        // make positive
        number *= -1;
        do { 
            // write the led
            this->Hex_WriteSpecific(index, number%10);
            number /= 10;
            // increase index
            index++;   
        } while (number != 0);

        // add the negative sign
        if(index <= 3) {   
            reg0_hexValue = (this->RegisterRead(HEX3_HEX0_BASE) | (64<<(8*index)));
            this->RegisterWrite(HEX3_HEX0_BASE, reg0_hexValue);
        }
        else {
            reg1_hexValue = (this->RegisterRead(HEX5_HEX4_BASE) | (64<<(8*(index - 4))));
            this->RegisterWrite(HEX5_HEX4_BASE, reg1_hexValue);
        }
    }
    // if the number is positive
    else {
        do { 
            this->Hex_WriteSpecific(index, number%10);
            number /= 10;
            index++;   
        } while (number != 0);
    }

}
