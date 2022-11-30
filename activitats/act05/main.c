#include "utils.h"

void signalHandler(int sig, siginfo_t *siginfo, void *context);

int players = 0;
char *alarmTime;
char *unlock;

pid_t alarmPid;
pid_t *childs;

struct sigaction siga;

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Ús: %s <TEMPS_DE_PARTIDA> <NUM_JUGADORS> <PARAULA>\n", argv[0]);
        exit(1);
    }

    alarmTime = argv[1];
    players = atoi(argv[2]);
    unlock = argv[3];

    siga.sa_sigaction = *signalHandler;
    siga.sa_flags |= SA_SIGINFO;

    //code
    if(sigaction(SIGUSR1, &siga, NULL) != 0) {
        perror("signal");
        exit(1);
    }

    if(sigaction(SIGUSR2, &siga, NULL) != 0) {
        perror("signal");
        exit(1);
    }

    printf("Inici del Escape Room [%d] (%s segons)\n", getpid(), alarmTime);
    printf("--- Entren %d jugadors a la sala\n", players);
    printf("--- La paraula a endevinar és: %s\n", unlock);

    int fd[2];
    pipe(fd);
    close(fd[0]);
    close(fd[1]);

    childs = (pid_t *) malloc((unsigned) players * sizeof(pid_t));

    for(int i = 0; i < players; i++) {
        switch(childs[i] = fork()) {
            case -1:
                perror("fork");
                exit(EXIT_FAILURE);
            case 0:
                printf(BLUE"EscapeRoom[%d] ha entrat el jugador[%d]\n"RESET, getppid(), getpid());
                char *args[] = {"./player", unlock, NULL};
                execv(args[0], args);
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    sleep(1);

    switch(alarmPid = fork()) {
        case -1:
            perror("Error creating alarm process");
            exit(-1);
        case 0: ;
            char *args[] = {"./alarm", alarmTime, NULL};
            execv(args[0], args);
            perror("Error executing alarm process");
            exit(-1);
    }

    pause();

    return 0;
}

void signalHandler(int sig, siginfo_t *siginfo, void *context) {
    pid_t sender_pid = siginfo->si_pid;

    if (sig == SIGUSR1) { // ALARM
        printf(RED"************DING DONG\n"RESET);
        for(int i = 0; i < players; i++) {
            printf(RED"El jugador[%d] ha quedat atrapat i surt de EscapeRoom[%d]\n"RESET, childs[i], getpid());
            kill(childs[i], SIGKILL);
        }
        printf("--- Els jugadors han perdut la partida. Fins aviat!\n");
        exit(0);
    } else if (sig == SIGUSR2) { // PLAYER FOUND KEY
        printf(RESET"El jugador[%d] ha trobat la contrasenya %s!\n", sender_pid, unlock);
        kill(alarmPid, SIGKILL);
        for(int i = 0; i < players; i++) {
            printf(GREEN"El jugador[%d] ha escapat i surt de EscapeRoom[%d]\n"RESET, childs[i], getpid());
            kill(childs[i], SIGKILL);
        }
        printf("--- Els jugadors han guanyat la partida en %d segons!\n", 3);
        exit(0);
    } else {
        //kill all subprocesses
        for(int i = 0; i < players; i++) {
            kill(childs[i], SIGKILL);
        }
        kill(alarmPid, SIGKILL);
        exit(0);
    }
}