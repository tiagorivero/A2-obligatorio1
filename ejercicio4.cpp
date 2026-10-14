#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HeapBinario.h"
#include "tads/HeapBinario.cpp"
#include "tads/GrafoLista.cpp"

using namespace std;

struct Modulo{
    int numero;
    int prioridad;
};

bool comparar(Modulo a, Modulo b)
{
    if(a.prioridad == b.prioridad)
    {
        return a.numero < b.numero;
    }
    return a.prioridad < b.prioridad;
}

int main()
{
    int V, A;
    cin >> V >> A;

    int* prioridad = new int[V + 1];
    for(int i = 1; i <= V; i++)
    {
        cin >> prioridad[i];
    }

    GrafoLista* grafo = new GrafoLista(true, false, V);
    int* cantDependencias = new int[V + 1]();
    for(int i = 0; i < A; i++)
    {
        int u, v;
        cin >> u >> v;
        grafo->agregarArista(u, v);
        cantDependencias[v]++;
    }

    Heap<Modulo>* heap = new Heap<Modulo>(V, comparar);
    for(int i = 1; i <= V; i++)
    {
        if(cantDependencias[i] == 0)
        {
            Modulo nuevo;
            nuevo.numero = i;
            nuevo.prioridad = prioridad[i];
            heap->insertar(nuevo);
        }
    }

    int* resultado = new int[V];
    int cantCompilados = 0;
    while(!heap->estaVacio())
    {
        Modulo actual = heap->tope();
        heap->eliminarTope();
        resultado[cantCompilados] = actual.numero;
        cantCompilados++;

        Arista* ady = grafo->adyacentes(actual.numero);
        while(ady)
        {
            cantDependencias[ady->destino]--;
            if(cantDependencias[ady->destino] == 0)
            {
                Modulo nuevo;
                nuevo.numero = ady->destino;
                nuevo.prioridad = prioridad[ady->destino];
                heap->insertar(nuevo);
            }
            ady = ady->sig;
        }
    }

    if(cantCompilados < V)
    {
        cout << "imposible" << "\n";
    }
    else
    {
        for(int i = 0; i < V; i++)
        {
            cout << resultado[i] << "\n";
        }
    }

    delete[] prioridad;
    delete[] cantDependencias;
    delete[] resultado;
    delete heap;
    delete grafo;

    return 0;
}