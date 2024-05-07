#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    primes.push_back(2);
    bool* prime;
    prime = new bool[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p]) primes.push_back(p);
    }
    return primes;
}
