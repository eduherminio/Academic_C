/* Author:      Eduardo Cáceres de la Calle
 * Subject:     Fundamentos de Informática
 * Degree:      Industrial Electronics and Automatic Control Engineering
 * University:  Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2014, during my first contact with C.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

#include <stdio.h>
#define TAM_MAX 100

int Pedir_Tamanio_Matriz(int *,int *,int);
void Pedir_Datos(int,int,float [*][*]);
int Escribe_Matriz_Fichero(int,int,float [*][*],char []);

main()
{
    int fil,col;

    if(Pedir_Tamanio_Matriz(&fil,&col,TAM_MAX))
    {
        float m[fil][col];                                      //Declaracion de la matriz
        printf("Introduce los valores de la matriz:\n");
        Pedir_Datos(fil,col,m);
        if(!Escribe_Matriz_Fichero(fil,col,m,"P8_Matrix"))                 //ok=[Función] \n if(!ok)
            printf("\nError en la apertura del fichero\n");
        else
            printf("\nEl proceso ha sido llevado a cabo satisfactoriamente\n");
    }
    else
        printf("El tamanio de la matriz no es valido\n");
}

int Pedir_Tamanio_Matriz(int *fil,int *col, int maximo)
{
    int ok=0;

    printf("Introduzca el tamanio de la matriz (nxm): ");
    scanf("%dx%d",fil,col);

    if((*fil>0)&&(*fil<=maximo)&&(*col>0)&&(*col<=maximo))
        ok=1;

    return ok;
}

void Pedir_Datos(int fil,int col,float m[fil][col])
{
    int i,j;

    printf("Introduzca los elementos de cada fila separados por un espacio\nCuando haya escrito %d elementos, pulse intro\n",col);
    for(i=0;i<fil;i++)
    {
        printf("[f%d]->",i+1);
        for(j=0;j<col;j++)
        {
            scanf("%f",&m[i][j]);
        }
    }
}

int Escribe_Matriz_Fichero(int fil,int col,float m[fil][col],char nombre[])
{
    FILE *fp;
    int i,j;
    int ok=0;
    fp=fopen(nombre,"w");
    if(fp!=NULL)
    {
        ok=1;
        fprintf(fp,"%dx%d\n",fil,col);
        for(i=0;i<fil;i++)
        {
            /*fprintf(fp,"[f%d]->\t",i+1);  */        //Usar sólo si no hay que leer de ese fichero
            for(j=0;j<col;j++)
            {
                fprintf(fp,"%f ",m[i][j]);
            }
            fprintf(fp,"\n");
        }
        fclose(fp);
    }
    return (ok);
}
