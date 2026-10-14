#include <iostream>
#include <cassert>

struct Arista{
    int origen;
    int destino;
    int peso;
    Arista* sig;
    Arista(int unOrigen, int unDestino, int unPeso, Arista* unSig = NULL)
    {
        this->origen = unOrigen;
        this->destino = unDestino;
        this->peso = unPeso;
        this->sig = unSig;
    };
};

class GrafoLista{
private:
    bool dirigido;
    bool ponderado;
    int cantidadVertices;
    Arista** vertices;

public:
    GrafoLista(bool esDirigido, bool esPonderado, int cantV)
    {
        this->dirigido = esDirigido;
        this->ponderado = esPonderado;
        this->cantidadVertices = cantV;
        vertices = new Arista*[cantV + 1]();
    }
    ~GrafoLista()
    {
        for(int i = 0; i <= cantidadVertices; i++)
        {
            Arista* actual = vertices[i];
            while(actual != NULL)
            {
                Arista* siguiente = actual->sig;
                delete actual;
                actual = siguiente;
            }
        }
        delete[] vertices;
    }
    void agregarArista(int origen, int destino, int peso = 1)
    {
        assert(ponderado || peso == 1);
        Arista* nuevaArista = new Arista(origen, destino, peso);
        nuevaArista->sig = vertices[origen];
        vertices[origen] = nuevaArista;

        if(!dirigido)
        {
            vertices[destino] = new Arista(destino, origen, peso, vertices[destino]);
        }
    }

    Arista* adyacentes(int vertice)
    {
        return vertices[vertice];
    }
    
    int cantVertices()
    {
        return this->cantidadVertices;
    }
};