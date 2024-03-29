#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include "Parcelle.hpp"
#include "Constructible.hpp"

using namespace std;

template <typename T>
class Zu : public Parcelle<T>, public Constructible
{
    private:

        float surfaceConstruite;

    protected:

    public:
        // Constructeur par défaut
        Zu();

        // Constructeur avec des valeurs initiales
        Zu(int num, string prop, Polygone<T> form, float surfaceConstruite, int pConstructible);

        // Constructeur par recopie
        Zu(const Zu<T>& other);

        // Redéfinition de la méthode virtuelle pure
        virtual float surfaceConstructible() const override;

        template <typename U>
        friend ostream& operator<<(ostream& os, const Zu<U>& zu);
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête

// Constructeur par défaut
template <typename T>
Zu<T>::Zu() : Parcelle<T>(),  surfaceConstruite(0)
{
    this->setType("Zu");
}

// Constructeur avec des valeurs initiales
template <typename T>
Zu<T>::Zu(int num, string prop, Polygone<T> form, float surfaceConstruite, int pConstructible) : Parcelle<T>(num, prop, form)
{
    if ((pConstructible < 0) || (pConstructible > 100))
        throw invalid_argument("pConstructible n'est pas compris entre 0 et 100");
    else
        this->setPContructible(pConstructible);

    this->surfaceConstruite = surfaceConstruite;
    if (this->surfaceConstructible() < 0.0f)
        throw invalid_argument("La surface contruite ne peut pas être supérieure à la surface de la parcelle...");

    this->setType("Zu");
}

// Constructeur par recopie
template <typename T>
Zu<T>::Zu(const Zu<T>& other) : Parcelle<T>(other), surfaceConstruite(other.surfaceConstruite) {}

// Redéfinition de la méthode virtuelle pure
template <typename T>
float Zu<T>::surfaceConstructible() const
{
    return ((this->getSurface() * this->getPContructible()) / 100) - this->surfaceConstruite;
}

//Surcharge de l'opérateur de sortie <<
template <typename T>
ostream& operator<<(ostream& os, const Zu<T>& zu)
{
    os << static_cast<const Parcelle<T>&>(zu); // Appel de l'opérateur << de la classe Parcelle
    os << "     Surface construite: " << zu.surfaceConstruite << endl;
    os << "     Surface à contruire restante: " << zu.surfaceConstructible();
    return os;
}