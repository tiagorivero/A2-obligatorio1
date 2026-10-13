#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HeapBinario.h"
#include "tads/HeapBinario.cpp"

using namespace std;

bool comparar(long long a, long long b)
{
    return a < b;
}

int main()
{
    int N;
    cin >> N;
    Heap<long long>* heap = new Heap<long long>(N, comparar);

    for (int i = 0; i < N; i++) {
        long long tamaño;
        cin >> tamaño;
        heap->insertar(tamaño);
    }

    long long costoTotal = 0;
    int cantidadDisponibles = N;

    while (cantidadDisponibles > 1) {
        long long menor1 = heap->tope();
        heap->eliminarTope();

        long long menor2 = heap->tope();
        heap->eliminarTope();

        long long nuevo = menor1 + menor2;
        costoTotal += nuevo;

        heap->insertar(nuevo);
        cantidadDisponibles--;
    }

    cout << costoTotal << "\n";
    delete heap;

    return 0;
}