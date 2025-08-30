#ifndef WINDOW_HPP
#define WINDOW_HPP

#define CENTER_X
#define CENTER_Y

#include <iostream>

#include "graphics_header.h"

class Window{
    public:
        int width;
        int height;
        
        int pos_x;
        int pos_y;
        char *TITLE;

        GLFWwindow* window_ptr;

        void setSize(int width, int height);
        void setPos(int pos_x, int pos_y);
        void setTitle(char *TITLE);
        int init();
        void destroy();
};


#endif