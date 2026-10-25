#include <iostream>
#include <stack>
#include <string>

    //emplace
struct Food {
    std::string name;
    int fruitCount;

    Food(std::string n, int f) {
        name = n;
        fruitCount = f;
        }
    };


int main() {

    //push
    //pop
    //isEmpty
    //isFull
    //Top
    //create an object:
    std::stack <char> stack1;
    std::stack <char> stack2;

    std::cout << "Is the stack empty? " << stack1.empty() << std::endl;
    stack1.push('j');
    std::cout << "current top of the stack: " << stack1.top() << std::endl;
    stack1.push('i');
    std::cout << "current top of the stack: " << stack1.top() << std::endl;
    stack1.push('m');

    std::cout << "Is the stack empty? " << stack1.empty() << std::endl;
    std::cout << "current top of the stack: " << stack1.top() << std::endl;
    std::cout << "what is the size of the stack? " << stack1.size() << std::endl;

    //swap
    stack1.push('y'); stack1.push('j');
    stack2.push('t'); stack2.push('i');
    std::cout << "currentstack: " << stack1.top() << std::endl;
    std::cout << "currentstack: " << stack2.top() << std::endl;
    stack2.swap(stack1);

    std::cout << "currentstack: " << stack1.top() << std::endl;
    std::cout << "currentstack: " << stack2.top() << std::endl;
    
    //emplace
    std::stack<Food> Stack3;
    Stack3.emplace("Banana", 25);

    std::cout << "Fruit: " << Stack3.top().name << std::endl;
    std::cout << "Fruit Count: " << Stack3.top().fruitCount << std::endl;

    return 0;

    }