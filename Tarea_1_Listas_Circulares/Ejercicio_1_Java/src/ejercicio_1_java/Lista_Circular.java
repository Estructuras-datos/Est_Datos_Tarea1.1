package ejercicio_1_java;

public class Lista_Circular<T> {

    private nodo_Circular<T> inicio;
    private nodo_Circular<T> ultimo;
    private int tam;

    public Lista_Circular() {
        inicio = null;
        ultimo = null;
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
            nodo_Circular<T> tmp = inicio;
            System.out.print(" -> ");
            do {
                System.out.print(tmp.getDato());
                System.out.print(" -> ");
                tmp = tmp.getSig();
            } while (tmp != inicio);

        } else {
            System.err.println("Lista Vacia!");
        }
    }

    void addInicio(T e) {
        nodo_Circular<T> nuevo = new nodo_Circular<T>(e, null);
        if (!isEmpty()) {
            nuevo.setSig(inicio);
            inicio = nuevo;
            ultimo.setSig(inicio);
            tam++;
        } else {
            nuevo.setSig(nuevo);
            inicio = ultimo = nuevo;
            tam++;
        }
    }

    void addFinal(T e) {
        nodo_Circular<T> nuevo = new nodo_Circular<T>(e, null);
        if (!isEmpty()) {
            nuevo.setSig(inicio);
            ultimo.setSig(nuevo);
            ultimo = nuevo;
            tam++;
        } else {
            nuevo.setSig(nuevo);
            inicio = ultimo = nuevo;
            tam++;
        }
    }

    void add(int pos, T e) {
        nodo_Circular<T> nuevo = new nodo_Circular<T>(e, null);
        if (!isEmpty()) {

            if (pos <= size() - 1 && pos >= 1) {
                nodo_Circular<T> tmp = inicio;
                for (int i = 0; i < pos - 1; i++) {
                    tmp = tmp.getSig();
                }
                nodo_Circular<T> aux = tmp.getSig();
                nuevo.setSig(aux);
                tmp.setSig(nuevo);
                tam++;
            } else if (pos == 0) {
                addInicio(e);
            } else if (pos == tam) {
                addFinal(e);
            }
        } else {

            System.err.println("Lista VACIA, posicion invalida!");

        }
    }

    void remove(int pos) {
        if (!isEmpty()) {
            if (pos == 0) {
                eliminaPrimero();
            } else {
                nodo_Circular<T> aux = inicio;
                nodo_Circular<T> temp = aux.getSig();
                int p = 1;
                while (temp.getSig() != inicio && p < pos) {
                    aux = aux.getSig();
                    temp = temp.getSig();
                    p++;
                }
                if (p == pos) {
                    aux.setSig(temp.getSig());
                    tam--;
                }
            }
        }
    }

    void eliminaPrimero() {
        if (!isEmpty()) {
            if (inicio == inicio.getSig()) //si solo hay un nodo
            {
                inicio = null;
            } else {

                nodo_Circular<T> temp = inicio;
                inicio = inicio.getSig();
                ultimo.setSig(inicio);
                tam--;
            }

        }
    }

    public void clear() {
        while (!isEmpty()) {
            remove(0);
        }
    }

    public Lista_Circular<T> clone() {

        if (!isEmpty()) {
            Lista_Circular<T> nueva = new Lista_Circular<T>();
            nodo_Circular<T> aux = inicio;

            do {

                nueva.addFinal(aux.getDato());
                aux = aux.getSig();

            } while (aux != inicio);
            return nueva;
        }
        return null;

    }

    public boolean contains(T e) {
        if (!isEmpty()) {
            nodo_Circular<T> aux = inicio;
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

    public T get(int pos) {
        if (!isEmpty()) {

            nodo_Circular<T> aux = inicio;
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

    public int indexOf(T e) {

        if (!isEmpty()) {

            nodo_Circular<T> aux = inicio;
            int p = 0;
            while (aux.getSig() != inicio && aux.getDato() != e) {
                aux = aux.getSig();
                p++;
            }
            return p;
        }
        return -1;

    }

}
