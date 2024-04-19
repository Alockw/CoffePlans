#include <iostream>
#include <map>
#include <string>
#include <list>
#include <set>

using namespace std;

int main(){
    string nombre, fecha, destino;

    cout << "Bienvenido a Planes Cooffe, la mejor plataforma para diseñar tus vacaciones " << endl;

    cout << "A continuacion, ingresa los siguientes datos: " << endl;
    cout << "Escribe tu nombre: ";
    cin >> nombre;
    cout << "¿Que fecha tienes dispoible para viajar? ";
    cin >> fecha;

    // Conjunto de ciudades de Colombia. 
    set<string> lugares; 

    lugares.insert("Santa Marta");
    lugares.insert("Cali");
    lugares.insert("San Andres");


    map<string, pair<string, string>> lugaresPersonas;

    // Asociamos nombre y la fecha al destino
    lugaresPersonas[destino] = make_pair(nombre, fecha);

    //Hacemos un for para mostrar. 
    cout << "\nDatos almacenados:\n" << endl;
    for (const auto& persona : lugaresPersonas) {
        cout << "Destino: " << persona.first << "\n";
        cout << "Nombre: " << persona.second.first << "\n";
        cout << "Fecha: " << persona.second.second << "\n";
    }  

    list<string> listaFamiliar = {};

    string desicionViaje;
    cout << "Si desea agregar a la lista de viajes familiares, escriba a continuacion el destino que desea agregar " << endl;
    cin >> desicionViaje;
    
    listaFamiliar.push_back(desicionViaje);

    cout << listaFamiliar << endl;
    return 0;
}
