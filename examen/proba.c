#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main () {
    char msg[250];
    sprintf(msg, "T");
    int a = 3;
    int codret, pid;
    write(1, msg, strlen(msg));
    if (fork() == 0){
        a = a + 2;
        sprintf(msg, "%sG", msg);
        write(1, msg, strlen(msg));
        exit(a);
    }
    pid=wait(&codret);
    sprintf(msg,"%sR%d", msg, WEXITSTATUS(codret));
    write(1, msg, strlen(msg));
    exit(1);
}