osShell : ShellProgram.o
	g++ -o osShell ShellProgram.cpp

clean :
	rm *.o osShell.exe
