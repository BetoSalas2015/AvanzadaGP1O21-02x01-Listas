// Sesion 28 - 20/10/2021

#include <stdio.h>				//   Para la I/O del programa (entrada / Salida)
#include <stdlib.h>				//  Para las funcionesde utilería P.E. system();
#include <malloc.h>				//  Para la asignación (memory allocation) dinamica de memoria

struct Nodo 
{ 
	char info; 
	struct Nodo *sig; 
};

typedef struct Nodo nodo;

nodo *raiz = NULL;				// Creamos la lista vacia

void insert(char dato)		// dato = 'b'
{
	nodo *nuevo = NULL;			// Apuntador auxiliar para crear el nuevo nodo
	nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
	if( nuevo == NULL )			//  Error: Overflow!
	{
		printf("Error - Overflow: Ya no hay memoria disponible. \n");
		system("Pause");
		return;          
	}
	nuevo -> info = dato;		//  Guardamos la información en el nodo
	nuevo -> sig = NULL;		//  No hay nodo delante..
	if( raiz == NULL )			//  ¿La lista está vacía?
	{							//  Verdadero: la lista está vacia
		raiz = nuevo;
	}
	else						//  Falso: la lista no esta vacía (al menos tiene 1 nodo)
	{
		nodo *ultimo = raiz;
		while( ultimo->sig != NULL)		//  ¿Es el ultimo nodo?
		{							//  Verdadero: no es el ultimo nodo
			 ultimo = ultimo -> sig;	// Avanzo al diguiente nodo...
		}
		ultimo -> sig = nuevo;
	}
}

int main()
{
	nodo caja;

	system("pause");
	return 1;
}