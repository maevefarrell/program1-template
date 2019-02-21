all: program1.cpp Star.cpp Planet.cpp List.cpp Vector.cpp
	g++ -g program1.cpp Star.cpp Planet.cpp List.cpp Vector.cpp -o program1
run: all
	./program1
clean:
	rm -f *.o program1.exe
