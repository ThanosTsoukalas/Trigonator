#include "calculator.h"
#include <iostream>
#include <cstdlib>
/*
    Σκέφτομαι να βάλω και άλλες δυνατότητες (όπως υπολογισμό τετραγώνου και κύκλου),
    αλλά το πρόγραμμα θα το αποκαλώ για πάντα «Τριγωνέιτορ»
*/
int main (){
    // Παίρνουμε πληροφορίες για το τρίγωνο του χρήστη
    system("chcp 65001");
    system("cls");

    while (true)
    {   
        int option;
        std::cout << "Τριγωνέιτορ v1.0" << std::endl << std::endl; 
        std::cout << "Επιλέξτε σχήμα: " << std::endl;
        std::cout << "[1] Τρίγωνο" << std::endl;
        std::cout << "[2] Τετράγωνο" << std::endl;
        std::cout << "[3] Έξοδος" << std::endl << std::endl;
        std::cout << "Επιλογή: ";
        std::cin >> option;

        if (option == 1)
        {
            vertex a;
            vertex b;
            vertex c;
            std::cout << "Στοιχεία Τριγώνου" << std::endl << std::endl;
            std::cout << "Σημείο Α(x, y):" << std::endl;
            std::cout << "x: ";
            std::cin >> a.x;
            std::cout << std::endl << "y: ";
            std::cin >> a.y;
            std::cout << std::endl << std::endl;
            std::cout << "Σημείο Β(x1, y1):" << std::endl;
            std::cout << "x1: ";
            std::cin >> b.x;
            std::cout << std::endl << "y1: ";
            std::cin >> b.y;
            std::cout << std::endl << std::endl;
            std::cout << "Σημείο Γ(x2, y2):" << std::endl;
            std::cout << "x2: ";
            std::cin >> c.x;
            std::cout << std::endl << "y2: ";
            std::cin >> c.y;
            std::cout << std::endl << std::endl;

            triangle usr_triangle = {a, b, c};

            DisplayInfo(usr_triangle);
        }
        else if (option == 2)
        {
            vertex a;
            vertex b;

            std::cout << "Στοιχεία Τετραγώνου" << std::endl << std::endl;
            std::cout << "Σημείο Α(x, y): (ένα άκρο της διαγωνίου) " << std::endl << std::endl;
            std::cout << "x: ";
            std::cin >> a.x;
            std::cout << "y: ";
            std::cin >> a.y;
            std::cout << "Σημείο Β(x1, y1): (άλλο άκρο της διαγωνίου)";
            std::cout << "x1: ";
            std::cin >> b.x;
            std::cout << "y1: ";
            std::cin >> b.y;

            rectangle usr_rectangle = {a, b};

            DisplayRectInfo(usr_rectangle);
        }
        else if (option == 3)
        {
            break;
            return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Δεν υπάρχει εντολή με ταυτοποιητή [" << option << "]. Δοκιμάστε ξανά." << std::endl;
        }
        
    }
    return 0;
}