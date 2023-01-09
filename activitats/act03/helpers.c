#include <string.h> // strstr()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "helpers.h"
#include "log.h" //log_debug(), log_error()

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define commands "help" "exit"

int ayuda(){
    printf(GRN "#### GTIDIC - UDL - OSSH #################################\n"
        "#" YEL "                                                       " GRN " #\n"   
        "#" YEL " Type program names and arguments, and hit enter.      " GRN " #\n"
        "#" YEL " Use the man command for information on other programs." GRN " #\n"
        "#" YEL "                                                       " GRN " #\n"
        "##########################################################\n" RESET);
    return 1;
}

int split_line(char *line, char* separator, char ***tokens){
    return 0;
}

int read_line(char** line){
    size_t buffersize = 0;

    if (getline(line, &buffersize, stdin) == -1){
        perror(RED "read_line():getline" RESET);
        return -1;
    }
    return 0;
}

int errors(char *c){
    for (int i = 0; i < strlen(c); i++){
        if (c[i] == '[' || c[i] == '|' || c[i] == '>' || c[i] == '<' || c[i] == '&' || c[i] == ']'){
            log_error(RED "Not allowed operators" MAG "[|><&]" RESET);
            return 1;
        }
    }
    return 0;
}

int enters(char *c){
    for (int i = 0; i < strlen(c); i++){
        if (c[i] == '\n'){
            free(c);
            return 1;
        }
    }
    return 0;
}

int compareCommands (char *c){
    if ((strcmp(c, commands))){
        return 0;
    } else {
        log_debug(RED "Command not recognisable >:( \n" RESET);
        return 1;
    }
}