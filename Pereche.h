#ifndef PERECHE_H
#define PERECHE_H
#include <iostream>

using namespace std;

class Pereche
{
    int x;
    int y;

    public:
        Pereche();
        Pereche(int a, int b);
        ~Pereche();
        Pereche(const Pereche& other);
        Pereche& operator=(const Pereche& other);

        //getters
        int get_x();
        int get_y();

        /*
        //setters
        void set_x(int value);
        void set_y(int value);
        */

        //overloading
        friend ostream& operator<< (ostream &out, const Pereche &pereche);
        friend istream& operator>> (istream &in, Pereche &pereche);


};

#endif // PERECHE_H
