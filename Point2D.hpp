#ifndef POINT2D_HPP
#define POINT2D_HPP

template <typename T>
class Point2D
{
public:
    // Constructeur par défaut
    Point2D();

    // Constructeur avec des valeurs initiales
    Point2D(T initialX, T initialY);

    // Constructeur par recopie
    Point2D(const Point2D& other);

    // Accesseurs get pour X et Y
    T getX() const;
    T getY() const;

    // Accesseurs set pour X et Y
    void setX(T newX);
    void setY(T newY);

    // Méthode pour déplacer les coordonnées du point
    void translate(T deltaX, T deltaY);

private:
    T x;
    T y;
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête
template <typename T>
Point2D<T>::Point2D() : x(T()), y(T())
{

}

template <typename T>
Point2D<T>::Point2D(T initialX, T initialY) : x(initialX), y(initialY)
{

}

// Implémentation du constructeur par recopie
template <typename T>
Point2D<T>::Point2D(const Point2D& other) : x(other.x), y(other.y)
{

}

template <typename T>
T Point2D<T>::getX() const
{
    return x;
}

template <typename T>
T Point2D<T>::getY() const
{
    return y;
}

template <typename T>
void Point2D<T>::setX(T newX)
{
    x = newX;
}

template <typename T>
void Point2D<T>::setY(T newY)
{
    y = newY;
}

template <typename T>
void Point2D<T>::translate(T deltaX, T deltaY)
{
    x += deltaX;
    y += deltaY;
}

// Surcharge de l'opérateur de sortie pour print
template <typename T>
std::ostream& operator<<(std::ostream& os, const Point2D<T>& point)
{
    os << "X: " << point.getX() << ", Y: " << point.getY();
    return os;
}

#endif // POINT2D_HPP
