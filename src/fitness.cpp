#include "fitness.h"

int calFitness(veci_1D &solution)
{
    int fitnessValue = 0;

    for (int i = 0; i < solutionSize - 1; i++)
    {
        fitnessValue = pow((pow(eil[solution[i]][0], 2) - pow(eil[solution[i + 1]][0], 2)) + (pow(eil[solution[i]][1], 2) - pow(eil[solution[i + 1]][1], 2)), 0.5);
    }

    return fitnessValue;
}