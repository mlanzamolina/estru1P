#pragma once
#include<iostream>
#include<sstream>
#include"NodoArbol.h"
class ArbolBinario
{
private:
	NodoArbol* Encontrar(NodoArbol* nodoPadre, string valor) {
		
		stringstream converter1(valor);
		stringstream converter2(nodoPadre->GetValor());
		int nuevo = 0;
		int actual = 0;
		converter1 >> nuevo;
		converter2 >> actual;
		if (nodoPadre==nullptr)
		{
			return nullptr;
		}
		else if (nodoPadre->GetValor()==valor)
		{
			return nodoPadre;
		}
		else if (nuevo<actual)
		{
			return Encontrar(nodoPadre->GetIzquierdo(), valor);


		}
		else
		{
			return Encontrar(nodoPadre->GetDerecho(), valor);
		}
	}
	void Insertar(NodoArbol* raiz, string value) {
		string tmp = raiz->GetValor();
		stringstream converter1(value);
		stringstream converter2(tmp);
		int nuevo = 0;
		int actual = 0;
		converter1 >> nuevo;
		converter2 >> actual;
		if (nuevo >= actual) {
			if (raiz->GetDerecho() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				raiz->SetDerecho(nuevo);
				return;

			}
			else {
				Insertar(raiz->GetDerecho(), value);
			}
		}
		else if (nuevo < actual) {
			if (raiz->GetIzquierdo() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				raiz->SetIzquierdo(nuevo);
				return;

			}
			else {
				Insertar(raiz->GetIzquierdo(), value);
			}
		}
	}

public:
	NodoArbol* Raiz;
	int Count;
	ArbolBinario() :Raiz(nullptr) {
		Count = 0;
	}

	void Agregar(string valor) {
		if (Count == 0) {
			NodoArbol* nuevo = new NodoArbol(valor);
			Raiz = nuevo;

		}
		else {

			Insertar(Raiz, valor);

		}
		Count++;

	}


	NodoArbol* Buscar(string valor) 
	{
		return Encontrar(Raiz, valor);
	}
	string GetMayor(NodoArbol* nodoActual)
	{
		if (nodoActual->GetDerecho() == nullptr)
		{
			if (nodoActual->GetIzquierdo() != nullptr)
			{
				nodoActual->GetPadre()->SetDerecho(nodoActual->GetIzquierdo());
				return nodoActual->GetValor();
			}
			else
			{
				nodoActual->GetPadre()->SetDerecho(nullptr);
				return nodoActual->GetValor();
			}

		}
		else
		{
			return GetMayor(nodoActual->GetDerecho());
		}
	}
	int altura(NodoArbol*actual) 
	{
		
		int alturaDerecha,alturaIzquierda;
		if (actual==nullptr)
		{
			return +1;
		}
		else
		{
			alturaDerecha = altura(actual->GetIzquierdo());
			alturaIzquierda = altura(actual->GetDerecho());
			if (alturaDerecha>alturaIzquierda)
			{
				return alturaDerecha + 1;
			}
			else
			{
				return alturaIzquierda + 1;
			}
		}
	    
	}
	

	void eliminar(string valor) 
	{
		NodoArbol* valorEncontrado = Buscar(valor);
		NodoArbol* padreEncontrado = valorEncontrado->GetPadre();
		//primer caso
		if (valorEncontrado->GetDerecho()==nullptr)
		{
			
			if (valorEncontrado==nullptr)
			{
				Raiz = valorEncontrado->GetIzquierdo();
			}
			else
			{
				if (padreEncontrado->toInt()>valorEncontrado->toInt())
				{
					padreEncontrado->SetIzquierdo(valorEncontrado->GetIzquierdo());

				}
				else if (padreEncontrado->toInt()<valorEncontrado->toInt())
				{
					padreEncontrado->SetDerecho(valorEncontrado->GetIzquierdo());
				}
			}
		}
		//segundo caso
		else if (valorEncontrado->GetDerecho()->GetIzquierdo()==nullptr)
		{
			valorEncontrado->GetDerecho()->SetIzquierdo(valorEncontrado->GetIzquierdo());

			if (padreEncontrado == nullptr)
			  Raiz = valorEncontrado->GetDerecho();
			else
			{
				if (padreEncontrado->toInt() > valorEncontrado->toInt())
				{
					padreEncontrado->SetIzquierdo(valorEncontrado->GetDerecho());
				}
				else if (padreEncontrado->toInt() < valorEncontrado->toInt())
				{
					padreEncontrado->SetDerecho(valorEncontrado->GetDerecho());
				}
			}

			
		}
		//tercer caso nodo hijo derecho tiene hijo izquierdo
		else
		{
			NodoArbol* masIzquierdo = valorEncontrado->GetDerecho()->GetIzquierdo();
			NodoArbol* masIzquierdoPadre = valorEncontrado->GetDerecho();
			while (masIzquierdo->GetIzquierdo()!=nullptr)
			{
				masIzquierdoPadre = masIzquierdo;
				masIzquierdo = masIzquierdo->GetIzquierdo();
			}
			masIzquierdoPadre->SetIzquierdo(masIzquierdo->GetDerecho());
			masIzquierdo->SetIzquierdo(valorEncontrado->GetIzquierdo());
			masIzquierdo->SetDerecho(valorEncontrado->GetDerecho());
			if (padreEncontrado == nullptr)
				Raiz = masIzquierdo;
			else
			{
				if (padreEncontrado->toInt() > valorEncontrado->toInt())
				{
					padreEncontrado->SetIzquierdo(masIzquierdo);
				}
				else if (padreEncontrado->toInt() < valorEncontrado->toInt())
				{
					padreEncontrado->SetDerecho(masIzquierdo);
				}
			}
			//
			//if (masIzquierdo == nullptr)
			//	Raiz = masIzquierdo;
			//else
			//{
			//	//valor encontrado padre no se setea????
			//	NodoArbol* padreEncontrado1 = valorEncontrado->GetPadre();
			//	padreEncontrado1->SetDerecho(masIzquierdo);
			//	NodoArbol* nuevoPadre = padreEncontrado1->GetDerecho();
			//	if (masIzquierdo->toInt() > valorEncontrado->GetIzquierdo()->toInt())
			//	{
			//		nuevoPadre->SetIzquierdo(valorEncontrado->GetIzquierdo());

			//	}
			//	else if (masIzquierdo->toInt() <valorEncontrado->GetDerecho()->toInt())
			//	{
			//		nuevoPadre->SetDerecho(valorEncontrado->GetIzquierdo());
			//	}
			//	else if (masIzquierdo->toInt() < valorEncontrado->GetIzquierdo()->toInt())
			//	{
			//		nuevoPadre->SetDerecho(valorEncontrado->GetDerecho());
			//	}
			//	else if (masIzquierdo->toInt() > valorEncontrado->GetDerecho ()->toInt())
			//	{
			//		nuevoPadre->SetIzquierdo(valorEncontrado->GetDerecho());
			//	}
			//}
			

		}
		
	}
};
