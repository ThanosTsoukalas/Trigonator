#include "calculator.h"

#include <iostream>
#include <cmath>

void display_info(triangle reffered_obj){
    // υπολογισμός των πλευρών του τριγώνου
    float ab = sqrtf(
        ((reffered_obj.a.x - reffered_obj.b.x) * (reffered_obj.a.x - reffered_obj.b.x)) +
        ((reffered_obj.a.y - reffered_obj.b.y) * (reffered_obj.a.y - reffered_obj.b.y))
    );
    float ac = sqrtf(
        ((reffered_obj.a.x - reffered_obj.c.x) * (reffered_obj.a.x - reffered_obj.c.x)) +
        ((reffered_obj.a.y - reffered_obj.c.y) * (reffered_obj.a.y - reffered_obj.c.y))
    );
    float cb = sqrtf(
        ((reffered_obj.c.x - reffered_obj.b.x) * (reffered_obj.c.x - reffered_obj.b.x)) +
        ((reffered_obj.c.y - reffered_obj.b.y) * (reffered_obj.c.y - reffered_obj.b.y))
    );
    
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