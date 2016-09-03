
package ejercicio_1_java;


public class nodo_Circular<T> {
    private T dato;
    private nodo_Circular sig;

public nodo_Circular(T dato, nodo_Circular sig) {
		this.dato = dato;
		this.sig = sig;
	}

	public T getDato() {
		return dato;
	}

	public void setDato(T dato) {
		this.dato = dato;
	}

	public nodo_Circular getSig() {
		return sig;
	}

	public void setSig(nodo_Circular sig) {
		this.sig = sig;
	}
}
