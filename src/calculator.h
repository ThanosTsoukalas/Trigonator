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

typedef struct rectangle{
    vertex a; // η μία άκρη της διαγωνίου του τετραγώνου
    vertex b; // η άλλη άκρη της διαγωνίου του τετραγώνου
} rectangle;


void display_info(triangle reffered_obj);
void display_rect_info(rectangle reffered_rect);
#endif