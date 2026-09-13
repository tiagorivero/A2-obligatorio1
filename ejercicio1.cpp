#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVLImp.cpp"
#include "tads/AVL.h"

using namespace std;

int main()
{
    AVL<int> monedas;
    AVL<string> pinturas;

    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        string operacion;
        string tipo;
        cin >> operacion >> tipo;

        if(operacion == "ALTA"){
            if(tipo == "M"){
                int c;
                cin >> c;
                monedas.insertar(c);
            } else if(tipo == "P"){
                string t;
                cin >> t;
                pinturas.insertar(t);
            }
        }
        else if (operacion == "BUSCAR") {
            if (tipo == "M"){
                int c;
                cin >> c;
                if (monedas.pertenece(c)){
                    cout << "si" << "\n";
                }else{
                    cout << "no" << "\n";
                }
            } else if(tipo == "P"){
                string t;
                cin >> t;
                if (pinturas.pertenece(t)){
                    cout << "si" << "\n";
                }else{
                    cout << "no" << "\n";
                }
            }
        }
        else if (operacion == "RANGO"){
            if(tipo == "M") {
                int desde;
                int hasta;
                cin >> desde >> hasta;
                monedas.rango(desde,hasta);
            } else if (tipo == "P"){
                string desde;
                string hasta;
                cin >> desde >> hasta;
                pinturas.rango(desde, hasta);
            }
        }
    }
    
    return 0;
}