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
        cout << "Ingrese el pais del destino: ";
        cin >> nuevoViaje.destino.pais;
        cout << "Ingrese la ciudad del destino: ";
        cin >> nuevoViaje.destino.ciudad;
        string lugar;
        cout<<nuevoViaje.destino.ciudad<<endl;
        cout << "Ingrese los lugares a visitar (separados por comas): \n";
        getline(cin, lugar);
        stringstream ss(lugar);
        string temp;
        while (getline(ss, temp, ','))
        {
            nuevoViaje.destino.lugaresAVisitar.insert(temp);
        }
        cout << "Ingrese la duración del viaje en dias: ";
        cin >> nuevoViaje.duracion;
        for (int i = 0; i <= nuevoViaje.duracion; ++i)
        {
            cout << "Ingrese el plan para el dia " << i << ": ";
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
            cout << "Fecha: " << viaje.second.fecha << ", Destino: " << viaje.second.destino.pais << " " << viaje.second.destino.ciudad << ", Duracion: " << viaje.second.duracion << " dias\n";
            cout << "Planes diarios:\n";
            for (const auto &plan : viaje.second.planDia)
            {
                cout << "Dia " << plan.first << ": " << plan.second << "\n";
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
            cout << "//////////////////////////////////////////////////////////////////////////////////////";
            cout << "\nBienvenido a Planes Cooffe, la mejor plataforma para planear tus vacaciones:\n";
            cout << "/&/&/&/&/&/&/&/&/&/&/&/&/&/&/&/&/&/&$\n";
            cout << "\nQue es lo que deseas hacer?:\n";
            cout << "1. Agregar amigo\n";
            cout << "2. Planificar viaje\n";
            cout << "3. Consultar destinos de un amigo\n";
            cout << "4. Encontrar miembros que tienen planificado visitar un destino específico\n";
            cout << "5. Recopilar planes de viaje\n";
            cout << "6. Ver recomendaciones\n";
            cout << "7. Salir\n";
            cout << "//////////////////////////////////////////////////////////////////////////////////////\n";
            cout << "Ingrese su opcion: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                agregarAmigo();
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
                recopilarPlanes();
                break;
            case 6:
                mostrarRecomendaciones();
                break;
            case 7:
                cout << "Saliendo del sistema de viajes.\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
            }
        } while (opcion != 7);
    }
};
// Función principal para ejecutar el sistema de viajes
int main()
{
    SistemaViajes sistema;
    sistema.mostrarMenu();
    return 0;
}