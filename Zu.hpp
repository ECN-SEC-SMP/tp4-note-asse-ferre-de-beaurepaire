#pragma once

#include <iostream>
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
        Zu();
        Zu(int num, string prop, Polygone<T> form, int pConstructible);

        float getSurfaceConstruite();
        void setSurfaceConstruite(float newSurfaceConstruite);

        // Redéfinition de la méthode virtuelle pure
        virtual float surfaceConstructible() const override;
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête

template <typename T>
Zu<T>::Zu() : Parcelle<T>(),  surfaceConstruite(0)
{

}

template <typename T>
Zu<T>::Zu(int num, string prop, Polygone<T> form, int surfaceConstruite) : Parcelle<T>(num, prop, form)
{
    if (surfaceConstruite > this->getSurface())
        throw invalid_argument("La surface contruite ne peut pas être supérieure à la surface de la parcelle...");
    else
        this->surfaceConstruite = surfaceConstruite;
}

// Redéfinition de la méthode virtuelle pure
template <typename T>
float Zu<T>::surfaceConstructible() const
{
    return this->getSurface() - this->surfaceConstruite;
}