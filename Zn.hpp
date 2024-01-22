#pragma once

#include <string>
#include "Parcelle.hpp"

using namespace std;

template <typename T>
class Zn : Parcelle
{
    private :

        string typeCulture;

    protected :

    public :

        string getTypeCulture();

        void setTypeCulture(string newTypeCulture);
};