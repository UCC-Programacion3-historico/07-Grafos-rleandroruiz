#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H


template<class T>
class GrafoMatriz {
private:

    int **valores_arcos;
    T **valores_nodo;
    bool **existe_arco;
    int size;

    bool inRange(int n){return n > 0 && n < size;}

public:
    GrafoMatriz(int size);

    virtual ~GrafoMatriz();

    // Metodos de Nodos

    void nodo_agregar(int n, T val);

    void nodo_remover(int n);

    void nodo_set_val(int n, T val);

    T nodo_get_val(int n2);


    // Metodos de Arcos

    void arco_agregar(int n1, int n2, int val);

    void arco_remover(int n1, int n2);

    void arco_set_val(int n1, int n2, int val);

    int arco_get_val(int n1, int n2);


    bool adyacentes(int n1, int n2);

    bool *vecinos(int n);

    bool esVacio();
};

template<class T>
GrafoMatriz<T>::GrafoMatriz(int size) {

    this->size = size;
    valores_nodo = new T*[size];
    valores_arcos = new int*[size];
    existe_arco = new bool*[size];

    for(int i = 0; i < size; i++){

        valores_nodo[i] = NULL;
        valores_arcos[i] = new int [size];
        existe_arco[i] = new bool [size];

        for(int j = 0; j < size; j++)
            existe_arco[i][j] = false;
    }

}

template<class T>
void GrafoMatriz<T>::nodo_agregar(int n, T val) {

    if(NULL == valores_nodo[n] && inRange(n)){
        valores_nodo[n] = new T;
        *valores_nodo = val;          // El tipo T debe tener implementado el operador '='
    }else
        throw 1;


}

template<class T>
void GrafoMatriz<T>::nodo_remover(int n) {

    if(valores_nodo != NULL && inRange(n)){
        for(int i = 0; i < size; i++){
            existe_arco[i][n] = false;
            existe_arco[n][i] = false;
        }
    }

    delete valores_nodo[n];
    valores_nodo[n] = NULL;
}

template<class T>
void GrafoMatriz<T>::nodo_set_val(int n, T val) {

    if(NULL == valores_nodo[n] || !inRange(n))
        throw 5;
    *valores_nodo[n] = val;

}

template<class T>
T GrafoMatriz<T>::nodo_get_val(int n) {

    if(NULL == valores_nodo[n] || !inRange(n))
        throw 5;
    return *valores_nodo[n];

}

template<class T>
void GrafoMatriz<T>::arco_agregar(int n1, int n2, int val) {

    if(NULL == valores_nodo[n1] || !inRange(n1))
        throw 2;
    if(NULL == valores_nodo[n2] || !inRange(n2))
        throw 3;
    if(existe_arco[n1][n2])
        throw 4;

    existe_arco[n1][n2] = true;
    valores_arcos[n1][n2] = val;

}

template<class T>
void GrafoMatriz<T>::arco_remover(int n1, int n2) {

    if(existe_arco[n1][n2] && inRange(n1) && inRange(n2))
        existe_arco[n1][n2] = false;
    else
        throw 7;

}

template<class T>
void GrafoMatriz<T>::arco_set_val(int n1, int n2, int val) {

    if(existe_arco[n1][n2] && inRange(n1) && inRange(n2))
        valores_arcos[n1][n2] = val;
    else
        throw 6;

}

template<class T>
int GrafoMatriz<T>::arco_get_val(int n1, int n2) {

    if(existe_arco[n1][n2] && inRange(n1) && inRange(n2))
        return valores_arcos[n1][n2];
    throw 6;
}

template<class T>
bool GrafoMatriz<T>::adyacentes(int n1, int n2) {

    return((existe_arco[n1][n2] || existe_arco[n2][n1]) && inRange(n1) && inRange(n2));
}

//Esta función requiere un delete luego de su uso
template<class T>
bool *GrafoMatriz<T>::vecinos(int n) {

    bool * resultados = new bool[size];
    for(int i = 0; i < size; i++)
        resultados[i] = existe_arco[n][i] || existe_arco[i][n];

    return resultados;
}

template<class T>
bool GrafoMatriz<T>::esVacio() {

    for(int i = 0; i < size; i++){
        if(valores_nodo != NULL)
            return false;
    }
    return true;
}

template <class T>
GrafoMatriz<T>::~GrafoMatriz() {
    for(int i = 0; i < size; i++)
        if(valores_nodo[i] != NULL)
            delete valores_nodo[i];

}


#endif //GRAFOMATRIZ_H
