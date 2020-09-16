#ifndef VERTEX_H
#define VERTEX_H


typedef struct {
    float _position[3];
    float _normal[3];
    float _texcoord[2];

    void SetTexcoord(float x, float y)
    {
        _texcoord[0] = x;
        _texcoord[1] = y;
    };
    void SetPosition(float x, float y, float z)
    {
        _position[0] = x;
        _position[1] = y;
        _position[2] = z;
    };
    void SetNormal(float x, float y, float z)
    {
        _normal[0] = x;
        _normal[1] = y;
        _normal[2] = z;
    };
} Vertex;


#endif // VERTEX_H
