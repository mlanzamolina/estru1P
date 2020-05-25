#include "Pila.h"
#include <iostream>
using namespace std;
Pila::Pila(int numero): count(0){
	size = numero;
	arrayPila = new int[numero];
	for (int n = 0; n < size; n++) {
		arrayPila[n] = 'a';
	}
}

void Pila::Push(int dato) {
	if (count != size) {
		if (count == 0) {
			arrayPila[0] = dato;
			count++;

		}
		else {
			for (int n = count; n > 0; n--) {
				arrayPila[n] = arrayPila[n - 1];
			}
			arrayPila[0] = dato;
			count++;
		}
	}
	else {
		cout << "STACK LLENO";
	}
}

int Pila::Pop() {
	if (count > 0) {
		int tmp = arrayPila[0];
		for (int n = 0; n < count; n++) {
			arrayPila[n] = arrayPila[n + 1];
		}
		arrayPila[count] = 'a';
		count--;
		return tmp;
	}
	else {
		cout << "STACK VACIO";
		return '\0';
	}
}

int Pila::Peek() {
	if (count > 0) {
		return arrayPila[0];
	}
	else {
		cout << "STACK VACIO";
		return '\0';
	}
}

void Pila::print() {
	cout << "-----------------------"<<endl;
	for (int n = 0; n < size; n++) {
		if (arrayPila[n] != 'a') {
			cout << arrayPila[n] << endl;
		}
	}
}

