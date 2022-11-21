#ifndef EQUATIONLINEAIRE_H
#define EQUATIONLINEAIRE_H

#include <vector>
#include <iostream>

using namespace std;

class EquationLineaire
{
    private:
        int SizeMatrice;
        vector <vector <double>> MatriceA;
        vector <double> Vecteur_b;
        
    public:
        vector <double> Vecteur_x;

        EquationLineaire();
        EquationLineaire(int TailleMatrice);
        ~EquationLineaire();

        void solver(vector<vector <double>> Matrice);
    
        double determinant(vector <vector <double>> Matrice, int TailleMatrice);
        
        vector <vector<double>> GetA();
        void SetA(int TailleMatrice);
        vector<double> Get_b();
        void Set_b(int TailleVecteur);
    
        bool IsSquared(vector<vector<double>> Matrice);
        bool IsUpperTriangular(vector<vector<double>> Matrice);
        bool IsLowerTriangular(vector<vector<double>> Matrice);

        vector<vector<double>> Inverse(vector<vector<double>> Matrice);
};
#endif