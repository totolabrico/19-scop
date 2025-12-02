#include "../include/Shape.h"
#include "iostream"
#include "fstream"

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
    std::cout << "New Shape created with "
              << vertices.size() << " vertices and "
              << faces.size() << " faces."
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

std::vector<std::array<float, 3>> const &Shape::getVertices() const
{
    return vertices;
}

std::vector<std::array<int, 3>> const &Shape::getFaces() const
{
    return faces;
}