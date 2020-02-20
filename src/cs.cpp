#include "cs.h"
#include <ctime>
#include <cstdlib>

Cuckoo::Cuckoo()
{
    
    //cout<<"yes"<<endl;
    //solution.resize(solutionSize);

    int r_1, r_2, tmp;

    for (int i = 0; i < solutionSize; i++)
        solution.push_back(i);

    for (int i = 0; i < solutionSize; i++)
    {
        r_1 = rand() % solutionSize;
        r_2 = rand() % solutionSize;

        tmp = solution[r_1];
        solution[r_1] = solution[r_2];
        solution[r_2] = tmp;

        //cout << r_1 << r_2<< " " ;
    }
    //cout << endl;
}

void rearrange(veci_1D &solution)
{
    
    //srand(time(NULL));
    int r_1, r_2, tmp;

    for (int i = 0; i < solutionSize; i++)
    {
        r_1 = rand() % solutionSize;
        r_2 = rand() % solutionSize;

        tmp = solution[r_1];
        solution[r_1] = solution[r_2];
        solution[r_2] = tmp;

        //cout << r_1 << " " << r_2;
    }
    //cout << endl;
}

int calculateStepSize(Cuckoo cuckoo, Cuckoo bestCuckoo)
{
    int _alpha = 0;

    for (int i = 0; i < solutionSize - 1;)
    {
        if (cuckoo.solution[i] == bestCuckoo.solution[i] && cuckoo.solution[i + 1] == bestCuckoo.solution[i + 1])
        {
            i++;
        }
        else
        {
            _alpha++;
            i += 2;
        }
    }

    return _alpha;
}

veci_2D updatingScheme(Cuckoo cuckoo)
{

    srand(time(NULL));
    veci_2D newSolution;
    veci_1D tmpSolution;

    for (int count = 0; count < evolutionTime; count++) //生成新的m個解
    {
        int r_1 = rand() % solutionSize;
        int r_2 = rand() % solutionSize;
        if (r_1 > r_2) //若r_1 > r_2, 則交換
        {
            int tmp = r_1;
            r_1 = r_2;
            r_2 = tmp;
        }

        tmpSolution.assign(cuckoo.solution.begin(), cuckoo.solution.end());

        for (int i = r_1, j = r_2; i < (r_1 + r_2 + 1) / 2; i++, j--) //invertion
        {
            swap(tmpSolution[i], tmpSolution[j]);
            //cout<<"swap sucess";
        }

        newSolution.push_back(tmpSolution);
    }

    return newSolution;
}

void selectnBestCuckoo(veci_2D newSolution, veci_2D newBestSolution, veci_2D newWorstSolution, vecf_1D newSolutionFitness, vecf_1D newBestSolutionFitness, vecf_1D newWorstSolutionFitness)
{
    vecf_1D selectSolutionFitness;
    veci_2D selectSolution;
    int indexPosition;

    //selectSolutionFitness.assign(newSolutionFitness.begin(),newSolutionFitness.end());
    //selectSolution.assign(newSolution.begin(),newSolution.end());

    for (int i = 0; i < cuckooNum; i++)
    {
        selectSolutionFitness.push_back(cuckooList[i].fitness);
        selectSolution.push_back(cuckooList[i].solution);
    }

    for (int i = 0; i < evolutionTime; i++) // 與 newSolution 比較, 替換較差解
    {
        indexPosition = max_element(selectSolutionFitness.begin(), selectSolutionFitness.end()) - (selectSolutionFitness.begin());

        if (selectSolutionFitness[indexPosition] > newSolutionFitness[i])
        {
            selectSolutionFitness[indexPosition] = newSolutionFitness[i];
            selectSolution[indexPosition].swap(newSolution[i]);
        }
    }

    for (int i = 0; i < evolutionTime; i++) // 與 newBestSolution 比較, 替換較差解
    {
        indexPosition = max_element(selectSolutionFitness.begin(), selectSolutionFitness.end()) - (selectSolutionFitness.begin());

        if (selectSolutionFitness[indexPosition] > newBestSolutionFitness[i])
        {
            selectSolutionFitness[indexPosition] = newBestSolutionFitness[i];
            selectSolution[indexPosition].swap(newBestSolution[i]);
        }
    }

    for (int i = 0; i < evolutionTime; i++) // 與 newWorstSolution 比較, 替換較差解
    {
        indexPosition = max_element(selectSolutionFitness.begin(), selectSolutionFitness.end()) - (selectSolutionFitness.begin());

        if (selectSolutionFitness[indexPosition] > newWorstSolutionFitness[i])
        {
            selectSolutionFitness[indexPosition] = newWorstSolutionFitness[i];
            selectSolution[indexPosition].swap(newWorstSolution[i]);
        }
    }

    for (int i = 0; i < cuckooNum; i++) // 更新 cuckooList
    {
        cuckooList[i].fitness = selectSolutionFitness[i];
        cuckooList[i].solution.swap(selectSolution[i]);
    }
}

