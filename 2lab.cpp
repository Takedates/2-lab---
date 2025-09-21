#include <iostream>
#include <cmath>

using namespace std;

double calculateThermalConductivity(double M, double Tc, double Pc, double Cp, double T) {
    double gamma = sqrt(M * pow(Tc / Pc, 0.75));
    double lambda = (Cp / gamma) * pow((4.452 / Tc) * (T / Tc - 0.534), 1.5) * sqrt(M) / 1000.0;
    return lambda;
}

int main() {
    double M[] = {44.1, 46.1, 88.1, 84.1, 119.4};
    double Tc[] = {370, 400, 523, 353, 537};
    double Pc[] = {42.0, 52.6, 37.8, 40.0, 54.0};
    double Cp[] = {21.1, 16.8, 32.4, 33.0, 17.1};
    double T = 373.0;

    int num_gases = sizeof(M) / sizeof(M[0]);

    for (int i = 0; i < num_gases; ++i) {
        double lambda = calculateThermalConductivity(M[i], Tc[i], Pc[i], Cp[i], T);
        cout << "Газ " << i + 1 << ": λ = " << lambda << " кал/моль*град" << endl;
    }

    return 0;
}
