#include "EquationLineaire.cpp"

int main()
{
    EquationLineaire Equation;

    Equation.solver(Equation.GetA());

    for (int i = 0; i < Equation.GetA().size(); i++)
    {
        Equation.Vecteur_x[i];
    }
    

    return 0;
}