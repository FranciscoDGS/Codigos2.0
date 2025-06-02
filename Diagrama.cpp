#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Función que procesa una cadena de derecha a izquierda
void ciclo(string cadena) {
    int estado = 1;
    string traza = "S1";

    for (int i = cadena.length() - 1; i >= 0; i--) {  // ? Recorre de derecha a izquierda
        char simbolo = cadena[i];

        if (estado == 1) {
            if (simbolo == 'a') {
                estado = 2;
                traza += " <- S2";
            } else if (simbolo == 'b') {
                estado = 3;
                traza += " <- S3";
            } else {
                estado = -1;
                break;
            }
        } else if (estado == 2) {
            if (simbolo == 'a') {
                estado = 2;
                traza += " <- S2";
            } else if (simbolo == 'b') {
                estado = 1;
                traza += " <- S1";
            } else if (simbolo == 'c') {
                estado = 4;
                traza += " <- S4";
            } else {
                estado = -1;
                break;
            }
        } else if (estado == 3) {
            if (simbolo == 'a') {
                estado = 1;
                traza += " <- S1";
            } else if (simbolo == 'b') {
                estado = 4;
                traza += " <- S4";
            } else {
                estado = -1;
                break;
            }
        } else if (estado == 4) {
            if (simbolo == 'b') {
                estado = 3;
                traza += " <- S3";
            } else if (simbolo == 'd') {
                estado = 4;
                traza += " <- S4";
            } else {
                estado = -1;
                break;
            }
        }
    }

    // Mostrar resultados
    cout << "\nCadena: " << cadena << endl;
    if (estado == 4) {
        cout << "Resultado: ACEPTADA ?" << endl;
    } else {
        cout << "Resultado: RECHAZADA ?" << endl;
    }
    cout << "Ruta (de derecha a izquierda): " << traza << endl;
}

int main() {
    int tamano;
    cout << "\ncuantos caracteres son ";
    cin >> tamano;
    cin.ignore(); // Limpia el salto de línea

    vector<string> cadenas(tamano);

    for (int i = 0; i < tamano; i++) {
        cout << "\nIngresa el caracter #" << i + 1 << ": ";
        getline(cin, cadenas[i]);
    }

    cout << "\n=== RESULTADOS ===\n";
    for (int i = 0; i < tamano; i++) {
        ciclo(cadenas[i]);
    }

    return 0;
}

