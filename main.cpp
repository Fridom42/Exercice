#include "EquationLineaire.cpp"

int main()
{
    EquationLineaire Equation;

    for (int i = 0; i < Equation.GetA().size(); i++)
    {
        for (int j = 0; j < Equation.GetA()[0].size(); j++)
        {
            cout << (Equation.GetA())[i][j] << " - ";
        }
        cout << endl;
    }

    return 0;
}