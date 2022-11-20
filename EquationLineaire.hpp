#ifndef EQUATIONLINEAIRE_H
#define EQUATIONLINEAIRE_H

#include <vector>

using namespace std;

class EquationLineaire
{
private:
    int nRows;
    int nCols;
    vector <vector <int>> MatriceA;
    vector <int> b;
    vector <int> x;
    
public:
    EquationLineaire();
    ~EquationLineaire();

};
#endif