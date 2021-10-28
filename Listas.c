// Sesion 31 - 27/10/2021

#include <stdio.h>				//   Para la I/O del programa (entrada / Salida)
#include <stdlib.h>				//  Para las funcionesde utilería P.E. system();
#include <malloc.h>				//  Para la asignación (memory allocation) dinamica de memoria

//  Prototipos					//  Avisarle al compilador que las funciones existen
void insert(char dato);
void insertn(char dato, int n);
void insert1(char dato);
void imprimeLista();

struct Nodo 
{ 
	char info; 
	struct Nodo *sig; 
};

typedef struct Nodo nodo;

nodo *raiz = NULL;				// Creamos la lista vacia

void insert(char dato)		// dato = 'c'
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

void insertn(char dato, int n)		// dato = 'k' n = 5
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
	if(n == 1)					//  Insertamos en la primera posición si n = 1
	{
		nodo *ultimo = raiz;
		raiz = nuevo;
		raiz -> sig = ultimo;
	}
	else						//  Falso: la lista no esta vacía (al menos tiene 1 nodo)
	{
		int pos = 1;
		nodo *anterior = raiz;
		nodo *siguiente = NULL;
		while((pos != n - 1) && (anterior->sig != NULL) )
		{
			anterior = anterior->sig;
			pos++;
		}
		siguiente = anterior -> sig;
		anterior ->sig = nuevo;
		nuevo ->sig = siguiente;
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


char remueven(int n)
{
	if(raiz != NULL)
	{
		nodo *siguiente = NULL, *anterior = NULL, *elimina = NULL;
		char dato;
		if(n == 1)
		{
			elimina = raiz;
			raiz = raiz -> sig;
			dato = elimina -> info;
			free(elimina);
			return dato;
		}
		else
		{
			int pos = 1;
			anterior = raiz;
			while((pos != n - 1) )
			{
				anterior = anterior->sig;
				pos++;
			}
			elimina = anterior ->sig;
			siguiente = elimina->sig;
			anterior ->sig = siguiente;
			dato = elimina -> info;
			free(elimina);
			return dato;
		}
	} 
	else
	{
		printf("Error - UnderFlow: No hay elementos en la lista. \n"); //  Error: Underflow!
		system("Pause");
		return;   
	}
}

int main()
{
	imprimeLista();

	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();

	insert(' ');
	insert('S');
	insert('a');
	insert('l');
	insert('a');
	insert('z');
	insert('a');
	insert('r');

    imprimeLista();

	insertn('m',2);

	imprimeLista();

	insertn('k', 5000);

	imprimeLista();

	remueven(9);

	imprimeLista();

	system("pause");
	return 1;
}