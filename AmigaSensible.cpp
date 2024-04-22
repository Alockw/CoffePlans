#include <iostream> 
#include <string> 
#include <set> 
#include <map> 

using namespace std; 


void menu(){
    int opcion; 
    do
    {
        cout << " Bienvenido!" ; 
        cout << "1. Ciudad 1";
        cout << "2. Ciudad 2";
        cout << "3. Ciudad 3";
        cout << "4. Salir";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            itinerarioOslso;
            break;
        case 2:
            itinerarioEstocolmo;
            break;
        case 3:
            itinerarioHelsinki;
            break;
        case 4:
            cout << "Saliendo de la plataforma";
            break;
        default:
            cout << " Ingrese un número válido";
            break;
        }
    } while (opcion != 4);
    
}
// info del destino 
struct destino {
    string ciudad; 
    string pais;
    set<string> destinos; 
}

// info del viaje
struct viaje {
    string fecha;
    string transporte;
    string salida; 
    float precioTransporte; 
    map<int, string> dia;
}

int main(){

    // Conjunto de ciudades de destino
    set<string> destinos; 

    destinos.insert("Oslo");
    destinos.insert("Estocolmo");
    destinos.insert("Helsinki");

    // se imprimen los datos agregados
    cout << "Los destinos del viaje son: " << endl; 
    for (const string& destino: destinos)
    {
        cout << destino << endl; 
    }


    // Mapa de lugares visitados en cada país

    map <int, string> itinerarioOslo;
    // dia 1
    itinerarioOslo[1]="Parque Oslofjord";
    // dia 2 
    itinerarioOslo[2]="Botanical Garden";
    // dia 3
    itinerarioOslo[3]="Lago Sognsvann";
    for(const auto& par: itinerarioOslo)
    {
        int orden = par.first;
        string lugarAVisitar = par.second;
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }


    map <int, string> itinerarioEstocolmo;
    // dia 4
    itinerarioEstocolmo[1]="Rosendals Garden";
    // dia 5
    itinerarioEstocolmo[2]="Riddarholmen";
    // dia 6
    itinerarioEstocolmo[3]="Porjus";
    for(const auto& par: itinerarioEstocolmo)
    {
        int orden = par.first;
        string lugarAVisitar = par.second;
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }


    map <int, string> itinerarioHelsinki;
    // dia 7
    itinerarioHelsinki[1]="Parque Sibelius";
    // dia 8 
    itinerarioHelsinki[2]="Playa Aurikolahti";
    // dia 9 
    itinerarioHelsinki[3]="Kumpula Botanic Garden";
    for(const auto& par: itinerarioHelsinki)
    {
        int orden = par.first;
        string lugarAVisitar = par.second;
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }
    
    return 0;
};
