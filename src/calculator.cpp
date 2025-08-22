#include "types.h"
#include "validator.h"

#include <iostream>
#include <cmath>
#include <vector>

RectangleProperties CalculateRectangleProperties (Rectangle *givenRectangle)
{
    bool is_rect = false;
    float diagonal = sqrtf(
        ((givenRectangle->a.x - givenRectangle->b.x) * (givenRectangle->a.x - givenRectangle->b.x)) +
        ((givenRectangle->a.y - givenRectangle->b.y) * (givenRectangle->a.y -givenRectangle->b.y))
    );

    if (diagonal > 0)
    {
        is_rect = true;

        float side_length = sqrtf((diagonal * diagonal)/2);
        float perimeter = side_length*4;

        return {is_rect, diagonal, side_length, perimeter};
    }else
    {
        return {is_rect, 0.0f, 0.0f, 0.0f};
    }
}


TriangleProperties CalculateTriangleProperties(Triangle* givenTriangle)
{
    bool is_triangle = false;
    // τσεκάρουμε αν ΟΝΤΩΣ υπάρχει το δοσμένο τρίγωνο
    if 
    (
        CheckForCollinearPoints({givenTriangle->a, givenTriangle->b, givenTriangle->c}) != true 
        && !(givenTriangle->a.y == givenTriangle->b.y && givenTriangle->a.y == givenTriangle->c.y)
    )
    {
        is_triangle = true;
    }
    // Αν είναι τρίγωνο, ξεκινάμε τον υπολογισμό
    if (is_triangle == true){
        // υπολογισμός των πλευρών του τριγώνου
        float ab = sqrtf(
            ((givenTriangle->a.x - givenTriangle->b.x) * (givenTriangle->a.x - givenTriangle->b.x)) +
            ((givenTriangle->a.y - givenTriangle->b.y) * (givenTriangle->a.y - givenTriangle->b.y))
        );
        float ac = sqrtf(
            ((givenTriangle->a.x - givenTriangle->c.x) * (givenTriangle->a.x - givenTriangle->c.x)) +
            ((givenTriangle->a.y - givenTriangle->c.y) * (givenTriangle->a.y - givenTriangle->c.y))
        );
        float cb = sqrtf(
            ((givenTriangle->c.x - givenTriangle->b.x) * (givenTriangle->c.x - givenTriangle->b.x)) +
            ((givenTriangle->c.y - givenTriangle->b.y) * (givenTriangle->c.y - givenTriangle->b.y))
        );

        /*
            Χρησμοποιώ έδω (και στις περισσότερες συναρτήσεις)
            την μέθοδο πολλαπλασιασμού μιας τιμής με τον εαυτό της
            για να βρούμε το τετράγωνό της. Αυτό το κάνω γιατί είναι 
            η απλούστερη (και πιο γρήγορη κατά την εκτέλεση) μέθοδος,
            σε σχέση με την std::powf([οποιαδήποτε τιμή], 2)
        */

        // βρίσκουμε την μεγαλύτερη πλευρά (για να μπορούμε και μετά να εξετάσουμε αν το τρίγωνο είναι
        // ορθογώνιο)

        float* largest_side;

        if (ab > ac && ab > cb)
        {
            largest_side = &ab;
        } 
        else if (ac > ab && ac > cb)
        {
            largest_side = &ac;
        }
        else if (cb > ac && cb > ab)
        {
            largest_side = &cb;
        }
        else
        {
            largest_side = nullptr;
        }

        // εύρεση τύπου τριγώνου
        std::string triangle_type;

        if (ab == ac || ac == cb || ab == cb)
        {
            triangle_type = "Ισοσκελές";
            largest_side = nullptr;
        }
        else if (ab == ac && ac == cb && ab == cb)
        {
            triangle_type = "Ισόπλευρο και Ισοσκελές";
            largest_side = nullptr;
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
            float minor_sides_square_and_sum;

            if (largest_side == &ab)
                minor_sides_square_and_sum = (ac*ac) + (cb*cb);
            else if (largest_side == &cb)
                minor_sides_square_and_sum = (ab*ab) + (ac*ac);
            else
                minor_sides_square_and_sum = (ab*ab) + (cb*cb);

            if (largest_side_squared == minor_sides_square_and_sum)
            {
                triangle_type = triangle_type + " και Ορθογώνιο";
            }

            return {is_triangle, ab, ac, cb, *largest_side, triangle_type};
        }
        else
        {
            return {is_triangle, ab, ac, cb, 0.0f, triangle_type};
        }
        
    }
    else
    {
        return {is_triangle, 0.0f, 0.0f, 0.0f, 0.0f, "Δεν είναι τρίγωνο"};
    }

}