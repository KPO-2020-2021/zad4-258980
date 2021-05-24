#pragma once

#include "matrix3x3.hh"
#include "vector3D.hh"
#define SIZE 8

class Cuboid
{
    double angle;
    Vector3D path;
    Vector3D center;
    double h;
    double w;
    double z;
    Vector3D size[SIZE];

public:
    const Vector3D &operator[](int index) const { return size[index]; }
    Vector3D &operator[](int index) { return size[index]; }
    Cuboid(Vector3D center = Vector3D(), double h = 50, double w = 50,double z=50);
    void translacja(double angle, Vector3D path, Matrix3x3 mac);
};

Cuboid::Cuboid(Vector3D center, double h, double w, double z)
{
    this->angle = 0;
    this->center = center;
    this->h = h;
    this->w = w;
    this->z = z;
    for (int i = 0; i < SIZE; i++)
    {
        size[i][0] = center[0] - w / 2;
        size[i][1] = center[1] - h / 2;
    }

    size[1][0] += w;

    size[2][1] += h;

    size[3][0] += w;
    size[3][1] += h;

    size[4][1] += w;
    size[4][2] += z;

    size[5][0] += w;
    size[5][1] += h;
    size[5][2] += z;

    size[6][2] += z;

    size[7][0] += w;
    size[7][2] += z;
 
}

void Cuboid::translacja(double angle, Vector3D path, Matrix3x3 mac)
{
    this->angle += angle;
    this->path = this->path + path;
    for (int i = 0; i < SIZE; i++)
    {
        size[i][0] = center[0] + this->path[0] - w / 2;
        size[i][1] = center[1] + this->path[1] - h / 2;
    }

      size[1][0] += w;

    size[2][1] += h;

    size[3][0] += w;
    size[3][1] += h;

    size[4][1] += w;
    size[4][2] += z;

    size[5][0] += w;
    size[5][1] += h;
    size[5][2] += z;

    size[6][2] += z;

    size[7][0] += w;
    size[7][2] += z;

    for (int i = 0; i < SIZE; i++)
    {
        size[i] = mac * size[i];
    }
}

std::ostream &operator<<(std::ostream &Strm, const Cuboid &Pr)
{
    for (int i = 0; i < SIZE; i++)
    {
        Strm << Pr[i] << std::endl;
        if((i+1)%2==0)
        Strm<<std::endl;
    }
    return Strm;
}