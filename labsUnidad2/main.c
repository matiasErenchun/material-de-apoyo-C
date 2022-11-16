#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct fecha
{
    int mes;
    int dia;
}fechaCumple;

typedef struct persona
{
    char nombre[255];
    int familiar;
    fechaCumple *cumple;

}conocidoPunteros;

typedef struct humano
{
    char nombre[255];
    int edad;
    fechaCumple cumple;
}myhumano;

conocidoPunteros * leerconocido()
{
    fechaCumple *fechaCumple1= (fechaCumple *)malloc(sizeof (fechaCumple));
    conocidoPunteros *conocidoActual= (conocidoPunteros *)malloc(sizeof (conocidoPunteros));
    printf("ingrese el nombre de la person, maximo 255 caracteres:\n");
    fgets(conocidoActual->nombre,255,stdin);
    printf("ingrese 1 si es familiar o 0 si es amigo\n");
    int familiar;
    scanf_s("%i",&familiar);
    getchar();
    conocidoActual->familiar=familiar;
    printf("ingrese el dia del  cumpleaños\n");
    int dia;
    scanf_s("%i",&dia);
    getchar();
    fechaCumple1->dia=dia;
    printf("ingrese el mes del  cumpleaños\n");
    int mes;
    scanf_s("%i",  &mes);
    getchar();
    fechaCumple1->mes=mes;
    conocidoActual->cumple=fechaCumple1;
    return conocidoActual;

}

int main()
{
    int cantidad=15;
    conocidoPunteros *conocidos= malloc(sizeof (conocidoPunteros));

    for (int i = 0; i < 2; ++i)
    {
        conocidoPunteros *conocido2=leerconocido();
        conocidos[i]=*conocido2;
    }
    for (int i = 0; i < 2; ++i)
    {
        conocidoPunteros *conocido2=&conocidos[i];
        printf("nombre %s", conocido2->nombre);
        printf("familiar : %i\n", conocido2->familiar);
        printf("fecha: %i del %i\n", conocido2->cumple->dia,conocidos[i].cumple->mes);
        printf("\n");
    }

    return 0;
}

/*
int main()
{
    myhumano *myhumano1= malloc(sizeof (myhumano));
    fechaCumple *fechaCumple1= malloc(sizeof (fechaCumple));
    fechaCumple1->mes=10;
    fechaCumple1->dia=1;
    char hola[]="hola";
    myhumano1->nombre= hola;
    myhumano1->cumple=fechaCumple1;
    myhumano1->edad=22;
    printf("%s",myhumano1->nombre);
    return 0;
}
*/