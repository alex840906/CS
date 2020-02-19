#ifndef Object_h
#define Object_h

#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <algorithm>
//#include "CS_ARG.h"
#include "fitness.h"

//#include "operator.h"

using namespace std;

// void generateNewSolution();
// void updatingScheme(Cuckoo);

class Cuckoo
{
private:
    float _alpha;

public:
    Cuckoo();
    float fitness;
    veci_1D solution;

    void update(Cuckoo);
};

veci_2D updatingScheme(Cuckoo);
void generateNewSolution();

inline vector<Cuckoo> cuckooList; //Use vector to construct Cuckoo
//inline Cuckoo bestCuckoo;

#endif