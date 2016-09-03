#pragma once
#include <iostream>
using namespace std;

template <typename T>
class NodoSimple {
private:
	T dato;
	NodoSimple* sig;

public:
	NodoSimple(T dato, NodoSimple* sig) {
		this->dato = dato;
		this->sig = sig;
	}

	T getDato() {
		return dato;
	}

	void setDato(T dato) {
		this->dato = dato;
	}

	NodoSimple* getSig() {
		return sig;
	}

	void setSig(NodoSimple* sig) {
		this->sig = sig;
	}

};