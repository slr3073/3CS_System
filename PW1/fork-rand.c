#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
        sleep(rand() % 3);
        printf("... je suis le fils\n");
    } else {
        srand(getpid());
        sleep(rand() % 3);
        printf("... je suis le pere\n");
        pid_child = wait(&status_child);

        if (pid_child == -1) perror("wait() error");
        fprintf(stderr, "status fils : %d\n", WEXITSTATUS(status_child));
    }
    return 0;
}



