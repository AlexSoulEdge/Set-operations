#include <iostream>
#include <fstream>
#include "Multime.h"

using namespace std;

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

    for(int i = 0; i < n; i ++)
    {
        cout << M[i];
    }





    //STUFF
    /*Multime Mx = M[1] + M[0];

    cout << Mx;*/

    if(M[2] == M[3])
        cout<<"da";
    else cout << "nu";

    return 0;
}
