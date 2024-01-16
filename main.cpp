#include <iostream>
#include "Point2D.hpp"

int main() {
    // Utilisation de Point2D avec des entiers
    Point2D<int> point1(1, 2);
    std::cout << "X: " << point1.getX() << ", Y: " << point1.getY() << std::endl;

    // Modification des coordonnées
    point1.setX(10);
    point1.setY(20);
    std::cout << "X: " << point1.getX() << ", Y: " << point1.getY() << std::endl;

    // Utilisation de Point2D avec des doubles
    Point2D<double> point2(3.5, 4.2);
    std::cout << "X: " << point2.getX() << ", Y: " << point2.getY() << std::endl;

    return 0;
}
