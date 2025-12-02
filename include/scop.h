#ifndef SCOPE_H
#define SCOPE_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <math.h>
#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "./Shader.h"

typedef struct s_material
{
    std::string name;
    float Ns;
    std::array<float, 3> Ka;
    std::array<float, 3> Kd;
    std::array<float, 3> Ks;
    float Ni;
    float d;
    float illum;
} t_material;

GLFWwindow *create_openGL_window(std::string const &name, int width, int height);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
std::array<std::array<float, 3>, 3> rotation_matrix(float x, float y, float z);
void rotate(std::array<float, 3> &v, std::array<std::array<float, 3>, 3> const &m);
void load_material(t_material &material, std::string const &path);
#endif