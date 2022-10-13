#include <stdio.h>
#include <malloc.h>

typedef struct fecha
{
    int mes;
    int dia;
}fechaCumple;

typedef struct persona
{
    char nombreCompleto[255];
    int familiar;
    fechaCumple *cumple;

}conocido;

conocido leerconocido()
{
    fechaCumple *fechaCumple1= malloc(sizeof (fechaCumple));
    conocido *conocidoActual= malloc(sizeof (conocido));
    printf("ingrese el nombre de la person, maximo 255 caracteres:\n");
    fgets(conocidoActual->nombreCompleto,255,stdin);
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
    return *conocidoActual;

}

int main()
{
    int cantidad=15;
    conocido conocidos[15];

    for (int i = 0; i < 2; ++i)
    {
        conocido conocido2=leerconocido();
        conocidos[i]=conocido2;
    }
    for (int i = 0; i < 2; ++i)
    {
        conocido conocido2=conocidos[i];
        printf("nombre : %s", conocido2.nombreCompleto);
        printf("familiar : %i\n", conocido2.familiar);
        printf("fecha: %i del %i\n", conocido2.cumple->dia,conocido2.cumple->mes);
        printf("\n");
    }

    return 0;
}
