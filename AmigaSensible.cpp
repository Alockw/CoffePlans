#include <iostream> 
#include <string> 
#include <set> 
#include <map> 

using namespace std; 

int main(){
    // Conjunto de países de destino
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
    map <int, string> oslo;
    oslo[1]="Parque Oslofjord";
    oslo[2]="Botanical Garden";
    oslo[3]="Lago Sognsvann";
    for(const auto& par: oslo)
    {
        int orden = par.first();
        string lugarAVisitar = par.second();
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }

    map <int, string> estocolmo;
    estocolmo[1]="Rosendals Garden";
    estocolmo[2]="Riddarholmen";
    estocolmo[3]="Porjus";
    for(const auto& par: estocolmo)
    {
        int orden = par.first();
        string lugarAVisitar = par.second();
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }

    map <int, string> helsinki;
    helsinki[1]="Parque Sibelius";
    helsinki[2]="Playa Aurikolahti";
    helsinki[3]="Kumpula Botanic Garden";
    for(const auto& par: helsinki)
    {
        int orden = par.first();
        string lugarAVisitar = par.second();
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }
    return 0;
};