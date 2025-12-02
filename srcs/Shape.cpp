#include "../include/Shape.h"
#include <iostream>
#include <fstream>

Shape::Shape() : name("empty") {}

Shape::~Shape() {}

void Shape::addElement(std::vector<std::string> &args)
{
    std::string arg = args.front();
    args.erase(args.begin());
    if (arg == "v")
        addVertice(args);
    else if (arg == "f")
        addFace(args);
    else if (arg == "mtllib" && args.size() == 1)
        load_material(material, args[0]);
}

void Shape::addVertice(std::vector<std::string> const &args)
{
    std::array<float, 3> vertice;

    if (args.size() != 3)
        return;
    for (size_t i = 0; i < 3; i++)
        vertice[i] = (std::stof(args.at(i)));

    vertices.push_back(vertice);
}

void Shape::addFace(std::vector<std::string> const &args)
{
    std::array<int, 3> face;

    if (args.size() < 3)
        return;
    if (args.size() == 4)
    {
        addFace({args[0], args[1], args[2]});
        addFace({args[0], args[2], args[3]});
        return;
    }
    for (size_t i = 0; i < 3; i++)
        face[i] = (std::stoi(args.at(i)));

    faces.push_back(face);
}

void Shape::center()
{
    std::array<float, 3> min;
    std::array<float, 3> max;
    std::array<float, 3> translation;

    min = vertices[0];
    max = vertices[0];
    for (size_t i = 1; i < vertices.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float value = vertices[i][j];
            if (value < min[j])
                min[j] = value;
            if (value > max[j])
                max[j] = value;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (min[i] > 0)
            translation[i] = max[i] - min[i];
        else
            translation[i] = max[i] + min[i];
        translation[i] /= 2;
    }

    for (size_t i = 0; i < vertices.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vertices[i][j] -= translation[j];
        }
    }
}

Shape::Shape(std::string const &src_path)
{
    std::fstream stream;
    stream.open(src_path, std::fstream::in);
    char c;
    std::vector<std::string> line;
    std::string word;

    while (stream.get(c))
    {
        if (c == '\n' || c == ' ')
        {
            line.push_back(word);
            if (c == '\n')
            {
                addElement(line);
                line.clear();
            }
            word.clear();
        }
        else
            word += c;
    }
    center();
    std::cout << "New Shape created with "
              << vertices.size() << " vertices and "
              << faces.size() << " faces." << std::endl
              << "Material name is " << material.name << "."
              << std::endl;
}

Shape &Shape::operator=(Shape const &src)
{
    name = src.getName();
    return *this;
}

std::string const &Shape::getName() const
{
    return name;
}

void Shape::getVertices(std::vector<float> &dest) const
{
    for (const auto &face : faces)
    {
        for (int vi = 0; vi < 3; vi++)
        {
            const auto &v = vertices.at(face[vi] - 1);
            for (int c = 0; c < 3; c++)
            {
                float value = v[c];
                dest.push_back(value);
            }
        }
    }
}