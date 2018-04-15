#include "Multime_Perechi.h"
#include "Pereche.h"
#include <iostream>


using namespace std;

Multime_Perechi::Multime_Perechi() : dimensiune(0)
{
    v = NULL;
}

Multime_Perechi::Multime_Perechi(int n, Pereche Array[]) : dimensiune(n)
{
    if(!dimensiune)
        v = NULL;
    else
    {
        v = new Pereche[dimensiune];

        for(int i = 0; i < dimensiune; i ++)
        {
            v[i] = Array[i];
        }
    }
}

Multime_Perechi::~Multime_Perechi()
{
    delete[] v;
}

Multime_Perechi::Multime_Perechi(const Multime_Perechi& other) : dimensiune(other.dimensiune)
{
    if(!dimensiune)
        v = NULL;
    else
    {
        v = new Pereche[dimensiune];

        for(int i = 0; i < dimensiune; i ++)
        {
            v[i] = other.v[i];
        }
    }
}

Multime_Perechi& Multime_Perechi::operator=(const Multime_Perechi& other)
{
    if (this == &other) return *this; // handle self assignment

    delete[] v;
    dimensiune = other.dimensiune;

    if(!dimensiune)
        v = NULL;
    else
    {
        v = new Pereche[dimensiune];

        for(int i = 0; i < dimensiune; i ++)
        {
            v[i] = other.v[i];
        }
    }
    return *this;
}

ostream& operator<< (ostream &out, const Multime_Perechi &multime_perechi)
{
    out << "Multime perechi: {";
    for(int i = 0; i < multime_perechi.dimensiune; i ++)
    {
        out << multime_perechi.v[i];

        if(i < multime_perechi.dimensiune - 1)
            out << "; ";
    }
    out << "}.";

    return out;
}

istream& operator>> (istream &in, Multime_Perechi &multime_perechi)
{
    in >> multime_perechi.dimensiune;

    if(!multime_perechi.dimensiune)
        multime_perechi.v = NULL;

    else
    {
        delete[] multime_perechi.v;
        multime_perechi.v = new Pereche[multime_perechi.dimensiune];

        for(int i = 0; i < multime_perechi.dimensiune; i ++)
        {
            in >> multime_perechi.v[i];
        }
    }

    return in;
}

void Multime_Perechi::fix_vector()
{
    for(int i = 0; i < dimensiune - 1; i ++)
    for(int j = i + 1; j < dimensiune; j ++)
    {
        if(v[i].get_x() == v[j].get_x() && v[i].get_y() == v[j].get_y())
        {
            for(int k = j; k < dimensiune - 1; k++)
            {
                v[k] = v[k+1];
            }

            j--;
            dimensiune--;
        }
    }
}


