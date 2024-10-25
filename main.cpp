#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
using namespace std;

vector<pair<int, int>> pi;   // edges
int a[1001][1001];           // matrix
vector<int> adj[1001];

// 1: { 2, 3 }
// 2: { 3, 4 }

int main() {

    int pid;
    pid = fork();

    if (pid > 0) {
        printf("I am the parent process\n");
        wait(nullptr);
        exit(0);
    } else if (pid == 0) {
        execl("/bin/ls", "ls", "-l", nullptr);
        printf("I am the child process\n");
        exit(0);
    } else {
        printf("fork failed\n");
        exit(-1);
    }

    return 0;
}