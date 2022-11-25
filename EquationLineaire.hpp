#ifndef EQUATIONLINEAIRE_H
#define EQUATIONLINEAIRE_H

#include <vector>
#include <iostream>
#include<math.h>

using namespace std;

class EquationLineaire
{
    private:
        // taille de la matrice
        int SizeMatrice;
        //  Matrice contenant les valeurs entrer par l'utilisateur ou par le constructeur par defaut
        vector <vector <double>> MatriceA;
        // Vecteur contenant les valeurs entrer par l'utilisateur ou par le constructeur par defaut
        vector <double> Vecteur_b;
        
    public:
        // vecteur contenant les solutions
        vector <double> Vecteur_x;

        // constructeur par defaut
        EquationLineaire();
        // constructeur personalisable
        EquationLineaire(int TailleMatrice);
        ~EquationLineaire();

        // trouve les solutions a l'equation et les mets dans vecteurX, prend en entrée une matrice triangulaire
        void solver(vector<vector <double>> Matrice);
    
        //double determinant(vector <vector <double>> Matrice, int TailleMatrice);
        
        //void Affiche(vector<vector<double>> Matrice);


        vector <vector<double>> GetA();
        void SetA(int TailleMatrice);
        vector<double> Get_b();
        void Set_b(int TailleVecteur);
    
        // verifie que la matrice entrer en parametre est bien une matrice triangulaire superieur et retourne vrai sinon retourne faux
        bool IsUpperTriangular(vector<vector<double>> Matrice);
        // verifie que la matrice entrer en parametre est bien une matrice triangulaire inferieur et retourne vrai sinon retourne faux
        bool IsLowerTriangular(vector<vector<double>> Matrice);
        // retourne la matrice d'entrée apres avoir été triangularisé en matrice triangulaire superieur
        vector<vector<double>> Triangulise(vector<vector<double>> Matrice);
        //vector<vector<double>> Inverse(vector<vector<double>> Matrice);
};
#endif