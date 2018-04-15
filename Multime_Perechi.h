#ifndef MULTIME_PERECHI_H
#define MULTIME_PERECHI_H
#include <iostream>
#include "Pereche.h"

using namespace std;

class Multime_Perechi
{
    friend class Pereche;

    Pereche *v;
    int dimensiune;

    public:
        Multime_Perechi();
        Multime_Perechi(int n, Pereche Array[]);
        ~Multime_Perechi();
        Multime_Perechi(const Multime_Perechi& other);
        Multime_Perechi& operator=(const Multime_Perechi& other);

        //overloading
        friend ostream& operator<< (ostream &out, const Multime_Perechi &multime_perechi);
        friend istream& operator>> (istream &in, Multime_Perechi &multime_perechi);

        //functions
        void fix_vector();
};

#endif // MULTIME_PERECHI_H
