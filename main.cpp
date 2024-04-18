#include <iostream>
#include <stdlib.h>

#include "utilities.h"

int main() {

    
    Utilities::clearScreen();

    int selection;
    
    Utilities::login();
    Utilities::initializeData();
    if (Utilities::authenticated) {
        do {
            std::cout << "Login successful. Welcome, " << Utilities::username << "!\n";
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "1.Enroll Student\n";
            std::cout << "2.Disenroll Student\n";
            std::cout << "3.View Student Roster\n";
            std::cout << "4.View Student Record\n";
            std::cout << "5.Course Catalog\n";
            std::cout << "6.Quit Program\n";
            std::cout << std::endl;
            std::cout << "Enter Selection: ";
            std::cin >> selection;

            switch(selection) {
                case 1:
                    Utilities::clearScreen();
                    Utilities::enroll();
                    break;
                case 2:
                    Utilities::clearScreen();
                    Utilities::disenroll();
                    break;
                case 3:
                    Utilities::clearScreen();
                    Utilities::viewStudentRoster();
                    break;
                case 4: 
                    Utilities::clearScreen();
                    Utilities::viewStudentRecord();
                    break;
                case 5:
                    Utilities::courseCatalogMenu();
                    break;
                case 6: 
                    break;
                default:
                    std::cout << "Incorrect Entry. Try again.\n";
                    break;
            } 
        } while (selection!=6);
    } else {
        std::cout << "Incorrect username or password. Please try again.\n";
    }

    return 0;
}
