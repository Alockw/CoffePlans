#include <iostream>
#include <map>
#include <set>

// INTELECTUAL

using namespace std;

class amigo {
    public:
        string nombre;
        set<string> destinos;
        map<string, string> atraccionesXdestino; // este string contiene el nombre del destino
        map<string, string> destinosXpersona; // este string contiene el nombre de la persona
        map<string, string> fechasXdestino; // este estring contiene la fecha

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
            fechasXdestino[destinox].insert(fechax);
        };
    };

    // metodo para relacionar un destino con una persona
    void personaDestino(nombre, string destinox){
        // se checa si el destino existe
        auto it = destinos.find(destinox);
        if(it != destinos.end()){
            // si existe el destino, entonces procedemos a relacionar la persona con el destino
            destinosXpersona[nombre].insert(destinox);
        };
    };

    // relacionar atracciones con destinos
    void atraccionDestino(string atraccionx, string destinox){
        // se checa si el destino existe
        auto it = destinos.find(destinox);
        if(it != destinos.end()){
            // si existe el destino, entonces procedemos a relacionar la atraccion con el destino
            atraccionesXdestino[destinox].insert(atraccionx);
        };
    };

    // impresion de destinoXpersona
    void imprimirDestinoXpersona(){
        for(const auto &destino : destinosXpersona){
            string clave = destino.first;
            string valor = destino.second;
            cout << clave << " : " << valor << endl;
        };
    };

    // impresion de atraccionesXdestino
    void imprimirAtraccionesXdestino(){
        for(const auto &atraccion : atraccionesXdestino){
            string clave = atraccion.first;
            string valor = atraccion.second;
            cout << clave << " : " << valor << endl;
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

    // checa si el destino que tiene este amigo, ya se encuentra en el set de otro amigo
    bool multiDestino(string destinox, amigo.destinos){
        auto it = amigo.destinos.find(destinox);
        if(it != amigo.destinos.end()){
            return true;
        }else{
            return false;
        };
    };
};