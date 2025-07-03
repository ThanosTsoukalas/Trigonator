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
    vertex a;
    vertex b;
    vertex c;
    while (true)
    {
        std::cout << "Τριγωνέιτορ v1.0" << std::endl;
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

        display_info(usr_triangle);
    }
    return 0;
}