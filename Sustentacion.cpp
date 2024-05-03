// sistema que permita almacenar los familiares mas frecuentes en vcaciones del que tiene mas a menos viajes. se ejecute el miembor de la familia que mas viajestiene programados 

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct miembroDeLaFamilia {
    string nombre;
    int viajesPlanificados;

    // Constructor predeterminado para la función que se usará mas adelante
    miembroDeLaFamilia() : nombre(""), viajesPlanificados(0) {}

    // Constructor con los parámetros establecidos para desarrollar el porograma 
    miembroDeLaFamilia(string nombre, int viajesPlanificados) : nombre(nombre), viajesPlanificados(viajesPlanificados) {}
};

// función para ordenar los miembros de la familia de mayor a menor viajes planificados (se utilizan ordenamientos para organizar los miembors de la familia)
void ordenarFamiliares(map<string, miembroDeLaFamilia>& miembros) {
    bool cambio = true;
    while (cambio) {
        cambio = false;
        for (auto it = miembros.begin(); it != prev(miembros.end()); ++it) {
            if (it->second.viajesPlanificados < next(it)->second.viajesPlanificados) {
                swap(it->second, next(it)->second);
                cambio = true;
            }
        }
    }
}

int main() {
    // mapa para crear los miembros de la familia 
    map<string, miembroDeLaFamilia> miembros;

    // datos de cada miembro  
    miembros["nombre1"] = miembroDeLaFamilia("nombre1", 20);
    miembros["nombre2"] = miembroDeLaFamilia("nombre2", 33);
    miembros["nombre3"] = miembroDeLaFamilia("nombre3", 41);
    miembros["nombre4"] = miembroDeLaFamilia("nombre4", 29);

    ordenarFamiliares(miembros);

    // función para encontrar el miembro de la familia que tenga más viajes planificados 
    cout << "Los familiares ordenados de mayor a menor según los viajes que tienen planificados son:\n" << endl; 
    for(const auto& par : miembros){
        cout << par.second.nombre << " con un total de:\n" << par.second.viajesPlanificados << " viajes." << endl;
    }

    return 0;
}