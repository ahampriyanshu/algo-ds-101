all: Kadane.o

Kadane.o: obj/main.o obj/functions.o
	g++ obj/main.o obj/functions.o -o Kadane

obj/main.o: src/main.cpp
	g++ -c src/main.cpp && mv main.o obj/main.o

obj/functions.o: src/functions.cpp
	g++ -c src/functions.cpp && mv functions.o obj/functions.o
