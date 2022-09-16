//
// Created by matias on 15-07-2022.
//
#include <stdio.h>

float suma(float A, float B)
{
    return A+B;
}
float resta(float A,float B)
{
    return A-B;
}
float multiplicaciona(float A,float B)
{
    return A*B;
}



void mostrarSopaCuadrada(int largo, char sopa[5][5])
{
    for (int i = 0; i < largo; ++i)
    {
        printf("|");
        for (int j = 0; j < largo; ++j)
        {
            printf("%c,", sopa[i][j]);
        }
        printf("|\n");
    }
}


