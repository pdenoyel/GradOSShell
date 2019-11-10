myshell : linuxShell.o
	gcc -o myshell linuxShell.c

clean :
	rm *.o myshell.exe
