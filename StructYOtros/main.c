#include <stdio.h>
#include <malloc.h>

//aqui creamos nuestro nuevo tipo de dato llamado nodo de maner ainterna , que se llamara nodolista por el resto del programa
typedef struct nodo
{
    int valor;
    struct nodo *nodoSiguente;
}nodoLista;

int main() {
    printf("Hello, World!\n");
    nodoLista *nodo1=malloc(sizeof (nodoLista));//reservamos memoria para guardar un nodoLista
    nodoLista *nodo2=malloc(sizeof (nodoLista));;
    nodoLista *nodo3=malloc(sizeof (nodoLista));;

    nodo1->valor=10;//asignamos los valores correspondientes a cada elemento del nodolista
    nodo2->valor=20;
    nodo1->nodoSiguente=nodo2;
    nodo3->valor=30;
    nodo2->nodoSiguente=nodo3;
    nodo3->nodoSiguente=NULL;
    nodoLista *nodoActual=nodo1;
    while (nodoActual!=NULL)
    {
        printf("valor nodo actual %i \n",nodoActual->valor);
        nodoActual=nodoActual->nodoSiguente;
    }
    return 0;
}
