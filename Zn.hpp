#pragma once

#include <string>
#include "Parcelle.hpp"

using namespace std;

template <typename T>
class Zn : public Parcelle<T>
{
    private:

        string typeCulture;

    protected:

    public:

        // Constructeur par défaut
        Zn();
        // Constructeur détaillé
        Zn(int num, string prop, Polygone<T> forme, string tCulture);
        // Constructeur par recopie
        Zn(const Zn& zn);

        // Assesseur get
        string getTypeCulture() const;

        // Assesseur set
        void setTypeCulture(string newTypeCulture);

};

// Inclusion de l'implémentation directement dans le fichier d'en-tête
// Constructeur par défaut
template <typename T>
Zn<T>::Zn() : Parcelle<T>(), typeCulture("")
{
    this->setType("ZN");
    this->setPContructible(0);
}

// Constructeur détaillé
template <typename T>
Zn<T>::Zn(int num, string prop, Polygone<T> forme, string tCulture) : Parcelle<T>(num, prop, forme)
{
    this->setType("ZN");
    this->setPContructible(0);
    this->typeCulture = tCulture;
}

// Constructeur par recopie
template <typename T>
Zn<T>::Zn(const Zn& zn): Parcelle<T>(zn)
{
    this->setPContructible(zn.getPContructible());
    this->setType(zn.getType());
    this->setTypeCulture(zn.getTypeCulture());
}

// Getter
template <typename T>
string Zn<T>::getTypeCulture() const
{
    return this->typeCulture;
}

// Setter
template <typename T>
void Zn<T>::setTypeCulture(string newTypeCulture)
{
    this->typeCulture = newTypeCulture;
}

//Surcharge de l'opérateur de sortie <<
template <typename T>
ostream& operator<<(ostream& os, const Zn<T>& zn)
{
    os << static_cast<const Parcelle<T>&>(zn) << endl; // Appel de l'opérateur << de la classe Parcelle
    os << "     Type de Culture: " << zn.getTypeCulture() << endl;
    return os;
}