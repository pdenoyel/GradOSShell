ShellProgram : ShellProgram.o
	g++ -o ShellProgram ShellProgram.cpp

clean :
	rm *.o ShellProgram.exe
