#include "types.h"
#include "calculator.h"
#include "interface.h"

#include <iostream>
#include <cstdlib>

int main (){
    #ifdef _WIN32
        system("title Trigonator v"APP_VER);
    #endif
    SetGreekCharScheme();

    std::cout << "Τριγωνέιτορ v" << APP_VER << std::endl << std::endl;

    while (true)
    {   
        std::string option = DisplayAndGetOption({
            "Ανάλυση Τριγώνου",
            "Ανάλυση Τετραγώνου",
            "Εκκαθάριση Τερματικού",
            "Σχετικά με το Τριγωνέιτορ",
            "Έξοδος"
        });

        if (option == "Ανάλυση Τριγώνου")
        {
            Triangle triangle_to_analyze = GetTriangleVertices();
            TriangleProperties triangle_props = CalculateTriangleProperties(&triangle_to_analyze);
            std::cout << "Returned properties" << std::endl;
            DisplayTriangleInfo(triangle_props);
        }
        else if (option == "Ανάλυση Τετραγώνου")
        {
            Point a;
            Point b;

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

            Rectangle usr_rectangle = {a, b};

            DisplayRectInfo(usr_rectangle);
        }
        else if (option == "Έξοδος")
        {
            break;
            return EXIT_SUCCESS;
        }
        else if (option == "Εκκαθάριση Τερματικού")
        {
            ClearTerminal();
        }
        else if (option == "Σχετικά με το Τριγωνέιτορ")
        {
            DisplayApplicationInfo();
        }
        else
        {
            std::cout << "Δεν υπάρχει εντολή με ταυτοποιητή [" << option << "]. Δοκιμάστε ξανά." << std::endl;
        }
        
    }

    return 0;
}