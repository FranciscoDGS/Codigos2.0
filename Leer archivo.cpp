#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Cambia esta ruta según tu nombre de usuario en Windows
    std::ifstream archivo("C:\\Users\\frnco\\Desktop\\Prueba.txt");

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }

    archivo.close();
    return 0;
}

