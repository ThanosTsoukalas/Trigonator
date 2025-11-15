#include "GuiCalculator.hpp"
// Το GuiCalculator είναι η εφαρμογή που εκκινείται όταν 
// επιλέγεται η επιλογή «Έναρξη γραφικού περιβάλλοντος
//
// ΧΡΗΣΙΜΟΠΟΙΟΥΜΕ OPENGL 3.3

void GuiCalculatorInit()
{
    Window applicationWindow = Window();

    applicationWindow.setSize(1000, 700);
    applicationWindow.setPos(0, 0);
    applicationWindow.setTitle("Trigonator GUI ("APP_VER")");
    applicationWindow.init();

    float positions[6] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    GLuint vao;
    GLuint buffer;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    std::string vertexShader = 
    "#version 410 compatibility \n "
    "layout(location = 0) in vec2 position; \n "
    "void main () \n"
    "{ \n"
    "   gl_Position = position; \n"
    "}\n";

    std::string fragmentShader = 
    "#version 410 compatibility \n "
    "layout(location = 0) out vec4 color; \n "
    "void main ()\n"
    "{ \n"
    "   color = vec4(0.9f, 0.9f, 0.9f, 0.9f); \n"
    "}\n";

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    

    while (!glfwWindowShouldClose(applicationWindow.window_ptr))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black background
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader);

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(applicationWindow.window_ptr);
        glfwPollEvents();
    }

    glDeleteProgram(shader);
    glDeleteBuffers(1, &buffer);
    glDeleteVertexArrays(1, &vao);
    applicationWindow.destroy();
}