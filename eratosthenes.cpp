#include "eratosthenes.h"
#include <iostream>
#include<vector>
#include<cstring>
std::vector<int> sieve(int n)
{
    std::vector<bool> prime(n + 1, true);
    std::vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (prime[p])
            primes.push_back(p);
    }

    return primes;

}
