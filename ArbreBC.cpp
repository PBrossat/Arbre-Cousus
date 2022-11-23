#include "ArbreBC.h"
#include <iostream>
using namespace std;



ArbreBC::ArbreBC()
{   
    racine=nullptr;
    minimum=nullptr;
}


void ArbreBC::suppressionRacine()
{
    delete racine;
}


ArbreBC::~ArbreBC()
{
    suppressionRacine(); //supprime recursivement TOUS les noeuds de l'arbre à partir de la racine.
}


const Noeud * ArbreBC::rechercheElem(const Elem & e)const 
{
    return racine->rechercheElement(e); //on appel rechercheElement de Noeud.h à partir de la racine de l'arbre 
}



Noeud* ArbreBC::insertionElement(const Elem & e)
{
    if (racine==nullptr)
    {
        racine=new Noeud(e); 
    } 
    return racine->insertionElement(e);
}


void ArbreBC::coudreArbre()
{
    if(racine==nullptr)
    {return;}
    racine->coudreArbre(nullptr);
    Noeud* curseur = racine; // création de curseur pour parcourir l'arbre et trouver le minimum
    while (curseur->filsG!=nullptr) //tant que le fils gauche existe 
    {
        curseur=curseur->filsG; // on se déplace à gauche 
    }
    minimum=curseur; // minimum est initialisé
}





 //affichage du plus petit
    //tant que fils droit != null
        //si j'ai pas de fils droit alors
            //courant = courant->filsdroit
            //afficher courant 
        //sinon j'ai un fils droit alors
            //courant = courant->filsdroit
            //Tant que filsgauche courant != null
                //courant = courant -> filsg
            //afficher courant


void ArbreBC::affichageInfixeItera()const
{
    Noeud* curseur =minimum;
    cout<<curseur->info<<endl;
    while (curseur->filsD!=nullptr)
    {
        if (curseur->filsDroitCousu) //fils droit pointe avec une coûture (pointe vers un element au dessus de lui)
        {
            curseur=curseur->filsD;
            cout<<curseur->info<<endl;
        }
        else 
        {
            curseur=curseur->filsD;
            while (curseur->filsG!=nullptr)
            {
                curseur=curseur->filsG;
            }
            cout<<curseur->info<<endl;
        }
    }
}



void ArbreBC::affichageInfixe()const
{
    racine->affichageInfixe();
}

void ArbreBC::affichagePrefixe()const
{
    racine->affichagePrefixe();
}

void ArbreBC::affichagePostfixe()const
{
    racine->affichagePostfixe();
}