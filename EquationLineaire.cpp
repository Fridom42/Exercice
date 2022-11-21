#include "EquationLineaire.hpp"
#include<math.h>


EquationLineaire::EquationLineaire()
{
    nRows = 4;
    nCols = 4;

    MatriceA = {{3,4,2,6},
                {7,8,9,5},
                {9,2,3,4},
                {5,6,7,8}};

    Vecteur_b = {4,6,1,9};
}
EquationLineaire::EquationLineaire(int Rows, int Cols)
{
    nRows = Rows;
    nCols = Cols;

    SetA(nRows,nCols);
    Set_b(nRows);
}

EquationLineaire::~EquationLineaire()
{
}

vector <vector<int>> EquationLineaire::GetA()
{
    return MatriceA;
}
void EquationLineaire::SetA(int Rows, int Cols)
{
    cout << "Saisisser les valeurs de votre matrice:" << endl;
    for (int row = 0; row < nRows; row++)
    {
        MatriceA.push_back(vector<int>());
        for (int col = 0; col < nCols; col++)
        {
            MatriceA[row].push_back(0);
            cout << "A" << row+1 << '.' << col+1 << "= ";
            cin >> MatriceA[row][col];
        }
        
    }
}
vector<int> EquationLineaire::Get_b()
{
    return Vecteur_b;
}
void EquationLineaire::Set_b(int Rows)
{
    cout << "Saisisser les valeurs de votre vecteur:" << endl;
    for (int row = 0; row < nRows; row++)
    {
        Vecteur_b.push_back(0);
        cout << "b" << row+1 << "= ";
        cin >> Vecteur_b[row];
    }
}

bool EquationLineaire::IsSquared(vector<vector<int>> Matrice)
{
    if (Matrice[0].size() == Matrice.size()) {return true;}
    else {return false;}
}
bool EquationLineaire::IsUpperTriangular(vector<vector<int>> Matrice)
{
    if(!IsSquared(Matrice)) {return false;}

    for (int i = 1; i < Matrice.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Matrice[i][j] != 0) { return false; }
        }
    }
    return true;
}
bool EquationLineaire::IsLowerTriangular(vector<vector<int>> Matrice)
{
    if(!IsSquared(Matrice)) {return false;}

    for (int i = 0; i < Matrice.size(); i++)
    {
        for (int j = i+1; j < Matrice.size(); j++)
        {
            if (Matrice[i][j] != 0) { return false; }
        }
    }
    return true;
}

int EquationLineaire::determinant(vector <vector <int>> Matrice, int TailleMatrice)
{
   int det = 0;
   vector <vector<int>> SousMatrice = Matrice;
   if (TailleMatrice == 2)
   return ((Matrice[0][0] * Matrice[1][1]) - (Matrice[1][0] * Matrice[0][1]));
   else {
      for (int x = 0; x < TailleMatrice; x++) {
         int subi = 0;
         for (int i = 1; i < TailleMatrice; i++) {
            int subj = 0;
            for (int j = 0; j < TailleMatrice; j++) {
               if (j == x)
               continue;
               SousMatrice[subi][subj] = Matrice[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * Matrice[0][x] * determinant( SousMatrice, TailleMatrice - 1 ));
      }
   }
   return det;
}

/*vector<vector<int>> EquationLineaire::Triangularise(vector<vector<int>> Matrice)
{

}

vector <int> EquationLineaire::solver(vector<vector <int>> Matrice, vector <int> Vecteur)
{

}*/


