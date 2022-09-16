#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAXLARGO=100;
/*
 * la siguente funcion llena un arreglo o cadena de chars y retorna el largo real usado
 *
 */
int llenarArreglochar(int largoMaximo, char arreglo[])
{
    printf("ingrese un texto de maximo 100 caracteres:\n");
    fgets(arreglo,largoMaximo,stdin);//stdin es para leer desde entrada estandar "teclado", se puede cambiar por otras cosas
    int contador=0;
    while (contador<largoMaximo && arreglo[contador]!='\n')
    {
        contador++;
    }
    //le restamos uno a contador-- para que cuente hasta el último caracter y no considere hasta el '\0'
    return contador--;
}

void miimprimirarreglo(int largo,char arreglo[])
{
    printf("la palabra: ");
    for (int i = 0; i < largo; ++i)
    {
        printf("%c",arreglo[i]);
    }
    printf(" ,usa la siguiente cantidad de caracteres:%i \n", largo);
}

void llenarmatriz(int filas, int columnas,int matriz[100][100])//los compiladores extrictos nos obligana colocar explicitamente los largos maximos
{
    //filas y columnas tienen que ser menores o iguales a 100, pero les dejo esa validation a ustedes
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            matriz[i][j]= rand() % 10;
        }
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[100][100])
{
    for (int i = 0; i < filas ; ++i)
    {
        printf("| ");
        for (int j = 0; j <columnas ; ++j)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("|\n");
    }
}

int main()
{
    srand(time(NULL));
    int largoMax=100;
    char palabra[100];
    int largopalabra = llenarArreglochar(largoMax,palabra);
    printf("la palabra %s, usa la siguiente cantidad de caracteres:%i\n",palabra,largopalabra);// esto imprime cortado porque considera el '\n' como parte el arreglo
    miimprimirarreglo(largopalabra,palabra);
    int filas = 5;
    int columnas = 5;
    int matriz[100][100];
    llenarmatriz(filas,columnas,matriz);
    imprimirMatriz(filas,columnas,matriz);
    printf("|----------------|\n");
    filas = 5;
    columnas = 7;
    llenarmatriz(filas,columnas,matriz);
    imprimirMatriz(filas,columnas,matriz);
}
