#include <iostream>
#include <fstream>
#include "Multime.h"
#include "Pereche.h"
#include "Multime_Perechi.h"

using namespace std;

Multime_Perechi produs_cartezian(const Multime &M1, const Multime &M2)
{
    int produs_size = M1.dimensiune * M2.dimensiune;
    Pereche Array[produs_size];
    int k = 0;

    for(int i = 0; i < M1.dimensiune; i ++)
    for(int j = 0; j < M2.dimensiune; j ++)
    {
        Pereche temp(M1.v[i], M2.v[j]);
        Array[k] = temp;
        k++;
    }

    Multime_Perechi produs(produs_size, Array);

    return produs;
}

int main()
{
    // Citirea de la tastatura a unui obiect;
    int size_Mx;
    Multime Mx;
    cin >> Mx;
    Mx.fix_vector();

    cout << Mx << endl;


    // Citirea dintr-un fisier si afisarea pe ecran
    int n;
    ifstream fin("text.txt");

    fin >> n;
    Multime M[n];

    for(int i = 0; i < n; i ++)
    {
        fin >> M[i];
        M[i].fix_vector(); //- nu stiu daca sa o apelez de fiecare data cand citesc sau sa o pun in interiorul supraincarcarii operatorului >>
    }

    for(int i = 0; i < n; i ++)
    {
        cout << M[i];
    }
    fin.close();


    // Operatii cu multimi
    cout << endl << endl << endl;
    cout << "Operatii: " << endl;
    cout << M[0] + M[1];


    cout << endl;
    cout << "Produsul Cartezian:" <<endl;
    cout << produs_cartezian(M[1], M[3]);
    cout << endl;


    //PERECHE
    /*ifstream fin2("text2.txt");

    int n2;

    fin2 >> n2;
    Pereche P[n2];

    for(int i = 0; i < n2; i ++)
    {
        fin2 >> P[i];
    }

    for (int i = 0; i < n2; i ++)
        cout << P[i] << " ";
    fin2.close();


    cout << endl << endl;
    Multime_Perechi MP(n2, P);

    //for(int i = 0; i < n2; i ++)
        cout << MP;*/



    //MULTIME_ PERECHE
    /*ifstream fin3("text3.txt");

    int n3;

    fin3 >> n3;

    Multime_Perechi MP[n3];

    for(int i = 0; i < n3; i ++)
    {
        fin3 >> MP[i];
        MP[i].fix_vector();
    }


    for(int i = 0; i < n3; i ++)
        cout << MP[i] << endl;
    fin3.close();*/


    return 0;
}
