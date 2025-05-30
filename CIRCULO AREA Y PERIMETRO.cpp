
#include <iostream>
#include <cmath> // Para usar M_PI y funciones matemáticas

using namespace std;

int main() {
    int opcion;
    double radio;
    
    do {
        cout << "\n=== Calculadora de Circulo ===";
        cout << "\n1. Calcular area";
        cout << "\n2. Calcular perimetro";
        cout << "\n3. Salir";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "\nIngrese el radio: ";
                cin >> radio;
                cout << "Área: " << M_PI * pow(radio, 2) << endl;
                break;
                
            case 2:
                cout << "\nIngrese el radio: ";
                cin >> radio;
                cout << "Perímetro: " << 2 * M_PI * radio << endl;
                break;
                
            case 3:
                cout << "Saliendo...";
                break;
                
            default:
                cout << "Opcion invalida!";
        }
    } while(opcion != 3);
    
    return 0;
}
