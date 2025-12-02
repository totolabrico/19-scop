#ifndef SCOPE_H
#define SCOPE_H

#include <iostream>
#include <math.h>
#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "./Shape.h"
#include "./Shader.h"

GLFWwindow *create_openGL_window(int width, int height);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

void rotate(std::array<float, 3> &v, std::array<float, 3> const &a);

#endif