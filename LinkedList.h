//
// Created by eduardo on 10/10/19.
//

#ifndef CS1103_PC2_201902_LINKEDLIST_H
#define CS1103_PC2_201902_LINKEDLIST_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::vector; using std::string; using std::ifstream;

template<class T>
class LinkedList{
private:
    struct node{
        T val;
        node* next;
    };
public:
    node* tail = nullptr;
    node* head = nullptr;

    T get_max() {
        T mayor = head->val;
        auto it = head;
        while(it != nullptr){
            if(it->val > mayor){
                mayor = it->val;
            }
            it = it->next;
        }
        return mayor;
    }

    void insert (T item){
        if(head == nullptr){
            crearNodos(item);
            tail = head;
        }
        else{
            crearNodos(item);
        }
    }

    template<class M>
    friend::std::ostream & operator << (std::ostream & out, const LinkedList<M> &);

    template<typename ... Args>
    void insert (Args ... items) {
        vector <T> temp = {items...};
        auto it = temp.begin();
        while(it != temp.end()){
            node* aux = new node();
            aux->val = *it;
            aux->next = head;
            head = aux;
            it++;
        }
    }

    void clear(){
        while(head != nullptr){
            head = head->next;
        }
    }

    void crearNodos(T item){
        node* temp = new node();
        temp->val = item;
        temp->next = head;
        head = temp;
    }

    void load_from (const string& file_name){
        ifstream file(file_name);
        if (!file.is_open()){
            std::cout<< "File is not open!";
        }
        clear();
        string fila;
        while(getline(file,fila)){
            std::stringstream ss (fila);
            string str;
            getline(ss,str);
            int num = stoi(str);
            crearNodos(num);
        }
    }

    template<class M>
    friend::std::istream & operator >>(std::istream & in, LinkedList<M>& );
};

template<typename M>
std::ostream & operator << (std::ostream & out, const LinkedList<M>& L){
    auto it = L.head;
    while(it != nullptr){
        out << it->val << " ";
        it = it->next;
    }
    return out;
}

template<typename M>
std::istream & operator >>(std::istream & in, LinkedList<M>&  L){
    std::cout <<"Ingrese los valores: " << std::endl;
    M input;
    in >> input;
    L.crearNodos(input);
    return in;
}

#endif //CS1103_PC2_201902_LINKEDLIST_H
