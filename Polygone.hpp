#pragma once

#include <vector>
#include "Point2D.hpp"

template <typename T>
class Polygone
{
    private:
        Vector<Point2D<T>> sommets;

    public:
        // Constructeur par défaut
        Polygone();

        // Constructeur avec des valeurs initiales
        Polygone(vector<Point2D<T>> listeSommets);

        // Constructeur par recopie
        Polygone(Polygone<T> poly);

        // Accesseurs get
        vector<Point2D<T>> getSommets() const;

        // Accesseurs set
        void setSommets(vector<Point2D<T>> listeSommets);

        void addPoint(Point2D<T>);

        void translate(T x, T y);
};
