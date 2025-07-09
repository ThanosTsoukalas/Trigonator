#include "calculator.h"

#include <iostream>
#include <cmath>


void DisplayInfo(triangle refferedObj){
    // υπολογισμός των πλευρών του τριγώνου
    float ab = sqrtf(
        ((refferedObj.a.x - refferedObj.b.x) * (refferedObj.a.x - refferedObj.b.x)) +
        ((refferedObj.a.y - refferedObj.b.y) * (refferedObj.a.y - refferedObj.b.y))
    );
    float ac = sqrtf(
        ((refferedObj.a.x - refferedObj.c.x) * (refferedObj.a.x - refferedObj.c.x)) +
        ((refferedObj.a.y - refferedObj.c.y) * (refferedObj.a.y - refferedObj.c.y))
    );
    float cb = sqrtf(
        ((refferedObj.c.x - refferedObj.b.x) * (refferedObj.c.x - refferedObj.b.x)) +
        ((refferedObj.c.y - refferedObj.b.y) * (refferedObj.c.y - refferedObj.b.y))
    );
    
    /*
        Χρησμοποιώ έδω (και στις περισσότερες συναρτήσεις)
        την μέθοδο πολλαπλασιασμού μιας τιμής με τον εαυτό της
        για να βρούμε το τετράγωνό της. Αυτό το κάνω γιατί είναι 
        η απλούστερη (και πιο γρήγορη κατά την εκτέλεση) μέθοδος,
        σε σχέση με την std::powf([οποιαδήποτε τιμή], 2)
    */
    
    // βρίσκουμε την μεγαλύτερη πλευρά (για να μπορούμε και μετά να εξετάσουμε αν το τρίγωνο είναι)
    // ορθογώνιο
    float* largest_side;
    float* minor_sides[2];

    if (ab > ac && ab > cb)
    {
        largest_side = &ab;
        minor_sides[0] = &ac;
        minor_sides[1] = &cb;
    } 
    else if (ac > ab && ac > cb)
    {
        largest_side = &ac;
        minor_sides[0] = &ab;
        minor_sides[1] = &cb;
    }
    else if (cb > ac && cb > ab)
    {
        largest_side = &cb;
        minor_sides[0] = &ab;
        minor_sides[1] = &ac;
    }
    else
    {
        largest_side = nullptr;
    }
    
    // εύρεση τύπου τριγώνου
    std::string triangle_type;
    
    if (ab == ac && ac == cb)
    {
        triangle_type = "Ισόπλευρο και Ισοσκελές";
        largest_side = nullptr;
    }

    // ---------------------------------

    if (ab == ac || ac == cb || ab == cb){
        triangle_type = "Ισοσκελές";
    }
    else
    {
        triangle_type = "Σκαληνό";
        // αυτό υποννοεί ότι ab != ac && ac != cb && ab != cb
    }

    // είναι το τρίγωνο ορθογώνιο ;;
    if (largest_side != nullptr)
    {
        float largest_side_squared = (*largest_side) * (*largest_side);
        float minor_sides_sum_and_square = ((*minor_sides[0]) * (*minor_sides[0])) + ((*minor_sides[1]) * (*minor_sides[1]));

        if (largest_side_squared == minor_sides_sum_and_square)
        {
            triangle_type = triangle_type + " και Ορθογώνιο";
        }
    }

    // ώρα να δείξουμε τα αποτελέσματα:

    std:: cout << "Πληροφορίες δοσμένου τριγώνου: " << std::endl << std::endl;

    std::cout << "(ΑΒ): " << ab << std::endl;
    std::cout << "(ΑΓ): " << ac << std::endl;
    std::cout << "(ΓΒ): " << cb << std::endl << std::endl;
    
    if (largest_side == &ab)
    {
        std::cout << "Μεγαλύτερη πλευρά: AB" << std::endl;
        std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΑΓ, ΓΒ" << std::endl;
    }
    else if (largest_side == &ac)
    {
        std::cout << "Μεγαλύτερη πλευρά: ΑΓ" << std::endl;
        std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΑΒ, ΓΒ" << std::endl;
    }
    else if (largest_side == &cb)
    {
        std::cout << "Μεγαλύτερη πλευρά: ΓΒ" << std::endl;
        std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΑΒ, ΑΓ" << std::endl;
    }
    else if (largest_side == nullptr){
        std::cout << "Μεγαλύτερη πλευρά: Δεν υπάρχει μεγ. πλευρά" << std::endl;
        std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): Δεν βρέθηκαν" << std::endl;
    }
    else
    {
        std::cout << "Μεγαλύτερη πλευρά: ΣΦΑΛΜΑ" << std::endl;
        std::cout << "Μικρότερες πλευρές (χωρίς ιδιαίτερη σειρά): ΣΦΑΛΜΑ" << std::endl;
    }

    
    std::cout << std::endl << "Τύπος ορθογωνίου: " << triangle_type << std::endl;
}

void DisplayRectInfo(rectangle refferedRect){
    //  βρίσκουμε την διαγώνιο του τετραγώνου

    float ab = sqrtf(
        ((refferedRect.a.x - refferedRect.b.x) * (refferedRect.a.x - refferedRect.b.x)) +
        ((refferedRect.a.y - refferedRect.b.y) * (refferedRect.a.y -refferedRect.b.y))
    );

    // αφού έχουμε την διαγώνιο, μπορούμε να βρούμε και την πλευρά του τετραγώνου
    
    float side_length = sqrtf((ab * ab)/2);

    float perimeter = side_length * 4;

    std::cout << "Πληροφορίες δοσμένου τετραγώνου: " << std::endl << std::endl;
    std::cout << "Διαγώνιος: " << ab << std::endl;
    std::cout << "Πλευρά: " << side_length << std::endl;
    std::cout << "Περίμετρος: " << perimeter << std::endl;

}