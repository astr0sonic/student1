#include "sundaram.h"
#include<string>
#include<vector>
std::vector<int> sieve(int n) {
    std::vector<int> primes;
    int nNew = (n - 1) / 2;
    bool* marked;
    marked = new bool[nNew + 1];
    memset(marked, false, sizeof(marked));
    for (int i = 1; i <= nNew; i++)
    {
        for (int j = i; (i + j + 2 * i * j) <= nNew; j++)
        {
            marked[i + j + 2 * i * j] = true;
        }
    }
    for (int i = 1; i <= nNew; i++)
    {
        if (marked[i] == false)
            primes.push_back(2 * i + 1);
    }
    return primes;
}
