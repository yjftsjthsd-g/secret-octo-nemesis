all: vm0 makeMemoryImage

vm0: vm0.cxx
	g++ -o vm0 vm0.cxx #TODO move choice of CC to variable

makeMemoryImage: makeMemoryImage.cxx
	g++ -o makeMemoryImage makeMemoryImage.cxx #TODO move choice of CC to variable

clean:
	rm vm0
	rm makeMemoryImage
