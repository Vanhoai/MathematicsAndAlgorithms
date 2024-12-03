#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

vector<int> a;
std::mutex mtx;

void addToArray() {
    for (int i = 0; i < 1000; ++i) {
        int randomNumber = rand() % 100;
        {
            std::lock_guard<std::mutex> lock(mtx);
            a.push_back(randomNumber);
            cout << "Thread 1: Added " << randomNumber
                 << " to array. Current size: " << a.size() << endl;
        }
    }
}

void removeFromArray() {
    for (int i = 0; i < 1000; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (!a.empty()) {
                int removed = a.back();
                a.pop_back();
                cout << "Thread 2: Removed " << removed
                     << " from array. Current size: " << a.size() << endl;
            } else {
                cout << "Thread 2: Nothing in array a\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));

    thread t1(addToArray);
    thread t2(removeFromArray);

    t1.join();
    t2.join();

    return 0;
}
