#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

/*
 * ya que están aprendiendo punteros les paso el arreglo como un puntero a un arreglo de ints
 * esta function retorna el índice del elemento buscado y si no lo encuentra retorna -1
 */
int busquedaBinaria(int target,int largo,int *arreglo)
{
    int limiteMenor = 0;
    int limiteSuperior = largo-1;
    int indextarget = -1;
    int centro;
    while (limiteMenor<=limiteSuperior)
    {
        centro = limiteMenor+((limiteSuperior-limiteMenor)/2);
        if(arreglo[centro]>target)
        {
            limiteSuperior = centro -1;
        }
        else if(arreglo[centro]<target)
        {
            limiteMenor = centro+1;
        }
        else
        {
            indextarget = centro;
            limiteMenor=limiteSuperior+1;
        }
    }
    return indextarget;
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

void llenarArrayIntOrdenado(int *arry, int N)
{
    for (int i = 0; i < N; ++i)
    {
        arry[i]=i;
    }
}

void llenarArryRandomint(int *arry,int largo)
{
    for (int i = 0; i < largo; ++i)
    {
        arry[i]= rand()%100;
    }
}

void printArregloint(int *arreglo, int largo)
{
    printf("| ");
    for (int i = 0; i < largo; ++i)
    {
        if(i== largo-1)
        {
            printf("%i",arreglo[i]);
        }
        else
        {
            printf("%i ,", arreglo[i]);
        }
    }
    printf(" |\n");
}
int main() {
    printf("Hello, World!\n");
    srand(time(NULL));
    int *arregloInt, largoArreglo=10;//esto nos permite tener arreglo más flexibles.
    arregloInt = (int *) malloc(largoArreglo*sizeof(int));// aqui reservamos la memoria nesesaria para n ints
    llenarArrayIntOrdenado(arregloInt,largoArreglo);
    printArregloint(arregloInt,largoArreglo);
    printf("se encontro %i en el indice: %i\n",11,busquedaBinaria(11,largoArreglo,arregloInt));
    printf("se encontro %i en el indice: %i\n",5,busquedaBinaria(5,largoArreglo,arregloInt));
    printf("se encontro %i en el indice: %i\n",1,busquedaBinaria(1,largoArreglo,arregloInt));
    printf("se encontro %i en el indice: %i\n",9,busquedaBinaria(9,largoArreglo,arregloInt));

    int largorandom=15;
    int *arreglorandom =(int *) malloc(largorandom*sizeof(int));
    llenarArryRandomint(arreglorandom, largorandom);
    printArregloint(arreglorandom,largorandom);
    insertionSort(arreglorandom,largorandom);
    printArregloint(arreglorandom,largorandom);
    return 0;


}
