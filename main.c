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
char leerCaracter() {
    //https://www.programiz.com/c-programming/c-input-output
    char a;
    printf("ingresa un caracter: ");
    scanf(" %c", &a);// bueno gente esto esta raro los e que diablos esta pasando aqui XD
    printf("tu caracter es %c\n", a);
    return a;
}

char *leerCaracteres()
{
    int i=0;
    char a[10];
    char b;
    while (i<10)
    {
        b=leerCaracter();
        a[i]= b;
        i++;
    }
    i=0;
    while (i<10)
    {
        printf("%c", a[i]);
        i++;
    }
    printf("\n");
    return a;
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

    printf("Hello, World!\n");
    printFloat(b);
    char *t =leerCaracteres();
    printf("%s \n",&t);

    return 0;
}