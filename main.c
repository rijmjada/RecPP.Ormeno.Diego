#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

/*
1. Crear una función llamada aplicarDescuento que reciba
como parámetro el precio de un producto y devuelva el valor del producto
con un descuento del 5%. Realizar la llamada desde el main. *


Crear una función que se llame contarCaracteres que reciba una cadena
 de caracteres como primer parámetro y un carácter como segundo y
 devuelva la cantidad de veces que ese carácter aparece en la cadena *

 Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita
 ordenar un array de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio.
 Hardcodear datos y mostrarlos desde el main. *
*/

typedef struct
{
    int id;
    char procesador[24];
    char marca[24];
    float precio;

}Notebook;

int ordenarPorMarca(Notebook lista[],int tam);

int contarCaracteres(char cadena[],char a);
void aplicarDescuento(int* precio);

int main()
{
    Notebook note [3] = {
    {1,"Ryzen","amd",150},
    {2,"i5","intel",200},
    {3,"Saraza","saraza",999},
    };


    int precio = 100;
    char cadena[] = "Diego";
    char caracter = 'o';

    aplicarDescuento(&precio);
    printf("%d\n",precio);

    printf("%d\n",contarCaracteres(cadena,caracter));



    return 0;
}


void aplicarDescuento(int* precio)
{
    (*precio) = (*precio)-((*precio)*5) /100;
}

int contarCaracteres(char cadena[],char caracter)
{
    int contador = 0;
    int len;

    if(cadena != NULL)
    {
        len = strlen(cadena);

        for(int i=0; i<len; i++)
        {
            if(cadena[i] == caracter)
            {
                contador++;
            }
        }
    }
    return contador;
}

int ordenarPorMarca(Notebook lista[],int tam)
{
    int ret = -1;
    Notebook aux;
    if(lista != NULL)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(lista[i].marca,lista[j].marca))>0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
    return ret;
}
