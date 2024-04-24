#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Estructura para almacenar información sobre un destino
struct Destino
{
    string pais;
    string ciudad;
    set<string> lugaresAVisitar; // Conjunto para evitar duplicados
};

// Estructura para almacenar información sobre un viaje
struct Viaje
{
    string fecha;
    string tipoTransporte;
    string horaSalida;
    double costoTransporte;
    Destino destino;
    int duracion;             // Duración del viaje en días
    map<int, string> planDia; // Planes diarios del viaje, donde la clave es el día y el valor es el plan
};

// Estructura para almacenar información sobre un amigo
struct Amigo
{
    string nombre;
    map<string, Viaje> planesViaje; // Mapa para almacenar viajes por fecha
};

class SistemaViajes
{
private:
    map<string, Destino> destinos; // Mapa para almacenar destinos por nombre del planificador
    map<string, Amigo> amigos;     // Mapa para almacenar amigos por nombre

public:
    SistemaViajes()
    {
        // Inicializar con recomendaciones de viajes predeterminadas
        agregarRecomendaciones();
    }

    // Función para agregar recomendaciones de viajes predeterminadas
    void agregarRecomendaciones()
    {
        Viaje recomendacion1;
        recomendacion1.fecha = "2024-05-15";
        recomendacion1.tipoTransporte = "Avión";
        recomendacion1.horaSalida = "08:00";
        recomendacion1.costoTransporte = 500.0;
        recomendacion1.destino.pais = "España";
        recomendacion1.destino.ciudad = "Barcelona";
        recomendacion1.destino.lugaresAVisitar.insert("Sagrada Familia");
        recomendacion1.destino.lugaresAVisitar.insert("Park Güell");
        recomendacion1.duracion = 5;
        recomendacion1.planDia[1] = "Visitar Sagrada Familia";
        recomendacion1.planDia[2] = "Visitar Park Güell";
        recomendacion1.planDia[3] = "Explorar la ciudad";
        recomendacion1.planDia[4] = "Visitar museos";
        recomendacion1.planDia[5] = "Regreso";

        Amigo amigoRecomendacion;
        amigoRecomendacion.nombre = "Recomendaciones";
        amigoRecomendacion.planesViaje[recomendacion1.fecha] = recomendacion1;
        amigos["Recomendaciones"] = amigoRecomendacion;
    }
    // Función para mostrar las recomendaciones de viajes
    void mostrarRecomendaciones()
    {
        if (amigos.find("Recomendaciones") == amigos.end())
        {
            cout << "No hay recomendaciones disponibles.\n";
            return;
        }
        cout << "Recomendaciones de viajes:\n";
        for (const auto &viaje : amigos["Recomendaciones"].planesViaje)
        {
            cout << "Fecha: " << viaje.second.fecha << ", Destino: " << viaje.second.destino.pais << " " << viaje.second.destino.ciudad << ", Duración: " << viaje.second.duracion << " días\n";
            cout << "Planes diarios:\n";
            for (const auto &plan : viaje.second.planDia)
            {
                cout << "Día " << plan.first << ": " << plan.second << "\n";
            }
        }
    }
    // Función para agregar un nuevo destino
    void agregarDestino()
    {
        Destino nuevoDestino;
        cout << "Ingrese el país del destino: ";
        cin >> nuevoDestino.pais;
        cout << "Ingrese la ciudad del destino: ";
        cin >> nuevoDestino.ciudad;
        string lugar;
        cout << "Ingrese los lugares a visitar (separados por comas): ";
        getline(cin, lugar);
        stringstream ss(lugar);
        string temp;
        while (getline(ss, temp, ','))
        {
            nuevoDestino.lugaresAVisitar.insert(temp);
        }
        destinos[nuevoDestino.pais + " " + nuevoDestino.ciudad] = nuevoDestino;
        cout << "Destino agregado exitosamente.\n";
    }

