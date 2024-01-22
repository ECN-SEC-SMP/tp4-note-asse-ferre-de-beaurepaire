#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"
#include "Parcelle.hpp"
#include "Zu.hpp"
//#include "Zn.hpp"
//#include "Za.hpp"

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
    originalPoly.addPoint(Point2D<int>(0, 0));
    originalPoly.addPoint(Point2D<int>(5, 0));
    originalPoly.addPoint(Point2D<int>(5, 5));
    originalPoly.addPoint(Point2D<int>(0, 5));

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
    floatPoly.addPoint(Point2D<float>(0.0f, 0.0f));
    floatPoly.addPoint(Point2D<float>(13.2f, 3.2f));
    floatPoly.addPoint(Point2D<float>(26.3f, 18.1f));
    floatPoly.addPoint(Point2D<float>(1.3f, 22.8f));
    Parcelle<float> parcelle2(4, "David", floatPoly);

    cout << "Parcelle2 (float, contructeur détaillé) - " << parcelle2 << endl;

    Parcelle<float> parcelleCopie(parcelle2);
    cout << parcelleCopie << endl;
    cout << "parcelleCopie (copie de parcelle2) - " << parcelleCopie << endl;

    cout << "Test du re-calcul de la surface - " << parcelleCopie << endl;
    Polygone<float> lesPolyFloat;
    lesPolyFloat.addPoint(Point2D<float>(0.0f, 0.0f));
    lesPolyFloat.addPoint(Point2D<float>(10.0f, 0.0f));
    lesPolyFloat.addPoint(Point2D<float>(10.0f, 10.0f));
    lesPolyFloat.addPoint(Point2D<float>(0.0f, 10.0f));
    parcelle2.setForme(lesPolyFloat);
    cout << "Recalcul de la surface suite à la modification de la forme - " << parcelle2 << endl;

    cout << "Tentative de calcul d'une surface négative - " << endl;
    Polygone<int> negPoly;
    negPoly.addPoint(Point2D<int>(0, 0));
    negPoly.addPoint(Point2D<int>(0, 10));
    negPoly.addPoint(Point2D<int>(10, 10));
    negPoly.addPoint(Point2D<int>(10, 0));

    try
    {
        Parcelle<int> parcNeg(9, "Coco", negPoly);
    }
    catch(const domain_error& e)
    {
        cerr << "Impossible d'instancier la parcelle... " << e.what() << endl;
    }

    cout << "*****************************Zu*******************************" << endl;

    cout << "Test du constructeur par défaut de Zu" << endl;
    Zu<float> defaultZu;
    cout << defaultZu << endl;

    cout << "Test du constructeur détaillé de Zu" << endl;
    Polygone<int> poly2100;
    poly2100.addPoint(Point2D<int>(0, 30));
    poly2100.addPoint(Point2D<int>(60, 100));
    poly2100.addPoint(Point2D<int>(0, 100));
    Zu<int> detailedZu(98, "jean", poly2100, 479.12198f, 55);
    cout << detailedZu << endl;

    cout << "Test de l'instanciation d'une Zu avec une surface de début supérieur à la surface de la parcelle..." << endl;
    try
    {
        Zu<int> zuError(99, "Dave", originalPoly, 115.0f, 100);
    }
    catch (const invalid_argument& e)
    {
        cout << "Impossible d'instancier la parcelle..." << endl;
        cout << e.what() << endl;
    }

    return 0;
}
