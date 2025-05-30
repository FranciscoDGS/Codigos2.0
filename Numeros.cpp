#include <iostream>

using namespace std;

int main() {
    int numeros[10];
    int i, j, temp;

    // Captura de los 10 números
    cout << "Ingresa 10 numeros:" << endl;
    for (i = 0; i < 10; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Ordenamiento ascendente (método burbuja)
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (numeros[i] > numeros[j]) {
                temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }

    // Despliegue de los números ordenados
    cout << "\nNumeros ordenados en forma ascendente:" << endl;
    for (i = 0; i < 10; i++) {
        cout << numeros[i] << " ";
    }

    cout << endl;
    return 0;
}

