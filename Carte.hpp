#pragma once

#include <string>
#include <vector>
#include "Parcelle.hpp"
#include "Constructible.hpp"

using namespace std;

class Carte {
    private :
    std::vector<Parcelle*> parcelles;
    double surfaceTotale;
public:
    // Attributs de la carte
    

    // Constructeur
    Carte() : surfaceTotale(0.0) {}

    // Méthode pour ajouter une parcelle à la carte
    void ajouterParcelle(Parcelle* parcelle) {
        parcelles.push_back(parcelle);
        // Ajouter la surface de la parcelle à la surface totale de la carte (à adapter selon vos besoins)
        // surfaceTotale += ...;
    }

    // Méthode pour afficher les informations de la carte
    void afficherCarte() const {
        for (const Parcelle* parcelle : parcelles) {
            std::cout << *parcelle << "\n\n";
        }
        std::cout << "Surface Totale de la Carte: " << surfaceTotale << " m2\n";
    }
};