#include "dataset.h"
#include "fitness.h"
//#include "CS_ARG.h"


float calFitness(veci_1D &solution)
{
    //veci_2D eil;
    float fitnessValue = 0.0;
    float tmp = 0;

    for (int i = 0; i < solutionSize - 1; i++)
    {
        fitnessValue += pow((pow(eil[solution[i]][0]-eil[solution[i + 1]][0], 2)  + pow(eil[solution[i]][1]-eil[solution[i + 1]][1], 2)),0.5);
        //tmp+=fitnessValue;
        //cout<<fitnessValue<<endl;
    }
    fitnessValue += pow((pow(eil[solution[50]][0]-eil[solution[0]][0], 2)  + pow(eil[solution[50]][1]-eil[solution[0]][1], 2)),0.5);

    return fitnessValue;
}