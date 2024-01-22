#pragma once

#include <string>
#include "Parcelle.hpp"
#include "Constructible.hpp"

using namespace std;

template <typename T>
class Zu : Parcelle, Constructible
{
    private :

        float surfaceConstruite;

    protected :

    public :

        float getSurfaceConstruite();

        void setSurfaceConstruite(float newSurfaceConstruite);
};