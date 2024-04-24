#include <iostream>
#include <vector>
using namespace std;
int encontrarMaximo (const vector<int> & lista){
    int maximo=lista[0];
    for(int i=1; i<lista.size(); i++){
        if(lista[i]>maximo){
            maximo=lista[i];
        }
    }
    return maximo;
}
int main(){
    vector<int>lista={1,2,3,4,5,6,7,8,9,10};
    int resultado=encontrarMaximo(lista);
    cout<<"el maximo elemento en la lista es: "<< resultado <<endl;
    return 0;
}
/*
1*se esta buscando el numero mas grande en una lista de numeros
2*lo mas importante es la funcion encontrarmaximo y el ciclo que tiene adentro
3*Dentro del bucle, se realiza una serie de operaciones básicas por cada elemento en la lista:
Asignación de maximo=lista[0]: 1 operación.
Inicialización de i=1: 1 operación.
Comparación i<lista.size(): 1 operación por iteración.
Incremento de i++: 1 operación por iteración.
Comparación lista[i]>maximo: 1 operación por iteración.
Asignación maximo=lista[i] en caso de que la condición sea verdadera: 1 operación por iteración.
4*La complejidad del algoritmo se expresa en términos de la cantidad de operaciones realizadas en función del tamaño de la entrada
dado que el bucle itera una vez por cada elemento en la lista, la complejidad es proporcional al tamaño de la lista, lo que se representa como O(n),
donde 'n' es el número de elementos en la lista
5*Solo hay un bucle en el código, el cual recorre la lista una vez
6*La función principal aquí es encontrarMaximo
7*Utilizamos un enfoque simple de búsqueda lineal para encontrar el máximo elemento en la lista.
8*No necesitamos ejecutar el código con diferentes tamaños de entrada para entender su complejidad
podemos determinarla mediante el análisis del código
9*Con una complejidad lineal, esperamos que el tiempo de ejecución
aumente de manera lineal a medida que aumenta el tamaño de la lista
10*Este algoritmo es eficiente para listas de tamaño moderado. Sin embargo,
si el tamaño de la lista crece significativamente, podríamos considerar algoritmos más eficientes
11*podriamos optimiar el codigo con un tipo de busqueda binaria si la lista esta ordenada
pero no lo veo necesario ya que este esta perfecto para un tamaño no muy grande 
*/