    // Función para planificar un nuevo viaje
    void planificarViaje()
    {
        string nombreAmigo;
        cout << "Ingrese el nombre del amigo: ";
        cin >> nombreAmigo;
        if (amigos.find(nombreAmigo) == amigos.end())
        {
            cout << "Amigo no encontrado.\n";
            return;
        }
        Viaje nuevoViaje;
        cout << "Ingrese la fecha del viaje (YYYY-MM-DD): ";
        cin >> nuevoViaje.fecha;
        cout << "Ingrese el tipo de transporte: ";
        cin >> nuevoViaje.tipoTransporte;
        cout << "Ingrese la hora de salida: ";
        cin >> nuevoViaje.horaSalida;
        cout << "Ingrese el costo del transporte: ";
        cin >> nuevoViaje.costoTransporte;
        cout << "Ingrese el país del destino: ";
        cin >> nuevoViaje.destino.pais;
        cout << "Ingrese la ciudad del destino: ";
        cin >> nuevoViaje.destino.ciudad;
        string lugar;
        cout << "Ingrese los lugares a visitar (separados por comas): ";
        getline(cin, lugar);
        stringstream ss(lugar);
        string temp;
        while (getline(ss, temp, ','))
        {
            nuevoViaje.destino.lugaresAVisitar.insert(temp);
        }
        cout << "Ingrese la duración del viaje en días: ";
        cin >> nuevoViaje.duracion;
        for (int i = 1; i <= nuevoViaje.duracion; ++i)
        {
            cout << "Ingrese el plan para el día " << i << ": ";
            getline(cin, nuevoViaje.planDia[i]);
        }
        amigos[nombreAmigo].planesViaje[nuevoViaje.fecha] = nuevoViaje;
        cout << "Viaje planificado exitosamente.\n";
    }

    // Función para consultar los destinos de un amigo
    void consultarDestinosAmigo(const string &nombreAmigo)
    {
        if (amigos.find(nombreAmigo) == amigos.end())
        {
            cout << "Amigo no encontrado.\n";
            return;
        }
        cout << "Destinos de " << nombreAmigo << ":\n";
        for (const auto &viaje : amigos[nombreAmigo].planesViaje)
        {
            cout << "Fecha: " << viaje.second.fecha << ", Destino: " << viaje.second.destino.pais << " " << viaje.second.destino.ciudad << ", Duración: " << viaje.second.duracion << " días\n";
            cout << "Planes diarios:\n";
            for (const auto &plan : viaje.second.planDia)
            {
                cout << "Día " << plan.first << ": " << plan.second << "\n";
            }
        }
    }

    // Función para encontrar miembros que tienen planificado visitar un destino específico
    void encontrarMiembrosDestino(const string &nombreDestino)
    {
        if (destinos.find(nombreDestino) == destinos.end())
        {
            cout << "Destino no encontrado.\n";
            return;
        }
        cout << "Miembros que tienen planificado visitar " << nombreDestino << ":\n";
        for (const auto &amigo : amigos)
        {
            for (const auto &viaje : amigo.second.planesViaje)
            {
                if (viaje.second.destino.pais + " " + viaje.second.destino.ciudad == nombreDestino)
                {
                    cout << amigo.first << "\n";
                }
            }
        }
    }

    // Función para agregar un nuevo amigo
    void agregarAmigo()
    {
        Amigo nuevoAmigo;
        cout << "Ingrese el nombre del amigo: ";
        cin >> nuevoAmigo.nombre;
        amigos[nuevoAmigo.nombre] = nuevoAmigo;
        cout << "Amigo agregado exitosamente.\n";
    }

    // Función para recopilar todos los planes de viaje sin duplicados
    void recopilarPlanes()
    {
        cout << "Planes de viaje:\n";
        for (const auto &amigo : amigos)
        {
            for (const auto &viaje : amigo.second.planesViaje)
            {
                cout << "Amigo: " << amigo.first << ", Fecha: " << viaje.second.fecha << ", Destino: " << viaje.second.destino.pais << " " << viaje.second.destino.ciudad << ", Duración: " << viaje.second.duracion << " días\n";
                cout << "Planes diarios:\n";
                for (const auto &plan : viaje.second.planDia)
                {
                    cout << "Día " << plan.first << ": " << plan.second << "\n";
                }
            }
        }
    }

