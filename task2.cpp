#include <fstream>
#include "eratosthenes.h"
#include<cstring>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);

    int n = 0;
    in >> n;
    in.close();

    vector<int> primes = sieve(n);

    ofstream out(argv[2]);


    if (!primes.empty()) {
        auto it = primes.begin();
        out << " " << *it;
        it++;

        for (; it != primes.end(); it++) {
            out << ", " << *it;
        }
    }
    out << endl;
    out.close();

    return 0;
}
