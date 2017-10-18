#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;

public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = NULL;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {
    vaciar();
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() {
    return inicio == NULL;
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int cont = 0;

    while (aux != NULL) {
        cont++;
        aux = aux->getNext();
    }
    return cont;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    int cont = 0;
    Nodo<T> *aux = inicio;

    if (pos == 0) {
        Nodo<T> *nn = new Nodo<T>(dato, inicio);
        inicio = nn;
        return;
    }


    while (cont < pos - 1 && aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    if (aux == NULL)
        throw 1;

    Nodo<T> *nn = new Nodo<T>(dato, aux->getNext());
    aux->setNext(nn);
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    Nodo<T> *nn = new Nodo<T>(dato, inicio);
    inicio = nn;
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {

}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    Nodo<T> *aux = inicio;
    int cont = 0;

    if (pos == 0) {
        if (inicio == NULL)
            throw 1;

        inicio = inicio->getNext();
        delete aux;
        return;
    }


    while (cont < pos - 1 && aux->getNext() != NULL) {
        cont++;
        aux = aux->getNext();
    }
    if (aux->getNext() == NULL)
        throw 1;

    Nodo<T> *tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete tmp;

}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    unsigned int i = 0;
    Nodo<T> *aux = inicio;

    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 3;

    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    unsigned int i = 0;
    Nodo<T> *aux = inicio;

    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 3;

    aux->setDato(dato);
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio;
    Nodo<T> *ant;

    while (aux != NULL) {
        ant = aux;
        aux = aux->getNext();
        delete ant;
    }
    inicio=NULL;
}


#endif //LISTA_H