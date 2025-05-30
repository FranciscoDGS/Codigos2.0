#include <iostream>
#include <map>
#include <vector>
#include <string>

struct InfoAnimal {
    int id;
    std::string habitat;
    std::string alimentacion;
};

class Animal {
public:
    void agregarAnimal(const std::string& nombre, int id, const std::string& habitat, const std::string& alimentacion) {
        InfoAnimal info;
        info.id = id;
        info.habitat = habitat;
        info.alimentacion = alimentacion;
        animales[nombre] = info;
    }

    int obtenerID(const std::string& nombre) const {
        std::map<std::string, InfoAnimal>::const_iterator it = animales.find(nombre);
        if (it != animales.end()) {
            return it->second.id;
        }
        return -1;
    }

    bool obtenerInfo(const std::string& nombre, InfoAnimal& info) const {
        std::map<std::string, InfoAnimal>::const_iterator it = animales.find(nombre);
        if (it != animales.end()) {
            info = it->second;
            return true;
        }
        return false;
    }

private:
    std::map<std::string, InfoAnimal> animales;
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
            std::cout << "No se encontraron caracteristicas para este animal.\n";
        }
    }

private:
    std::map<std::string, std::vector<int> > caracteristicas;
};

int main() {
    Animal a;
    Caracteristicas c;

    // lista animales / id / habitad / tipo de alimentacion
    a.agregarAnimal("elefante", 1, "sabana", "herbivoro");
    a.agregarAnimal("tigre", 2, "selva", "carnivoro");
    a.agregarAnimal("gato naranja", 3, "hogar domestico", "carnivoro");
    a.agregarAnimal("tortuga", 4, "agua", "herbivoro");
    a.agregarAnimal("serpiente marina", 5, "oceano", "carnivoro");

    // caracteristica id / id animal
    std::vector<int> ids1; ids1.push_back(4); ids1.push_back(5);
    std::vector<int> ids2; ids2.push_back(2); ids2.push_back(3);
    std::vector<int> ids3; ids3.push_back(1); ids3.push_back(2); ids3.push_back(3);
    std::vector<int> ids4; ids4.push_back(1); ids4.push_back(2);
    std::vector<int> ids5; ids5.push_back(4); ids5.push_back(5);
    

    c.agregarCaracteristica("es oviparo", ids1);
    c.agregarCaracteristica("es naranja", ids2);
    c.agregarCaracteristica("es mamifero", ids3);
    c.agregarCaracteristica("es grande", ids4);
    c.agregarCaracteristica("es sangre fria", ids5);


    std::string nombreAnimal;
    std::cout << "Ingrese el nombre del animal: ";
    std::getline(std::cin, nombreAnimal);

    InfoAnimal info;
    if (a.obtenerInfo(nombreAnimal, info)) {
        std::cout << "\nCaracteristicas de " << nombreAnimal << ":\n";
        std::cout << "Habitat: " << info.habitat << "\n";
        std::cout << "Alimentacion: " << info.alimentacion << "\n";
        c.mostrarPorID(info.id);
    } else {
        std::cout << "Animal no encontrado.\n";
    }

    return 0;
}

