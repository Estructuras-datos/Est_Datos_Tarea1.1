
package ejercicio_1_java;



public class nodoCircularDoble<T> {
    
    private T dato;
    private nodoCircularDoble sig;
    private nodoCircularDoble ant;

    public nodoCircularDoble(T dato, nodoCircularDoble sig, nodoCircularDoble ant) {
		this.dato = dato;
		this.sig = sig;
		this.ant = ant;
	}

	T getDato() {
		return dato;
	}

	void setDato(T dato) {
		this.dato = dato;
	}

	nodoCircularDoble getSig() {
		return sig;
	}

	void setSig(nodoCircularDoble sig) {
		this.sig = sig;
	}

	nodoCircularDoble getAnt() {
		return ant;
	}

	void setAnt(nodoCircularDoble ant) {
		this.ant = ant;
	}

    
}
