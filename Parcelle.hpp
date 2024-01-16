#pragma once

#include "Polygone.hpp"
#include <string>
#include <ostream>

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
        Polygone<T> forme;

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
        string getProprietaire() const;
        float getSurface() const;
        Polygone<T> getForme() const;
        string getName() const;

        // Accesseurs set
        void setNumero(int n);
        void setProprietaire(string prop);
        void setForme(Polygone<T> forme);
        void setType(string type);

        // Surcharge opérateur <<
        template <typename U>
        friend ostream& operator<<(ostream& os, const Parcelle<U>& parc);
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête
template <typename T>
Parcelle<T>::Parcelle() : type(""), proprietaire(""), numero(0), pConstructible(0), surface(0.0f), forme(Polygone<T>())
{

}

// Constructeur détaillé
template <typename T>
Parcelle<T>::Parcelle(int num, string prop, Polygone<T> forme)
    : type(""), proprietaire(prop), numero(num), pConstructible(0), surface(0.0f), forme(forme)
{

}

// Constructeur par recopie
template <typename T>
Parcelle<T>::Parcelle(const Parcelle& parc)
    : type(parc.type), proprietaire(parc.proprietaire), numero(parc.numero), pConstructible(parc.pConstructible),
      surface(parc.surface), forme(parc.forme)
{

}

template <typename T>
int Parcelle<T>::getNumero() const
{
    return this->numero;
}

// Surcharge de l'opérateur de sortie <<
template <typename T>
ostream& operator<<(ostream& os, const Parcelle<T>& parc)
{
    os << "Parcelle :";
    os << " Type: " << parc.type << " Proprietaire: " << parc.proprietaire << endl;
    os << " Numero: " << parc.getNumero() << " pConstructible: " << parc.pConstructible << endl;
    os << " Surface: " << parc.surface << " forme: " << parc.forme;

    return os;
}