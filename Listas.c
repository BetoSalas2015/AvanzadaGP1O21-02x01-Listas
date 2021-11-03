// Sesion 33 - 03/11/2021

#include <stdio.h>				//   Para la I/O del programa (entrada / Salida)
#include <stdlib.h>				//  Para las funcionesde utilería P.E. system();
#include <malloc.h>				//  Para la asignación (memory allocation) dinamica de memoria

//  Prototipos					//  Avisarle al compilador que las funciones existen
//nodo *insert(nodo *raiz, char dato);
//nodo *insertn(nodo *raiz, char dato, int n);
//nodo *insert1(nodo *char dato);
//void imprimeLista(nodo *raiz);

struct Nodo 
{ 
	char info; 
	struct Nodo *sig; 
};

typedef struct Nodo nodo;

nodo *raiz = NULL;				// Creamos la lista vacia (Variable global)

nodo *insert(nodo *raiz, char dato)		// dato = 'c'
{
	nodo *nuevo = NULL;			// Apuntador auxiliar para crear el nuevo nodo
	nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
	if( nuevo == NULL )			//  Error: Overflow!
	{
		printf("Error - Overflow: Ya no hay memoria disponible. \n");
		system("Pause");
		return NULL;          
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
	return raiz;
}

nodo *insertn(nodo *raiz, char dato, int n)		// dato = 'k' n = 5
{
	nodo *nuevo = NULL;			// Apuntador auxiliar para crear el nuevo nodo
	nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
	if( nuevo == NULL )			//  Error: Overflow!
	{
		printf("Error - Overflow: Ya no hay memoria disponible. \n");
		system("Pause");
		return NULL;          
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
	return raiz;
}


nodo *insert1(nodo *raiz, char dato)		
{
	nodo *nuevo = NULL;			// Apuntador auxiliar para crear el nuevo nodo
	nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
	if( nuevo == NULL )			//  Error: Overflow!
	{
		printf("Error - Overflow: Ya no hay memoria disponible. \n");
		system("Pause");
		return NULL;          
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
	return raiz;
}

void imprimeLista(nodo *raiz)
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
			while((pos != n - 1))
			{
				anterior = anterior->sig;
				pos++;
				if(anterior->sig == NULL )
				{
					printf("Error! No se puede eliminar el elemento %d\n", n);
					return '\0';
				}
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
		return ;   
	}
}

char remueve1()
{
	if(raiz != NULL)
	{
		nodo *siguiente = NULL, *anterior = NULL, *elimina = NULL;
		char dato;
		elimina = raiz;
		raiz = raiz -> sig;
		dato = elimina -> info;
		free(elimina);
		return dato;
	} 
	else
	{
		printf("Error - UnderFlow: No hay elementos en la lista. \n"); //  Error: Underflow!
		system("Pause");
		return;   
	}
}

char remueve()
{
	if(raiz != NULL)
	{
		nodo *siguiente = NULL, *anterior = raiz, *elimina = NULL;
		char dato;
		if(anterior->sig == NULL)
		{
			raiz = raiz -> sig;
			dato = anterior -> info;
			free(anterior);
			return dato;
		}
		else
		{
			elimina = anterior->sig;
			while(elimina -> sig != NULL )
			{
				anterior = anterior->sig;
				elimina = elimina -> sig;
			}
			anterior ->sig = NULL;			// anterior -> sig = elimina -> sig;
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
	nodo *lista1 = NULL;
	nodo *lista2 = NULL;
	nodo *lista3 = NULL;
	
	lista1 = insert(lista1, 'R');
	lista1 = insert(lista1, 'o');
	lista1 = insert(lista1, 'b');
	lista1 = insert(lista1, 'e');
	lista1 = insert(lista1, 'r');
	lista1 = insert(lista1, 't');
	lista1 = insert(lista1, 'o');

	printf("Lista1: ");
	imprimeLista(lista1);

	lista2 = insert1(lista2, 'S');
	lista2 = insert1(lista2, 'a');
	lista2 = insert1(lista2, 'l');
	lista2 = insert1(lista2, 'a');
	lista2 = insert1(lista2, 'z');
	lista2 = insert1(lista2, 'a');
	lista2 = insert1(lista2, 'r');
	
	printf("Lista2: ");
	imprimeLista(lista2);

	//  insertn tiene un error, lo depuramos en clase.

	//lista3 = insertn(lista3, 'M', 1);
	//lista3 = insertn(lista3, 'a', 1);
	//lista3 = insertn(lista3, 'r', 2);
	//lista3 = insertn(lista3, 'q', 2);
	//lista3 = insertn(lista3, 'u', 500);
	//lista3 = insertn(lista3, 'e', 5);
	//lista3 = insertn(lista3, 'z', 6);
	//
	//printf("Lista3: ");
	//imprimeLista(lista3);
	
	system("pause");
	return 1;
}