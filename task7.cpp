#include <fstream>
#include <iomanip>
#include "calculator.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);

    string expr = "";
    getline(in, expr);
    in.close();

    double value = 0.0;

    if (isValidExpression(expr))

        value = calculate(expr);
    else {
        ofstream out(argv[2]);
        out << "invalid" << endl;
        out.close();
        return 0;
    }

    ofstream out(argv[2]);
    out << fixed << setprecision(4) << value << endl;
    out.close();
    return 0;
}
