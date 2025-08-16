#include "types.h"
#include "calculator.h"
#include "interface.h"

#include <iostream>
#include <cstdlib>

int main (){
    SetApplicationTitle("Trigonator v"APP_VER);
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
            DisplayTriangleInfo(triangle_props);
        }
        else if (option == "Ανάλυση Τετραγώνου")
        {
            Rectangle rectangle_to_analyze = GetRectangleVertices();
            RectangleProperties rectangle_props = CalculateRectangleProperties(&rectangle_to_analyze);
            DisplayRectangleInfo(rectangle_props);
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