//utility to make a memory image for use with virtual machine
//by Brian Cole, started 2014-05-31

#include <fstream>
using namespace std;

char mainMemory[100];

int main()
{
	mainMemory[0] = 1;      //mov
	mainMemory[1] = 0;      //a
	mainMemory[2] = 66;     //'B'
	mainMemory[3] = 3;      //out
	mainMemory[4] = 2;      //mainMemory[2]
	mainMemory[5] = 3;      //out
	mainMemory[6] = 2;      //mainMemory[2]
	mainMemory[7] = 5;      //hlt

	ofstream outputFile ("mainMemoryImage.memimg", ios::out | ios::binary); //open file stream for writing
	
	outputFile.write(mainMemory, 100);
	outputFile.close();
}
