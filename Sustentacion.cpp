// sistema que permita almacenar los familiares mas frecuentes en vcaciones del que tiene mas a menos viajes. se ejecute el miembor de la familia que mas viajestiene programados 

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct miembroDeLaFamilia {
    string nombre;
    int viajesPlanificados;

    miembroDeLaFamilia(string nombre, int viajesPlanificados) : nombre(nombre), viajesPlanificados(viajesPlanificados) {}
};

// función para ordenar los miembors de la familia de mayor a menor viajes planificados 
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

    // función para encontrar el miebmro de la familia que tenga mas viajes planificados 
    string miembroConMasViajesPlanificados;
    int maximoDeViajes = 0;
    for (const auto& par : miembros) {
        if (par.second.viajesPlanificados > maximoDeViajes) {
            miembroConMasViajesPlanificados = par.first;
            maximoDeViajes = par.second.viajesPlanificados;
        }
    }
    cout << "Los familiares ordenados de mayor a menor segun los viajes que tienen planificados son: \n" << endl; 
    for(const auto& par : miembros){
        cout << par.second.miembros << " Con un total de: \n" << par.second.viaijesPlanificados << " viajes." << endl;
    }

    return 0;
};
