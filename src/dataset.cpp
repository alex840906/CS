#include "dataset.h"
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
//#include "CS_ARG.h"


void readfile() /////////////讀檔//////////////
{
    vector<vector<int>> eil(dataSize);
    string line, tmp;
    int tmp_2;
    int i = 0;

    //eil.resize(dataSize);
    fstream file;
    file.open("datasets/eil51.txt", ios::in);

    while (getline(file, line))
    {
        stringstream t_line(line), ss;
        while (getline(t_line, tmp, ' '))
        {
            ss.clear();
            ss << tmp;
            ss >> tmp_2;
            eil[i].push_back(tmp_2);
        }
        i++;
    }
}