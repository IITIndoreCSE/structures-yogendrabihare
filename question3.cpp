#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

struct Point {
    double x;
    double y;
};

// Helper to print numbers without trailing .0000
void print_number(double val) {
    if (fabs(val - round(val)) < 1e-6) {
        cout << (long long)round(val);  // print as integer
    } else {
        cout << val;  // print as double
    }
}

void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    // Round tiny values close to zero
    if (fabs(x_after) < 1e-6) x_after = 0.0;
    if (fabs(y_after) < 1e-6) y_after = 0.0;

    cout << "Before rotation: (x=";
    print_number(x_before);
    cout << ", y=";
    print_number(y_before);
    cout << ")\n";

    cout << "After rotation (θ=" << fixed << setprecision(4) << theta << " rad): (x=";
    print_number(x_after);
    cout << ", y=";
    print_number(y_after);
    cout << ")\n";
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

    Point p;
    double theta;
    Point pivot;

    // Read from input: x, y, theta, px, py
    input >> p.x >> p.y >> theta >> pivot.x >> pivot.y;

    // Perform rotation around pivot
    double x_shifted = p.x - pivot.x;
    double y_shifted = p.y - pivot.y;

    double x_after = pivot.x + (x_shifted * cos(theta) - y_shifted * sin(theta));
    double y_after = pivot.y + (x_shifted * sin(theta) + y_shifted * cos(theta));

    // Print result
    print_point_rotation(p.x, p.y, theta, x_after, y_after);

    return 0;
}
