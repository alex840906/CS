#include "CS_ARG.h"
#include "cs.h"
#include "dataset.h"

int main()
{
    srand(time(NULL));
    int iteration = 0;
    int run = 0;

    float bestFitness = 10000;
    float avgBestFitness = 0;
    readfile();

    for (run = 0; run < runNum; run++)
    {
        bestFitness = 10000;

        for (int i = 0; i < cuckooNum; i++)
        {
            cuckooList[i].initialize();
            cuckooList[i].fitness = calFitness(cuckooList[i].solution);
        }

        for (iteration = 0; iteration < iterationNum; iteration++)
        {
            for (int i = 0; i < cuckooNum; i++)
            {
                if (bestFitness >= cuckooList[i].fitness)
                    bestFitness = cuckooList[i].fitness;
            }
            generateNewSolution();
        }
        avgBestFitness += bestFitness;
        cout<<"run: "<<run<<" bestFitness: "<<bestFitness<<endl;
    }
    avgBestFitness /= runNum;
    cout << "avgFitness: " << avgBestFitness << endl;

    // 輸出結果
    // for (int i = 0; i < cuckooNum; i++)
    // {
    //     cout << " No: " << i << " "
    //          << "fitness: " << cuckooList[i].fitness << endl;
    // }

    //cout << iteration << " " << bestFitness << endl;

    system("pause");
    return 0;
}
