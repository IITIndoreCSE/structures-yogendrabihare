#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct Point {
    double x;
    double y;
};

void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    cout << "After rotation (θ=" << theta << " rad): "
         << "(x=" << x_after << ", y=" << y_after << ")\n";
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
