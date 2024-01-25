#pragma once

#include <string>
#include "Parcelle.hpp"

using namespace std;

template <typename T>
class Za : public Zn<T>
{
    private:

        string typeCulture;

    protected:

    public:

        // Constructeur par défaut
        Za();
        // Constructeur détaillé
        Za(int num, string prop, Polygone<T> forme, string tCulture);
        // Constructeur par recopie
        Za(const Za& Za);

        // Assesseur get
        string getTypeCulture() const;

        // Assesseur set
        void setTypeCulture(string newTypeCulture);
};


// Inclusion de l'implémentation directement dans le fichier d'en-tête
// Constructeur par défaut
template <typename T>
Za<T>::Za() : Zn<T>(), typeCulture("")
{
    this->setType("ZA");
    this->setPContructible(0);
}

// Constructeur détaillé
template <typename T>
Za<T>::Za(int num, string prop, Polygone<T> forme, string tCulture)
: Zn<T>(num, prop, forme)
{
    this->setType("ZA");
    this->setPContructible(0);
    this->setTypeCulture(tCulture);
}

// Constructeur par recopie
template <typename T>
Za<T>::Za(const Za& za) : Zn<T>(za)
{
    this->setType(za.type);
    this->setPContructible(za.pConstructible);
    this->setTypeCulture(za.typeCulture);
}

// Getter
template <typename T>
string Za<T>::getTypeCulture() const
{
    return this->typeCulture;
}

// Setter
template <typename T>
void Za<T>::setTypeCulture(string newTypeCulture)
{
    this->typeCulture = newTypeCulture;
}

//Surcharge de l'opérateur de sortie <<
template <typename T>
ostream& operator<<(ostream& os, const Za<T>& Za)
{
    os << static_cast<const Parcelle<T>&>(Za) << endl; // Appel de l'opérateur << de la classe Parcelle
    os << " Type de Culture: " << Za.getTypeCulture() << endl;
    return os;
}