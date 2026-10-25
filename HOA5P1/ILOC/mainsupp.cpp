#include <iostream>
#include <string>
#include "queueArr.h"

int main()
{
    Printer printer(10);
    int menuChoice;
    Job jobData;

    do
    {
        std::cout << "\n=================================================================\n";
        std::cout << "                        PRINTER QUEUE\n";
        std::cout << "=================================================================\n";
        std::cout << "[1] Add Job\n";
        std::cout << "[2] Process Jobs\n";
        std::cout << "[3] Remove Job\n";
        std::cout << "[4] Display Jobs\n";
        std::cout << "[5] Clear Queue\n";
        std::cout << "[6] Exit\n";
        std::cout << "=================================================================\n";
        std::cout << "Choice: ";
        std::cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            std::cout << "\n--- Add Print Job ---\n";

            std::cout << "Job ID: ";
            std::cin >> jobData.ID;

            std::cout << "Username: ";
            std::cin >> jobData.username;

            std::cout << "Number of Pages: ";
            std::cin >> jobData.number_of_pages;

            printer.addJob(jobData);
            break;

        case 2:
            std::cout << "\n--- Process Jobs ---\n";
            printer.JobProcess();
            break;

        case 3:
            std::cout << "\n--- Remove Job ---\n";

            jobData = printer.RemoveJob();

            if (jobData.ID != 0)
            {
                std::cout << "Removed Job ID: " << jobData.ID << "\n";
                std::cout << "Username: " << jobData.username << "\n";
                std::cout << "Pages: " << jobData.number_of_pages << "\n";
            }
            break;

        case 4:
            std::cout << "\n--- Display Jobs ---\n";
            printer.DisplayJob();
            break;

        case 5:
            printer.Clear();
            std::cout << "\nAll jobs have been cleared.\n";
            break;

        case 6:
            std::cout << "\nExiting Printer Queue...\n";
            break;

        default:
            std::cout << "\nInvalid choice.\n";
            std::cout << "Please select from 1 to 6.\n";
            break;
        }

    } while (menuChoice != 6);

    return 0;
}