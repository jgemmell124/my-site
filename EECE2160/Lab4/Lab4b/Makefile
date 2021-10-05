output: main.o DE1SoCfpga.o SevenSegment.o LEDControl.o
		g++ main.o DE1SoCfpga.o SevenSegment. LEDControl.o -o output

main.o: main.cpp
		g++ -g -Wall -c main.cpp

DE1SoCfpga.o:	DE1SoCfpga.cpp DE1SoCfpga.h
				g++ -g -Wall -c DE1SoCfpga.cpp

SevenSegment.o:	SevenSegment.cpp SevenSegment.h
				g++ -g -Wall -c SevenSegment.cpp

LEDControl.o:	LEDControl.cpp LEDControl.h
				g++ -g -Wall -c LEDControl.cpp

clean:
		rm *.o output
			