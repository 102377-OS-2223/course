#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "helpers.h" //errors; enters; compareCommands
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include "log.h" //log_debug()

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void launchcmd(char** args);

int main(int argc, char *argv[]){
    // while not comand exit
        // readline
        // parseline
        // launch comand
    char *buffer;
    //int acabado = 0;
    size_t buffersize;
    bool exit = false;
    
    while (!exit){
        printf(BLU "ossh> " RESET);
        getline(&buffer, &buffersize, stdin);
        //read_line(&buffer);
        //parseline();
        buffer[strcspn(buffer, "\n")] = '\0';
        launchcmd(&buffer);

        if (strncmp(buffer, "exit", buffersize) == 0){
            exit = true; 
        }

        compareCommands(buffer);
        errors(buffer);
        enters(buffer);

        if (strncmp(buffer, "help", buffersize) == 0){
            ayuda();
        }
    }
    log_debug(MAG "Stopping the ossh shell... :(" RESET);
	return EXIT_SUCCESS;
}

void launchcmd(char** args){
    pid_t pid;
    int st;
    pid = fork();

    if(pid == 0){
        execvp(args[0], args);
    } else {
        waitpid(pid, &st, 0);
    }
}