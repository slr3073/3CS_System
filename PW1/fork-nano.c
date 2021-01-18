#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mssleep(long ms){
    struct timespec delai;
    delai.tv_sec = ms / 1000;
    delai.tv_nsec = (ms / 1000) * 1000000;
    int res = nanosleep(&delai, NULL);
    if (res == -1) perror("nanosleep");
}

int main() {
    pid_t pid_child;
    int status_child;
    printf("Bonjour\n");

    pid_child = fork();
    if (pid_child == -1) {
        perror("fork() impossible");
        exit(1);
    }
    if (pid_child == 0) {
        srand(getpid());
        mssleep(rand() % 3);
        printf("... je suis le fils\n");
    } else {
        srand(getpid());
        mssleep(rand() % 3);
        printf("... je suis le pere\n");
        pid_child = wait(&status_child);
        if (pid_child == -1) {
            perror("wait() error");
        } else {
            fprintf(stderr, "status fils: %d\n", WEXITSTATUS(status_child));
        }
    }
    return rand() % 256;
}