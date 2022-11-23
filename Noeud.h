#ifndef _NOEUD
#define _NOEUD
#include "Element.h"


class Noeud
{
    public:
    Noeud();
    Noeud(const Elem &e);
    ~Noeud();
    const Noeud* rechercheElement(const Elem &e)const;   
    Noeud*  insertionElement( const Elem &e);
    void coudreArbre(Noeud* dernier_gauche);
    void affichageInfixe()const;
    void affichagePrefixe()const;
    void affichagePostfixe()const;
    bool filsDroitCousu;//bool permettant de savoir si le fils droit est cousu ou non
    Elem info;
    Noeud * filsD; //fils droit du noeud 
    Noeud * filsG; //fils gauche du noeud 


};



#endif