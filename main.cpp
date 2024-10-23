#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    __darwin_pid_t pid;
    pid = fork();

    if (pid > 0) {
        printf("PARENTS | PID = %ld | PPID = %ld\n", (long) getpid(),
               (long) getppid());

        if (argc > 2) {
            printf("PARENTS | There are %d arguments\n", argc - 1);
            wait(nullptr);
        }
    }

    if (pid == 0) {
        printf("CHILDREN | PID = %ld | PPID = %ld\n", (long) getpid(),
               (long) getppid());

        printf("CHILDREN | List of arguments: \n");

        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    exit(0);
}