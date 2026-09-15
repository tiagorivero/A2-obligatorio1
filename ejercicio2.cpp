#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/TablaHashImp.cpp"
#include "tads/TablaHash.h"

using namespace std;

int funcionDeHash(string clave){
    int h = 0;
    for(int i = 0; i < clave.length(); i++){
        h = 31*h + int(clave[i]);
    }
    return h;
}

bool funcionComparar(string clave1, string clave2){
    return clave1 == clave2;
}

string nuevaClave (string palabra) {
    int* conteo = new int[26];

    for (int i = 0; i < 26; i++) {
        conteo[i] = 0;
    }

    for (int i = 0; i < palabra.length(); i++) {
        char c = palabra[i];
        conteo[c - 'a']++;
    }

    string clave = "";
    for (int i = 0; i < 26; i++) {
        if (conteo[i] > 0) {
            clave += char(('a' + i));
            clave += char(conteo[i]); 
        }
    }

    delete[] conteo;

    return clave;
}

int main()
{
    int cantCajonesDistintos = 0;
    int cantCajonMax = 0;

    int N;
    cin >> N;
    HashAbierto<string, int>* tabla = new HashAbierto<string, int>(N, funcionDeHash, funcionComparar);

    for (int i = 0; i < N; i++)
    {
        string dato;
        cin >> dato;
        string clave = nuevaClave(dato);

        if(tabla->existe(clave)){
            int* cantidad = tabla->recuperar(clave);
            (*cantidad)++;

            if (*cantidad > cantCajonMax) {
                cantCajonMax = *cantidad;
            }
        } else {
            tabla->insertar(clave, 1);
            cantCajonesDistintos++;
            if (cantCajonMax < 1) {
                cantCajonMax = 1;
            }
        }
    }
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        string elem;
        cin >> elem;
        string clave = nuevaClave(elem);

        if(tabla->existe(clave)){
            int* cantidad = tabla->recuperar(clave);
            cout << *cantidad << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    cout << cantCajonesDistintos << " " << cantCajonMax << "\n";

    return 0;
}