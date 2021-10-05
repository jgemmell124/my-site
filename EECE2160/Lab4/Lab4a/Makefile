output: main.o DE1SoCfpga.o SevenSegment.o
		g++ main.o DE1SoCfpga.o SevenSegment.o -o output

main.o: main.cpp
		g++ -g -Wall -c main.cpp

DE1SoCfpga.o:	DE1SoCfpga.cpp DE1SoCfpga.h
				g++ -g - Wall -c DE1SoCfpga.cpp

SevenSegment.o:	SevenSegment.cpp SevenSegment.h
				g++ -g -Wall -c SevenSegment.cpp

clean:
		rm *.o output
			