#pragma once
#include "Nodo_Doble_Enlazada.h"

template <typename T>
class ListaDoble {
private:
	NodoDoble<T>* inicio;
	int tam;
public:
	ListaDoble() {
		inicio = NULL;
		tam = 0;
	}
	//destructor
	~ListaDoble(){}

	bool isEmpty() {
		return (inicio == NULL);
	}
	int size() {
		return tam;
	}
	void toString() {
		if (!isEmpty()) {
			NodoDoble<T>* tmp = inicio;
			cout << " <-> ";
			do {
				cout << tmp->getDato() << " <-> ";
				tmp = tmp->getSig();
			} while (tmp != inicio);
			cout << endl;
		}
		else {
			cout << "Lista Vacia!" << endl;
		}
	}
	void addInicio(T e) {
		NodoDoble<T>* nuevo = new NodoDoble<T>(e, NULL, NULL);
		if (!isEmpty()) {
			nuevo->setSig(inicio);
			nuevo->setAnt(inicio->getAnt());
			inicio->getAnt()->setSig(nuevo);
			inicio->setAnt(nuevo);
			inicio = nuevo;
			tam++;
		}
		else {
			nuevo->setSig(nuevo);
			nuevo->setAnt(nuevo);
			inicio = nuevo;
			tam++;
		}
	}
	void addFinal(T e) {
		NodoDoble<T>* nuevo = new NodoDoble<T>(e, NULL, NULL);
		if (!isEmpty()) {
            inicio->getAnt()->setSig(nuevo);
            nuevo->setSig(inicio);
            nuevo->setAnt(inicio->getAnt());
            inicio->setAnt(nuevo);
            
            
            
			//inicio->getSig()->setAnt(nuevo);
			//inicio->setSig(nuevo);
			tam++;
		}
		else {
			nuevo->setSig(nuevo);
			nuevo->setAnt(nuevo);
			inicio = nuevo;
			tam++;
		}
	}
    void add(int pos, T e) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(e, NULL, NULL);
        if (!isEmpty()) {
            if (pos == 0)
            {
                addInicio(e);
            }
            else if (pos <= size()-1 && pos >= 0)
            {
                NodoDoble<T>* tmp = inicio;
                for (int i = 0; i < pos; i++)
                {
                    tmp = tmp->getSig();
                }
                nuevo->setSig(tmp);
                nuevo->setAnt(tmp->getAnt());
                tmp->getAnt()->setSig(nuevo);
                tmp->setAnt(nuevo);
                tam++;
            }
            else if (pos == size())
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
                NodoDoble<T>* aux=inicio;
                int p=0;
                while(aux->getSig()!=inicio && p<pos){
                    aux=aux->getSig();
                    p++;
                }
                if(p==pos){
                    aux->getAnt()->setSig(aux->getSig());
                    aux->getSig()->setAnt(aux->getAnt());
                    tam--;
                    delete aux;
                }
            }
        }
    }
    
    
    
    
    void eliminaPrimero()
    {
        if(!isEmpty())
        {
            if(inicio==inicio->getAnt()) //si solo hay un nodo
            {
                inicio=NULL;
            }
            else
            {
                
                NodoDoble<T> *temp=inicio;
                inicio->getSig()->setAnt(inicio->getAnt());
                inicio->getAnt()->setSig(inicio->getSig());
                inicio=inicio->getSig();
                delete temp;
                tam--;
            }
            
        }
    }
    
    
    
    void clear(){
        while(!isEmpty())
            remove(0);
    }
    
    
    ListaDoble<T>* clone(){
        
        if(!isEmpty()){
            ListaDoble<T>* nueva = new ListaDoble<T>();
            NodoDoble<T>* aux=inicio->getSig();
            nueva->addInicio(inicio->getDato()); //en caso de que solo hay 1 nodo no entraria al while
            
            while(aux!= inicio){
                nueva->addFinal(aux->getDato());
                aux=aux->getSig();
            }
            return nueva;
        }
        return NULL;
        
    }
    
    
    bool contains(T e){
        if(!isEmpty()){
            NodoDoble<T>* aux= inicio;
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
            
            NodoDoble<T>* aux=inicio;
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
            
            NodoDoble<T>* aux=inicio;
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