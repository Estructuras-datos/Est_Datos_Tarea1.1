#include "Lista_Doble_Enlazada.h"
#include "Lista_Simple_Enlazada.h"



template<typename T>
class Iterador{
private:
    ListaDoble<T>* lista;
    ListaSimple<T>* lista2;
    int _posicion;
    
public:
    Iterador(ListaDoble<T>* lista) {
        this->lista = lista;
        this->lista2=NULL;
        _posicion = 0;
    }
    
    Iterador(ListaSimple<T>* lista) {
        this->lista2 = lista;
        this->lista=NULL;
        _posicion = 0;
    }
    
    bool hasNext(){
        if(!lista2){
            if (_posicion < lista->size())
                return true;
            else
                return false;
        }
        
        else{
            if (_posicion < lista2->size())
                return true;
            else
                return false;
        }
    }
    
    T next(){
        if(!lista2){
            T valor = lista->get(_posicion);
            _posicion++;
            return valor;
        }
        else{
            T valor = lista2->get(_posicion);
            _posicion++;
            return valor;
        }
    }
    
    void add(T e){
        if(!lista2){
            lista->add(_posicion, e);
            _posicion++;
        }
        else{
            lista2->add(_posicion, e);
            _posicion++;
        }
    }
    
    
};