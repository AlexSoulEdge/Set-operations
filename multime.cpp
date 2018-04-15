#include <iostream>
#include "Multime.h"
//#include <cstring>

using namespace std;

Multime::Multime() : dimensiune(0)
{
    v = NULL; // nullptr ?!

    //cout << "Constructor default" <<endl;
}

Multime::Multime(int n, int Array[]) : dimensiune(n)
{
    if(!dimensiune)
        v = NULL; // nullptr ?!
    else
    {
        v = new int[dimensiune];

        for(int i = 0; i < dimensiune; i ++)
        {
            v[i] = Array[i];
        }
    }

    //cout << "Constructor cu parametri" << endl;
}

/* -- still to be worked on
Multime::Multime(int n, char* Array) : dimensiune(n)
{
    if(!dimensiune)
        v = NULL; // nullptr ?!
    else
    {
        v = new int[dimensiune];
        char number[16];
        int last_space = 0, number_toadd, last_position = 0;

        for(int i = 0; i < strlen(Array); i ++)
        {
            if(Array[i] == ' ')
            {
                for(int j = last_space; j < i; j++)
                    strcat(number, Array[j]);

                number_toadd = atoi(number);
                v[last_position] = number_toadd;
                last_position ++;
                last_space = i + 1;
            }
        }
    }
}
*/

Multime::~Multime()
{
    delete[] v;

    //cout << "Destructor" << endl;
}

Multime::Multime(const Multime& other) : dimensiune(other.dimensiune)
{
    //dimensiune = other.dimensiune;
    if(!dimensiune)
        v = NULL;
    else
    {
        v = new int[dimensiune];

        for(int i = 0; i < dimensiune; i ++)
        {
            v[i] = other.v[i];
        }
    }
    //cout << "Copy Constructor" << endl;
}

Multime& Multime::operator=(const Multime& other)
{
    if (this == &other) return *this; // handle self assignment

    delete[] v;
    dimensiune = other.dimensiune;
    if(!dimensiune)
        v = NULL;
    else
    {
        v = new int[dimensiune];

        for(int i = 0; i < dimensiune; i ++)
        {
            v[i] = other.v[i];
        }
    }

    //cout << "Assignment operator" << endl;
    return *this;
}

int Multime::get_size()
{
    return dimensiune;
}

void Multime::set_size(int x)
{
    dimensiune = x;
}


void Multime::fix_vector()
{
    for(int i = 0; i < dimensiune - 1; i ++)
    for(int j = i + 1; j < dimensiune; j ++)
    {
        if(v[i] == v[j])
        {
            for(int k = j; k < dimensiune - 1; k ++)
            {
                v[k] = v[k+1];
            }

            j --;
            v[dimensiune - 1] = 0;  // M-am gandit ca nu e cazul sa dau delete si sa fac o 'realocare' pentru fiecare element pe care il elimin
            dimensiune --;

            /* ALTFEL -
            int *newArray = new int[dimensiune-1];
            copy(v, v+i, newArray);
            copy(v+i+1, v+dimensiune, newArray+i);
            delete[] v;
            v = newArray;
            dimensiune --;*/
        }
    }

}

ostream& operator<<(ostream &out, const Multime &multime)
{
    out << "Multime: ";
    for(int i = 0; i < multime.dimensiune; i ++)
    {
        out << multime.v[i];
        if(i < multime.dimensiune - 1)
            out << ", ";
        else
            out << ".";
    }
    out << endl;

    return out;
}

istream& operator>>(istream &in, Multime &multime)
{
    //cout << "Dimensiune:";
    in >> multime.dimensiune;

    if(!multime.dimensiune)
        multime.v = NULL;

    else
    {
        delete[] multime.v;
        multime.v = new int[multime.dimensiune];

        for(int i = 0; i < multime.dimensiune; i ++)
        {
            //cout << "Elementul nr." << i + 1 << " : ";
            in >> multime.v[i];
        }
    }

    //multime.fix_vector(); //- nu stiu daca sa o apelez de fiecare data cand citesc sau sa o pun in interiorul supraincarcarii operatorului >>

    return in;
}

Multime operator+(const Multime &M1, const Multime &M2)
{
    int new_size = M1.dimensiune + M2.dimensiune;
    int* newArray = new int[new_size];
    //int newArray[new_size];
    int k = 0;

    for(int i = 0; i < M1.dimensiune; i ++)
        newArray[i] = M1.v[i];

    for(int i = M1.dimensiune; i < new_size; i ++)
    {
        newArray[i] = M2.v[k];
        k++;
    }

    Multime M3(new_size, newArray);
    M3.fix_vector();
    delete[] newArray;

    return M3;
}

Multime operator*(const Multime &M1, const Multime &M2)
{
    int new_size, temp_size = 0;
    int* newArray;

    if(M1.dimensiune <= M2.dimensiune)
        new_size = M1.dimensiune;
    else
        new_size = M2.dimensiune;

    newArray = new int[new_size];

    for(int i = 0; i < M1.dimensiune; i ++)
    for(int j = 0; j < M2.dimensiune; j ++)
    {
        if(M1.v[i] == M2.v[j])
        {
            newArray[temp_size] = M1.v[i];
            temp_size ++;
        }
    }

    int* tempArray;
    tempArray = new int[temp_size];
    for(int i = 0; i < temp_size; i ++)
    {
        tempArray[i] = newArray[i];
    }

    Multime M3(temp_size, tempArray);
    M3.fix_vector();
    delete[] tempArray;
    delete[] newArray;

    return M3;
}

Multime operator-(const Multime &M1, const Multime &M2)
{
    bool found = false;
    int new_size, temp_size = 0;
    int* newArray;

    if(M1.dimensiune >= M2.dimensiune)
        new_size = M1.dimensiune;
    else
        new_size = M2.dimensiune;

    newArray = new int[new_size];

    for(int i = 0; i < M1.dimensiune; i ++)
    {
        found = false;

        for(int j = 0; j < M2.dimensiune; j ++)
        {
            if(M1.v[i] == M2.v[j])
            {
                found = true;
                j = M2.dimensiune;
            }
        }

        if(!found)
        {
            newArray[temp_size] = M1.v[i];
            temp_size ++;
        }
    }

    int* tempArray;
    tempArray = new int[temp_size];
    for(int i = 0; i < temp_size; i ++)
    {
        tempArray[i] = newArray[i];
    }


    Multime M3(temp_size, tempArray);
    //M3.fix_vector(); // - not sure if i need it here, will check later.
    delete[] tempArray;
    delete[] newArray;

    return M3;
}

bool operator== (const Multime &M1, const Multime &M2)
{
    if(M1.dimensiune != M2.dimensiune)  // Multimile trebuie sa aiba acelasi numar de elemente pentru a fi identice.
        return false;

    Multime M3 = M1 * M2;

    /*
        Daca intersectia a doua multimi are acelasi numar de elemente ca si oricare dintre cele doua multimi(avand in vedere faptul ca cele doua multimi au acelasi numar de elemente)
        inseamna ca toate elementele uneia se regasesc si in cealalta.

        TL;DR: Daca ai 2 multimi cu acelasi numar de elemente si intersectia lor are tot acelasi numar de elemente inseamna ca cele 2 multimi sunt egale.
    */
    if(M3.dimensiune != M1.dimensiune || M3.dimensiune != M2.dimensiune)
        return false;

    return true;
}

bool operator!= (const Multime &M1, const Multime &M2)
{
    return !(M1 == M2);
}
