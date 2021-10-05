#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cmath>
#include <iostream>
#include "DE1SoCfpga.h" // DE1 class
#include "SevenSegment.h"   // SevenSegment class

/**
* Main operates the DE1-SoC 7-Segment Displays
 * *This program writes an integer number on the 7-Segment Displays
 * 
 * */
int main(void){
    int count=-25;
    //Create a pointer object of the SevenSegment class 
    SevenSegment *display = new SevenSegment;
    cout<<"ProgramStarting...!"<<endl; 
    //Update the display every second 
    while(count<=25) {
        int hex_value = count*count*count;  //Value to display
        cout<<"Count:"<<count<<",Value="<<hex_value<<endl;
        display->Hex_WriteNumber(hex_value);  //display value
        sleep(1); //wait for 1 second 
        count++; //increment count 
    }
    delete display; //delete class object
    cout<<"Terminating...!"<<endl;
    return 0;
}