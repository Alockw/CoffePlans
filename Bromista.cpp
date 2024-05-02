#include <iostream>
#include <map>
#include <string>
#include <list>
#include <set>

using namespace std;

int main(){

    SaberMas();

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

    for(const auto& item : listaFamiliar){
        cout << item << " ";
    }
}
int desicionUsuario;
void SaberMas(){
cout << "Si desea conocer los detalles del viaje a Santa Marta, digite 1\n" << endl; 
cout << "Si desea conocer los detalles del viaje a Cali, digite 2\n" << endl;
cout << "Si desea conocer los detalles del viaje a San Andres, digite 3\n" << endl;
cout << "Si desea salir, digite 4\n" << endl;
cin >> desicionUsuario;


if(desicionUsuario == 1){
    cout << "Plan Santa Marta:" << endl;
    cout << "Hora de salida: 9:00 am" << endl;
    cout << "fecha: 2024-06-27";
    cout << "Tipo de transporte: Avión Avianca" << endl;
    cout << "500.0" << endl;
    cout << "Planes: Caminata de 7 horas en taganga, playa Buritaca y el acuario Rodadero." << endl;
}
if(desicionUsuario == 2){
    cout << "Plan Cali:" << endl;
    cout << "Hora de salida: 10:00 am" << endl;
    cout << "fecha: 2024-05-13";
    cout << "Tipo de transporte: Avión Avianca" << endl;
    cout << "300.0" << endl;
    cout << "Planes: Visitar el museo la Tertulia, Bahia Magdalena y Parque Nacional Natural Puracé. " << endl;

}
if(desicionUsuario == 3){
    cout << "Plan San Andres:" << endl;
    cout << "Hora de salida: 5:00 am" << endl;
    cout << "fecha: 2025-01-04";
    cout << "Tipo de transporte: Avión Kayak" << endl;
    cout << "700.0" << endl;
    cout << "Planes: Playa Spratt Bight, Practica snorkel o careteo, El Hoyo Soplador." << endl;

}

if(desicionUsuario == 4){
    cout << "Saliendo de la pagina..." << endl;
}
}


/* Complejidad

Tiempo de Ejecución : La mayor parte del tiempo de ejecución se consume en las operaciones 
de inserción e iteración sobre los conjuntos y mapas. Dado que estas operaciones tienen 
complejidades logarítmicas y lineales, el tiempo total de ejecución será dominado por la 
operación de iteración, que es lineal O(n), donde n es el número total de elementos en 
todos los conjuntos y mapas combinados.

Espacio de Memoria : El espacio de memoria requerido aumenta con el número de elementos 
almacenados en los conjuntos y mapas. La complejidad espacial es directamente proporcional
al número de elementos almacenados, es decir, O(n), donde n es el número total de 
elementos en todos los conjuntos y mapas.


El código tiene una complejidad de tiempo principalmente lineal O(n) debido a las 
operaciones de iteración sobre los conjuntos y mapas, y una espacial de O(n) debido 
al almacenamiento de elementos en estos contenedores. Es importante notar que estas 
complejidades asumen que el número de elementos en los conjuntos y mapas es significativo. 
Para conjuntos y mapas pequeños, las complejidades logarítmicas de las operaciones 
de inserción pueden ser menos relevantes en comparación con la complejidad lineal de las 
operaciones de iteración. */
