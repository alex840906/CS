#include "operator.h"

int round_double(double number)
{
    return (number > 0.0) ? (number + 0.5) : (number - 0.5);
}

void swapObject(Cuckoo &A, Cuckoo &B)
{
    Cuckoo tmp = A;
    A = B;
    B = tmp;
}

