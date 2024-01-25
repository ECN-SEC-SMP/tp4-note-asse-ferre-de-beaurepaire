#pragma once

#include <string>
#include <vector>
#include "Parcelle.hpp"
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class Carte
{
private:
    vector<Parcelle<T>> parcelles;
    float surfaceTotale;

public:
    // Constructeur
    Carte() : surfaceTotale(0.0) {}
    void ajouterParcelle(Parcelle<T> parcelle);
    void afficherCarte() const;
    void sauvegarderCarte() const;
};

// Méthode pour ajouter une parcelle à la carte
template <typename T>
void Carte<T>::ajouterParcelle(Parcelle<T> parcelle)
{
    this->parcelles.push_back(parcelle);
    // Ajouter la surface de la parcelle à la surface totale de la carte
    this->surfaceTotale += parcelle.getSurface();
}

// Méthode pour afficher les informations de la carte
template <typename T>
void Carte<T>::afficherCarte() const
{
    for (const Parcelle<T> &parcelle : this->parcelles)
    {
        cout << parcelle << "\n";
    }
    cout << "Surface Totale de la Carte: " << this->surfaceTotale << " m2\n";
}

// Méthode pour sauvegarder la carte
template <typename T>
void Carte<T>::sauvegarderCarte() const
{
    string nomFichier = "Carte.txt";

    // Créer un objet ofstream pour écrire dans le fichier
    ofstream fichierSortie(nomFichier);

    // Vérifier si le fichier a pu être ouvert
    if (fichierSortie.is_open())
    {
        // Écrire du contenu dans le fichier
        for (const Parcelle<T> &parcelle : this->parcelles)
        {
            fichierSortie << parcelle.getType() << " " << parcelle.getNumero() << " " << parcelle.getProprietaire() << endl;
            fichierSortie << parcelle.getForme() << endl;
        }
        // Fermer le fichier après avoir écrit
        fichierSortie.close();

        cout << "La carte est extraite.\n";
    }
    else
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier pour écriture.\n";
    }
}