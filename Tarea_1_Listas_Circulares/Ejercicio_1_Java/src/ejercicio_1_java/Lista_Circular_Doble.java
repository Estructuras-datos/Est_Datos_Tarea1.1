package ejercicio_1_java;

import java.util.Iterator;

public class Lista_Circular_Doble<T> implements Iterable<T>{

    private nodoCircularDoble<T> inicio;
    private int tam;

    public Lista_Circular_Doble() {
        inicio = null;
        tam = 0;
    }

    public boolean isEmpty() {
        return (inicio == null);
    }

    public int size() {
        return tam;
    }

    public void to_String() {
        if (!isEmpty()) {
            nodoCircularDoble<T> tmp = inicio;
            System.out.print(" <=> ");
            do {
                System.out.print(tmp.getDato());
                System.out.print(" <=> ");
                tmp = tmp.getSig();
            } while (tmp != inicio);

        } else {
            System.out.println("Lista Vacia!");
        }
    }

    void addInicio(T e) {
        nodoCircularDoble<T> nuevo = new nodoCircularDoble<T>(e, null, null);
        if (!isEmpty()) {
            nuevo.setSig(inicio);
            nuevo.setAnt(inicio.getAnt());
            inicio.getAnt().setSig(nuevo);
            inicio.setAnt(nuevo);
            inicio = nuevo;
            tam++;
        } else {
            nuevo.setSig(nuevo);
            nuevo.setAnt(nuevo);
            inicio = nuevo;
            tam++;
        }
    }

    void addFinal(T e) {
        nodoCircularDoble<T> nuevo = new nodoCircularDoble<T>(e, null, null);
        if (!isEmpty()) {
            inicio.getAnt().setSig(nuevo);
            nuevo.setSig(inicio);
            nuevo.setAnt(inicio.getAnt());
            inicio.setAnt(nuevo);

            tam++;
        } else {
            nuevo.setSig(nuevo);
            nuevo.setAnt(nuevo);
            inicio = nuevo;
            tam++;
        }
    }

    void add(int pos, T e) {
        nodoCircularDoble<T> nuevo = new nodoCircularDoble<T>(e, null, null);
        if (!isEmpty()) {
            if (pos == 0) {
                addInicio(e);
            } else if (pos <= size() - 1 && pos >= 0) {
                nodoCircularDoble<T> tmp = inicio;
                for (int i = 0; i < pos; i++) {
                    tmp = tmp.getSig();
                }
                nuevo.setSig(tmp);
                nuevo.setAnt(tmp.getAnt());
                tmp.getAnt().setSig(nuevo);
                tmp.setAnt(nuevo);
                tam++;
            } else if (pos == size()) {
                addFinal(e);
            }
        } else {
            System.out.println("Lista VACIA, posicion invalida!");
        }
    }

    void remove(int pos) {
        if (!isEmpty()) {
            if (pos == 0) {
                eliminaPrimero();
            } else {
                nodoCircularDoble<T> aux = inicio;
                int p = 0;
                while (aux.getSig() != inicio && p < pos) {
                    aux = aux.getSig();
                    p++;
                }
                if (p == pos) {
                    aux.getAnt().setSig(aux.getSig());
                    aux.getSig().setAnt(aux.getAnt());
                    tam--;
                }
            }
        }
    }

    void eliminaPrimero() {
        if (!isEmpty()) {
            if (inicio == inicio.getAnt()) //si solo hay un nodo
            {
                inicio = null;
            } else {

                nodoCircularDoble<T> temp = inicio;
                inicio.getSig().setAnt(inicio.getAnt());
                inicio.getAnt().setSig(inicio.getSig());
                inicio = inicio.getSig();

                tam--;
            }

        }
    }

    void clear() {
        while (!isEmpty()) {
            remove(0);
        }
    }

    public Lista_Circular_Doble<T> clone() {

        if (!isEmpty()) {
            Lista_Circular_Doble<T> nueva = new Lista_Circular_Doble<T>();
            nodoCircularDoble<T> aux = inicio.getSig();
            nueva.addInicio(inicio.getDato()); //en caso de que solo hay 1 nodo no entraria al while

            while (aux != inicio) {
                nueva.addFinal(aux.getDato());
                aux = aux.getSig();
            }
            return nueva;
        }
        return null;

    }

    boolean contains(T e) {
        if (!isEmpty()) {
            nodoCircularDoble<T> aux = inicio;
            for (int i = 0; i < tam; i++) {
                if (aux.getDato() == e) {
                    return true;
                } else {
                    aux = aux.getSig();
                }

            }
        }
        return false;
    }

    T get(int pos) {
        if (!isEmpty()) {

            nodoCircularDoble<T> aux = inicio;
            int p = 0;
            while (aux.getSig() != inicio && p < pos) {
                aux = aux.getSig();
                p++;
            }
            if (p == pos) {
                return aux.getDato();
            }
        }
        return null;

    }

    int indexOf(T e) {

        if (!isEmpty()) {

            nodoCircularDoble<T> aux = inicio;
            int p = 0;
            while (aux.getSig() != inicio && aux.getDato() != e) {
                aux = aux.getSig();
                p++;
            }
            return p;
        }
        return -1;

    }

    @Override
    public Iterator<T> iterator() {
        return this.iterator();
    }

}
