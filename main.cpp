#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"
#include "Parcelle.hpp"
#include "Zu.hpp"
#include "Zau.hpp"
#include "Zn.hpp"
#include "Za.hpp"
#include "Carte.hpp"

using namespace std;

int main()
{
    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Point2D :" << endl;
    cout         << "------------------------------" << endl;

    // Test du constructeur par défaut
    Point2D<int> point1;
    cout << "Point1 (par défaut) : " << point1 << endl;

    // Test du constructeur avec des valeurs initiales
    Point2D<int> point2(8, 4);
    cout << "Point2 (initialisé à 3, 4) : " << point2 << endl;

    // Test du constructeur par recopie
    Point2D<int> point3(point2);
    cout << "Point3 (copie de Point2) : " << point3 << endl;

    // Test des accesseurs et mutateurs
    point2.setX(10);
    point2.setY(20);
    cout << "Point2 (après modification [10, 20]) : " << point2 << endl;

    // Test de la méthode de translation
    point2.translate(1, 2); // Translation positive
    cout << "Point2 (après translation positive [10 + 1, 20 + 2]) : " << point2 << endl;

    // Test avec des float
    Point2D<float> point4(1.5f, 2.5f);
    cout << "Point4 (float, initialisé à 1.5f, 2.5f): " << point4 << endl;

    // Jeu d'essais pour la classe Polygone
    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Polygone :" << endl;
    cout         << "------------------------------" << endl;
    // Test du constructeur par défaut
    Polygone<int> polygone1;
    cout << "Polygone1 (par défaut) : " << polygone1 << endl;

    // Test du constructeur avec des valeurs initiales (liste de points)
    vector<Point2D<int>> listePoints = {point1, point2, point3};
    Polygone<int> polygone2(listePoints);
    cout << "Polygone2 (initialisé avec une liste de points) : " << polygone2 << endl;

    // Test du constructeur par recopie
    Polygone<int> polygone3(polygone2);
    cout << "Polygone3 (copie de Polygone2) : " << polygone3 << endl;

    // Test des accesseurs et mutateurs
    vector<Point2D<int>> listePoints2 = {point1, point2};
    polygone1.setSommets(listePoints2);
    cout << "Polygone1 initialement vide apres ajout de sommets : " << polygone1 << endl;

    // Test de la méthode addPoint
    Point2D<int> p4(4, 4);
    polygone1.addPoint(p4);
    cout << "Polygone1 après ajout d'un nouveau point [4, 4]: " << polygone1 << endl;

    // Test de la méthode translate
    polygone2.translate(1, 1);
    cout << "Polygone2 après translation de [1, 1]: " << polygone2 << endl;

    // Vérification de l'absence de translation sur le Polygone3 (copie de Polygone2)
    cout << "Polygone3 (copie de Polygone2) après translation de Polygone2 : " << polygone3 << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Parcelle :" << endl;
    cout         << "------------------------------" << endl;

    //Création d'un polygone avec une surface négative.
    Polygone<int> polygone4_negatif;
    polygone4_negatif.addPoint(Point2D<int>(0, 0));
    polygone4_negatif.addPoint(Point2D<int>(0, 10));
    polygone4_negatif.addPoint(Point2D<int>(10, 10));
    polygone4_negatif.addPoint(Point2D<int>(10, 0));

    Polygone<int> polygone5_2100;
    polygone5_2100.addPoint(Point2D<int>(0, 30));
    polygone5_2100.addPoint(Point2D<int>(60, 100));
    polygone5_2100.addPoint(Point2D<int>(0, 100));

    cout << "Création de polygone4 (surface négative) pour test de l'exception" << endl;
    cout << polygone4_negatif << endl;
    cout << "Création de polygone5 (surface de 2100) pour test du calcul de la surface" << endl;
    cout << polygone5_2100 << endl;

    // Test du constructeur par défaut
    Parcelle<int> parcelle1;
    cout << "Parcelle1 (par défaut) : " << endl << parcelle1 << endl;

    // Test du constructeur détaillé
    Parcelle<int> parcelle2(2, "Alice", polygone5_2100);
    cout << "Parcelle2 (détaillé, surface attendue 2100): " << endl << parcelle2 << endl;

    // Test du constructeur par recopie
    Parcelle<int> parcelle3(parcelle2);
    cout << "Parcelle3 (copie de Parcelle2) : " <<  endl << parcelle3 << endl;


    cout << "Tentative d'instanciation d'une parcelle avec une surface négative - " << endl;
    try
    {
        Parcelle<int> parcelle4(9, "Coco", polygone4_negatif);
    }
    catch(const domain_error& e)
    {
        cerr << "[OK] Impossible d'instancier la parcelle... " << e.what() << endl;
    }

    parcelle1.setForme(polygone5_2100);
    cout << "Parcelle1 re-calcul de la surface après modification des sommets : " << parcelle1 << endl;

     // Test des setters
    parcelle1.setNumero(42);
    parcelle1.setProprietaire("Zizou");
    parcelle1.setType("Je suis de type...");
    parcelle1.setPContructible(90);
    cout << "Parcelle1 suite à l'utilisation des méthodes de type \"set\": " << parcelle1 << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Zu :" << endl;
    cout         << "------------------------------" << endl;

    // Test du constructeur par défaut
    Zu<int> zu1;
    cout << "Zu1 (par défaut) : " << endl;
    cout << zu1 << endl;

    // Test du constructeur avec des valeurs initiales (sans exception)
    Zu<int> zu2(2, "Romain", polygone5_2100, 479.12198f, 55);

    try
    {
        cout << "Zu3 avec une surface construite supérieur à la surface de la parcelle (2101 avec un max à 2100): " << endl;
        Zu<int> zu3(2, "Coco", polygone5_2100, 2101.0f, 100);
        cout << "[KO] Exception non levée..." << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "[OK] Exception attrapée : " << e.what() << endl;
    }

    try
    {
        cout << "Zu4 avec une surface constructible supérieur à 100 (101)" << endl;
        Zu<int> zu4(2, "Jbabe", polygone5_2100, 214.0f, 101);
        cout << "[KO] Exception non levée..." << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "[OK] Exception attrapée : " << e.what() << endl;
    }

    // Test du constructeur par recopie
    Zu<int> zu5(zu2);
    cout << "Zu4 (copie de Zu2) : " << endl;
    cout << zu5 << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Zau :" << endl;
    cout         << "------------------------------" << endl;

     // Test du constructeur par défaut
    Zau<int> zau1;
    cout << "Zau1 (par défaut) : " << endl;
    cout << zau1 << endl;

    // Test du constructeur avec des valeurs initiales
    Zau<int> zau2(2, "Rémi", polygone5_2100, 80);
    cout << "Zau2 (avec des valeurs initiales) : " << endl;
    cout << zau2 << endl;

    // Test du constructeur par recopie
    Zau<int> zau3(zau2);
    cout << "Zau3 (copie de Zau2) : " << endl;
    cout << zau3 << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Zn :" << endl;
    cout         << "------------------------------" << endl;

    // Test du constructeur par défaut
    Zn<int> zn1;
    cout << "Zn1 (par défaut) : " << endl;
    cout << zn1 << endl;

    // Test du constructeur détaillé
    Zn<int> zn2(2, "Je sais plus", polygone5_2100);
    cout << "Zn2 (avec des valeurs initiales) : " << endl;
    cout << zn2 << endl;

    // Test du constructeur par recopie
    Zn<int> zn3(zn2);
    cout << "Zn3 (copie de Zn2) : " << endl;
    cout << zn3 << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Za :" << endl;
    cout         << "------------------------------" << endl;

    // Test du constructeur par défaut
    Za<int> za1;
    cout << "Za1 (par défaut) : " << endl;
    cout << za1 << endl;

    // Test du constructeur détaillé
    Za<int> za2(2, "Fiuuuuuuuuuuuuuu", polygone5_2100, "Blé");
    cout << "Za2 (avec des valeurs initiales) : " << endl;
    cout << za2 << endl;

    // Test du constructeur par recopie
    Za<int> za3(za2);
    cout << "Za3 (copie de Za2) : " << endl;
    cout << za3 << endl;

    // Test des getters et setters
    za1.setTypeCulture("Maïs");
    cout << "Type de culture de za1 après modification (utilisation de méthode \"set\"): " << za1.getTypeCulture() << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Tests pour la classe Carte :" << endl;
    cout         << "------------------------------" << endl;

    // Création de la carte
    Carte<int> carte;

    // Ajout des parcelles à la carte
    carte.ajouterParcelle(zn1);
    carte.ajouterParcelle(za2);
    carte.ajouterParcelle(zn2);
    carte.ajouterParcelle(zu2);
    carte.ajouterParcelle(zn3);
    carte.ajouterParcelle(za1);
    carte.ajouterParcelle(za3);
    carte.ajouterParcelle(zu5);
    carte.ajouterParcelle(zau3);
    carte.ajouterParcelle(zau2);
    carte.ajouterParcelle(zu1);
    carte.ajouterParcelle(zau1);

    // Affichage de la carte
    cout << "Contenu de la carte : " << endl;
    carte.afficherCarte();

    // Sauvegarde de la carte
    carte.sauvegarderCarte();

    return 0;
}
