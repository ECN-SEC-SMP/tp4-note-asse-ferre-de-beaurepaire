#pragma once

#include <string>
#include "Zn.hpp"
#include "Constructible.hpp"

using namespace std;

template <typename T>
class Za : public Zn<T>, public Constructible
{
    private :

        string typeCulture;

    protected :

    public :

        // Constructeur par défaut
        Za();
        // Constructeur détaillé
        Za(string tCulture);
        // Constructeur par recopie
        Za(const Za& za);

        // Assesseur get
        string getTypeCulture();

        // Assesseur set
        void setTypeCulture(string newTypeCulture);
};

/* // Inclusion de l'implémentation directement dans le fichier d'en-tête
template <typename T>
Za<T>::Za() : type(""), proprietaire(""), numero(0), pConstructible(0), surface(0.0f), forme(Polygone<T>())
{

} */

// Getter
template <typename T>
string Za<T>::getTypeCulture()
{
    return this.typeCulture;
}

// Setter
template <typename T>
void Za<T>::setTypeCulture(string newTypeCulture)
{
    this.typeCulture = newTypeCulture;
}
