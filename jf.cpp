#include <iostream>
#include <map>
#include <set>
#include <vector>

// INTELECTUAL

using namespace std;

class amigo {
    public:
        string nombre;
        set<string> destinos;
        map<int, string> fechas;
        map<string, vector<string>> atraccionesXdestino; // este string contiene el nombre del destino
        map<string, string> destinosXpersona; // este string contiene el nombre de la persona
        map<string, string> fechasXdestino; // este estring contiene la fecha

        // destinos y fechas automatizadas
        set<string> destinosEU;
        set<string> destinosAS;
        set<string> destinosAM;
        set<string> destinosAF;
        set<string> destinosOC;
        map<int, string> fechasAUT;

    // Constructor
    amigo(){

    }

    // set y get
    void setNombre(string nombrex){
        nombre = nombrex;
    };

    string getNombre(){
        return nombre;
    };

    // metodos

    void registroEU(){
        destinosEU.insert("Monaco");
        destinosEU.insert("Roma");
        destinosEU.insert("Frankfurt");
        destinosEU.insert("Atenas");
        destinosEU.insert("Barcelona");
    };

    void registroAS(){
        destinosEU.insert("Ankara");
        destinosEU.insert("Dubai");
        destinosEU.insert("Taiwan");
        destinosEU.insert("Beijing");
        destinosEU.insert("Kyoto");
    };

    void registroAM(){
        destinosEU.insert("Cartagena");
        destinosEU.insert("Lima");
        destinosEU.insert("Rio de la plata");
        destinosEU.insert("Rio de janeiro");
        destinosEU.insert("La patagonia");
    };

    void registroAF(){
        destinosEU.insert("Johannesburgo");
        destinosEU.insert("El Cairo");
        destinosEU.insert("Nairobi");
        destinosEU.insert("Durban");
        destinosEU.insert("Botsuana");
    };

    void registroOC(){
        destinosEU.insert("Fiji");
        destinosEU.insert("Sidney");
        destinosEU.insert("Melbourne");
        destinosEU.insert("Auckland");
        destinosEU.insert("Newcastle");
    };

    void registroFechas(){
        fechasAUT[1] = 2024-09-25;
        fechasAUT[2] = 2024-09-28;
        fechasAUT[3] = 2024-09-31;
        fechasAUT[4] = 2024-10-02;
        fechasAUT[5] = 2024-10-06;
    };

    // CREAR METODO PARA AGREGAR FECHAS

    void agregarDestino(string destinox){
        if (destinos.find(destinox) == destinos.end()){
            destinos.insert(destinox);
        }else{
            cout << "El destino ya existe" << endl;
        };
    };

    // metodo para proponer fecha para un destino
    void proponerFecha(string destinox, string fechax){
        // utilizamos find para buscar si existe el destino
        auto it = destinos.find(destinox);
        if(it != destinos.end()){
            // si existe el destino, entonces procedemos a agregar la fecha
            // pero primero verificamos si existen fechas que se crucen
            for (const auto& destino : fechasXdestino){
                string clave = destino.first();
                string valor = destino.second();
                if (valor != string fechax){
                    fechasXdestino[destinox] = fechax
                }else{
                    cout << "La fecha ya existe" << endl;
                };
            };
        };
    };


    // metodo para relacionar un destino con una persona
    void personaDestino(string destinox){
        // se checa si el destino existe
        auto it = destinos.find(destinox);
        if(it != destinos.end()){
            // si existe el destino, entonces procedemos a relacionar la persona con el destino
            destinosXpersona[getNombre()] = destinox;
        };
    };

    // relacionar atracciones con destinos
    void atraccionDestino(string atraccionx, string destinox){
        // se checa si el destino existe
        auto it = destinos.find(destinox);
        if(it != destinos.end()){
            // si existe el destino, entonces procedemos a relacionar la atraccion con el destino
            atraccionesXdestino[destinox].push_back(atraccionx);
        };
    };

    // impresion de atraccionesXdestino
    void imprimirAtraccionesXdestino(){
        for(const auto &atraccion : atraccionesXdestino){
            string clave = atraccion.first;
            // como second es un vector, entonces lo recorremos
            for(const auto &atraccion2 : atraccion.second){
                string valor = atraccion2;
                cout << valor << endl;
            };
            cout << clave << endl;
        };
    };

    // impresion de fechasXdestino
    void imprimirFechasXdestino(){
        for(const auto &fecha : fechasXdestino){
            string clave = fecha.first;
            string valor = fecha.second;
            cout << clave << " : " << valor << endl;
        };
    };
};

int main(){
    

    return 0;
};
