// La amiga sensible es aquella amiga que tiene los lugares establecidos que quiere visitar, no hay mucho orden con respecto a las horas pero quiere visitar cada destino que tiene dentro de su lista de planes
#include <iostream> 
#include <string> 
#include <set> 
#include <map> 

using namespace std; 

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
