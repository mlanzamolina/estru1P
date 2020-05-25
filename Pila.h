#pragma once
class Pila
{
private :
	int* arrayPila;

public:
	int count;
	int size;
	Pila(int);
	void Push(int);
	int Pop();
	int Peek();
	void print();
};

