#ifndef TYPES_H 
#define TYPES_H 

#include <iostream>
#include <vector>

typedef struct Point{
    float x;
    float y;
}Point;

typedef struct Triangle{
    Point a;
    Point b;
    Point c;
}Triangle;

typedef struct Rect{
    Point a; // η μία άκρη της διαγωνίου του τετραγώνου
    Point b; // η άλλη άκρη της διαγωνίου του τετραγώνου
} Rect;


typedef struct TriangleProperties{
    bool is_triangle;
    float ab;
    float ac;
    float cb;
    float largest_side;
    std::string triangle_type;
}TriangleProperties;

typedef struct RectProperties{
    bool is_rect;
    float diagonal;
    float side_length;
    float perimeter;
}RectProperties;

typedef struct StraightLineEquation{
    // Για συναρτήσεις τύπου y = αχ + β
    float slope;
    float increment;
} StraightLineEquation;


#endif