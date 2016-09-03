
template<typename T>
class IteradorSimple{
private:
    ListaSimple<T>* lista;
    int _posicion;
    
public:
    IteradorSimple(ListaSimple<T>* lista1) {
        this->lista = lista1;
        _posicion = 0;
    }
    
    bool hasNext(){
        if (_posicion < lista->size())
            return true;
        else
            return false;
    }
    
    T next(){
        T valor = lista->get(_posicion);
        _posicion++;
        return valor;
    }
};