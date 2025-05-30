#include <iostream>
#include <map>
#include <vector>
#include <string>

struct InfoDeporte {
    int id;
    std::string reglas;
    std::string faltas;
};

class Deporte {
public:
    void agregarDeporte(const std::string& nombre, int id, const std::string& reglas, const std::string& faltas) {
        InfoDeporte info;
        info.id = id;
        info.reglas = reglas;
        info.faltas = faltas;
        deportes[nombre] = info;
    }

    int obtenerID(const std::string& nombre) const {
        std::map<std::string, InfoDeporte>::const_iterator it = deportes.find(nombre);
        if (it != deportes.end()) {
            return it->second.id;
        }
        return -1;
    }

    bool obtenerInfo(const std::string& nombre, InfoDeporte& info) const {
        std::map<std::string, InfoDeporte>::const_iterator it = deportes.find(nombre);
        if (it != deportes.end()) {
            info = it->second;
            return true;
        }
        return false;
    }

private:
    std::map<std::string, InfoDeporte> deportes;
};

class Caracteristicas {
public:
    void agregarCaracteristica(const std::string& descripcion, const std::vector<int>& ids) {
        caracteristicas[descripcion] = ids;
    }

    void mostrarPorID(int id) const {
        std::map<std::string, std::vector<int> >::const_iterator it;
        bool encontrado = false;

        for (it = caracteristicas.begin(); it != caracteristicas.end(); ++it) {
            const std::vector<int>& ids = it->second;
            for (size_t i = 0; i < ids.size(); ++i) {
                if (ids[i] == id) {
                    std::cout << it->first << "\n";
                    encontrado = true;
                    break;
                }
            }
        }

        if (!encontrado) {
            std::cout << "No se encontraron caracteristicas para este deporte.\n";
        }
    }

private:
    std::map<std::string, std::vector<int> > caracteristicas;
};

int main() {
    Deporte d;
    Caracteristicas c;

    // nombre / id / reglas / faltas
    d.agregarDeporte("futbol", 1, "11 jugadores, se juega con los pies, 2 tiempos de 45 min", "mano, falta, fuera de lugar");
    d.agregarDeporte("baloncesto", 2, "5 jugadores, botar balón, encestar", "caminar, doble drible, empujar");
    d.agregarDeporte("voleibol", 3, "6 jugadores, no dejar caer el balón, máximo 3 toques", "invadir red, retención");
    d.agregarDeporte("rugby", 4, "15 jugadores, avanzar con balón, marcar tries", "pases hacia adelante, tackleo alto");
    d.agregarDeporte("handball", 5, "7 jugadores, lanzar el balón con la mano al arco", "pasos excesivos, invadir área");

    // característica / ids
    std::vector<int> ids1;
    ids1.push_back(1);
    ids1.push_back(2);
    ids1.push_back(3);
    ids1.push_back(5);

    std::vector<int> ids2;
    ids2.push_back(4);

    std::vector<int> ids3;
    ids3.push_back(1);
    ids3.push_back(4);
    ids3.push_back(5);

    std::vector<int> ids4;
    ids4.push_back(2);
    ids4.push_back(3);
    ids4.push_back(5);

    std::vector<int> ids5;
    ids5.push_back(1);
    ids5.push_back(2);
    ids5.push_back(3);
    ids5.push_back(4);
    ids5.push_back(5);

    c.agregarCaracteristica("Usa balon redondo", ids1);
    c.agregarCaracteristica("Usa balon ovalado", ids2);
    c.agregarCaracteristica("Es de contacto", ids3);
    c.agregarCaracteristica("No es de contacto", ids4);
    c.agregarCaracteristica("Es un deporte en equipo", ids5);

    std::string nombreDeporte;
    std::cout << "Ingrese el nombre del deporte: ";
    std::getline(std::cin, nombreDeporte);

    InfoDeporte info;
    if (d.obtenerInfo(nombreDeporte, info)) {
        std::cout << "\nCaracteristicas de " << nombreDeporte << ":\n";
        std::cout << "Reglas: " << info.reglas << "\n";
        std::cout << "Faltas: " << info.faltas << "\n";
        std::cout << "Otras caracteristicas:\n";
        c.mostrarPorID(info.id);
    } else {
        std::cout << "Ese deporte no usa balon o ingresó un nombre incorrecto.\n";
    }

    return 0;
}

