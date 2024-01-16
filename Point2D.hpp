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

    // Accesseurs get pour X et Y
    T getX() const;
    T getY() const;

    // Accesseurs set pour X et Y
    void setX(T newX);
    void setY(T newY);

private:
    T x;
    T y;
};

// Inclusion de l'implémentation directement dans le fichier d'en-tête
template <typename T>
Point2D<T>::Point2D() : x(T()), y(T()) {}

template <typename T>
Point2D<T>::Point2D(T initialX, T initialY) : x(initialX), y(initialY) {}

template <typename T>
T Point2D<T>::getX() const {
    return x;
}

template <typename T>
T Point2D<T>::getY() const {
    return y;
}

template <typename T>
void Point2D<T>::setX(T newX) {
    x = newX;
}

template <typename T>
void Point2D<T>::setY(T newY) {
    y = newY;
}

#endif // POINT2D_HPP
