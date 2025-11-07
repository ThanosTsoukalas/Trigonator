#include "Window.hpp"

void Window::setSize(int width, int height)
{
    Window::width = width;
    Window::height = height;
}

void Window::setPos(int pos_x, int pos_y)
{
    Window::pos_x = pos_x;
    Window::pos_y = pos_y;
}

void Window::setTitle(char *TITLE)
{
    Window::TITLE = TITLE;
}

int Window::init()
{
    InitializeOpenGLContext();

    GLFWwindow* window;
    window = glfwCreateWindow(Window::width, Window::height, Window::TITLE, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "(GLFW): Σφάλμα αρχικοποίησης παραθύρου." << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Σφάλμα αχρικοποίησης GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, Window::width, Window::height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Window::window_ptr = window;
    
    return 0;
}

void Window::destroy()
{
    glfwTerminate();
}