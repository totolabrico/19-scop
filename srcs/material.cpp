#include "../include/scop.h"

static void load_material_element(t_material &material, std::vector<std::string> args)
{

    std::string cmd = args[0];

    if (args.size() < 2)
        return;
    if (cmd == "newmtl")
        material.name = args[1];
    if (cmd == "Ns" || cmd == "Ni" || cmd == "d" || cmd == "illum")
    {
        float value = std::stof(args[1]);
        if (cmd == "Ns")
            material.Ns = value;
        if (cmd == "Ni")
            material.Ni = value;
        if (cmd == "d")
            material.d = value;
        if (cmd == "illum")
            material.illum = value;
    }
    if (cmd == "Ka" || cmd == "Kd" || cmd == "Ks")
    {
        if (args.size() != 4)
            return;
        std::array<float, 3> value;
        for (int i = 1; i < 4; i++)
            value[i - 1] = std::stof(args[1]);
        if (cmd == "Ns")
            material.Ka = value;
        if (cmd == "Ni")
            material.Kd = value;
        if (cmd == "d")
            material.Ks = value;
    }
}

void load_material(t_material &material, std::string const &path)
{
    std::fstream stream;
    char c;
    std::string buf;
    std::vector<std::string> args;

    stream.open(path, std::fstream::in);
    while (stream.get(c))
    {
        if (c == ' ' || c == '\n')
        {
            args.push_back(buf);
            if (c == '\n')
            {
                load_material_element(material, args);
                args.clear();
            }
            buf.clear();
        }
        else
            buf += c;
    }
}