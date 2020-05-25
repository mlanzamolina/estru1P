
#include"Pila.h"
#include<conio.h>
#include <iostream>
using namespace std;


int main() {

    cout << a[0];
	Pila stack(10);
	stack.Push(1);
	stack.Push(2);
	cout << "ELEMENTO CONSULTADO= " << stack.Peek() << endl;
	stack.Push(3);
	stack.print();
	cout << "ELEMENTO CONSULTADO= " << stack.Peek() << endl;
	cout<<"ELEMENTO ELIMINADO= "<<stack.Pop()<<endl;
	stack.print();
	cout << "ELEMENTO ELIMINADO= " << stack.Pop() << endl;
	cout << "ELEMENTO ELIMINADO= " << stack.Pop() << endl;
	cout << "ELEMENTO ELIMINADO= " << stack.Pop() << endl;
	stack.print();
     stack.Push(9);
	 stack.print();
   cout << "ELEMENTO CONSULTADO= " << stack.Peek() << endl;

	_getch();
}