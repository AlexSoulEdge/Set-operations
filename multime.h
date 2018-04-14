#ifndef MULTIME_H
#define MULTIME_H
#include <iostream>

using namespace std;


class Multime
{
    int *v;
    int dimensiune;


    public:
        Multime();
        Multime(int n, int Array[]);
        Multime(int n, char* Array);
        ~Multime();
        Multime(const Multime& other);
        Multime& operator=(const Multime& other);

        //getters
        int get_size();

        //setters
        void set_size(int x);

        //functions
        void fix_vector();

        //overloading
        friend ostream& operator<< (ostream &out, const Multime &multime);
        friend istream& operator>> (istream &in, Multime &multime);
        friend Multime operator+ (const Multime &M1, const Multime &M2);
        friend Multime operator* (const Multime &M1, const Multime &M2);
        friend Multime operator- (const Multime &M1, const Multime &M2);
        friend bool operator== (const Multime &M1, const Multime &M2);
        friend bool operator!= (const Multime &M1, const Multime &M2);


};

#endif // MULTIME_H
