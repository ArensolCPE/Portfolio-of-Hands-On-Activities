#include <iostream>
using namespace std;

int main() {
    float buyCar, sellCar, payment, transactionHistory;
    int price;
    int choice;
    int carChoice;

    cout << "=========================== WELCOME TO THE CAR STORE ===========================" << endl;
    cout << "\n Pick a Option! \n" << endl;
    cout << "================================================================================" << endl;

    cout << "1. " << "View and Buy Cars Section" << endl;
    cout << "2. " << "Sell Section" << endl;
    cout << "3. " << "Payment" << endl;
    cout << "4. " << "Transaction History" << endl;
    cout << "5. " << "Exit" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\n Available Cars in the Market \n";

        cout << "1. " << "Lamborghini Revuelto" << endl;
        cout << "2. " << "Bugatti Chiron" << endl;
        cout << "3. " << "Tesla Roadster" << endl;
        cout << "4. " << "Batmobile" << endl;
        cout << "5. " << "Einstein's Secret 1949 Rocket Car" << endl;
        cout << "6. " << "1967 Ford Mustang" << endl;

        cout << "Select a Car: ";
        cin >> carChoice;

            switch (carChoice) {
            case 1:
                cout << "You Chose Lamborghini Revuelto!";
                price = 750000;
                break;
            case 2:
                cout << "You Chose Bugatti Chiron!";
                price = 1450000;
                break;
            case 3:
                cout << "You Chose Tesla Roadster!";
                price = 400000;
                break;
            case 4:
                cout << "You Chose Batmobile!";
                price = 150000000;
                break;
            case 5:
                cout << "You Chose Einstein's Secret 1949 Rocket Car!";
                price = 300000000;
                break;
            case 6:
                cout << "You Chose 1967 Ford Mustang!";
                price = 647000;
                break;
            default:
                cout << "This Car is Not Available in Here in the Market!";               
            }

        break;
    
    default:
        break;
    }

    return 0;

}