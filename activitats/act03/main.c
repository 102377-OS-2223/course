#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void launchcmd(char** args);

int main(int argc, char *argv[]){
    // while not comand exit
        // readline
        // parseline
        // launch comand

    int acabado = 0;
    char *buffer;
    size_t buffersize = 0;
    
    do{
        getline(&buffer, &buffersize, stdin);
        //parseline();
        launchcmd(&buffer);
        if (strcmp(buffer, "exit")){
            acabado = 1;
        } 


    } while(acabado == 0);
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