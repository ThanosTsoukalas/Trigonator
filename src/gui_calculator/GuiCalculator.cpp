#include "GuiCalculator.hpp"

/*
    Το GuiCalculator είναι η εφαρμογή που εκκινείται όταν 
    επιλέγεται η επιλογή «Έναρξη γραφικού περιβάλλοντος»
*/

void GuiCalculatorInit()
{
    Window applicationWindow = Window();

    applicationWindow.setSize(1000, 700);
    applicationWindow.setPos(0, 0);
    applicationWindow.setTitle("Trigonator GUI ("APP_VER")");
    applicationWindow.init();

    while (!glfwWindowShouldClose(applicationWindow.window_ptr))
    {
        glfwSwapBuffers(applicationWindow.window_ptr);
        glfwPollEvents();
    }

    applicationWindow.destroy();
}