#pragma once

#include "WarehouseSolution.hpp"
#include <set>
#include <unordered_map>

using namespace std;

class Heuristic_2 {
    public :
        unordered_map<int, vector<int>> product_to_orders; // dictionnaire qui associe un produit à un vecteur de commande auxquel il est associé
        // vector<vector<int>> product_in_circuit; // Pour chaque circuit l'ensemble des produits qui y sont associés
        vector<vector<int>> path; // Pour chaque commande l'ensemble des racks parcouru pour la réaliser (dans l'ordre de passage)
        WarehouseSolution solution; // data and initial solution
        int solution_cost;
        
        Heuristic_2(); // default constructor
        Heuristic_2(const WarehouseSolution& initial_solution); // initialization constructor of class memebers

        void build_product_to_orders();
        void calcul_cost_and_path();  // calculate initial solution_cost and path 
        void improve(); // heuristique d'amélioration intra-circuit : recherche locale par déplacements de produits au sein de l'intervalle de racks de leur circuit
};

vector<vector<int>> build_product_in_circuit(const WarehouseInstance& data);
vector<int> read_frequency_circuits(string filename, int num_circuits);
vector<int> initial_solution(const WarehouseInstance& data, const vector<int>& frequency_circuits);