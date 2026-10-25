#include <iostream>
#include <queue>
#include <string>

void displayAll(std::queue <std::string> q) {
    std::queue <std::string> c = q;

    std::cout << "Size: " << c.size() << std::endl;
    std::cout << "Front: " << c.front() << std::endl;
    std::cout << "Back: " << c.back() << std::endl;
    std::cout << "\nStudents in Queue:\n";

    while(!c.empty()) {
        std::cout << c.front() << std::endl;
        c.pop();
    }
}

int main() {
    std::queue <std::string> student_queue;

    student_queue.push("James");
    student_queue.push("Joshua");
    student_queue.push("Anthony");
    student_queue.push("Mark");
    displayAll(student_queue);
    
    return 0;
}