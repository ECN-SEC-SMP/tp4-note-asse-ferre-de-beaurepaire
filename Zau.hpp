#pragma once

#include <string>
#include "Parcelle.hpp"
#include "Zu.hpp"

using namespace std;

template <typename T>
class Zau : public Zu<T>
{
    private :

        float surfaceAConstruire;

    protected :

    public :

        float getSurfaceAConstruire();

        void setSurfaceAConstruire(float newSurfaceAConstruire);
};