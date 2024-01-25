#pragma once

#include <string>
#include "Parcelle.hpp"
#include "Zu.hpp"

using namespace std;

template <typename T>
class Zau : public Zu<T>
{
    private :

    protected :

    public :

        // Constructeur par défaut
        Zau();

        // Constructeur avec des valeurs initiales
        Zau(int num, string prop, Polygone<T> form, int pConstructible);

        // Constructeur par recopie
        Zau(const Zau<T>& other);
};

// Constructeur par défaut
template <typename T>
Zau<T>::Zau() : Zu<T>() {
    this->setType("Zau");
}

// Constructeur avec des valeurs initiales
template <typename T>
Zau<T>::Zau(int num, string prop, Polygone<T> form, int pConstructible) : Zu<T>(num, prop, form, 0, pConstructible)
{
    this->setType("Zau");
}

// Constructeur par recopie
template <typename T>
Zau<T>::Zau(const Zau<T>& other) : Zu<T>(other) {}