void selectnBestCuckoo(veci_2D newSolution, veci_2D newBestSolution, vecf_1D newSolutionFitness, vecf_1D newBestSolutionFitness)
{
    vecf_1D selectSolutionFitness;
    veci_2D selectSolution;
    int indexPosition;

    //selectSolutionFitness.assign(newSolutionFitness.begin(),newSolutionFitness.end());
    //selectSolution.assign(newSolution.begin(),newSolution.end());

    for (int i = 0; i < cuckooNum; i++)
    {
        selectSolutionFitness.push_back(cuckooList[i].fitness);
        selectSolution.push_back(cuckooList[i].solution);
    }

    for (int i = 0; i < cuckooNum; i++) // 與 newSolution 比較, 替換較差解
    {
        indexPosition = max_element(selectSolutionFitness.begin(), selectSolutionFitness.end()) - (selectSolutionFitness.begin());

        if (selectSolutionFitness[indexPosition] > newSolutionFitness[i])
        {
            selectSolutionFitness[indexPosition] = newSolutionFitness[i];
            selectSolution[indexPosition].swap(newSolution[i]);
        }
    }

    for (int i = 0; i < evolutionTime; i++) // 與 newBestSolution 比較, 替換較差解
    {
        indexPosition = max_element(selectSolutionFitness.begin(), selectSolutionFitness.end()) - (selectSolutionFitness.begin());

        if (selectSolutionFitness[indexPosition] > newBestSolutionFitness[i])
        {
            selectSolutionFitness[indexPosition] = newBestSolutionFitness[i];
            selectSolution[indexPosition].swap(newBestSolution[i]);
        }
    }

    for (int i = 0; i < cuckooNum; i++) // 更新 cuckooList
    {
        cuckooList[i].fitness = selectSolutionFitness[i];
        cuckooList[i].solution.swap(selectSolution[i]);
    }
}

void generateNewSolution()
{
    veci_2D newSolution;
    veci_2D newBestSolution;
    int bestCuckoo = 0;
    float bestFitness = cuckooList[0].fitness;

    int randomSelect = rand() % cuckooNum;

    for (int i = 1; i < cuckooNum; i++) //找出 best cuckoo
    {
        if (bestFitness > cuckooList[i + 1].fitness)
        {
            bestCuckoo = i;
            bestFitness = cuckooList[i + 1].fitness;
        }
    }
    newSolution = updatingScheme(cuckooList[randomSelect]);
    newBestSolution = updatingScheme(cuckooList[bestCuckoo]);

    double probibility = (double)rand() / (RAND_MAX + 1.0);
    if (probibility < Pa)
    {
        veci_2D newWorstSolution;
        int worstCuckoo = 0;
        float worstFitness = cuckooList[0].fitness;

        for (int i = 1; i < cuckooNum; i++) //找出 worst cuckoo
        {
            if (worstFitness < cuckooList[i + 1].fitness)
            {
                worstCuckoo = i;
                worstFitness = cuckooList[i + 1].fitness;
            }
        }

        newWorstSolution = updatingScheme(cuckooList[worstCuckoo]);

        vecf_1D newSolutionFitness;
        vecf_1D newBestSolutionFitness;
        vecf_1D newWorstSolutionFitness;

        for (int i = 0; i < evolutionTime; i++)
        {
            newSolutionFitness.push_back(calFitness(newSolution[i]));
            newBestSolutionFitness.push_back(calFitness(newBestSolution[i]));
            newWorstSolutionFitness.push_back(calFitness(newWorstSolution[i]));
        }

        selectnBestCuckoo(newSolution,newBestSolution,newWorstSolution,newSolutionFitness,newBestSolutionFitness,newWorstSolutionFitness);
    }

    else
    {
        vecf_1D newSolutionFitness;
        vecf_1D newBestSolutionFitness;

        for (int i = 0; i < evolutionTime; i++)
        {
            newSolutionFitness.push_back(calFitness(newSolution[i]));
            newBestSolutionFitness.push_back(calFitness(newBestSolution[i]));
        }
        selectnBestCuckoo(newSolution,newBestSolution,newSolutionFitness,newBestSolutionFitness);
    }
}
