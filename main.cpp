#include "ArbreBC.h"
#include <time.h> 
#include <stdlib.h>
using namespace std;
#include <iostream>

int main ()
{
    ArbreBC arb;
    srand (time(NULL));
    for (int i=0; i<=10; i++)
    {
        int c=rand() % 100;
        arb.insertionElement(c);
    }
    //arb.affichageInfixe();
    // cout<<endl;
    // cout<<endl;
    // arb.affichagePrefixe();
    // cout<<endl;
    // cout<<endl;
    // arb.affichagePostfixe();
    arb.coudreArbre();
    arb.affichageInfixeItera();
}