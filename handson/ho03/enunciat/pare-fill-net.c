#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys.wait.h>

int status;
pid_t childPid;

int main() {
    pid_t pid;

    char *buffer = malloc(100*sizeof(char));
    sprintf(buffer, "PARE pid: %d", getpid());
    write(1, buffer, strlen(buffer));
    free(buffer);

    pid = fork();
    if (pid == 0) {
        char *buffer = malloc(100*sizeof(char));
        sprintf(buffer, "FILL pid: %d", getpid());
        write(1, buffer, strlen(buffer));
        buffer = '\0';
        free(buffer);
    }

    childPid = fork();
    if (childPid == 0) {
        char *buffer = malloc(100*sizeof(char));
        sprintf(buffer, "FILL pid: %d", getpid());
        write(1, buffer, strlen(buffer));
        buffer = '\0';
        free(buffer);

        char *buffer = malloc(100*sizeof(char));
        sprintf(buffer, "FILL pid: %d", getpid());
        write(1, buffer, strlen(buffer));
        buffer = '\0';
        free(buffer);
    }
}