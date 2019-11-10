#include <iostream>
#ifndef linux
#include <direct.h>
#endif
#include <sstream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string>

#ifdef linux 
#include <sys/wait.h>
#include <unistd.h>
#endif
using namespace std;

void inception() {
#ifdef linux
	system("clear");
#else
	system("cls");
#endif
	system("echo '**************Inception Mode**************\n'");
	system("echo '**********A Shell within a Shell**********\n'");
}

int main(){
	bool isInceptionMode = false;

#ifdef linux
	system("clear");
#endif
#ifndef linux
	system("cls");
	_chdir("c:\\");
#endif
	if (isInceptionMode) {
		inception();
	}
	system("echo '**********Welcome to The Shell of The Future**********\n'");
	
	while(true){
		if (isInceptionMode) {
			inception();
			isInceptionMode = false;
		}//if
	//display prompt
	//cout << getcwd(NULL, 0) << ">>" << flush;
	cout << "ShellYeah>>" << flush;
	char command[128];
	cin.getline(command, 128);//getting input from user

	if (strlen(command) == 0) {//user pressed enter
#ifdef linux
		system("\n");
		break;
#else
		system("");
#endif
	}//if
#ifdef linux
	else{//text entered
		vector<char*> args;
		string testString(command);
		int n = (int)testString.length();
		char message[n+1];
		strcpy(message, testString.c_str());
		char* prog = strtok(command, " ");//converting input to char* with string tokens
		char* temp = prog;

		while(temp != NULL){
			args.push_back(temp);
			temp = strtok(NULL, " ");
		}//while

		char** argv = new char*[args.size()+1];
		for(int k=0; k < args.size(); k++)
			argv[k] = args[k];//converting our tokens into an argument list

		argv[args.size()] = NULL;

		if(strcmp(command, "exit")==0){//user wants to exit
			printf("Goodbye\n");
			return 0;
		}//if


		else{//not exit
			if(!strcmp(prog, "cd")){//we don't want to fork for cd
				if (argv[1] == NULL)
					chdir("/");
				else
					chdir(argv[1]);
				perror(command);
			}//if

			else if(testString.find(">")!=-1
				|| testString.find("<")!= -1
				|| testString.find("<<") != -1
				|| testString.find(">>") != -1){//looking for >> << < > tokens
				system(message);
			}//else if
			else{
				pid_t child = fork();
				if(child < 0){//error
					perror("Internal Error: Cannot fork.\n");
					return -1;
				}//if

				else if(child == 0){//child process
					execvp(prog, argv);
					//in case of any errors
					perror(command);
					return -1;
				}//else if

				else{//parent
					if (waitpid(child, 0, 0) < 0){//error again
						perror("Internal error\n");
						return -1;
					}//if
				}//else parent
			}//else pid
		}//else not exit
		}//else

		//else{//text entered
			/*vector<char*> args;
			string testString(command);
			int n = (int)testString.length();
			char message[n+1];
			strcpy(message, testString.c_str());
			char* prog = strtok(command, " ");//converting input to char* with string tokens
			char* temp = prog;

			while(temp != NULL){
				args.push_back(temp);
				temp = strtok(NULL, " ");
			}//while

			char** argv = new char*[args.size()+1];
			for(int k=0; k < args.size(); k++)
				argv[k] = args[k];//converting our tokens into an argument list

			argv[args.size()] = NULL;

			if(strcmp(command, "exit")==0){//user wants to exit
				printf("Goodbye\n");
				return 0;
			}//if


			else{//not exit
				if(!strcmp(prog, "cd")){//we don't want to fork for cd
					if (argv[1] == NULL)
						chdir("/");
					else
						chdir(argv[1]);
					perror(command);
				}//if

			else if(testString.find(">")!=-1
				|| testString.find("<")!= -1
				|| testString.find("<<") != -1
				|| testString.find(">>") != -1){//looking for >> << < > tokens
				system(message);
			}//else if
			else{
				pid_t child = fork();
				if(child < 0){//error
					perror("Internal Error: Cannot fork.\n");
					return -1;
				}

			else if(child == 0){//child process
				execvp(prog, argv);
				//in case of any errors
				perror(command);
				return -1;
			}//

			else{//parent
				if (waitpid(child, 0, 0) < 0){//error again
					perror("Internal error\n");
					return -1;
					}
				}//else parent
			}//else
			}//else cd
		//}//else no text*/
#endif
#ifndef linux
		stringstream substring(command);
		string singleWord;
		getline(substring, singleWord, ' ');
		if (strcmp(singleWord.c_str(), "cd") == 0) {
			getline(substring, singleWord, ' ');
			_chdir(singleWord.c_str());
		}//if
#endif
		if (strcmp(command, "Shell.exe") == 0) {
			isInceptionMode = true;
		}//if
		if (strcmp(command, "exit") == 0) {//user wants to exit
			printf("Goodbye\n");
			return 0;
		}//if
		system(command);
	}//while true

	return 0;
}
