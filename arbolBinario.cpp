#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *&, int);
void inOrden(Nodo *);

Nodo *arbol=NULL;

int main(){
	menu();
		
	getch();
	return 0;
}

void menu(){
	int dato, opcion, contador=0;
	
	do{
		cout<<"\t .:MENU de arbol:."<<endl;
		cout<<"1.- Insertar un nuevo numero: "<<endl;
		cout<<"2.- Mostrar arbol: "<<endl;
		cout<<"3.- Recorrer el arbol en orden "<<endl;
		cout<<"4.- Salir"<<endl;
		cout<<"Opcion: "<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\n Digite un dato: ";
					cin>>dato;
					insertarNodo(arbol,dato);
					cout<<"\n";
					system("pause");	
					break;
			case 2: cout<<"\n Mostrando el arbol: \n\n";
					mostrarArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
			case 3: cout<<"\n REcorrido en Orden : ";
					inOrden(arbol);
					cout<<"\n\n";
					system("pause");	
					break;
		}
		system("cls");
	}while(opcion !=4 );
	
}

Nodo *crearNodo(int n){
	Nodo *nuevoNodo=new Nodo();
	
	nuevoNodo->dato=n;
	nuevoNodo->der=NULL;
	nuevoNodo->izq=NULL;
	
	return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int n){
	if(arbol==NULL){
		Nodo *nuevoNodo=crearNodo(n);
		arbol=nuevoNodo;
	}
	else{
		int valorRaiz=arbol->dato;
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n);	
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
}

void mostrarArbol(Nodo *&arbol, int cont){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0; i<cont;i++){
			cout<<"   ";	
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}	

void inOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}
