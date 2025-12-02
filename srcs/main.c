#include "../include/scop.h"

void rotate_shape(std::vector<float> &vertices, std::array<std::array<float, 3>, 3> matrix)
{
    std::array<float, 3> temp;
    for (size_t i = 0; i < vertices.size() / 3; i++)
    {
        for (int j = 0; j < 3; j++)
            temp[j] = vertices[i * 3 + j];
        rotate(temp, matrix);
        for (int j = 0; j < 3; j++)
            vertices[i * 3 + j] = temp[j];
    }
}

void zoom_shape(std::vector<float> &vertices, float value)
{
    for (auto &vertice : vertices)
    {
        vertice *= value;
    }
}

void loop(GLFWwindow *window, int VAO, Shader shader, std::vector<float> vertices)
{
    std::array<float, 3> angle = {0.0, 0.02, 0.0};
    std::array<std::array<float, 3>, 3> matrix = rotation_matrix(angle[0], angle[1], angle[2]);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.f, 0.f, 0.f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        rotate_shape(vertices, matrix);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() * 3);
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
    GLFWwindow *window = create_openGL_window("SCOP", 1000, 800);
    if (window == NULL)
        return 1;
    Shader shader("./shaders/shader.vs", "./shaders/shader.fs");
    Shape shape = Shape(argv[1]);
    std::vector<float> vertices;
    shape.getVertices(vertices);
    zoom_shape(vertices, 0.25);
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    loop(window, VAO, shader, vertices);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}
