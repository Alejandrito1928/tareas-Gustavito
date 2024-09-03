#include <iostream>
using namespace std;

void desglosarBilletes(double monto) {
    int billetes200 = monto / 200;
    monto -= billetes200 * 200;

    int billetes100 = monto / 100;
    monto -= billetes100 * 100;

    int billetes50 = monto / 50;
    monto -= billetes50 * 50;

    int billetes20 = monto / 20;
    monto -= billetes20 * 20;

    int billetes10 = monto / 10;
    monto -= billetes10 * 10;

    int billetes5 = monto / 5;
    monto -= billetes5 * 5;

    int monedas1 = monto / 1;
    monto -= monedas1 * 1;

    int monedas05 = monto / 0.5;
    monto -= monedas05 * 0.5;

    int monedas02 = monto / 0.2;
    monto -= monedas02 * 0.2;

    int monedas01 = monto / 0.1;
    monto -= monedas01 * 0.1;

    
    cout << "Billetes de 200 soles: " << billetes200 << endl;
    cout << "Billetes de 100 soles: " << billetes100 << endl;
    cout << "Billetes de 50 soles: " << billetes50 << endl;
    cout << "Billetes de 20 soles: " << billetes20 << endl;
    cout << "Billetes de 10 soles: " << billetes10 << endl;
    cout << "Billetes de 5 soles: " << billetes5 << endl;
    cout << "Monedas de 1 sol: " << monedas1 << endl;
    cout << "Monedas de 0.5 soles: " << monedas05 << endl;
    cout << "Monedas de 0.2 soles: " << monedas02 << endl;
    cout << "Monedas de 0.1 soles: " << monedas01 << endl;
}

int main() {
    double monto;
    cout << "Ingresa el monto en soles: ";
    cin >> monto;

    desglosarBilletes(monto);

    return 0;
}
