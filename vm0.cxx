//first virtual machine
//by Brian Cole, started 2014-05-30

#include <iostream>
using namespace std;

#define MEMSIZE 100

int reg[10]; //general purpose registers
int mainMemory[MEMSIZE];
int executionPointer;

void resetMachine()
{
	executionPointer = 0;
	for(int i = 0; i < 10; i++) {
		reg[i] = 0;
	}
}

int main()
{
	resetMachine();

	//initialize contents of main memory
	mainMemory[0] = 1;	//mov
	mainMemory[1] = 0;	//a
	mainMemory[2] = 13;	//13
	mainMemory[3] = 3;	//out
	mainMemory[4] = 2;	//mainMemory[2]
	mainMemory[5] = 5;	//hlt

	//main loop
	while(executionPointer < MEMSIZE) {
		/*
		opcodes:
		0 reset()
		1 mov(var, val)
		2 in(addr)
		3 out(addr)
		4 jmp(addr)
		5 hlt()
		other nop()
		*/
		cout << "DEBUG: executionPointer = " << executionPointer << ", mainMemory[executionPointer] = " << mainMemory[executionPointer] << endl;
		switch(mainMemory[executionPointer]) {
			case 0: //reset
				resetMachine();
				break;
			case 1: //mov(var, val)
				reg[mainMemory[executionPointer + 1]] = mainMemory[executionPointer + 2];
				executionPointer += 2; //skip arguments
				break;
			case 2: //in(addr)
				mainMemory[executionPointer+1] = 0; //TODO
				break;
			case 3: //out(addr)
				cout << mainMemory[mainMemory[executionPointer+1]] << endl;
				executionPointer += 1; //skip argument
				break;
			case 4: //jmp(addr)
				executionPointer = mainMemory[executionPointer+1] - 1;
				break;
			case 5: //hlt()
				executionPointer = MEMSIZE + 1;
				break;
			default: //nop()
				break;
		}
		executionPointer++;
	}
	return 0;
}
