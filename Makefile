CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic
OPTFLAGS=-O3
LDFLAGS=$(OPTFLAGS) $(CXXFLAGS)

all:  pi

pi: pi.cc
	$(CXX) $(LDFLAGS) pi.cc -o pi

clean:
	rm -rf *.o pi
