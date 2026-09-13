#include <stdio.h>
#include <iostream>

using namespace std;

template<typename T>
struct NodoAVL{
  T dato;
  int altura;
  NodoAVL *izq;
  NodoAVL *der;

  NodoAVL(T elem) {
    dato = elem;
    altura = 1;
    izq = der = NULL;
  }
};

template<typename T>
class AVL{
  private:
    NodoAVL<T>* raiz;

    int getAltura(NodoAVL<T>* nodo)
    {
        if(!nodo)
            return 0;
        return nodo->altura; 
    }

    int getBalance(NodoAVL<T>* nodo){
        if(!nodo)
            return 0;
        return getAltura(nodo->der) - getAltura(nodo->izq);
    }

    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* nodo)
    {
      NodoAVL<T>* A = nodo->izq;
      NodoAVL<T>* B = nodo;
      NodoAVL<T>* T2 = A->der;

      B->izq = T2;
      A->der = B;

      B->altura = 1 + max(getAltura(B->izq), getAltura(B->der));
      A->altura = 1 + max(getAltura(A->izq), getAltura(A->der));

      return A;
    }

    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* nodo)
    {
      NodoAVL<T>* A = nodo->der;
      NodoAVL<T>* B = nodo;
      NodoAVL<T>* T2 = A->izq;

      B->der = T2;
      A->izq = B;

      B->altura = 1 + max(getAltura(B->izq), getAltura(B->der));
      A->altura = 1 + max(getAltura(A->izq), getAltura(A->der));

      return A;
    }

    NodoAVL<T>* insertarRec(NodoAVL<T>* nodo, T elem)
    {
      if(!nodo){
        return new NodoAVL<T>(elem);
      }
      else if(elem < nodo->dato){
        nodo->izq = insertarRec(nodo->izq, elem);
      } else if(elem > nodo->dato){
        nodo->der = insertarRec(nodo->der, elem);
      }
      else{
        return nodo;
      }

      nodo->altura = 1 + max(getAltura(nodo->izq),getAltura(nodo->der));
      int balance = getBalance(nodo);

      if(balance < -1 && elem < nodo->izq->dato){
        return rotacionDerecha(nodo);
      }

      if(balance < -1 && elem > nodo->izq->dato){
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
      }

      if(balance > 1 && elem < nodo->der->dato)
      {
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
      }

      if(balance > 1 && elem > nodo->der->dato){
        return rotacionIzquierda(nodo);
      }

      return nodo;
    }

    bool perteneceRec(NodoAVL<T>* nodo, T elem)
    {
      if(!nodo){
        return false;
      }
      if(elem == nodo->dato){
        return true;
      }
      if(elem < nodo->dato){
        return perteneceRec(nodo->izq, elem);
      }else{
        return perteneceRec(nodo->der, elem);
      }
    }

    void rangoRec(NodoAVL<T>* nodo, T desde, T hasta)
    {
      if(!nodo){
        return;
      }
      if(nodo->dato > desde){
        rangoRec(nodo->izq, desde, hasta);
      }
      if(nodo->dato >= desde && nodo->dato <= hasta){
        cout << nodo->dato << "\n";
      }
      if(nodo->dato < hasta){
        rangoRec(nodo->der, desde, hasta);
      }
    }

  public:

    AVL()
    {
      raiz = NULL;
    }

    void insertar(T elem)
    {
      raiz = insertarRec(raiz,elem);
    }

    bool pertenece(T elem)
    {
      return perteneceRec(raiz,elem);
    }

    void rango(T desde,T hasta)
    {
      rangoRec(raiz,desde,hasta);
    }
};