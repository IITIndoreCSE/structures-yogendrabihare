#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void print_taylor_term(int index, int order, double coeff, double value) {
    cout << "Term[" << index << "]: "
         << "order=" << order << ", "
         << "coeff=" << coeff << ", "
         << "value=" << value << "\n";
}

void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    cout << "Approximation of " << function_name
         << "(x) at x=" << x
         << " with " << terms << " terms: "
         << approximation << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    double x;
    int terms;
    input >> x >> terms;

    double approximation = 0.0;

    for (int k = 0; k < terms; k++) {
        int order = 2 * k;  // even powers for cos
        double coeff = (k % 2 == 0 ? 1 : -1);  // (-1)^k
        double value = coeff * pow(x, order) / tgamma(order + 1); // factorial = Γ(order+1)

        print_taylor_term(k, order, coeff, value);
        approximation += value;
    }

    print_taylor_result("cos", x, terms, approximation);

    return 0;
}
