#include <iostream>
#include <thread>
using namespace std;

#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)
#define READ_WRITE_FILE                                                        \
    freopen("in.txt", "r", stdin);                                             \
    freopen("out.txt", "w", stdout)

void printFromThread() { cout << "Hello from thread" << endl; }

int main() {
    FAST_IO;
    READ_WRITE_FILE;

    thread threadObject(printFromThread);

    cout << "Hello from main" << endl;

    return 0;
}
