#include "Pereche.h"
#include <iostream>

using namespace std;

Pereche::Pereche() : x(0), y(0) {}

Pereche::Pereche(int a, int b) : x(a), y(b) {}

Pereche::~Pereche() {}

Pereche::Pereche(const Pereche& other)
{
    x = other.x;
    y = other.y;
}

Pereche& Pereche::operator=(const Pereche& other)
{
    if (this == &other) return *this;

    x = other.x;
    y = other.y;
    return *this;
}

int Pereche::get_x()
{
    return x;
}

int Pereche::get_y()
{
    return y;
}

ostream& operator<< (ostream &out, const Pereche &pereche)
{
    out << "(" << pereche.x << ", " << pereche.y << ")";

    return out;
}

istream& operator>> (istream &in, Pereche &pereche)
{
    in >> pereche.x >> pereche.y;

    return in;
}
