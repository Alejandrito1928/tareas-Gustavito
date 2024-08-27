#include <iostream>
#include <string>
using namespace std;

string nombres[] = {
    "cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve",
    "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete",
    "dieciocho", "diecinueve", "veinte"
};

string nombresendiez[] = { "", "", "", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa", "cien"
};

string numerosencienes[] = { "", "doacientos", "trecientos ", "cuatrocientos", "", "cincuenta", "sesenta", "setenta", "ochenta", "noventa", "cien"
};

string convertirANombre(int numero) {
    //int unimil;
    //int unidiezmiles
    if (numero >= 0 && numero <= 20) {
        return nombres[numero];
    }
    else if (numero > 20 && numero < 30) {
        return "veinti" + nombres[numero - 20];
    }
    else if (numero >= 30 && numero <= 100) {
        return nombresendiez[numero / 10];
    }
    else if (numero > 100 && numero < 1000) {
        return numerosencienes[numero];
    }

    else {
        return "Número fuera de rango";
    }
}

string numeros_en_diez(int numero) {
    if (numero > 20 && numero < 30) {
        int decenas = numero / 10;
        int unidades = numero % 10;
        string resultado = convertirANombre(decenas * 10);
        if (unidades != 0) {
            resultado += " y " + convertirANombre(unidades);
        }
        return resultado;
    }
    if (numero > 30 && numero < 100) {
        int decenas = numero / 10;
        int unidades = numero % 10;
        string resultado = convertirANombre(decenas * 10);
        if (unidades != 0) {
            resultado += " " + convertirANombre(unidades);
        }
        return resultado;
    }
    else {
        return "Número fuera de rango para esta función";
    }
}

string numeros_en_cienes(int numero) {
    if (numero > 100 && numero < 1000) {
        int decenas = numero / 10;
        //numero = numero / 10;
        int unidades = numero % 10;
        //numero = numero % 10;

        string resultado = convertirANombre(decenas);
        if (unidades != 0) {
            resultado += " ciento " + convertirANombre(unidades);
        }
        return resultado;



    }
    else {
        return "Número fuera de rango para esta función";
    }
}

int main() {
    int numero;
    cout << "Ingresa un número: ";
    cin >> numero;

    string nombre;

    if (numero >= 0 && numero <= 20) {
        nombre = convertirANombre(numero);
    }
    else if (numero > 20 && numero <= 99) {
        nombre = numeros_en_diez(numero);
    }
    else if (numero >= 100 && numero <= 1000) {
        nombre = numeros_en_cienes(numero);
    }
    else {
        nombre = "Número fuera de rango soportado";
    }

    cout << "El nombre del número es: " << nombre << endl;

    return 0;
}
