#include <iostream>
using namespace std;

template<typename K, typename V>
class HashAbierto
{
private:
    struct Nodo {
        K clave;
        V valor;
        Nodo* siguiente;
        Nodo( K nuevaClave, V nuevoValor): clave(nuevaClave), valor(nuevoValor), siguiente(NULL) {}
    };

    Nodo** tabla;
    int cantBuckets;
    int (*funcionDeHash)(K);
    bool(*sonIguales)(K,K);

    int obtenerIndice(K clave)
    {
        int h = funcionDeHash(clave) % cantBuckets;
        if (h < 0){
            h += cantBuckets;
        }
        return h;
    }

    Nodo* buscar(K clave)
    {
        int indice = obtenerIndice(clave);
        Nodo* actual = tabla[indice];

        while(actual != NULL && !sonIguales(actual->clave, clave)){ 
            actual = actual->siguiente;
        }

        return actual;
    }

public:
    HashAbierto(int nuevoCantBuckets, int (*funcionDeHashParam)(K), bool (*sonIgualesParam)(K,K)) 
    {
        cantBuckets = nuevoCantBuckets;
        sonIguales = sonIgualesParam;
        funcionDeHash = funcionDeHashParam;
        tabla = new Nodo*[cantBuckets]();
    }

    ~HashAbierto() 
    {   
        for(int i = 0; i < cantBuckets; i++){
            Nodo* actual = tabla[i];
            while (actual != NULL){
                Nodo* siguiente = actual->siguiente;
                delete actual;
                actual = siguiente;
            }
            tabla[i] = NULL;
        }
        delete[] tabla;
        tabla = NULL;
    }

    void insertar(K clave, V valor){
        Nodo* existe = buscar(clave);
        if(existe != NULL){
            existe->valor = valor;
            return;
        }

        int indice = obtenerIndice(clave);
        Nodo* nuevo = new Nodo(clave, valor);
        nuevo->siguiente = tabla[indice];
        tabla[indice] = nuevo;
    }

    void eliminar(K clave){
        int indice = obtenerIndice(clave);
        Nodo* actual = tabla[indice];
        Nodo* anterior = NULL;

        while(actual != NULL && !sonIguales(actual->clave, clave)) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if(actual != NULL){
            if(anterior == NULL){
                tabla[indice] = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
        }
    }

    V* recuperar(K clave){
        Nodo* nodo = buscar(clave);
        if (nodo == NULL){
            return NULL;
        }
        return &nodo->valor;
    }

    bool existe(K clave){
        return buscar(clave) != NULL;
    }
};
