#include "Lista_Doble_Enlazada.h"

int main() {
	//cout << "Hola prostituto!" << endl;
	ListaDoble<int>* li = new ListaDoble<int>();
	li->toString();
	cout << "Con un elemento:" << endl;
	li->addInicio(1);
	li->toString();
	cout << "Con varios elementos:" << endl;
	li->addInicio(2);
	li->addInicio(3);
	li->addFinal(4);
	li->addFinal(5);
	li->addFinal(6);
<<<<<<< HEAD
	
=======
	li->add(2,9);
	li->add(6,1);
	li->add(0,11);
	li->add(5,12);
>>>>>>> 2941946a71dde52d9ebdcc1cd68ca93384620e80
	li->toString();
	cout << endl;
	system("pause");
	return 0;
}
