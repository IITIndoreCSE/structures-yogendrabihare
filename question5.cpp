#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Sensor {
    int id;
    double temperature;
    double voltage;
    char status[10];
};

void print_sensor(int index, int id, double temperature, double voltage, const char* status) {
    cout << "Sensor[" << index << "]: "
         << "id=" << id << ", "
         << "temperature=" << temperature << ", "
         << "voltage=" << voltage << ", "
         << "status=" << status << "\n";
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

    int num_sensors;
    input >> num_sensors;

    Sensor sensors[10];  // allow up to 10 sensors

    for (int i = 0; i < num_sensors; i++) {
        input >> sensors[i].id;
        input >> sensors[i].temperature;
        input >> sensors[i].voltage;
        input >> ws;  // eat whitespace before reading status
        input.getline(sensors[i].status, 10);
    }

    // pointer traversal
    Sensor* ptr = sensors;
    for (int i = 0; i < num_sensors; i++, ptr++) {
        print_sensor(i, ptr->id, ptr->temperature, ptr->voltage, ptr->status);
    }

    return 0;
}
