all: psmain
	
psmain: pstack.h psmain.cpp
	g++ -Wall psmain.cpp -o psmain
