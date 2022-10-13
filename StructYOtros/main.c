#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//aqui creamos nuestro nuevo tipo de dato llamado nodo de maner ainterna , que se llamara nodolista por el resto del programa
typedef struct nodo
{
    int valor;
    struct nodo *nodoSiguente;
}nodoLista;

typedef struct ListNode ListNode;
struct ListNode{
    int val;
    struct ListNode *next;
};

//https://leetcode.com/problems/middle-of-the-linked-list/submissions/
struct ListNode* middleNode()
{
    int cantidadNodos=6;
    struct ListNode *head = malloc(sizeof (ListNode));;
    struct ListNode *actual = malloc(sizeof (ListNode));
    struct ListNode *siguente;
    for (int i = 1; i <= cantidadNodos; ++i)
    {

        actual->val=i;
        siguente = malloc(sizeof (ListNode));
        actual->next=siguente;
        if(i==1)
        {
            head=actual;
        }
        if(i==cantidadNodos)
        {
            actual->next=NULL;
        }
        else
        {

            actual=siguente;
        }
    }
    int count=0;
    actual=head;
    while (actual != NULL)
    {
        printf("%i\n", actual->val);
        actual=actual->next;
        count++;

    }
    printf("count/2 = %i",(count/2));
    int nuevocount=0;
    actual=head;
    printf("actual %i\n", head->val);
    while (nuevocount!=(count/2))
    {
        actual=actual->next;
        nuevocount++;
    }
    printf("actual %i\n", actual->val);
    return actual;
}

bool PalindromeNumber(int valor)
{
    bool si=true;
    if(valor>=0)
    {
        int real=valor;
        int reverse_number=0;
        while (valor != 0)
        {
            reverse_number = reverse_number * 10;
            reverse_number = reverse_number + valor % 10;
            valor = valor / 10;
        }
        if(real!=reverse_number)
        {
            si=false;
        }

    }
    else
    {
        si=false;
    }

    return si;
}

void ejemplostruct()
{
    printf("un ejemplo de estructuras y listas enlazadas\n");
    nodoLista *nodo1=malloc(sizeof (nodoLista));//reservamos memoria para guardar un nodoLista
    nodoLista *nodo2=malloc(sizeof (nodoLista));;
    nodoLista *nodo3=malloc(sizeof (nodoLista));;

    nodo1->valor=10;//asignamos los valores correspondientes a cada elemento del nodolista
    //nodo2->valor=20;
    printf("ingrese valor nodo 2\n");
    scanf_s("%i",&nodo2->valor);
    printf("%i \n",nodo2->valor);
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
}

int main()
{
    ejemplostruct();
    //middleNode();
    //printf("%i \n",PalindromeNumber(121));

    return 0;
}
