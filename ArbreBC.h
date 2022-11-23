#ifndef _LISTE
#define _LISTE
#include "Noeud.h" // offrant le type Noeud 
#include "Element.h" //offrant le type Elem

class ArbreBC
{
    public:

    ArbreBC();

    ~ArbreBC();

    void suppressionRacine();

    const Noeud * rechercheElem(const Elem & e)const;

    Noeud* insertionElement(const Elem &e);

    void affichageInfixeItera()const; //permet d'afficher infixement l'arbre sans recursivité

    void coudreArbre(); 

    Noeud * racine; //pointeur vers la racine de l'arbre 

    Noeud * minimum; //pointeur vers l'element minimum de l'arbre (parcours uniquement à gauche jusqu'à que le noeud n'ai plus de fils gauche)

    void affichageInfixe()const;
    
    void affichagePrefixe()const;
    
    void affichagePostfixe()const;
};
#endif