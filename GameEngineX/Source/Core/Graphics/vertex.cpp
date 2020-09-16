#include "vertex.hpp"

void Vertex::SetColor(float r, float g, float b, float a)
{
    _color[0] = r; _color[1] = g; _color[2] = b; _color[3] = a;
}
void Vertex::SetTexcoord(float x, float y)
{
    _texcoord[0] = x; _texcoord[1] = y;
}
void Vertex::SetPosition(float x, float y, float z)
{
    _position[0] = x; _position[1] = y; _position[2] = z;
}
void Vertex::SetNormal(float x, float y, float z)
{
    _normal[0] = x; _normal[1] = y; _normal[2] = z;
}
