#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid_child;
    printf("Bonjour\n");
    pid_child = fork();

    if (pid_child == 0)
        printf("... je suis le fils\n");
    else
        printf("... je suis le pere\n");

    return 0;
}
