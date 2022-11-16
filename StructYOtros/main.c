#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

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

typedef struct
{
    char marca[10];
    char modelo[10];
    int ntelefonico;

}telefono;

typedef struct persona
{
    int edad;
    char nombre[20];
    telefono telefono;

}mypersona;

typedef struct ppersona
{
    int edad;
    char nombre[20];
    telefono telefono;
}myppersona;

myppersona * crearppersona(int edad, char nombre[20], telefono telefono)
{
    myppersona *nuevapersona = malloc(sizeof (myppersona));
    nuevapersona->edad=edad;
    strcpy(nuevapersona->nombre,nombre);
    nuevapersona->telefono = telefono;
    return nuevapersona;
}

void insertionSort(int *arreglo, int largo)
{
    for (int i = 0; i < largo; ++i)
    {
        int indexmin=i;
        for (int j = i; j < largo; ++j)
        {
            if(arreglo[j]<arreglo[indexmin])
            {
                indexmin=j;
            }
        }
        int aux = arreglo[i];
        arreglo[i]=arreglo[indexmin];
        arreglo[indexmin]=aux;
    }
}

void insertSortPersonas(mypersona *personas, int largoPersona)
{
    int i=0;
    while (i<largoPersona)
    {
        int j =i;
        int indicemenor = j;
        int valor = personas[indicemenor].edad;
        while (j<largoPersona)
        {
            if(personas[j].edad < valor)
            {
                indicemenor=j;
                valor = personas[j].edad;
            }
            j++;
        }
        mypersona aux = personas[i];
        personas[i] = personas[indicemenor];
        personas[indicemenor]=aux;
        i++;
    }
}
mypersona crearpersona(int edad, char nombre[20], telefono telefono)
{
    mypersona nuevapersona;
    nuevapersona.edad=edad;
    strcpy(nuevapersona.nombre,nombre);
    nuevapersona.telefono = telefono;
    return nuevapersona;
}



int main()
{

    ejemplostruct();
    mypersona personas[4];
    int largopersonsp=4;
    myppersona *personasp = malloc(sizeof (myppersona)*largopersonsp);
    telefono telefono1 = {"nokia","A10",99999999};
    telefono telefono2 = {"nokia","A20",99999998};
    telefono telefono3 = {"nokia","A11",99999997};
    telefono telefono4 = {"nokia","A13",99999996};
    /*
    for (int i = 0; i < 4; ++i)
    {
        char nombre[20];
        int edad;

         // llenar desde teclado antes de pasar

        personas[i]= crearpersona(edad,nombre);
    }
    */
    personas[0] = crearpersona(10, "jaun", telefono1);
    personas[1] = crearpersona(22, "mari", telefono2);
    personas[2] = crearpersona(19,"fraco", telefono3);
    personas[3] = crearpersona(18,"chika", telefono4);

    *(personasp+0) = *crearppersona(10, "jaun", telefono1);
    *(personasp+1) = *crearppersona(22, "mari", telefono2);
    *(personasp+2) = *crearppersona(19,"fraco", telefono3);
    *(personasp+3) = *crearppersona(18,"chika", telefono4);
    insertSortPersonas(personas,4);


    int count=0;
    for (int i = 0; i < 4; ++i)
    {
        if(personas[i].edad <= 50)
        {
            count++;
            printf("%s tiene  %i annos\n",personas[i].nombre, personas[i].edad);
            printf("%i \n", personas[i].telefono.ntelefonico);
        }
    }
    if(count==0)
    {
        printf("no se encontro ninguno\n");
    }
    int c = 15;
    int c1 = 3;
    printf("%c == %c \n",c,c1);

    for (int i = 0; i < 4; ++i)
    {
        if(personasp[i].edad <= 50)
        {
            count++;
            printf("%s tiene  %i annos\n",personasp[i].nombre, personasp[i].edad);
            printf("%i \n", personasp[i].telefono.ntelefonico);
        }
    }



    return 0;
}
