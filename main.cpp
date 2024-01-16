#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"
#include "Parcelle.hpp"

using namespace std;

int main()
{
    cout << "********************************POINT********************************" << endl;
    // Utilisation de Point2D avec des entiers
    Point2D<int> intPoint1;  // Constructeur par défaut
    Point2D<int> intPoint2(1, 2);  // Constructeur avec valeurs initiales
    Point2D<int> intPoint3(intPoint2);  // Constructeur par recopie

    // Affichage des coordonnées des points entiers
    cout << "Point1 - " << intPoint1 << endl;
    cout << "Point2 - " << intPoint2 << endl;
    cout << "Point3 (copie de Point2) - " << intPoint3 << endl;

    // Translation du point entier
    intPoint2.translate(3, 4);

    // Affichage des coordonnées après la translation
    cout << "Après translation - " << intPoint2 << endl;

    // Utilisation de Point2D avec des doubles
    Point2D<double> doublePoint1;  // Constructeur par défaut
    Point2D<double> doublePoint2(2.5, 3.5);  // Constructeur avec valeurs initiales
    Point2D<double> doublePoint3(doublePoint2);  // Constructeur par recopie

    // Affichage des coordonnées des points doubles
    cout << "Point1 - " << doublePoint1 << endl;
    cout << "Point2 - " << doublePoint2 << endl;
    cout << "Point3 (copie de Point2) - " << doublePoint3 << endl;

    // Translation du point double
    doublePoint2.translate(1.5, 2.5);

    // Affichage des coordonnées après la translation
    cout << "Après translation - " << doublePoint2 << endl;

    // Utilisation de Point2D avec des caractères
    Point2D<char> charPoint1;  // Constructeur par défaut
    Point2D<char> charPoint2('A', 'B');  // Constructeur avec valeurs initiales
    Point2D<char> charPoint3(charPoint2);  // Constructeur par recopie

    // Affichage des coordonnées des points caractères
    cout << "Point1 - " << charPoint1 << endl;
    cout << "Point2 - " << charPoint2 << endl;
    cout << "Point3 (copie de Point2) - " << charPoint3 << endl;

    // Translation du point caractère
    charPoint2.translate(1, 1);

    // Affichage des coordonnées après la translation
    cout << "Après translation - " << charPoint2 << endl;

    cout << "********************************POLY********************************" << endl;
    // Création d'un polygone avec des points entiers
    Polygone<int> polyInt;
    polyInt.addPoint(Point2D<int>(1, 2));
    polyInt.addPoint(Point2D<int>(3, 4));
    polyInt.addPoint(Point2D<int>(5, 6));

    // Affichage du polygone
    cout << "Polygone entier : " << polyInt << endl;

    // Translation du polygone
    polyInt.translate(1, 1);

    // Affichage du polygone après la translation
    cout << "Polygone entier après translation : " << polyInt << endl;

    // Utilisation du constructeur avec sommets.
    Polygone<int> constuctorSommets(polyInt.getSommets());
    cout << "Polygone avec le constructeur des sommets: "  << constuctorSommets << endl;

    // Création d'un polygone avec des points doubles
    Polygone<double> polyDouble;
    polyDouble.addPoint(Point2D<double>(2.5, 3.5));
    polyDouble.addPoint(Point2D<double>(4.5, 5.5));

    // Affichage du polygone
    cout << "Polygone double : " << polyDouble << endl;

    // Translation du polygone
    polyDouble.translate(1.5, 2.5);

    // Affichage du polygone après la translation
    cout << "Polygone double après translation : " << polyDouble << endl;

    // Test de la recopie...
    cout << "Test de la non-translation d'un polygone post recopie: " << endl;
    // Création d'un polygone avec des points entiers
    Polygone<int> originalPoly;
    originalPoly.addPoint(Point2D<int>(1, 2));
    originalPoly.addPoint(Point2D<int>(3, 4));
    originalPoly.addPoint(Point2D<int>(5, 6));

    // Affichage du polygone original
    cout << "Polygone original : " << originalPoly << endl;

    // Création par recopie d'un nouveau polygone
    Polygone<int> copiedPoly(originalPoly);

    // Affichage du polygone copié
    cout << "Polygone copié : " << copiedPoly << endl;

    // Translation du polygone original
    originalPoly.translate(1, 1);

    // Affichage des polygones après la translation
    cout << "Polygone original après translation : " << originalPoly << endl;
    cout << "Polygone copié après translation : " << copiedPoly << endl;

    cout << "*****************************PARCELLE*******************************" << endl;

    // Création parcelle par défaut
    Parcelle<int> parcelle1;
    cout << "Parcelle1 (int, contructeur par défaut) - " << parcelle1 << endl;

    // Création nouvelle parcelle
    Polygone<float> floatPoly;
    floatPoly.addPoint(Point2D<float>(7.2f, 2.2f));
    floatPoly.addPoint(Point2D<float>(1.2f, 3.2f));
    floatPoly.addPoint(Point2D<float>(0.0f, 0.0f));
    floatPoly.addPoint(Point2D<float>(6.3f, 8.1f));
    Parcelle<float> parcelle2(4, "David", floatPoly);

    cout << "Parcelle2 (float, contructeur détaillé) - " << parcelle2 << endl;

    Parcelle<float> parcelleCopie(parcelle2);
    cout << parcelleCopie << endl;
    cout << "parcelleCopie (copie de parcelle2) - " << parcelleCopie << endl;
    return 0;
}
