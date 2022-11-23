#include "Noeud.h"
#include <iostream>
using namespace std;

Noeud::Noeud()
{
    info=0;
    filsD=nullptr;
    filsG=nullptr;
}

Noeud::Noeud(const Elem & e )
{
    info=e;
    filsD=nullptr;
    filsG=nullptr;
}

Noeud::~Noeud()
{   
    if (!filsDroitCousu)
    {
        delete filsD;
    }
    delete filsG;
}

const Noeud * Noeud::rechercheElement(const Elem &e)const
{
    if (e==this->info)
    {
        return this; 
    }
    if ((e<this->info)&&(this->filsG!=nullptr)) //si l'element en parametre est < que l'info du noeud et que le fils g existe => aller à gauche 
    {
       return this->filsG->rechercheElement(e); //appel recursif à gauche 
    }
    else if((e>this->info)&&(this->filsD!=nullptr)) //si l'element en parametre est > que l'info du noeud et que le fils D existe => aller à droite
    {
        return this->filsD->rechercheElement(e); //appel recursif à droite 
    }
    else return nullptr; //sinon l'élément n'est pas dans l'arbre donc renvoie nullptr
}



Noeud* Noeud::insertionElement(const Elem & e)
{
    
    if (e==this->info) // si l'élément en parametre = l'info du noeud 
    {
        return this; //on retourne le Noeud 
    }
    if (e<this->info) //cas filsG
    {
        if (filsG!=nullptr) //si il existe un fils gauche 
        {
            filsG->insertionElement(e); //apel recursif sur le filsG 
        }else //sinon
        {
            Noeud * res= new Noeud(e); // création d'un nouveau noeud res 
            filsG=res; //le fils gauche est maintenant le nouveau noeud res créé 
        }
    }
    else if (e>this->info) //cas filsD
    {
        if (filsD!=nullptr) //si il existe un fils droit  
        {
            filsD->insertionElement(e); //appel recursif sur le filsD
        }else //sinon 
        {
            Noeud * res= new Noeud(e); // création d'un nouveau noeud res 
            filsD=res; //le fils droit est maintenant le nouveau noeud res créé 
        }
    }
    return this ; 
}


void Noeud::coudreArbre(Noeud*dernier_gauche)
{
    if (this->filsG!=nullptr) //si il existe un fils gauche 
    {
        this->filsG->coudreArbre(this); //appel recursif
    }

    if (this->filsD!=nullptr) //si il existe un fils droit 
    {
        this->filsD->coudreArbre(dernier_gauche); //appel recursif 
    }
    else 
    {
        this->filsD=dernier_gauche; //alors je le fais pointer sur le dernier gauche 
        filsDroitCousu=true;
    }
}




void Noeud::affichageInfixe()const 
{
    if (this->filsG!=nullptr)
    {
        this->filsG->affichageInfixe();
    }
    cout<<this->info<<endl;
    if (this->filsD!=nullptr)
    {
        this->filsD->affichageInfixe();
    }
}



void Noeud::affichagePrefixe()const 
{
    cout<<this->info<<endl;
    if (this->filsG!=nullptr)
    {
        this->filsG->affichagePrefixe();
    }
    if (this->filsD!=nullptr)
    {
        this->filsD->affichagePrefixe();
    }
}



void Noeud::affichagePostfixe()const 
{
    
    if (this->filsG!=nullptr)
    {
        this->filsG->affichagePostfixe();
    }
    if (this->filsD!=nullptr)
    {
        this->filsD->affichagePostfixe();
    }
    cout<<this->info<<endl;
}