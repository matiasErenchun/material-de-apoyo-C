#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*estas librerias las creamos nosotros es una buena forma de ordenar los codigos
*https://ricardoromo.co/2019/como-crear-una-libreria-en-c-c/
*/
#include "miLibreriaPrototipo.h"

//primero lo primero asi se crean comentarios en C, este es un comentario de una linea
/*
pero esta es la forma de hacer comenatarios multilinea, por convencion se suele anteponer un * antes de cada linea, pero no es necesario
* de esta manera para que quede mas ordenado.
 */

/*----------------------------------Funciones con parametros simples---------------------*/
/*
 * en C existen disitntos tiposd e parametros en este caso vamos a ver funciones con parametros simples.
 */

/*
 * Como definir una funcion:
 * primero va el tipo de dato que retorna, en el casod e mas abajo es un float(ya tienen que conocerlo),
 * luego su nombre y entre parentesis los parametros que recibe con el tipo especifico al que pertenesen.
 * finalmente el return con lo que queremos regresar
 */
float dividir(float A,float B)
{
    return A/B;
}

/*
 * las funciones void no retornan nada
 */
void printFloat(float a)
{
    printf("%f \n",a);
    //https://www.programiz.com/c-programming/c-input-output
    //https://www.tutorialspoint.com/format-specifiers-in-c
    //la letra luego del % representa el tipo de dato a imprimir
}


//----------------------------------------------Leer Desde Teclado-------------------------------------------
/*
 *
 */

//  ahora lo chido Punteros http://chuwiki.chuidiang.org/index.php?title=Arrays_en_C
void cargardatos(int *i, char *c)
{
    printf("ingresa un numero: ");
    scanf(" %i", i);// bueno gente esto esta raro lo se, que diablos esta pasando aqui XD
    //en la direccion de memoria i guardamos lo que scanf nos traiga
    printf("tu numero es %i\n", *i);// cone sot apuntamos al valor de la variable.
    printf("ingresa un caracter: ");
    scanf(" %c", c);// bueno gente esto esta raro lo se, que diablos esta pasando aqui XD
    printf("tu caracter es %c\n", *c);
}
char leerCaracter() {
    //https://www.programiz.com/c-programming/c-input-output
    char a;
    printf("ingresa un caracter: \n");
    scanf(" %c", &a);// bueno gente esto esta raro lo se, que diablos esta pasando aqui XD
    printf("tu caracter es %c\n", a);
    return a;
}

void llenarArrayInt(int* arry, int N)
{
    int j;
    for (int i = 0; i < N; ++i)
    {
        printf("ingresa un numero: ");
        scanf(" %i", &j);
        arry[i]=j;
    }
}


void tamanoArreglo(char** t)
{
    int tamnoArreglo = sizeof (*t);
    int tamanosPrimerElemento = sizeof (t[0]);
    printf(" arrar: %d \n", tamnoArreglo);
    printf(" prim: %d \n", tamanosPrimerElemento);
    printf("%d \n", tamnoArreglo/tamanosPrimerElemento);
    printf("%s \n",t[0]);
}

int main() {
    //como podemos ver el main es la funcion general de nuestro programa, la cuals era llamada por el sistema operativo para ahcer correr el programa
    //al ser esta una funcion  tiene que terminar con return, el cual el sistema operativo utiliza para determinar como termino la ejecucion del programa,
    // el return 0 es cuando el programa se ejecuto sin errores


    /* C es un lenguaje con tipado fuerte,lo que quiere decir que las cosas una vez que las creas con un tipo
     * este ya no puede cambiar, ademas de que solo se puedne guardar cosas de ese tipo en esa variable.
     * un ejemplo acontinuacion:
     * creamos a como int y luego intentamos crearlo como caracter y no nos lo permite
     */
    int a;
    //char a;
    float b =1.0004;
    printFloat(b);

    //punteros
    int i;
    char c;
    cargardatos(&i,&c);//el & indica que pasamos la direccion de memoria del puntero
    printf("i:%i ,c:%c",i,c);// luego aqui ya imprimimos las varibles con los valores que estan guardados

    //arreglos dinamiscos en C
    int *arregloInt, N;
    printf("ingresa el numero de lemento del arreglo: ");
    scanf(" %i", &N);//recuerden en este caso le estamos diciendo que llenela direcciond e memoria donde estaguardado N
    arregloInt = (int *) malloc(N*sizeof(int)); //reservamos la memoria requerida para una rreglo  de N elementos
    llenarArrayInt(arregloInt,N);// aqui llenamos nuestro puntero de ints
    printf("el elemento %i es:%i \n",0,arregloInt[0]);// aqui mostramos el elemento en en indice 5.
    // con lo siguente imprimimos todos los elementos del arreglo
    for (int j = 0; j < N; ++j) {
        printf("%i, ", arregloInt[j]);
    }
    free(arregloInt);/*cuando se usa malloc es necesario liberar la memoria  al final del programa,
    * de lo contrario las variables quedaran en memoria(esto depende de cada sistema ).
    */
    return 0;
}