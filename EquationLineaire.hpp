#ifndef EQUATIONLINEAIRE_H
#define EQUATIONLINEAIRE_H

#include <vector>
#include <iostream>

using namespace std;

class EquationLineaire
{
    private:
        int nRows;
        int nCols;
        vector <vector <int>> MatriceA;
        vector <int> Vecteur_b;
        vector <int> Vecteur_x;
        
    public:
        EquationLineaire();
        EquationLineaire(int Rows, int Cols);
        ~EquationLineaire();

        vector <int> solver(vector<vector <int>> Matrice, vector <int> Vecteur);
    
        int determinant(vector <vector <int>> Matrice, int TailleMatrice);
        
        vector <vector<int>> GetA();
        void SetA(int Rows, int Cols);
        vector<int> Get_b();
        void Set_b(int Rows);
    
        bool IsSquared(vector<vector<int>> Matrice);
        bool IsUpperTriangular(vector<vector<int>> Matrice);
        bool IsLowerTriangular(vector<vector<int>> Matrice);

        vector<vector<int>> Triangularise(vector<vector<int>> Matrice);
};
#endif