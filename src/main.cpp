#include <types.h>
#include <interface.h>
#include <calculator.h>

#include "gui_calculator/GuiCalculator.hpp"

#include <iostream>

#include <cstdlib>

int main (int argc, char *argv[]){
    SetApplicationTitle("Trigonator v"APP_VER);
    SetGreekCharScheme();

    std::cout << "Τριγωνέιτορ v" << APP_VER << dnl;

    while (true)
    {   
        std::string option = DisplayAndGetOption({
            "Ανάλυση Τριγώνου",
            "Ανάλυση Τετραγώνου",
            "Εκκαθάριση Τερματικού",
            "Σχετικά με το Τριγωνέιτορ",
            "Έναρξη γραφικού περιβάλλοντος",
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
            Rect Rect_to_analyze = GetRectVertices();
            RectProperties Rect_props = CalculateRectProperties(&Rect_to_analyze);
            DisplayRectInfo(Rect_props);
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
        else if (option == "Έναρξη γραφικού περιβάλλοντος")
        {
            GuiCalculatorInit();
        }
        else
        {
            std::cout << "Δεν υπάρχει εντολή με ταυτοποιητή [" << option << "]. Δοκιμάστε ξανά." << std::endl;
        }
        
    }

    return 0;
}

