#include <cassert>

template<typename T>
class Heap{
    private:
    T* arr;
    int capacidad;
    int ultimoOcupado;

    //PRE: -
    //POS: Retorna true si el primer parametro va antes que el segundo.
    bool (*comparar)(T, T);

    int padre(int pos)
    {
        return pos/2;
    }
    int izq(int pos)
    {
        return pos * 2;
    }
    int der(int pos)
    {
        return pos * 2 + 1;
    }

    void swap(int posA, int posB)
    {
        T aux = arr[posA];
        arr[posA] = arr[posB];
        arr[posB] = aux;
    }

    void flotar(int posActual)
    {
        if(posActual == 1) return;

        int posPadre = padre(posActual);

        if(comparar(arr[posActual], arr[posPadre]))
        {
            swap(posActual, posPadre);
            flotar(posPadre);
        }
    }
    void hundir(int posActual)
    {
        int posHijoIzq = izq(posActual);
        int posHijoDer = der(posActual);

        if(posHijoIzq > ultimoOcupado) return;

        int posMax = posHijoIzq;

        if(posHijoDer <= ultimoOcupado && comparar(arr[posHijoDer], arr[posHijoIzq])){
            posMax = posHijoDer;
        }

        if(comparar(arr[posMax], arr[posActual]))
        {
            swap(posMax, posActual);
            hundir(posMax);
        }
    }

    public:

    Heap(int unaCapacidad, bool (*comparar)(T, T))
    {
        this->arr = new T[unaCapacidad + 1]();
        this->capacidad = unaCapacidad;
        this->comparar = comparar;
        this->ultimoOcupado = 0;
    }

    T tope(){
        assert(!estaVacio());
        return arr[1];
    }
    
    void eliminarTope()
    {
        assert(!estaVacio());
        arr[1] = arr[ultimoOcupado];
        ultimoOcupado--;
        hundir(1);
    }

    void insertar(T elem){
        assert(!estaLleno());
        arr[++ultimoOcupado] = elem; 
        flotar(ultimoOcupado);
    }

    bool estaLleno()
    {
        return ultimoOcupado == capacidad;
    }

    bool estaVacio()
    {
        return ultimoOcupado == 0;
    }

};