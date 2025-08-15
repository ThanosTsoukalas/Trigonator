#include "interface.h"
#include "calculator.h"
#include "types.h"

#include <iostream>

std::string DisplayAndGetOption(std::vector<std::string> options)
{
    int option_couter = 1;
    int usr_option;
    
    std::cout << "Επιλογές:" << std::endl;

    for (auto option : options){
        std::cout << "[" << option_couter << "]" << " " << option << std::endl;
        option_couter++;
    }

    std::cout << "Επιλογή [1 - " << options.size() << "]: ";
    std::cin >> usr_option;
    
    return options[usr_option - 1];
    
}

Triangle GetTriangleVertices()
{
    Point a;
    Point b;
    Point c;

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

    return {a, b, c};
    
}

void DisplayTriangleInfo (TriangleProperties givenTriangle)
{
    if (givenTriangle.is_triangle == true)
    {   
        std::cout << "Πληροφορίες δοσμένου τριγώνου: " << std::endl << std::endl;
        std::cout << "(ΑΒ): " << givenTriangle.ab << std::endl;
        std::cout << "(ΑΓ): " << givenTriangle.ac << std::endl;
        std::cout << "(ΓΒ): " << givenTriangle.cb << std::endl << std::endl;

        if (givenTriangle.largest_side == givenTriangle.ab)
        {
            std::cout << "Μεγαλύτερη πλευρά: AB" << std::endl;
            std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΑΓ, ΓΒ" << std::endl;
        }
        else if (givenTriangle.largest_side == givenTriangle.ac)
        {
            std::cout << "Μεγαλύτερη πλευρά: ΑΓ" << std::endl;
            std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΑΒ, ΓΒ" << std::endl;
        }
        else if (givenTriangle.largest_side == givenTriangle.cb)
        {
            std::cout << "Μεγαλύτερη πλευρά: ΓΒ" << std::endl;
            std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΑΒ, ΑΓ" << std::endl;
        }
        else if (givenTriangle.largest_side == 0.0f){
            std::cout << "Μεγαλύτερη πλευρά: Δεν υπάρχει μεγ. πλευρά" << std::endl;
            std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): Δεν βρέθηκαν" << std::endl;
        }
        else
        {
            std::cout << "Μεγαλύτερη πλευρά: ΣΦΑΛΜΑ" << std::endl;
            std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΣΦΑΛΜΑ" << std::endl;
        }

        std::cout << "Τύπος τριγώνου: " << givenTriangle.triangle_type << std::endl << std::endl;
    }
    else
    {
        std::cout << "Τα δοσμένα σημεία δεν αποτελούν τρίγωνο. Προσπαθήστε ξανά." << std::endl;
    }
}

void ClearTerminal()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void SetGreekCharScheme()
{
    #ifdef _WIN32
        system("chcp 65001");
    #endif
    ClearTerminal();
}

void DisplayApplicationInfo()
{   
    ClearTerminal();

    std::cout << "Τριγωνέιτορ (Trigonator) v" << APP_VER << std::endl;
    std::cout << "Αρχιτεκτονική: " << ARCHITECTURE << std::endl;
    std::cout << "Εκδόθηκε: " << RELEASE_DATE << std::endl;
    std::cout << "Άδεια Ανοιχτού Κώδικα: " << LICENSE << std::endl;
    std::cout << std::endl;
    std::cout << "(c) " << RELEASE_YEAR << " " << COPYRIGHT_NOTICE << std::endl << std::endl;

    std::cout << "Πατήστε οποιοδήποτε κουμπί για συνέχεια στο μενού επιλογών.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.get();
    
    ClearTerminal();
}