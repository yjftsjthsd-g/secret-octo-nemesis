//utility to make a memory image for use with virtual machine
//by Brian Cole, started 2014-05-31

#include <iostream>
#include <fstream>
using namespace std;

#define MEMSIZE 100

char mainMemory[MEMSIZE];

int main(int argcount, char **argvals)
{
	if(argcount > 1 && argvals[1][0] == '-' && argvals[1][1] == 'd') {
		//use default image:
		mainMemory[0] = 1;      //mov
		mainMemory[1] = 0;      //a
		mainMemory[2] = 66;     //'B'
		mainMemory[3] = 3;      //out
		mainMemory[4] = 2;      //mainMemory[2]
		mainMemory[5] = 3;      //out
		mainMemory[6] = 2;      //mainMemory[2]
		mainMemory[7] = 5;      //hlt
	} else { //read in image from user
		int inValue;
		int i = 0;
		while(i < MEMSIZE && cin) {
			cout << i << ' ' << flush;
			cin >> inValue;
			mainMemory[i] = (char)(inValue);
			i++;
		}
	}

	//output file:
	ofstream outputFile ("mainMemoryImage.memimg", ios::out | ios::binary);
	outputFile.write(mainMemory, 100);
	outputFile.close();
}
