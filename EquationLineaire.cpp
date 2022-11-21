#include "EquationLineaire.hpp"
#include<math.h>


EquationLineaire::EquationLineaire()
{
    SizeMatrice = 3;

    MatriceA = {{1,-1,2},
                {3,2,1},
                {2,-3,-2}};

    Vecteur_b = {5,10,-10};

    Vecteur_x = {0,0,0};
}
EquationLineaire::EquationLineaire(int TailleMatrice)
{
    SizeMatrice = TailleMatrice;

    SetA(SizeMatrice);
    Set_b(SizeMatrice);

    Vecteur_x = Vecteur_b;
    for (int i = 0; i < TailleMatrice; i++)
    {
        Vecteur_x[i] = 0;
    }
    
}

EquationLineaire::~EquationLineaire()
{
}

vector <vector<double>> EquationLineaire::GetA()
{
    return MatriceA;
}
void EquationLineaire::SetA(int TailleMatrice)
{
    cout << "Saisisser les valeurs de votre matrice:" << endl;
    for (int row = 0; row < TailleMatrice; row++)
    {
        MatriceA.push_back(vector<double>());
        for (int col = 0; col < TailleMatrice; col++)
        {
            MatriceA[row].push_back(0);
            cout << "A" << row+1 << '.' << col+1 << "= ";
            cin >> MatriceA[row][col];
        }
        
    }
}
vector<double> EquationLineaire::Get_b()
{
    return Vecteur_b;
}
void EquationLineaire::Set_b(int TailleVecteur)
{
    cout << "Saisisser les valeurs de votre vecteur:" << endl;
    for (int row = 0; row < TailleVecteur; row++)
    {
        Vecteur_b.push_back(0);
        cout << "b" << row+1 << "= ";
        cin >> Vecteur_b[row];
    }
}

bool EquationLineaire::IsSquared(vector<vector<double>> Matrice)
{
    if (Matrice[0].size() == this->SizeMatrice) {return true;}
    else {return false;}
}
bool EquationLineaire::IsUpperTriangular(vector<vector<double>> Matrice)
{
    if(!IsSquared(Matrice)) {return false;}

    for (int i = 1; i < this->SizeMatrice; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Matrice[i][j] != 0) { return false; }
        }
    }
    return true;
}
bool EquationLineaire::IsLowerTriangular(vector<vector<double>> Matrice)
{
    if(!IsSquared(Matrice)) {return false;}

    for (int i = 0; i < this->SizeMatrice; i++)
    {
        for (int j = i+1; j < this->SizeMatrice; j++)
        {
            if (Matrice[i][j] != 0) { return false; }
        }
    }
    return true;
}

double EquationLineaire::determinant(vector <vector <double>> Matrice, int TailleMatrice)
{
   double det = 0;
   vector <vector<double>> SousMatrice = Matrice;
   if (TailleMatrice == 2)
   return ((Matrice[0][0] * Matrice[1][1]) - (Matrice[1][0] * Matrice[0][1])); //calcul determinant pour matrice 2x2
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

vector<vector<double>> EquationLineaire::Inverse(vector<vector<double>> Matrice)
{
    //crée une Matrice temporaire de la meme taille que MatriceA, remplie de 0
    vector<vector<double>> MatriceTemp;
    for (int row = 0; row < SizeMatrice; row++)
        {
            MatriceTemp.push_back(vector<double>());
            for (int col = 0; col < SizeMatrice; col++)
            {
                MatriceTemp[row].push_back(0);
            }
        }

        for(int i = 0; i < SizeMatrice;i++)
        {
            
            for(int j = 0; j < SizeMatrice; j++)
            {
                    //inverse la diagonale
                    MatriceTemp[i][i] = 1/MatriceA[i][i];
                    if(j != i)
                    {
                        MatriceTemp[i][j] = -MatriceA[i][j] / MatriceA[i][i]; // -A[i][j] / (diagonale de la ligne)
                    }

                    for(int k = 0; k < SizeMatrice; k++)
                    {
                        
                        if(k != i)
                        {
                                MatriceTemp[k][i] = MatriceA[k][i] / MatriceA[i][i]; // A[k][i] / (diagonale de la colonne)
                        }
                        if(j != i && k != i)
                        {
                                MatriceTemp[k][j] = MatriceA[k][j] - MatriceA[i][j] * MatriceA[k][i] / MatriceA[i][i];
                        }		
                    }
                        
            }
            return MatriceTemp;
        }
}

void EquationLineaire::solver(vector<vector <double>> Matrice)
{
    vector<vector <double>> MatriceTemp = Inverse(Matrice);
    for(int i = 0; i < SizeMatrice; i++) 
    {
        for(int j = 0; j < SizeMatrice; j++)
        {
            Vecteur_x[i] += MatriceTemp[i][j] * Vecteur_b[j];
        }           
    }

/*for(int k = 0; k < SizeMatrice - 1; k++)
{
    if (Matrice[k][k]==0) 
    {
        cout << "pivot nul!"<< endl;
        exit(-1);
    }                 

    //réduction
    for(int i = k + 1; i < SizeMatrice; i++)
    {
        int pivot = Matrice[i][k]/Matrice[k][k];
        for (int j = k; j < SizeMatrice; j++) {Matrice[i][j] = Matrice[i][j] - pivot * Matrice[k][j];}
        Vecteur[i] = Vecteur[i] - pivot * Vecteur[k];
    }
}

//Résolution
for(int i = SizeMatrice - 1; i >= 0; i--)
{
    int s=0;   
    for(int j = i+1; j < SizeMatrice; j++) {s += Matrice[i][j] * Vecteur_x[j];}             
    Vecteur_x[i] = (Vecteur[i] - s) / MatriceA[i][i];
}

cout << "solution" << endl;
printf("\n * La resolution donne :\n\n");
for (int i = 0; i < SizeMatrice; i++) 
{
    cout << "X_" << i+1 << " = " << Vecteur_x[i] << " ;" << endl;
}
    return Vecteur_x;*/
}


