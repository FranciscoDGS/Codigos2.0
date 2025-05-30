#include <iostream>   
#include <conio.h>    
#include <stdio.h>    

using namespace std;

// Clase Triangulo
class Triangulo {
private:
    float base;
    float altura;

public:
    // Constructor
    Triangulo(float b, float h) {
        base = b;
        altura = h;
    }

    // Método para calcular el área
    float calcularArea() {
        return (base * altura) / 2;
    }
};

int main() {
    float base, altura;

    cout << "Ingrese la base del triangulo: ";
    cin >> base;

    cout << "Ingrese la altura del triangulo: ";
    cin >> altura;

    // Crear objeto de la clase Triangulo
    Triangulo t(base, altura);

    
    cout << "\nEl area del triangulo es: " << t.calcularArea() << endl;

   
    getch(); 
    return 0;
}

