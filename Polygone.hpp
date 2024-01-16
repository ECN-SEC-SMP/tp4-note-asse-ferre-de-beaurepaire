#pragma once

#include <vector>
#include <ostream>
#include "Point2D.hpp"

using namespace std;

template <typename T>
class Polygone
{
    private:
        vector<Point2D<T>> sommets;

    public:
        // Constructeur par défaut
        Polygone();

        // Constructeur avec des valeurs initiales
        Polygone(vector<Point2D<T>> listeSommets);

        // Constructeur par recopie
        Polygone(const Polygone<T>& poly);

        // Accesseurs get
        vector<Point2D<T>> getSommets() const;

        // Accesseurs set
        void setSommets(const vector<Point2D<T>>& listeSommets);

        // Permet d'ajouter un point
        void addPoint(const Point2D<T>& point);

        void translate(T x, T y);
};

// Constructeur par défaut
template <typename T>
Polygone<T>::Polygone()
{

}

// Constructeur avec des valeurs initiales
template <typename T>
Polygone<T>::Polygone(vector<Point2D<T>> listeSommets) : sommets(listeSommets)
{

}

// Constructeur par recopie
template <typename T>
Polygone<T>::Polygone(const Polygone<T>& poly) : sommets(poly.sommets)
{

}

// Accesseurs get
template <typename T>
vector<Point2D<T>> Polygone<T>::getSommets() const
{
    return sommets;
}

// Accesseurs set
template <typename T>
void Polygone<T>::setSommets(const vector<Point2D<T>>& listeSommets)
{
    sommets = listeSommets;
}

// Ajouter un point au polygone
template <typename T>
void Polygone<T>::addPoint(const Point2D<T>& point)
{
    sommets.push_back(point);
}

// Translation du polygone
template <typename T>
void Polygone<T>::translate(T x, T y)
{
    for (auto& point : sommets)
    {
        point.translate(x, y);
    }
}

// Surcharge de l'opérateur de sortie <<
template <typename T>
std::ostream& operator<<(std::ostream& os, const Polygone<T>& poly)
{
    os << "Polygone [";
    const auto& sommets = poly.getSommets();
    for (size_t i = 0; i < sommets.size(); ++i) {
        os << sommets[i];
        if (i < sommets.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}