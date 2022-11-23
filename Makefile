prog : main.o ArbreBC.o Element.o Noeud.o
	g++ main.o ArbreBc.o Element.o Noeud.o -o main

main.o : main.cpp ArbreBc.h Element.h
	g++ -g -Wall -c main.cpp -o main.o

ArbreBc.o : ArbreBc.cpp ArbreBc.h Element.h
	g++ -g -Wall -c ArbreBc.cpp -o ArbreBc.o

Element.o : Element.cpp Element.h
	g++ -g -Wall -c Element.cpp -o Element.o

Noeud.o : Noeud.cpp Noeud.h
	g++ -g -Wall -c Noeud.cpp -o Noeud.o