    // Función para mostrar el menú principal y manejar las opciones seleccionadas por el usuario
    void mostrarMenu()
    {
        int opcion;
        do
        {
            cout << "\nBienvenido a Planes Cooffe, la mejor plataforma para diseñar tus vacaciones:\n";
            cout << "1. Agregar destino\n";
            cout << "2. Planificar viaje\n";
            cout << "3. Consultar destinos de un amigo\n";
            cout << "4. Encontrar miembros que tienen planificado visitar un destino específico\n";
            cout << "5. Agregar amigo\n";
            cout << "6. Recopilar planes de viaje\n";
            cout << "7. Ver recomendaciones\n";
            cout << "8. Salir\n";
            cout << "Ingrese su opción: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                agregarDestino();
                break;
            case 2:
                planificarViaje();
                break;
            case 3:
            {
                string nombreAmigo;
                cout << "Ingrese el nombre del amigo: ";
                cin >> nombreAmigo;
                consultarDestinosAmigo(nombreAmigo);
            }
            break;
            case 4:
            {
                string nombreDestino;
                cout << "Ingrese el nombre del destino: ";
                cin >> nombreDestino;
                encontrarMiembrosDestino(nombreDestino);
            }
            break;
            case 5:
                agregarAmigo();
                break;
            case 6:
                recopilarPlanes();
                break;
            case 7:
                mostrarRecomendaciones();
                break;
            case 8:
                cout << "Saliendo del sistema de viajes.\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
            }
        } while (opcion != 8);
    }
};
// Función principal para ejecutar el sistema de viajes
int main()
{
    SistemaViajes sistema;
    sistema.mostrarMenu();
    return 0;
}
/*
1*el porblema principal es el hacer un sistema para poder planear un plan de viaje 
ya sea con amigos o familia con destino y que se ajuste a el usuario 
2*estas son las partes criticas del codigo :
Planificación de viajes: Esto incluye la función planificarViaje(), donde se solicita información 
sobre el viaje al usuario y se almacena en la estructura de datos.
Consulta de destinos de un amigo: Esta funcionalidad está cubierta por la función consultarDestinosAmigo(),
donde se muestra la información de los destinos de un amigo dado.
Búsqueda de miembros que tienen planificado visitar un destino específico: Esto se realiza en la función encontrarMiembrosDestino(), donde se busca en los planes
de viaje de todos los amigos para encontrar quién ha planeado visitar un destino específico.
Recopilación de planes de viaje: Se realiza en la función recopilarPlanes(), donde se muestran todos los planes de viaje almacenados en el sistema.
5*Bucle en la función planificarViaje():
Itera sobre los días del viaje, lo que está determinado por la duración del viaje (denotada como "d").
por lo tanto, la complejidad de este bucle es O(d), donde "d" es la duración del viaje.
Bucle en la función consultarDestinosAmigo():
Itera sobre los viajes de un amigo dado, lo que está relacionado con el número de viajes que tiene ese amigo (denotado como "m")
por lo tanto, la complejidad de este bucle es O(m), donde "m" es el número de viajes del amigo.
Bucle en la función encontrarMiembrosDestino():
Itera sobre todos los amigos y todos sus viajes, lo que está relacionado con el número total de amigos 
("n") y el número promedio de viajes por amigo ("m") por lo tanto, la complejidad de este bucle es O(n * m), 
donde "n" es el número de amigos y "m" es el número promedio de viajes por amigo.
Bucle en la función recopilarPlanes():
Similar al bucle anterior, itera sobre todos los amigos y todos sus viajes, 
lo que tiene una complejidad de O(n * m), donde "n" es el número de amigos y "m" es el número promedio de viajes por amigo.
6*en el codigo no hay funciones reursivas pero si hay funciones que llaman a otras funciones
comoLa función mostrarMenu() llama a otras funciones dependiendo de la opción seleccionada por el usuario, como agregarDestino(), planificarViaje(), consultarDestinosAmigo(),
encontrarMiembrosDestino(), agregarAmigo(), recopilarPlanes(), y mostrarRecomendaciones()
7*algoritmo de búsqueda lineal. Este algoritmo consiste en recorrer secuencialmente una lista de elementos hasta
encontrar el elemento buscado o llegar al final de la listapor ejemplo, para buscar amigos por su nombre dentro de la lista de amigos
la complejidad de este algoritmo es lineal O(n), donde "n" es el número total de elementos en la lista
8*el codigo no entra mucho en conflicto con una catidad de planes no tan amplia pero cuando ya hay demasiados 
planes creados a la vez que dia se demora mas en analizar y lanzar algunos resultados ejemplo con unos 
10 planes cada uno con 5 dias se demora un poco pero no demasiado pero si es un plan con mas de 20 dias si se demora un poco mas
9*se podria tomar como se sabe que es un algotirmo linean entonconces se sabe que entre mas grande 
sean los planes osaese los dias o entre mas cantidad de amigos sean se necesitara tomar mas recursos del sistema 
que podrian llevar a un peor funcionamiento de este sistema 
10* el sistema tiene una complejidad que se podria tomar como omega Ω ya que amenos que sea un plan o 
muchas personas siempre tendra buen rendimiento y no daria problema de tiempo ni de recursos muy grande haceindo que 
sea un sistema bien optimizado en lo que se encuentra para su proposito pero con obvias mejoras posoibles para este mismo 
11*se podria optimizar al usar mapas ordenados en lugar de mapas no ordenados para almacenar
los destinos y los amigos esto haria mejor los metodos de busqueda y consulta 
y en la busqueda de amigos por nombre se podria mejorar con un metodo de busqueda binaria
si la lista de amigos estubiera ordenada por orden alfabetico 
tambien se podria evitar el salto de linea en algunas entredas del usuario con un cin.ignore 
para que despues de leer un valor cin no pase eso 
*/