#include <iostream>
#include <map>
#include <string>
#include <list>
#include <set>

using namespace std;

int main(){
    // Declaración de variables para almacenar información del usuario
    string nombre, fecha;

    // Saludo inicial al usuario
    cout << "Bienvenido a Planes Cooffe, la mejor plataforma para diseñar tus vacaciones " << endl;

    // Solicita al usuario que ingrese su nombre y la fecha disponible para viajar
    cout << "A continuacion, ingresa los siguientes datos: " << endl;
    cout << "Escribe tu nombre: ";
    cin >> nombre;
    cout << "¿Que fecha tienes dispoible para viajar? ";
    cin >> fecha;

    // Inicialización de un conjunto para almacenar ciudades de Colombia
    set<string> lugares; 

    // Agrega ciudades al conjunto
    lugares.insert("Santa Marta");
    lugares.insert("Cali");
    lugares.insert("San Andres");

    // Inicialización de un mapa para asociar destinos con nombres y fechas
    map<string, pair<string, string>> lugaresPersonas;

    // Itera sobre el conjunto de lugares e imprime cada uno
    cout << "Los destinos del viaje son: " << endl; 
    for (const string& destino: lugares)
    {
        cout << destino << endl; 
    }

    // Inicialización de mapas para almacenar itinerarios por ciudad
    map <int, string> itinerarioSanta_Marta;
    map <int, string> itinerarioCali;
    map <int, string> itinerarioSan_Andres;

    // Agrega actividades a los itinerarios
    itinerarioSanta_Marta[1]="Caminata de 7 horas (Taganga).";
    itinerarioSanta_Marta[2]="Playa Buritaca.";
    itinerarioSanta_Marta[3]="Acuario Rodadero.";

    itinerarioCali[1]="Visitar el museo La Tertulia. ";
    itinerarioCali[2]="Conocer Bahia Magdalena. ";
    itinerarioCali[3]="Parque Nacional Natural Puracé. ";

    itinerarioSan_Andres[1]=" Playa Spratt Bight. ";
    itinerarioSan_Andres[2]="Practica snorkel o careteo. ";
    itinerarioSan_Andres[3]="El Hoyo Soplador. ";

    // Imprime los itinerarios
    for(const auto& par: itinerarioSanta_Marta)
    {
        int orden = par.first;
        string lugarAVisitar = par.second;
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }

    for(const auto& par: itinerarioCali)
    {
        int orden = par.first;
        string lugarAVisitar = par.second;
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }

    for(const auto& par: itinerarioSan_Andres)
    {
        int orden = par.first;
        string lugarAVisitar = par.second;
        cout << "El" << orden << "lugar a visitar es: " << lugarAVisitar << endl;
    }
    
    return 0;
}

// Función no utilizada en el código principal
void AgregarDestinoALista(){
    list<string> listaFamiliar = {};

    string desicionViaje;
    cout << "Si desea agregar a la lista de viajes familiares, escriba a continuacion el destino que desea agregar " << endl;
    cin >> desicionViaje;
    
    listaFamiliar.push_back(desicionViaje);

    cout << listaFamiliar << endl;
}
