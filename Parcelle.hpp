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

        float calculerSurface();

    protected :

    public :

        // Constructeur par défaut
        Parcelle();
        // Constructeur détaillé
        Parcelle(int num, string prop, Polygone<T> form);
        // Constructeur par recopie
        Parcelle(const Parcelle& parc);

        // Accesseurs get
        string getType() const;
        string getProprietaire() const;
        int getNumero() const;
        int getPContructible() const;
        float getSurface() const;
        Polygone<T> getForme() const;

        // Accesseurs set
        void setNumero(int n);
        void setProprietaire(string prop);
        void setForme(Polygone<T> forme);
        void setType(string type);
        void setPContructible(int pConstructible);

        // Surcharge opérateur <<
        template <typename U>
        friend ostream& operator<<(ostream& os, const Parcelle<U>& parc);
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête
template <typename T>
Parcelle<T>::Parcelle() : type(""), proprietaire(""), numero(0), pConstructible(100), surface(0.0f), forme(Polygone<T>())
{

}

// Constructeur détaillé
template <typename T>
Parcelle<T>::Parcelle(int num, string prop, Polygone<T> forme)
    : type(""), proprietaire(prop), numero(num), pConstructible(100), forme(forme)
{
    this->surface = this->calculerSurface();
}

// Constructeur par recopie
template <typename T>
Parcelle<T>::Parcelle(const Parcelle& parc)
    : type(parc.type), proprietaire(parc.proprietaire), numero(parc.numero), pConstructible(parc.pConstructible),
      surface(parc.surface), forme(parc.forme)
{

}

// Fonction pour calculer la surface du polygone
template <typename T>
float Parcelle<T>::calculerSurface()
{
    vector<Point2D<T> > sommets = this->forme.getSommets();

    // Calcul de la surface en utilisant les sommets du polygone
    size_t n = sommets.size();
    if (n < 3)
        return 0.0;  // Un polygone avec moins de 3 sommets n'a pas de surface

    float surface = 0.0;
    for (size_t i = 0; i < n - 1; ++i)
        surface += (sommets[i].getX() * sommets[i + 1].getY() - sommets[i + 1].getX() * sommets[i].getY());

    surface += (sommets[n - 1].getX() * sommets[0].getY() - sommets[0].getX() * sommets[n - 1].getY());
    surface /= 2;

    if (surface < 0)
        throw domain_error("La surface du polygone ne peut pas être négative.");

    return surface;
}

// getters
// a mettre en virtuel pur plus tard pour ne pas bloquer l'instanciation lors des jeux d'essai
template <typename T>
string Parcelle<T>::getType() const
{
    return this->type;
}

template <typename T>
string Parcelle<T>::getProprietaire() const
{
    return this->proprietaire;
}

template <typename T>
int Parcelle<T>::getNumero() const
{
    return this->numero;
}

template <typename T>
int Parcelle<T>::getPContructible() const
{
    return this->pConstructible;
}

template <typename T>
float Parcelle<T>::getSurface() const
{
    return this->surface;
}

template <typename T>
Polygone<T> Parcelle<T>::getForme() const
{
    return this->forme;
}

// setters
template <typename T>
void Parcelle<T>::setType(string type)
{
    this->type = type;
}

template <typename T>
void Parcelle<T>::setProprietaire(string prop)
{
    this->numero = prop;
}

template <typename T>
void Parcelle<T>::setNumero(int n)
{
    this->numero = n;
}

template <typename T>
void Parcelle<T>::setForme(Polygone<T> forme)
{
    this->forme = forme;

    //Recalcul de la surface
    this->surface = this->calculerSurface();
}

template <typename T>
void Parcelle<T>::setPContructible(int pConstructible)
{
    this->pConstructible = pConstructible;
}

// Surcharge de l'opérateur de sortie <<
template <typename T>
ostream& operator<<(ostream& os, const Parcelle<T>& parc)
{
    os << "Parcelle :";
    os << " Type: " << parc.getType() << " Proprietaire: " << parc.getProprietaire() << endl;
    os << " Numero: " << parc.getNumero() << " pConstructible: " << parc.getPContructible() << endl;
    os << " Surface: " << parc.getSurface() << " forme: " << parc.getForme();

    return os;
}