#include "EquationLineaire.cpp"

int main()
{
    EquationLineaire Equation;

    int x;
    if(Equation.IsSquared(Equation.GetA())){
      x = Equation.determinant(Equation.GetA(),Equation.GetA().size());
    }

    cout << x << endl;

    return 0;
}