#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef struct vertex{
    int x;
    int y;
}vertex;

typedef struct triangle{
    vertex a;
    vertex b;
    vertex c;
}triangle;

void display_info(triangle reffered_obj);
#endif