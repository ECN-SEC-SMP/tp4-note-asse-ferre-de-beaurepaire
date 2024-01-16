#pragma once

#include "Polygone.hpp"
#include <string>

using namespace std;

template <typename T>
class Parcelle
{
    private :

        string type;
        string proprietaire

        int numero;
        int pConstructible;

        float surface;

        Polygone<int, float> forme;

    protected :

    public :

        // Constructeur par défaut
        Parcelle();

        // Constructeur détaillé
        Parcelle(int num, string prop, Polygone<int, float> forme);

        // Constructeur par recopie
        Parcelle(const Parcelle& parc);


        // Accesseurs get
        int getNumero() const;
        int getProprietaire() const;

        float getSurface() const;

        Polygone<int, float> getForme() const;

        string getName() const;


        // Accesseurs set
        void setNumero(int n);
        void setProprietaire(string prop);
        void setForme(Polygone<int, float> forme);
        void setType(string type);
};