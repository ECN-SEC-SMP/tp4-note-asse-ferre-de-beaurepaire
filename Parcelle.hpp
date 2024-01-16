#pragma once

#include "Polygone.hpp"
#include <string>

using namespace std;

template <typename T>
class Parcelle
{
    private :

        string type;
        string proprietaire;

        int numero;
        int pConstructible;

        float surface;

        Polygone<int, float> forme;

    protected :

    public :

        // Constructeur par défaut
        Parcelle();

        // Constructeur détaillé
        Parcelle(int num, string prop, Polygone<T> form);

        // Constructeur par recopie
        Parcelle(const Parcelle& parc);


        // Accesseurs get
        int getNumero() const;
        int getProprietaire() const;

        float getSurface() const;

        Polygone<int, float> getForme() const;

        string getName() const;


        // Accesseurs set
        void setNumero(int n);
        void setProprietaire(string prop);
        void setForme(Polygone<int, float> forme);
        void setType(string type);

        // Surcharge opérateur <<
        template <typename T>
        ostream& operator<<(ostream& os, const Parcelle<T>& parc);
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête
template <typename T>
Parcelle<T>::Parcelle() : numero(0), proprietaire(""), forme(T()), type(""), pConstructible(0), surface(0.0f)
{

}

template <typename T>
Parcelle<T>::Parcelle(int num, string prop, Polygone<T> forme) : numero(num), proprietaire(prop), forme(form), type(""), pConstructible(0), surface(0.0f)
{

}

// Implémentation du constructeur par recopie
template <typename T>
Point2D<T>::Point2D(const Point2D& other) : x(other.x), y(other.y)
{

}

// Surcharge de l'opérateur de sortie <<
template <typename T>
ostream& operator<<(ostream& os, const Parcelle<T>& parc)
{
    os << "Parcelle :";
    os << parc.type;
    os << ", ";
    os << parc.proprietaire;
    os << ". ";

    return os;
}