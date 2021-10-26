// Sesion 29 - 21/10/2021

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

void insert2(char dato)		// dato = 'c'
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

void insert1(char dato)		
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
		raiz = nuevo;
		raiz -> sig = ultimo;
	}
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre != NULL)		//  ¿Es el ultimo nodo?
	{							//  Verdadero: no es el ultimo nodo
		printf("%c, ", recorre->info);
		 recorre = recorre -> sig;	// Avanzo al diguiente nodo...
	}
	putchar('\n');
}

int main()
{
	imprimeLista();

	insert1('R');
	insert1('o');
	insert1('b');
	insert1('e');
	insert1('r');
	insert1('t');
	insert1('o');

	imprimeLista();

	insert1(' ');
	insert1('S');
	insert1('a');
	insert1('l');
	insert1('a');
	insert1('z');
	insert1('a');
	insert1('r');

    imprimeLista();

	system("pause");
	return 1;
}