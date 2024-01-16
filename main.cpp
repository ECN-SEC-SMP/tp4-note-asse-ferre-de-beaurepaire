#include <iostream>
#include "Point2D.hpp"

int main() {
    // Utilisation de Point2D avec des entiers
    Point2D<int> intPoint1;  // Constructeur par défaut
    Point2D<int> intPoint2(1, 2);  // Constructeur avec valeurs initiales
    Point2D<int> intPoint3(intPoint2);  // Constructeur par recopie

    // Affichage des coordonnées des points entiers
    std::cout << "Point1 - " << intPoint1 << std::endl;
    std::cout << "Point2 - " << intPoint2 << std::endl;
    std::cout << "Point3 (copie de Point2) - " << intPoint3 << std::endl;

    // Translation du point entier
    intPoint2.translate(3, 4);

    // Affichage des coordonnées après la translation
    std::cout << "Après translation - " << intPoint2 << std::endl;

    // Utilisation de Point2D avec des doubles
    Point2D<double> doublePoint1;  // Constructeur par défaut
    Point2D<double> doublePoint2(2.5, 3.5);  // Constructeur avec valeurs initiales
    Point2D<double> doublePoint3(doublePoint2);  // Constructeur par recopie

    // Affichage des coordonnées des points doubles
    std::cout << "Point1 - " << doublePoint1 << std::endl;
    std::cout << "Point2 - " << doublePoint2 << std::endl;
    std::cout << "Point3 (copie de Point2) - " << doublePoint3 << std::endl;

    // Translation du point double
    doublePoint2.translate(1.5, 2.5);

    // Affichage des coordonnées après la translation
    std::cout << "Après translation - " << doublePoint2 << std::endl;

    // Utilisation de Point2D avec des caractères
    Point2D<char> charPoint1;  // Constructeur par défaut
    Point2D<char> charPoint2('A', 'B');  // Constructeur avec valeurs initiales
    Point2D<char> charPoint3(charPoint2);  // Constructeur par recopie

    // Affichage des coordonnées des points caractères
    std::cout << "Point1 - " << charPoint1 << std::endl;
    std::cout << "Point2 - " << charPoint2 << std::endl;
    std::cout << "Point3 (copie de Point2) - " << charPoint3 << std::endl;

    // Translation du point caractère
    charPoint2.translate(1, 1);

    // Affichage des coordonnées après la translation
    std::cout << "Après translation - " << charPoint2 << std::endl;

    return 0;
}
