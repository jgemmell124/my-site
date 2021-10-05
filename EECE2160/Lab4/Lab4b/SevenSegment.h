#include "DE1SoCfpga.h" // DE1 class
#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

using namespace std;


const unsigned int bit_values[16] = {
    0x3F, 0x06, 0x5B, 0x4F,
    0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C,
    0x3B, 0x5E, 0x79, 0x71
};

class SevenSegment: public DE1SoCfpga {
    unsigned int reg0_hexValue;
    unsigned int reg1_hexValue;

      
    public: 

    // constructor
    SevenSegment();

    // clear all values
    void Hex_ClearAll();
    
    // destructor
    ~SevenSegment();


    /** 
     * clears the specificed segment display
     * @param index    the seven segment display # (0-5)
     */
    void Hex_ClearSpecific(int index);

    /** 
     * writes a hexidecimal digit at the specificed segment display
     * @param display_id    the seven segment display # (0-5)
     * @param value     the hexidecimal digit (0-15)
     */
    void Hex_WriteSpecific(int display_id, int value);


    /** 
     * writes a positive or negative number on segment display
     * @param number    the positive or negative number
     */
    void Hex_WriteNumber(int number);

};
#endif