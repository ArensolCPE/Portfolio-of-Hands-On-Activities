#include <iostream>
#include <string>

class Food {
protected:
    std::string itemName;
    double price;
    int quantity;

public:
    //Constructor
    Food(std::string name = "", double p = 0, int q = 0) {
        itemName = name;
        price = p;
        quantity = q;
    }

    //Destructor
    virtual ~Food() {
        std::cout << itemName << " Removed" << std::endl;
    }

    //Copy Constructor
    Food(const Food& copy) {
        itemName = copy.itemName;
        price = copy.price;
        quantity = copy.quantity;
    }

    //Copy Assignment Operator
    Food& operator=(const Food& copy) {
        if (this != &copy) {
            itemName = copy.itemName;
            price = copy.price;
            quantity = copy.quantity;
        }
        return *this;
    }

    virtual void menuDetails() {
        std::cout << itemName << " | Price: PHP " << price << " | Quantity: " << quantity << " | Total: PHP " << totalCalculation() << std::endl;
    }

    double totalCalculation() {
        return price * quantity;
    }
};

class Fruit: public Food {
public:
    Fruit(std::string name, double p, int q): Food(name, p, q) {}

    void menuDetails() override {
        std::cout << "[Fruit] ";
        Food::menuDetails();
    }
};

class Vegetable: public Food {
public:
    Vegetable(std::string name, double p, int q): Food(name, p, q) {}

    void menuDetails() override {
        std::cout << "[Vegetable] ";
        Food::menuDetails();
    }
};

double sum(Food * List[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        if (List[i] != nullptr) {
            total += List[i]->totalCalculation();
        }
    }
    return total;
}

int main () {
    Food* List[4];

    List[0] = new Fruit("Apple", 10, 7);
    List[1] = new Fruit("Banana", 10, 8);
    List[2] = new Vegetable("Broccoli", 60, 12);
    List[3] = new Vegetable("Lettuce", 50, 10);

    std::cout << "================== Jenny's Grocery List ==================\n\n";
    for (int i = 0; i < 4; i++) {
        List[i]->menuDetails();
    }
    
    std::cout << "\nTotal Grocery Cost: PHP " << sum(List, 4) << std::endl;
    std::cout << "Deleting lettuce from the list...\n" << std::endl;
        delete List[3];
        List[3] = nullptr;
    std::cout << "\nUpdated Grocery List:\n\n";
    for (int i = 0; i < 4; i++) {
        if (List[i] != nullptr) {
            List[i]->menuDetails();
        }
    }

    std::cout << "\nTotal Grocery Cost: PHP " << sum(List, 4) << std::endl;

    return 0;
}