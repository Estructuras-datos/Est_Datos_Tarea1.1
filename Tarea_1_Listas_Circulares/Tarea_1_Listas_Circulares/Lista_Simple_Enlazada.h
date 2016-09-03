#pragma once
#include "Nodo_Simple_Enlazada.h"

template <typename T>
class ListaSimple {
    
    
    
    
private:
    NodoSimple<T>* inicio;
    NodoSimple<T>* ultimo;
    int tam;
public:
    ListaSimple() {
        inicio = NULL;
        ultimo=NULL;
        tam = 0;
    }
    //destructor
    ~ListaSimple(){}
    
    bool isEmpty() {
        return (inicio == NULL);
    }
    int size() {
        return tam;
    }
    void toString() {
        if (!isEmpty()) {
            NodoSimple<T>* tmp = inicio;
            do {
                cout << tmp->getDato() << " -> ";
                tmp = tmp->getSig();
            } while (tmp != inicio);
            cout << endl;
        }
        else {
            cout << "Lista Vacia!" << endl;
        }
    }
    void addInicio(T e) {
        NodoSimple<T>* nuevo = new NodoSimple<T>(e, NULL);
        if (!isEmpty()) {
            nuevo->setSig(inicio);
            inicio = nuevo;
            ultimo->setSig(inicio);
            tam++;
        }
        else {
            nuevo->setSig(nuevo);
            inicio = ultimo = nuevo;
            tam++;
        }
    }
    void addFinal(T e) {
        NodoSimple<T>* nuevo = new NodoSimple<T>(e, NULL);
        if (!isEmpty()) {
            nuevo->setSig(inicio);
            ultimo->setSig(nuevo);
            ultimo=nuevo;
            tam++;
        }
        else {
            nuevo->setSig(nuevo);
            inicio = ultimo = nuevo;
            tam++;
        }
    }
    void add(int pos, T e) {
        NodoSimple<T>* nuevo = new NodoSimple<T>(e, NULL);
        if (!isEmpty()) {
            
            if (pos <= size()-1 && pos >= 1)
            {
                NodoSimple<T>* tmp = inicio;
                for (int i = 0; i < pos-1; i++)
                {
                    tmp = tmp->getSig();
                }
                NodoSimple<T>* aux=tmp->getSig();
                nuevo->setSig(aux);
                tmp->setSig(nuevo);
                tam++;
            }
            
            else if (pos == 0)
            {
                addInicio(e);
            }
            else if (pos == tam + 1)
            {
                addFinal(e);
            }
        }
        else {
             
            cout << "Lista VACIA, posicion invalida!" << endl;
            
        }
    }
    
    
    void remove(int pos){
        if(!isEmpty()){
            if(pos==0){
                eliminaPrimero();
            }
            else{
                NodoSimple<T>* aux=inicio;
                NodoSimple<T>* temp=aux->getSig();
                int p=1;
                while(temp->getSig()!=inicio && p<pos){
                    aux=aux->getSig();
                    temp=temp->getSig();
                    p++;
                }
                if(p==pos){
                    aux->setSig(temp->getSig());
                    tam--;
                    delete temp;
                }
            }
        }
    }
    
    
    
    
    void eliminaPrimero()
    {
        if(!isEmpty())
        {
            if(inicio==inicio->getSig()) //si solo hay un nodo
            {
                inicio=NULL;
            }
            else
            {
                
                NodoSimple<T> *temp=inicio;
                inicio=inicio->getSig();
                ultimo->setSig(inicio);
                delete temp;
                tam--;
            }
            
        }
    }
    
    
    
    void clear(){
        while(!isEmpty())
            remove(0);
    }
    
    
    ListaSimple<T>* clone(){
        
        if(!isEmpty()){
            ListaSimple<T>* nueva = new ListaSimple<T>();
            NodoSimple<T>* aux=inicio;
            
            do{
                
                nueva->addFinal(aux->getDato());
                aux=aux->getSig();
                
            }
            while(aux!= inicio);
            return nueva;
        }
        return NULL;
        
    }
    
    
    bool contains(T e){
        if(!isEmpty()){
            NodoSimple<T>* aux= inicio;
            for(int i=0;i<tam;i++){
                if(aux->getDato()==e)
                    return true;
                else aux=aux->getSig();
                
            }
        }
        return false;
    }
    
    
    T get(int pos){
        if(!isEmpty()){
            
            NodoSimple<T>* aux=inicio;
            int p=0;
            while(aux->getSig()!=inicio && p<pos){
                aux=aux->getSig();
                p++;
            }
            if(p==pos){
                return aux->getDato();
            }
        }
        return NULL;
        
    }
    
    
    int indexOf(T e){
        
        if(!isEmpty()){
            
            NodoSimple<T>* aux=inicio;
            int p=0;
            while(aux->getSig()!=inicio && aux->getDato() != e){
                aux=aux->getSig();
                p++;
            }
            return p;
        }
        return -1;
        
    }
    
    
    
    
};