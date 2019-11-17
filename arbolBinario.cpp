#include <iostream>
using namespace std;
struct NODO{
	int dato;
	NODO* izq,*der;
};
NODO* raiz=NULL;

int main(int argc, char** argv) {
	NODO *aux=raiz;
	raiz=new NODO();
	raiz->dato=7;
	raiz->izq=new NODO();
	raiz->der=new NODO();
	aux=raiz->izq;
	aux->dato=5;
	aux->izq=new NODO();
	aux->der=new NODO();
	aux=aux->izq;
	aux->dato=2;
	aux->izq=NULL;
	aux->der=NULL;
	aux=raiz->izq;
	aux=aux->der;
	aux->dato=3;
	aux->izq=NULL;
	aux->der=NULL;
	aux=raiz->der;
	aux->dato=4;
	aux->izq=NULL;
	aux->der=new NODO();
	aux=aux->der;
	aux->dato=1;
	aux->izq=NULL;
	aux->der=NULL;


	cout<<raiz->dato<<endl;
	cout<<raiz->izq->dato<<" "<<raiz->der->dato<<endl;
	cout<<raiz->izq->izq->dato<<" "<<raiz->izq->der->dato<<" "<<raiz->der->der->dato<<endl;

	return 0;
}
