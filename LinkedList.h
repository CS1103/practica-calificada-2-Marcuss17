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
            node* temp = new node();
            temp->val = item;
            temp->next = head;
            head = temp;
            tail = temp;
        }
        else{
            node* temp = new node();
            temp->val = item;
            temp->next = head;
            head = temp;
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

    void load_from (const string& file_name){
        ifstream file(file_name);
        if (!file.is_open()){
            std::cout<< "File is not open!";
        }
        clear();
        string fila;
        while(getline(file,fila)){
            node* temp = new node();
            std::stringstream ss (fila);
            string str;
            getline(ss,str);
            int num = stoi(str);
            temp->val = num;
            temp->next = head;
            head = temp;
        }
    }
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

#endif //CS1103_PC2_201902_LINKEDLIST_H
