#ifndef Object_h
#define Object_h

#include <iostream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "fitness.h"

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
    void initialize();
};

veci_2D updatingScheme(Cuckoo);
void generateNewSolution();
void rearrange(veci_1D &);

//inline vector<Cuckoo> cuckooList(cuckooNum,Cuckoo()); //Use vector to construct Cuckoo
extern vector<Cuckoo> cuckooList;

#endif