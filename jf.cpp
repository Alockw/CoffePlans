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
        map<string, vector<string>> atraccionesXdestino; // este string contiene el nombre del destino
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
    // metodo para agregar destinos a la bolsa global de destinos
    void agregarDestinoGlobal(amigo &amigoG, string destinox){
        // se checa si el destino ya existe en la bolsa global de destinos
        auto it = amigoG.destinos.find(destinox);
        if(it != amigoG.destinos.end()){
            // si el destino no existe, entonces se agrega
            amigoG.destinos.insert(destinox);
        };
    };

    // metodo para proponer fecha para un destino
    void proponerFecha(string destinox, string fechax, const amigo &amigo2){
        // utilizamos find para buscar si existe el destino
        auto it = destinos.find(destinox);
        if(it != destinos.end()){
            // si existe el destino, entonces procedemos a agregar la fecha

            /*
            Las fechas para poder ser ordenadas tienen que escribirse de la siguiente manera:
            "YYYY-MM-DD"
            */

           // primero buscamos si esta fecha ya existe, para esto creamos un for que recorra todos los destinos de amigo2
           // y luego recorremos las fechas de cada destino comparando si la fecha ya existe con la fecha que queremos agregar
            for(auto &destino : amigo2.destinos){
                string clave = destino;
                string valor = amigo2.fechasXdestino[destino];
                if(valor == fechax){
                    cout << "La fecha ya existe" << endl;
                    return;
                }else{
                    fechasXdestino[destinox] = fechax;
                }
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

    // impresion de destinoXpersona
    void imprimirDestinoXpersona(amigo &amigo2){
        cout << "Destinos de " << amigo2.getNombre() << endl;
        for(const auto &destino : amigo2.destinosXpersona){
            string clave = destino.first;
            string valor = destino.second;
            cout << valor << endl;
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

    // checa si el destino que tiene este amigo, ya se encuentra en el set de otro amigo
    string multiDestino(string destinox, amigo &amigo2){
        auto it = amigo2.destinos.find(destinox);
        if(it != amigo2.destinos.end()){
            return "El destino ya existe en otro amigo: " + amigo2.getNombre();
        }else{
            return "El destino no existe en otro amigo";
        };
    };
};

int main(){
    amigo amigo1;
    amigo amigo2;
    amigo amigoGlobal;

    amigo1.setNombre("Juan");
    amigo2.setNombre("Pedro");
    amigoGlobal.setNombre("Global");

    amigo1.agregarDestino("Cancun");
    amigo1.agregarDestino("Acapulco");
    amigo1.agregarDestino("Guadalajara");

    amigo2.agregarDestino("Cancun");
    amigo2.agregarDestino("Bogota");
    amigo2.agregarDestino("Santa Marta");

    amigo1.agregarDestinoGlobal(amigoGlobal, "Cancun");
    amigo1.agregarDestinoGlobal(amigoGlobal, "Acapulco");
    amigo1.agregarDestinoGlobal(amigoGlobal, "Guadalajara");

    amigo2.agregarDestinoGlobal(amigoGlobal, "Cancun");
    amigo2.agregarDestinoGlobal(amigoGlobal, "Bogota");
    amigo2.agregarDestinoGlobal(amigoGlobal, "Santa Marta");

    amigo1.proponerFecha("Cancun", "2021-12-25", amigo2);
    amigo1.proponerFecha("Cancun", "2021-12-26", amigo2);
    amigo1.proponerFecha("Cancun", "2021-12-27", amigo2);

    amigo2.proponerFecha("Cancun", "2021-12-25", amigo1);
    amigo2.proponerFecha("Cancun", "2021-12-26", amigo1);
    amigo2.proponerFecha("Cancun", "2021-12-27", amigo1);


    return 0;
};