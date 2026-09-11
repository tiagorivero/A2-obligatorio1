#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVL.h"
#include "tads/AVLImp.cpp"

using namespace std;

int main()
{
    AVL<int> monedas;
    AVL<string> pinturas;

    int num;
    cin >> num;
    for(int i = 0; i < n; i++){
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
        else if (operacion == "BUSCAR"){
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
    

    while(num > count){
        cin >> operacion >> tipo >> dato1 >> dato2;
        if(operacion == "ALTA"){
            if(tipo == "M"){
                monedas.insertar(dato1);
            }else if(tipo == "P"){
                pinturas.insertar(dato1);
            }
        }else if(operacion = "BUSCAR"){
            if(tipo == "M"){
                bool pertenece = monedas.pertenece(dato1)
                monedas.pertenece(dato1) ? cout << "si"; : cout << "no";
            }else if(tipo == "P"){
                bool pertenece = pinturas.pertenece(dato1)
                cout << "si";
            }
        }else if(operacion = "RANGO"){
            if(tipo == "M"){
                monedas.rango(dato1, dato2)
            }else if(tipo == "P"){
                pinturas.rango(dato1, dato2)
            }
        }
    }
    cout << endl;

    return 0;
}