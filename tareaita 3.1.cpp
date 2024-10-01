#include <iostream>
using namespace std;

void swap(int* numero1, int* numero2) {
    int temp = *numero1;
    *numero1 = *numero2;
    *numero2 = temp;


}

int* llenar_fila(int* fila, int x) {
    int numero;
    int mitad = x / 2;
    int ultimo_par = 0;

    for (int i = 0; i < x; i++) {
        cout << "Escoje un numero par en la posicion : ";
        cin >> numero;
        if ((numero > ultimo_par)) {
            *(fila + i) = numero;
            ultimo_par = numero;
        }
        else {
            cout << "El numero debe ser mayor que " << ultimo_par << endl;
            i--;
        }
    }
    return fila;
}

void imprimir_filas(int* p, int* q) {
    cout << "Tu fila: ";
    for (int* i = p; i <= q; i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void ordenar(int* p, int* q) {
    int* inicio = p;
    int* final2 = q;
    int* final = q;

    while (p < final) {
        if ((*p % 2) == 0) {
            p++;  // Avanzamos si es par
        }
        if ((*p % 2) != 0) {
            int temp = *p;  // Guardamos el impar
            for (int* r = p; r < q; r++) {
                *r = *(r + 1);  // Desplazamos todos a la izquierda
            }
            *q = temp;  // Colocamos el impar al final
            imprimir_filas(inicio, final2);
            
            final--;
        }
    }
}

int main() {
    //int fila1[6] = { 3, 4, 5 , 7, 10,11};
    //int fila1[15] = { 3, 4, 6, 7, 10, 13, 14, 15, 16, 17, 20, 30, 45, 46, 50 };
    int fila1[8] = { 1,2,3, 4, 5 , 6, 7,8 };
    int* p = fila1;
    int* q = (fila1 + (8-1));

    cout << "Fila inicial: " << endl;
    imprimir_filas(p, q);

    ordenar(p, q);

    cout << "Fila ordenada (pares al principio, impares al final): " << endl;
    imprimir_filas(p, q);
   /*
    //colcoar numeros de cualquier tamaño
    cout << "Cuantos numeros quiere colocar en su fila: ";
    int x;
    cin >> x;
    int* fila_pedida = new int[x];
    int* pa = fila_pedida;
    int* qa = (fila_pedida + (x - 1));

    llenar_fila(fila_pedida, x);
    imprimir_filas(pa, qa);

    ordenar(pa, qa);
    //bubble(fila_pedida, x);
    cout << "Ordenado: " << endl;
    imprimir_filas(pa, qa);

    delete[] fila_pedida;
    */
    return 0;
}
