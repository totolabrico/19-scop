#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <array>
#include <vector>

class Shape
{
public:
    Shape();
    Shape(std::string const &src_path);
    ~Shape();
    Shape &operator=(Shape const &src);
    std::string const &getName() const;
    void getVertices(std::vector<float> &dest) const;

private:
    std::string name;
    std::vector<std::array<float, 3>> vertices;
    std::vector<std::array<int, 3>> faces;
    void addElement(std::vector<std::string> &args);
    void addVertice(std::vector<std::string> const &args);
    void addFace(std::vector<std::string> const &args);
    void center();
};

#endif