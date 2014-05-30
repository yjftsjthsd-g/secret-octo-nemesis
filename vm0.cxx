//first virtual machine
//by Brian Cole, 2014-05-30

#include <iostream>

//int a, b, c, d, e; //general purpose registers
int reg[10]; //general purpose registers
int mainMemory[100];
int nextInstruction;

void resetMachine()
{
	nextInstruction = 0;
	for(int i = 0; i < 10; i++) {
		reg[i] = 0;
	}
	//a = b = c = d = e = 0;
}

int main()
{
	resetMachine();

	//initialize contents of main memory
	mainMemory[0] = 1;	//mov
	mainMemory[1] = 0;	//a
	mainMemory[2] = 13;	//13
	mainMemory[3] = 13;

	//main loop
	while(nextInstruction < 100) { //TODO should do MEMSIZE or such
		/*
		opcodes:
		0 reset()
		1 mov(var, val)
		2 in(addr)
		3 out(addr)
		4 jmp(addr)
		5 hlt()
		*/
		switch(mainMemory[nextInstruction]) {
			case 0:
				resetMachine();
				break;
			case 1:
				reg[mainMemory[nextInstruction+1]] = mainMemory[nextInstruction+2];
				nextInstruction += 2;
				break;
			case 2:
				mainMemory[nextInstruction+1] = 0; //TODO
				break;
			case 3:
				cout << mainMemory[nextInstruction+1] << endl;
				break;
			default:
				//do nothing
		}
	}
	return 0;

