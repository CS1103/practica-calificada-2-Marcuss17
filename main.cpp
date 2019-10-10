#include "LinkedList.h"

using std::cout; using std::cin; using std::endl;
int main(){
    LinkedList<int>L1;

    //Ingresa multiples elementos a la lista
    L1.insert(2,3,74,5);

    //Ingresa elemento por elemento a la lista
    L1.insert(15);
    L1.insert(35);

    //Retorna el mayor elemento de la lista
    cout <<"El mayor elemento del la lista es: " << endl;
    cout << L1.get_max();
    cout << endl;

    //Lee los elementos desde un archivo
    L1.load_from("/home/eduardo/Desktop/Utec/Poo2/practica-calificada-2-Marcuss17/cmake-build-debug/data.txt");

    //Implementada sobrecarga operador >>
    cin >> L1;

    //Imprimir los elementos de la lista, sobrecarga de  <<
    cout << "Los elementos de la lista son: " << endl;
    cout << L1;

    return 0;
}