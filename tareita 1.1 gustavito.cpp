#include <iostream>
#include <string>
using namespace std;
string convertirANombre(int numero);
string numeros_cienes(int numero);
string numeros_miles(int numero);
string numeros_diesmiles(int numero);
string numeros_cienmiles(int numero);

string nombres[] = {
    "cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve",
    "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete",
    "dieciocho", "diecinueve", "veinte"};

string nombresendiez[] = {"", "", "veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};

string nombresencien[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

string numeros_deiz(int numero) {
    //                10
    if (numero >= 30 && numero < 100) {
        int decenas = numero / 10;
        //1
        int unidades = numero % 10;
        //0

        string resultado = nombresendiez[decenas]; 
        if (unidades != 0) {
            resultado += " y " + nombres[unidades]; 
        }
        return resultado;
    } else {return "Número fuera de rango para esta función en decenas";}
}
string numeros_cienes(int numero) {
    if (numero >= 100 && numero < 1000) {
        int centenas = numero / 100;
        int resto = numero % 100;

        string resultado = nombresencien[centenas];
        if (resto != 0) {
            resultado += " " + convertirANombre(resto); 
        } else if (centenas == 1) {
            resultado = "cien";  
        }
        return resultado;
    } else {return "Número fuera de rango para esta función en cienes";}
}
string numeros_miles(int numero) {
    if (numero > 1000 && numero < 2000) {
        int unidad = numero % 1000;
        string resultado = "mil";
        if (unidad != 0) {
            resultado += " " + convertirANombre(unidad); 
        } 
        return resultado;
    } else if (numero >= 2000 && numero < 10000) {
        int miles = numero / 1000; 
        int unidad = numero % 1000;

        string resultado = nombres[miles];
        resultado += " mil";
        if (unidad != 0) {
            resultado += " " + convertirANombre(unidad); 
        } 
        return resultado;
    } else if (numero == 1000) {
        return "mil";
    } else {
        return "Número fuera de rango para esta función en miles";
    }
}

string numeros_diesmiles(int numero) 
{
    string resultado;
    if (numero >= 10000 && numero < 100000) 
    {
        int miles = numero / 1000;  
        int resto = numero % 1000;    

        if (resto != 0)
        {
            resultado = convertirANombre(miles);  
            resultado += " mil " + convertirANombre(resto);  
        }
        else
        {
            resultado = convertirANombre(miles);  
            resultado += " mil";  
        }
    }return resultado;
}
string numeros_cienmiles(int numero) 
{
    if (numero >= 100000 && numero < 1000000) {
        //                   123456
        int centenasDeMil = numero / 100000;  
        //                             1 
        int restoDeCienMil = numero % 100000; 
        //                     23456

    string resultado = nombresencien[centenasDeMil]; 

    if (restoDeCienMil == 0) {
        resultado += " mil";
    } else {
        if (restoDeCienMil >= 10000) {
            resultado += " " + numeros_diesmiles(restoDeCienMil);
        } else {
            resultado += " " + convertirANombre(restoDeCienMil);
        }
    }

        return resultado;
    } else {
        return "Número fuera de rango para esta función en cien miles";
    }
}

//semi bucle loco
string convertirANombre(int numero) {
    if (numero >= 0 && numero <= 20) {
        return nombres[numero];
    } 
    else if (numero >= 21 && numero < 30) {
        return "veinti" + nombres[numero - 20];
    } 
    else if (numero >= 30 && numero < 100) {
        return numeros_deiz(numero);  
    } 
    else if (numero >= 100 && numero < 1000) {
        return numeros_cienes(numero);  
    }
    else if (numero >= 1000 && numero < 10000) {
        return numeros_miles(numero);  
    }
    else if (numero >= 10000 && numero < 100000) {
        return numeros_diesmiles(numero);  
    }
    else if (numero >= 100000 && numero < 999999) {
        return numeros_cienmiles(numero);  
    }return "Número fuera de rango";}

int main() {
    int numero;
    cout << "Ingresa un número: ";
    cin >> numero;
    string nombre;
    
    if (numero >= 0 && numero < 1000000) {
        nombre = convertirANombre(numero);
    }
    
    cout << "El nombre del número es: " << nombre << endl;
    if(numero == 1000000){cout<<"UN MILLON abusivo";} else {
        nombre = "Número fuera de rango soportado";
    }
    return 0;
}
