all: vm0 makeMemoryImage viewMemoryImage

#TODO move choice of CC to variable
#TODO add ccoptions variable

vm0: vm0.cxx
	g++ -Wall -o vm0 vm0.cxx

makeMemoryImage: makeMemoryImage.cxx
	g++ -Wall -o makeMemoryImage makeMemoryImage.cxx

viewMemoryImage: viewMemoryImage.cxx
	g++ -Wall -o viewMemoryImage viewMemoryImage.cxx

clean:
	rm vm0
	rm makeMemoryImage
	rm viewMemoryImage
