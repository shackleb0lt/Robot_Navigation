CC = g++


CPP = Main.cpp  Grid.cpp File.cpp Node.cpp

EXE = main

all:
	$(CC) $(CPP) -o $(EXE)
clean:
	rm $(EXE)
	clear