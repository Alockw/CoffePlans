#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct Destino
{
    string pais;
    string ciudad;
    set<string> lugaresAVisitar;
};

struct Viaje
{
    string fecha;
    string tipoTransporte;
    string horaSalida;
    double costoTransporte;
    Destino destino;
    int duracion;
    map<int, string> planDia;
};

struct PlanViaje
{
    int id;
    string nombreAmigo;
    string fecha;
    string pais;
    string ciudad;
    map<int, string> planDia;
};

struct Amigo
{
    string nombre;
    map<string, Viaje> planesViaje;
};

class SistemaViajes
{
private:
    map<string, Destino> destinos;
    map<string, Amigo> amigos;

public:
    SistemaViajes() {}

    void agregarRecomendaciones()
    {
        Viaje recomendacion1;
        // Configurar recomendacion1 con datos de ejemplo
        amigos["Recomendaciones"].planesViaje["2024-05-15"] = recomendacion1;
    }

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

    void planificarViaje()
{
    string nombreAmigo;
    cout << "Ingrese el nombre del amigo para quien está planificando el viaje: ";
    cin >> nombreAmigo;

    string fecha;
    cout << "Ingrese la fecha del viaje (formato YYYY-MM-DD): ";
    cin >> fecha;

    string tipoTransporte;
    cout << "Ingrese el tipo de transporte (por ejemplo, avión, tren, coche): ";
    cin >> tipoTransporte;

    string horaSalida;
    cout << "Ingrese la hora de salida (formato HH:MM): ";
    cin >> horaSalida;

    double costoTransporte;
    cout << "Ingrese el costo del transporte: ";
    cin >> costoTransporte;

    Destino destino;
    cout << "Ingrese el país del destino: ";
    cin >> destino.pais;
    cout << "Ingrese la ciudad del destino: ";
    cin >> destino.ciudad;

    set<string> lugaresAVisitar;
    cout << "Ingrese los lugares a visitar separados por comas: ";
    string lugares;
    getline(cin >> ws, lugares); // Limpiar el buffer de entrada
    stringstream ss(lugares);
    string lugar;
    while (ss >> lugar) {
        lugaresAVisitar.insert(lugar);
    }

    int duracion;
    cout << "Ingrese la duración del viaje en días: ";
    cin >> duracion;

    map<int, string> planDia;
    cout << "Ingrese los planes diarios separados por día y actividad (formato DIA:ACTIVIDAD): ";
    string diaActividad;
    while (cin >> diaActividad) {
        stringstream ssDiaActividad(diaActividad);
        int dia;
        string actividad;
        ssDiaActividad >> dia >> actividad;
        planDia[dia] = actividad;
    }

    Viaje viaje;
    viaje.fecha = fecha;
    viaje.tipoTransporte = tipoTransporte;
    viaje.horaSalida = horaSalida;
    viaje.costoTransporte = costoTransporte;
    viaje.destino = destino;
    viaje.duracion = duracion;
    viaje.planDia = planDia;

    amigos[nombreAmigo].planesViaje[fecha] = viaje;

    cout << "Viaje planificado exitosamente.\n";
}

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

    void encontrarMiembrosDestino(const string &nombreDestino)
{
    cout << "Encontrando miembros que planean visitar " << nombreDestino << "...\n";

    for (const auto &amigo : amigos)
    {
        for (const auto &viaje : amigo.second.planesViaje)
        {
            if (viaje.second.destino.pais == nombreDestino || viaje.second.destino.ciudad == nombreDestino)
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

    cout << "Fin de la búsqueda.\n";
}

    void agregarAmigo()
    {
        Amigo nuevoAmigo;
        cout << "Ingrese el nombre del amigo: ";
        cin >> nuevoAmigo.nombre;
        amigos[nuevoAmigo.nombre] = nuevoAmigo;
        cout << "Amigo agregado exitosamente.\n";
    }

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

    void recopilarPlanesPorOrden()
    {
        queue<PlanViaje> colaPlanes;
        int id = 0;

        for (const auto &amigo : amigos)
        {
            for (const auto &viaje : amigo.second.planesViaje)
            {
                PlanViaje plan;
                plan.id = id++;
                plan.nombreAmigo = amigo.first;
                plan.fecha = viaje.second.fecha;
                plan.pais = viaje.second.destino.pais;
                plan.ciudad = viaje.second.destino.ciudad;
                plan.planDia = viaje.second.planDia;

                colaPlanes.push(plan);
            }
        }

        while (!colaPlanes.empty())
        {
            PlanViaje planActual = colaPlanes.front();
            cout << "Amigo: " << planActual.nombreAmigo << ", Fecha: " << planActual.fecha << ", Destino: " << planActual.pais << " " << planActual.ciudad << "\n";
            cout << "Planes diarios:\n";
            for (const auto &plan : planActual.planDia)
            {
                cout << "Día " << plan.first << ": " << plan.second << "\n";
            }
            colaPlanes.pop();
        }
    }

    void mostrarMenu()
    {
        int opcion;
        do
        {
            cout << "Bienvenido a Planes Cooffe:\n";
            cout << "\nQue es lo que deseas hacer?:\n";
            cout << "1. Agregar amigo\n";
            cout << "2. Planificar viaje\n";
            cout << "3. Consultar destinos de un amigo\n";
            cout << "4. Encontrar miembros que tienen planificado visitar un destino específico\n";
            cout << "5. Recopilar planes de viaje\n";
            cout << "6. Ver planes por orden de creacion\n";
            cout << "7. Salir\n";
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
                recopilarPlanesPorOrden();
                break;
            case 7:
                cout << "Saliendo del sistema de viajes.\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
            }
        } while (opcion!= 7);
    }
};

int main()
{
    SistemaViajes sistema;
    sistema.agregarRecomendaciones();
    sistema.mostrarMenu();
    return 0;
}
