#pragma once

#include <string>
#include <vector>
#include "Parcelle.hpp"
#include "Constructible.hpp"
#include <iostream>
#include <fstream>

using namespace std;
template <typename T>
class Carte
{
private:
    std::vector<Parcelle<T>> parcelles;
    float surfaceTotale;

public:
    // Constructeur
    Carte() : surfaceTotale(0.0) {}
    void ajouterParcelle(Parcelle<T> parcelle);
    void afficherCarte() const;
    void sauvegarderCarte() const;
};

template <typename T>
// Méthode pour ajouter une parcelle à la carte
void Carte<T>::ajouterParcelle(Parcelle<T> parcelle)
{
    this->parcelles.push_back(parcelle);
    // Ajouter la surface de la parcelle à la surface totale de la carte (à adapter selon vos besoins)
    this->surfaceTotale += parcelle.getSurface();
}

template <typename T>
// Méthode pour afficher les informations de la carte
void Carte<T>::afficherCarte() const
{
    for (const Parcelle<T> parcelle : this->parcelles)
    {
        std::cout << parcelle << "\n\n";
    }
    std::cout << "Surface Totale de la Carte: " << this->surfaceTotale << " m2\n";
}

template <typename T>
// Méthode pour sauvegarder la carte
void Carte<T>::sauvegarderCarte() const
{

    string nomFichier = "Carte.txt";

    // Créer un objet ofstream pour écrire dans le fichier
    ofstream fichierSortie(nomFichier);

    // Vérifier si le fichier a pu être ouvert
    if (fichierSortie.is_open())
    {
        // Écrire du contenu dans le fichier
        for (const Parcelle<T> parcelle : this->parcelles)
        {
            fichierSortie << parcelle << "\n";
        }
        // Fermer le fichier après avoir écrit
        fichierSortie.close();

        std::cout << "La carte est extraite.\n";
    }
    else
    {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour écriture.\n";
    }
}
    // os << "Parcelle :";
    // os << " Type: " << parc.getType() << " Proprietaire: " << parc.getProprietaire() << endl;
    // os << " Numero: " << parc.getNumero() << " pConstructible: " << parc.getPContructible() << endl;
    // os << " Surface: " << parc.getSurface() << " forme: " << parc.getForme();