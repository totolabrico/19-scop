#include "../include/scop.h"

void loop(GLFWwindow *window)
{
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please precise .obj file" << std::endl;
        return 0;
    }

    GLFWwindow *window = create_openGL_window(600, 600);
    if (window == NULL)
        return 1;

    Shape *shape = new Shape(argv[1]);

    loop(window);
    glfwTerminate();
    delete(shape);

    return 0;
}
