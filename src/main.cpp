#include "CS_ARG.h"
#include "cs.h"
#include "dataset.h"
// #include <ctime>
// #include <cstdlib>

int main()
{
    srand(time(NULL));
    int iteration = 0;
    int run = 0;
    readfile();

    for (int i = 1; i < cuckooNum; i++)
        rearrange(cuckooList[i].solution);

    for (int i = 0; i < cuckooNum; i++)
    {
        cuckooList[i].fitness = calFitness(cuckooList[i].solution);
    }

    for (iteration = 0; iteration < iterationNum; iteration++)
    {
        for (int i = 0; i < cuckooNum; i++)
        {
            cout<<iteration<<" No: "<<i<<" "<<"fitness: "<<cuckooList[i].fitness<<endl;
        }
        
        // for (int i = 1; i < solutionSize; i++)
        //     cout << cuckooList[0].solution[i] << " ";
        // cout << endl;

        generateNewSolution();
        // for (int i = 1; i < solutionSize; i++)
        //     cout << cuckooList[0].solution[i]<<" ";
    }

    system("pause");
    return 0;
}
