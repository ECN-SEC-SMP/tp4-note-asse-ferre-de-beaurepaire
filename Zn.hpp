#pragma once

#include <string>
#include "Parcelle.hpp"

using namespace std;

template <typename T>
class Zn : public Parcelle<T>
{
    private:

    protected:

    public:

        // Constructeur par défaut
        Zn();
        // Constructeur détaillé
        Zn(int num, string prop, Polygone<T> forme);
        // Constructeur par recopie
        Zn(const Zn& zn);
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête
// Constructeur par défaut
template <typename T>
Zn<T>::Zn() : Parcelle<T>()
{
    this->setType("ZN");
    this->setPContructible(0);
}

// Constructeur détaillé
template <typename T>
Zn<T>::Zn(int num, string prop, Polygone<T> forme) : Parcelle<T>(num, prop, forme)
{
    this->setType("ZN");
    this->setPContructible(0);
}

// Constructeur par recopie
template <typename T>
Zn<T>::Zn(const Zn& zn): Parcelle<T>(zn)
{
    this->setPContructible(zn.getPContructible());
    this->setType(zn.getType());
}