#include <iostream>
#include <thread>
#include <vector>

int gloVar = 0;

void add(int value) {
    gloVar += value;
}

int main() {
    std::vector<int> values = {2, 4, 6};
    std::vector<std::thread> threads;

    for (int i = 0; i < values.size(); ++i) {
        threads.push_back(std::thread(add, values[i]));
    }

    for (int i = 0; i < threads.size(); ++i) {
        threads[i].join();
    }

    std::thread T1(add, 2);
    std::thread T2(add, 4);
    std::thread T3(add, 6);

    std::cout << "Value after starting the threads: " << gloVar << std::endl;

    T1.join();
    std::cout << "Value after T1.join(): " << gloVar << std::endl;

    T2.join();
    std::cout << "Value after T2.join(): " << gloVar << std::endl;

    T3.join();
    std::cout << "Value after T3.join(): " << gloVar << std::endl;

    return 0;
}