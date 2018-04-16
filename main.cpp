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

void sort(int szArray, Multime Array[])
{
    for(int i = 0; i < szArray; i ++)
    for(int j = 0; j < szArray; j ++)
    {
        Multime temp;
        if((Array[i] < Array[j]))
        {
            temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
        }
    }
}

int main()
{
    int n;
    ifstream fin("text.txt");

    fin >> n;
    Multime M[n];

    for(int i = 0; i < n; i ++)
    {
        fin >> M[i];
        M[i].fix_vector(); //- nu stiu daca sa o apelez de fiecare data cand citesc sau sa o pun in interiorul supraincarcarii operatorului >>
    }

    menu:
        cout << "1. Citeste un obiect de la tastatura si afiseaza-l pe ecran." << endl;
        cout << "2. Citeste obiecte din fisier si afiseaza-le pe ecran." << endl;
        cout << "3. Operatii cu multimi citite dintr-un fisier. (vezi 2.)" << endl;
        cout << "4. Sorteaza un vector de multimi citit dintr-un fisier. (vezi 2.)" << endl;
        cout << "5. Exit." << endl << endl;

    pickoption:
    int option;
    cout << "Optiune: ";
    cin >> option;

    if(option == 1)
        goto option1;
    else if(option == 2)
        goto option2;
    else if(option == 3)
        goto option3;
    else if(option == 4)
        goto option4;
    else if(option == 5)
        goto option5;
    else
        goto pickoption;

    option1:
    {
        // Citirea de la tastatura a unui obiect;
        //int size_Mx;
        Multime Mx;
        cin >> Mx;
        Mx.fix_vector();

        cout << Mx << endl;
        cout << endl << endl;
        goto menu;
    }

    option2:
        // Citirea dintr-un fisier si afisarea pe ecran

        cout << endl << endl;
        cout << "Multimile din fisier sunt: " << endl;
        for(int i = 0; i < n; i ++)
        {
            cout << M[i];
        }
        fin.close();

        cout << endl << endl;
        goto menu;


    option3:
    {
        // Operatii cu multimi
        cout << endl;
        cout << "1. + - Reuniunea a doua multimi" << endl;
        cout << "2. - - Scaderea a doua multimi" << endl;
        cout << "3. * - Intersectia a doua multimi" << endl;
        cout << "4. == - Egalitatea" << endl;
        cout << "5. != - text" << endl;
        cout << "6. < - Comparatia" << endl;
        cout << "7. Produsul cartezian al 2 multimi." << endl;
        cout << "8. Afiseaza multimile." << endl;
        cout << "9. Inapoi la meniu." << endl << endl;

        pickoptionx:
            int optionx;
            cout << "Optiune: ";
            cin >> optionx;

            if(optionx == 1)
                goto option31;
            else if(optionx == 2)
                goto option32;
            else if(optionx == 3)
                goto option33;
            else if(optionx == 4)
                goto option34;
            else if(optionx == 5)
                goto option35;
            else if(optionx == 6)
                goto option36;
            else if(optionx == 7)
                goto option37;
            else if(optionx == 8)
                goto option38;
            else if(optionx == 9)
                goto option39;
            else
                goto pickoptionx;

            int m1, m2;

        option31:
        {
            cout << "Alege 2 multimi (de la 0 la " << n-1 << ") : ";
            cin >> m1 >> m2;
            cout << M[m1] + M[m2] << endl;

            cout << endl << endl;
            goto option3;
        }

        option32:
        {
            cout << "Alege 2 multimi (de la 0 la " << n-1 << ") : ";
            cin >> m1 >> m2;
            cout << M[m1] - M[m2] << endl;

            cout << endl << endl;
            goto option3;
        }

        option33:
        {
            cout << "Alege 2 multimi (de la 0 la " << n-1 << ") : ";
            cin >> m1 >> m2;
            cout << M[m1] * M[m2] << endl;

            cout << endl << endl;
            goto option3;
        }

        option34:
        {
            cout << "Alege 2 multimi (de la 0 la " << n-1 << ") : ";
            cin >> m1 >> m2;
            if(M[m1] == M[m2])
                cout << "Cele doua multimi SUNT egale.";
            else
                cout << "Cele doua multimi NU SUNT egale.";

            cout << endl << endl;
            goto option3;
         }

        option35:
        {
            cout << "Alege 2 multimi (de la 0 la " << n-1 << ") : ";
            cin >> m1 >> m2;
            if(M[m1] != M[m2])
                cout << "Cele doua multimi NU SUNT egale.";
            else
                cout << "Cele doua multimi SUNT egale.";

            cout << endl << endl;
            goto option3;
        }

        option36:
        {
            cout << "Alege 2 multimi (de la 0 la " << n-1 << ") : ";
            cin >> m1 >> m2;
            if(M[m1] < M[m2])
                cout << "Multimea "<< m1 << " ARE mai putine elemente decat multimea " << m2 <<".";
            else
                cout << "Multimea "<< m1 << " NU ARE mai putine elemente decat multimea " << m2 <<".";

            cout << endl << endl;
            goto option3;
        }

        option37:
        {
            cout << "Alege 2 multimi (de la 0 la " << n-1 << ") : ";
            cin >> m1 >> m2;
            cout << produs_cartezian(M[m1], M[m2]);
            cout << endl << endl;
            goto option3;
        }

        option38:
        {
            cout << endl;
            for(int i = 0; i < n; i ++)
            {
            cout << M[i];
            }
            goto option3;
        }

        option39:
        {
            goto menu;
        }

    }


    /*cout << endl << endl << endl;
    cout << "Operatii: " << endl;
    cout << M[0] + M[1];


    cout << endl;
    cout << "Produsul Cartezian:" <<endl;
    cout << produs_cartezian(M[1], M[3]);
    cout << endl;
    goto menu;*/


    option4:
    {
        // Sortarea unui vector de multimi prin utilizarea <
        cout << endl;
        cout << "Sortat: " << endl;
        sort(n, M);
        for(int i = 0; i < n; i ++)
        {
            cout << M[i];
        }
        cout << endl << endl;
        goto menu;
    }


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

    option5:
    return 0;
}
