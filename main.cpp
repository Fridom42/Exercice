#include "EquationLineaire.hpp"

int main()
{
    int taille;

    cout << endl << "Saississer la taille de votre matrice CARRE: ";
    cin >> taille;

    EquationLineaire Equation(taille);

    Equation.solver(Equation.Triangulise(Equation.GetA()));

    cout << endl << "Les solutions sont:" << endl;
    for (int i = 0; i < taille; i++)
    {
        cout << "x" << i << "= " << Equation.Vecteur_x[i] << endl;
    }

    return 0;
}