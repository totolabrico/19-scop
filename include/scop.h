#ifndef SCOPE_H
#define SCOPE_H

#include <iostream>
#include <math.h>
#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "./Shape.h"
#include "./Shader.h"

GLFWwindow *create_openGL_window(std::string const &name, int width, int height);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
std::array<std::array<float, 3>, 3> rotation_matrix(float x, float y, float z);
void rotate(std::array<float, 3> &v, std::array<std::array<float, 3>, 3> const &m);

#endif