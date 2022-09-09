#include "milibreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*estas librerias las creamos nosotros es una buena forma de ordenar los codigos
*https://ricardoromo.co/2019/como-crear-una-libreria-en-c-c/
*/


//primero lo primero asi se crean comentarios en C, este es un comentario de una linea
/*
pero esta es la forma de hacer comenatarios multilinea, por convencion se suele anteponer un * antes de cada linea, pero no es necesario
* de esta manera para que quede mas ordenado.
 */

/*----------------------------------Funciones con parametros simples---------------------*/
/*
 * en C existen disitntos tipos de parametros en este caso vamos a ver funciones con parametros simples.
 */

/*
 * Como definir una funcion:
 * primero va el tipo de dato que retorna, en el casod e mas abajo es un float(ya tienen que conocerlo),
 * luego su nombre y entre parentesis los parametros que recibe con el tipo especifico al que pertenesen.
 * Finalmente, el return con lo que queremos regresar
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

int mirandom(int min,int max)
{
    int a;
    a = (rand() % (max -min))+1;
    return a;
}

void llenararreglode1a10(int n,int arreglo[])
{
    for (int i = 0; i < n; ++i)
    {
        arreglo[i]= mirandom(1,10);
    }
}

void llenarArregloSecuencial(int n,int arreglo[])
{
    for (int i = 0; i < n; ++i)
    {
        arreglo[i]=i;
    }
}

void imprimirarreglo(int n, int arreglo[])
{
    for (int i = 0; i < n; ++i) {
        if(i==0)
        {
            printf(" [ %i,",arreglo[i]);
        }
        else
        {
           if(i==n-1)
           {
               printf("%i ]",arreglo[i]);
           }
           else
           {
               printf(" %i,",arreglo[i]);
           }
        }
    }
}

void imprimirCadena(int n, char cadena[])
{
    for (int i = 0; i < n; ++i)
    {
        printf("%c", cadena[i]);
    }
    printf("\n");
}

//la busqueda binaria es una forma muy eficiente de buscar elementos dentro de una lista ordenada
//el tiempo de busqueda es similar a log2(n)
int busquedaBinaria(int largo,int elementoBuscar, int arr[])
{
    int respuesta = -1;
    int bordeinferior = 0;
    int bordeSuperior = largo-1;
    int continuar=1;
    if(arr[bordeinferior]>elementoBuscar || arr[bordeSuperior]<elementoBuscar)
    {
        continuar=0;
    }
    while (continuar)
    {
        printf("bordein %i , bordesup %i",bordeinferior,bordeSuperior);
        if(elementoBuscar == arr[bordeinferior])
        {
            respuesta=bordeinferior;
            continuar=0;
        }
        else if( elementoBuscar == arr[bordeSuperior])
        {
            respuesta= bordeSuperior;
            continuar=0;
        }
        else
        {
            int centro = (bordeSuperior+bordeinferior)/2;
            printf("centro: %i\n", centro);
            if(elementoBuscar == arr[centro])
            {
                respuesta=centro;
                continuar=0;
            }
            else if(elementoBuscar > arr[centro])
            {
                bordeinferior = centro;
            }
            else if(elementoBuscar < arr[centro])
            {
                bordeSuperior= centro;
            }
            else if(bordeSuperior-bordeinferior<=1)
            {
                continuar=0;
            }
        }
    }
    return respuesta;
}

int leercadenaChar(int n,char cadena[])
{
    printf("ingrese una cadena de largo maximo %i\n", n);
    scanf("%s", cadena);
    int i=0, largo=0;
    while(i<n)
    {
        if(cadena[i]>=32 && cadena[i]<127)
        {
            printf("%i, ", cadena[i]);
            largo++;
        }
        i++;
    }
    printf("\n");
    return largo;
}

void invertirCadena(int largo, char cadena[], char cadenaI[])
{
    for (int i = 0; i < largo; ++i)
    {
        cadenaI[i]=cadena[largo-1-(i)];
    }
}

int sonIguales(int largo1, char cadena1[], int largo2, char cadena2[])
{
    int salida = 1;
    if(largo1==largo2)
    {
        for (int i = 0; i < largo1; ++i)
        {
            if(cadena2[i]!=cadena1[i])
            {
                salida = 0;
            }
        }
    }
    else
    {
        salida = 0;
    }
    return salida;
}

int espalindromo(int largo, char cadena[])
{
    printf("largo %i\n", largo);
    printf("cadena: %s\n", cadena);
    int es=1,i=0;
    while (i<largo && es==1)
    {
        if(cadena[i]!=cadena[largo-1])
        {
            es = 0;
        }
        i++;
        largo--;
    }
    return es;
}

int contiene(int laro1, char cadena1[], int largo2, char cadena2[])
{
    int esta=0,i=0,j=0,p;
    while (i<laro1)
    {
        if(cadena1[i]==cadena2[0])
        {
            p=i;
            while (j<largo2 && p<laro1)
            {
                if(cadena1[p]!=cadena2[j])
                {
                    p+=laro1;
                }
                else
                {
                    p++;
                    j++;
                }
            }
            if(j==largo2)
            {
                esta=1;
                i+=laro1;
            }
        }
        i++;
    }
    return esta;
}

int contarH(int largoPalabra, char palabra[],int largoFila,char fila[])
{
    int j, k,h=0;
    for (int i = 0; i < largoFila; ++i)
    {
        j=0;
        k=i;
        while (k<largoFila && j<largoPalabra)
        {
            if(fila[k]==palabra[j])
            {
                k++;
                j++;
            }
            else
            {
                k=largoFila*2;
            }
        }
        if(j==largoPalabra)
        {
            h++;
        }
    }
    return h;
}

int sopadeletras(int largo,char palabra[], int lsopa, char sopa[5][5])
{

    int cantidadCadena=0;
    int i=0;
    while (i<lsopa)
    {
        cantidadCadena+= contarH(largo,palabra,lsopa,sopa[i]);
        i++;
    }
    return cantidadCadena;
}

int main() {

    //para usar random se require sembrar la semilla
    srand(time(NULL));

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

    //
    //---------------------------- Arreglos estaticos
    //
    int elementos;
    printf("ingrese el numero de elementos que tendran sus listas, maximo 100 elementos: \n");
    /*
    scanf_s("%i", &elementos);
    int arr1a10[elementos];

     en algunos compiladores lo anterior no funciona y se tiene que hacer lo que hice.
     */
    scanf_s("%i", &elementos);
    /*
    int arr1a10[100];
    llenararreglode1a10(elementos,arr1a10);
    imprimirarreglo(elementos, arr1a10);

    int arr[100];
    llenarArregloSecuencial(elementos,arr);
    int elementoBuscar;
    printf("ingrese el numero de elemento a buscar\n");
    scanf_s("%i", &elementoBuscar);
    imprimirarreglo(elementos,arr);
    int salida = busquedaBinaria(elementos,elementoBuscar,arr);
    printf("el elemento esta en el indice %i.\n",salida);
    */

    //1

    int largo=10;
    char ala[2] ="tt";
    char sopa[5][5] = {{"alalq"},
                       {"pepla"},
                       {"laatt"},
                       {"ttttl"},
                       {"ceela"}};

    mostrarSopaCuadrada(5,sopa);
    printf("%s %i \n",ala,sopadeletras(2,ala,5,sopa));
    /*
    char cadenaa[10];
    char cadenai[10];
    int t = leercadenaChar(largo,cadenaa);
    printf("largo cadena %i.\n", t);
    invertirCadena(t,cadenaa,cadenai);
    imprimirCadena(t, cadenai);
     */
    //2
    /*
    char cadena1[10];
    char cadena2[10];
    int largoc1= leercadenaChar(largo,cadena1);
    int largoc2= leercadenaChar(largo, cadena2);
    printf("son: %i \n",sonIguales(largoc1,cadena1,largoc2,cadena2));
    */

    //3
    /*
    char cadena3[10];
    int largoc3= leercadenaChar(largo,cadena3);
    printf("es :%i\n",espalindromo(largoc3, cadena3));
     */

    //4
    /*
    char cadena4[10];
    int largoc4= leercadenaChar(largo,cadena4);
    char cadena5[10];
    int largoc5= leercadenaChar(largo,cadena5);
    printf("%i\n",contiene(largoc4,cadena4,largoc5,cadena5));
     */

    //
    //------------------------ Punteros
    //
    int i;
    char c;
    cargardatos(&i,&c);//el & indica que pasamos la direccion de memoria del puntero
    printf("i:%i ,c:%c",i,c);// luego aqui ya imprimimos las varibles con los valores que estan guardados
    //
    //------------------------ arreglos dinamiscos en C
    //
    int *arregloInt, N;
    printf("ingresa el numero de elemento del arreglo: ");
    scanf(" %i", &N);//recuerden en este caso le estamos diciendo que llene la direccion de memoria donde esta guardado N
    arregloInt = (int *) malloc(N*sizeof(int)); //reservamos la memoria requerida para un arreglo de N elementos
    llenarArrayInt(arregloInt,N);// aqui llenamos nuestro puntero de ints
    printf("el elemento %i es:%i \n",0,arregloInt[0]);// aqui mostramos el elemento en en indice 5.
    // con lo siguente imprimimos todos los elementos del arreglo

    /* SABER EL TAMAÑO DE UN ARRAY */
    /*segun el siguente link lo siguente no funciona en c para arreglos creados dinamicamente,
     * aun asi existen soluciones que se plantean en el link
     * https://stackoverflow.com/questions/492384/how-to-find-the-sizeof-a-pointer-pointing-to-an-array
     */
    // RECORDAR QUE ESTO ES PARA ARREGLOS ESTATICOS

    //------------- tranformar int a ASII-------------
    int miASII=55;
    char asii = (char) miASII;
    printf("mi char is %c\n",asii);
    //https://spreadsheeto.com/wp-content/uploads/2017/09/ascii-codes-table.png

    int cadena[5]={1,2,3,4,5};
    printf("el elemento :%i \n", sizeof(cadena)/sizeof (int));// dividimos la cantidad de bits que usa el arreglo en los bits que usa el tipop de variable

    for (int j = 0; j < N; ++j) {
        printf("%i, ", arregloInt[j]);
    }
    free(arregloInt);/*cuando se usa malloc es necesario liberar la memoria  al final del programa,
    * de lo contrario las variables quedaran en memoria(esto depende de cada sistema ).
    */

    return 0;
}