//memory image viewer
//by Brian Cole, 2014-05-31

#include <iostream>
#include <fstream>
using namespace std;

#define MEMSIZE 100

char mainMemory[MEMSIZE];
ifstream inputFile;

int main(int argc, char **argv)
{
	if(argc == 1) {
		cout << "viewMemoryImage must be supplied a file to read, ex." << endl;
		cout << "viewMemoryImage mainMemoryImage.memimg" << endl;
		return 1;
	} else {
		inputFile.open(argv[1], ios::in | ios::binary); //open the spec'd file in binary+input mode
		//example code at http://www.cplusplus.com/doc/tutorial/files/ also had file.seekg(0, ios::beg); here
		inputFile.read(mainMemory, MEMSIZE);
		inputFile.close();

		//TODO scan backwards for last nonzero item, then only list up to that

		for(int i = 0; i < MEMSIZE; i++) {
			cout << i << ' ' << (int)(mainMemory[i]) << endl;
		}
	}
}

