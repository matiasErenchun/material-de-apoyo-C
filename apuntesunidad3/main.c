#include <stdio.h>


//leer achivos http://ingenieriainversa.org/2017/02/14/leer-un-fichero-en-c/
int main() {

    FILE *file;

    char caracteres[255];
    char *resultado;

    file= fopen("..\\cosas.txt","rt");

    if (file == NULL)
    {
        printf("error in fopen");
    }
    else
    {
        resultado = fgets(caracteres,255,file);
        while (resultado!=NULL)
        {
            printf("%s",caracteres);
            resultado = fgets(caracteres,255,file);
        }
    }

    return 0;
}
