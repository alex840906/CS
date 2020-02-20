#include "fitness.h"

float calFitness(veci_1D &solution)
{
    float fitnessValue = 0.0;
    float tmp = 0;

    for (int i = 0; i < solutionSize - 1; i++)
    {
        fitnessValue += pow((pow(eil[solution[i]][0]-eil[solution[i + 1]][0], 2)  + pow(eil[solution[i]][1]-eil[solution[i + 1]][1], 2)),0.5);
        //tmp+=fitnessValue;
        //cout<<fitnessValue<<endl;
    }

    return fitnessValue;
}