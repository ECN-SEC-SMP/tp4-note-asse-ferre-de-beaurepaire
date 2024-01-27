#pragma once

#include <string>
#include "Parcelle.hpp"

using namespace std;

template <typename T>
class Za : public Zn<T>, public Constructible
{
    private:

    protected:

    public:

        // Constructeur par défaut
        Za();
        // Constructeur détaillé
        Za(int num, string prop, Polygone<T> forme, string tCulture);
        // Constructeur par recopie
        Za(const Za& Za);

        // Redéfinition de la méthode virtuelle pure
        virtual float surfaceConstructible() const override;
};


// Inclusion de l'implémentation directement dans le fichier d'en-tête
// Constructeur par défaut
template <typename T>
Za<T>::Za() : Zn<T>()
{
    this->setType("ZA");
    this->setPContructible(10);
}

// Constructeur détaillé
template <typename T>
Za<T>::Za(int num, string prop, Polygone<T> forme, string tCulture)
: Zn<T>(num, prop, forme, tCulture)
{
    this->setType("ZA");
    this->setPContructible(10);
}

// Constructeur par recopie
template <typename T>
Za<T>::Za(const Za& za) : Zn<T>(za) {}

// Redéfinition de la méthode virtuelle pure
template <typename T>
float Za<T>::surfaceConstructible() const
{
    int s_constructible = (this->getSurface() * this->getPContructible()) / 100;
    return (s_constructible > 200) ? 200 : s_constructible;
}

//Surcharge de l'opérateur de sortie <<
template <typename T>
ostream& operator<<(ostream& os, const Za<T>& za)
{
    os << static_cast<const Zn<T>&>(za) << endl; // Appel de l'opérateur << de la classe Parcelle
    os << "     Surface constructible: " << za.surfaceConstructible() << endl;
    return os;
}