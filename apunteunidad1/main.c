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
    //filas y columnas tienen que ser menores a 100, pero les dejo esa validation a ustedes
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            matriz[i][j]= rand() % 10;
        }
    }
}

//las funciones de tipo void no retornan nada
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

void menu()
{
    //en c los boleanos como atl no exiten  asi  que se usa 0 para falso y 1 para verdadero
    int continuar=1;
    int opcion;
    while (continuar)
    {
        printf("ingrese un numero:\n");
        printf("*- con 0 se termina el menu.\n");
        //aqui podemos colocar un menu, imprimiendo las opciones y que un número se la option elegida
        scanf("%i",&opcion);
        switch (opcion)// se evalua el valor de opcion  con cada uno de los case
        {
            case 0:
                printf("opcion es 0, se cerrara el programa\n");
                continuar=0;
                break;
            case 1:
                //si ponene funciones en este lugar la que este en el case correspondiente se ejecutara
                //lo cuall es bastante comodo.
                printf("opcion es 1\n");
                break;
            case 2:
                printf("opcion es 2\n");
                break;
            case 3:
                printf("opcion es 3\n");
                break;
            default: // si no coincide con ninguno se ejecuta loq ue este en default
                printf("es un numero distinto de 0,1, 2 o 3\n");
                break;
        }
    }
    printf("Bye Bye bro :D\n");
    printf("O.o o.O\n");
    printf("OoO -.-\n");
    printf("Q.Q ToT\n");

}

/*
 * propuesta de solucion ejercicio 2 prueba1 2022-2
 */
int  ejercicio2prueba120222(int largocadena1, char cadena1[], int largocadena2, char cadena2[], char cadenasalida[])
{
    //si no entienden como funciona hablar con matias por discord: onibushi#1453, después de las 00:00 me tienen que mandar un meme
    int contadorcadena1=0;
    int contadorcadena2=largocadena2-1;
    int contadorcadenasalida=0;
    while (contadorcadenasalida<(largocadena1+largocadena2))
    {
        //si es par 0,2,4,6,8
        if(contadorcadenasalida%2==0)//si aun no termino de copiar la cadena1
        {
            if(contadorcadena1<largocadena1)
            {
                cadenasalida[contadorcadenasalida]=cadena1[contadorcadena1];
                contadorcadena1++;
            }
            else//si ya termine de copiar la cadena1 copio lo que me falte de la cadena2
            {
                cadenasalida[contadorcadenasalida]=cadena2[contadorcadena2];
                contadorcadena2--;
            }
        }
        else//si es inpar 1,3,5,7,8
        {
            if(contadorcadena2>=0)//si aun no termino de copiar la cadena2
            {
                cadenasalida[contadorcadenasalida]=cadena2[contadorcadena2];
                contadorcadena2--;
            }
            else//si ya termine la cadena2 copio lo que me falte de la cadena1
            {
                cadenasalida[contadorcadenasalida]=cadena1[contadorcadena1];
                contadorcadena1++;
            }
        }
        contadorcadenasalida++;
    }
    return contadorcadenasalida;
}

int main()
{
    srand(time(NULL));
    int largoMax=100;
    char palabra[100];
    int largopalabra = llenarArreglochar(largoMax,palabra);
    printf("la palabra %s, usa la siguiente cantidad de caracteres:%i\n",palabra,largopalabra);// esto imprime cortado porque considera el '\n' como parte el arreglo
    miimprimirarreglo(largopalabra,palabra);
    printf("\n");
    printf("|--------Matrices-------|\n");
    printf("\n");
    int filas = 5;
    int columnas = 5;
    int matriz[100][100];
    llenarmatriz(filas,columnas,matriz);/* las matrices se pasan por referencia,
    *lo que quiere decir que dentro de las funciones se cambia el elemento original sin necesidad de retornarlos ni
    * de recibirlos en alguna variable, por otra parte, los elementos individuales de tipos primitivos (int, float, char,double)
    * se pasan por parametro ósea una copia de esta manera se requiere retornarlos y guardarlos en una variable.
    */
    imprimirMatriz(filas,columnas,matriz);
    printf("\n");
    printf("|----------------|\n");
    printf("\n");
    filas = 5;
    columnas = 7;
    llenarmatriz(filas,columnas,matriz);
    imprimirMatriz(filas,columnas,matriz);

    //ejercicio2
    //dos palabras igual largo
    int largocadena1=4;
    char cadena1[]={"hola"};
    int largocadena2=4;
    char cadena2[]={"hola"};
    char cadenasalida1[8];//esto tiene que coincidir con los largos,
    // lo ideal sería usar la estrategia de que las dos cadenas se lean con la funcion llenarArreglochar
    ejercicio2prueba120222(largocadena1,cadena1,largocadena2,cadena2,cadenasalida1);
    miimprimirarreglo(largocadena1+largocadena2,cadenasalida1);

    //distinto tamaño
    int largocadena3=3;
    char cadena3[]={"xxx"};
    char cadenasalida2[7];
    ejercicio2prueba120222(largocadena1,cadena1,largocadena3,cadena3,cadenasalida2);
    miimprimirarreglo(largocadena1+largocadena3,cadenasalida2);

    //una sin nada
    int largocadena4=0;
    char cadena4[]={""};
    char cadenasalida3[4];
    ejercicio2prueba120222(largocadena1,cadena1,largocadena4,cadena4,cadenasalida3);
    miimprimirarreglo(largocadena1+largocadena4,cadenasalida3);
    // ahora al reves la palabras
    //una sin nada
    ejercicio2prueba120222(largocadena4,cadena4,largocadena1,cadena1,cadenasalida3);
    miimprimirarreglo(largocadena1+largocadena4,cadenasalida3);


    printf("|-------un menu--------|\n");
    menu();
}
