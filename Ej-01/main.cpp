#include <iostream>
#include "GrafoMatriz.h"
using namespace std;

int main() {
    GrafoMatriz<string> gr(4);
    gr.nodo_agregar(0,"Hola");
    gr.nodo_agregar(1,"Chau");
    gr.nodo_agregar(2,"Hi");
    gr.nodo_agregar(3,"Bye");

    gr.arco_agregar(0, 2, 3);
    gr.arco_agregar(0, 1, 2);
    gr.arco_agregar(1, 0, 3);
    gr.arco_agregar(2, 1, 5);

    cout << "Adyacente 0-1" << gr.adyacentes(0, 1) << endl;
    cout << "Adyacente 0-1" << gr.adyacentes(1, 2) << endl;
    cout << "Adyacente 0-1" << gr.adyacentes(2, 3) << endl;



    std::cout << "Ejercicio 07/01\n" << std::endl;
    return 0;
}