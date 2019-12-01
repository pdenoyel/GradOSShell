projectshell : ShellProgram.o
	g++ -o projectshell ShellProgram.cpp

clean :
	rm *.o projectshell.exe
