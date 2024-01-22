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

        Zau(int num, string prop, Polygone<T> form, int pConstructible);
};

template <typename T>
Zau<T>::Zau(int num, string prop, Polygone<T> form, int pConstructible) : Zu<T>(num, prop, form, 0, pConstructible)
{

}       