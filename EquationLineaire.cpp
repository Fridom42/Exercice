#include "EquationLineaire.hpp"


EquationLineaire::EquationLineaire()
{
    nRows = 4;
    nCols = 4;

    SetA(nRows,nCols);
    Set_b(nRows);
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
    for (int col = 0; col < nCols; col++)
    {
        for (int row = 0; row < nRows; row++)
        {
            cout << "A" << row << '.' << col << "= ";
            cin >> MatriceA[row][col];
        }
        
    }
}
vector<int> EquationLineaire::Get_b()
{
    return Vecteur_b;
}
void EquationLineaire::Set_b()
{
    cout << "Saisisser les valeurs de votre vecteur:" << endl;
    for (int row = 0; row < nRows; row++)
    {
        cout << "b" << row << "= ";
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

int EquationLineaire::determinant(vector <vector <int>> Matrice)
{

}

vector<vector<int>> EquationLineaire::Triangularise(vector<vector<int>> Matrice)
{

}

vector <int> EquationLineaire::solver(vector<vector <int>> Matrice, vector <int> Vecteur)
{

}


