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
            printf("%i, ", arreglo[i]);
        }
    }
    printf(" |\n");
}

int determinarLargo(char *frase,int maxLargo)
{
    int i=0;
    while (*(frase+i)!='\n')
    {
        i++;
    }
    printf("largo real %i \n");
    return i;
}

void printFrase(int largo,char *frase)
{
    for (int i = 0; i < largo; ++i)
    {
        printf("%c",*(frase+i));
    }
    printf("\n");
}

void lab0510E4()
{
    int continuar=1;
    while (continuar)
    {
        char *frase = malloc(sizeof (char)*255);//aqui reservamos 255 cajas donde puedo guardar char
        printf("ingrese una frase, maximo de 255 caracteres:");
        fgets(frase,255, stdin);
        printf("%s \n",frase);
        int largoreal=determinarLargo(frase,255);
        if(largoreal>0)
        {
            char *frasechort= malloc((sizeof (char)*largoreal)+1);
            int countfshort=0;
            for (int i = 0; i < largoreal; ++i)
            {
                if(*(frase+i)!='a' && *(frase+i)!='e' && *(frase+i)!='i' && *(frase+i)!='o' && *(frase+i)!='u')
                {
                    *(frasechort+countfshort)=*(frase+i);
                    countfshort++;
                }
            }
            *(frasechort+countfshort)='\n';
            printFrase(countfshort,frasechort);
            determinarLargo(frasechort,largoreal+1);
            free(frasechort);
        }
        else
        {
            continuar=0;
        }
        free(frase);

    }
    printf("fin del ejemplo");

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

    lab0510E4();
    return 0;


}
