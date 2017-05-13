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

int Lee_Fil_Col_Fichero(int *,int *,char []);
int Lee_Matriz_Fichero(int,int,float[*][*],char []);
void Muestra_Matriz(int,int,float[*][*]);

main()
{
    int exito,fil,col,ok;

    ok=Lee_Fil_Col_Fichero(&fil,&col,"P8_Matrix.txt");
    if(ok)
    {
        float m[fil][col];                                          //Declaración matriz
        if(Lee_Matriz_Fichero(fil,col,m,"P8_Matrix.txt"))          //ok2=funcion[] \n if(ok2)
        {
            exito=1;
            Muestra_Matriz(fil,col,m);
        }
    }

    if(exito==1)
        printf("\nEl proceso ha sido llevado a cabo satisfactoriamente\n");
    else
        printf("\nFallo en la lectura del fichero\n");
}

int Lee_Fil_Col_Fichero(int *p_fil, int *p_col,char nombre[])
{
    FILE *fp;
    int ok=0;

    fp=fopen(nombre,"r");
    if(fp!=NULL)
    {        ok=1;
        fscanf(fp,"%dx%d",p_fil,p_col);
        fclose(fp);
    }
    return(ok);
}

int Lee_Matriz_Fichero(int fil,int col,float m[fil][col],char nombre[])
{
    FILE *fp;
    int ok=0;
    int i,j;

    fp=fopen(nombre,"r");
    if(fp!=NULL)
    {
        ok=1;
        fscanf(fp,"%dx%d",&fil,&col);
        for(i=0;i<fil;i++)
        {
            for(j=0;j<col;j++)
            {
                fscanf(fp,"%f",&m[i][j]);
            }
        }
        fclose(fp);
    }
    return(ok);
}

void Muestra_Matriz(int fil,int col,float m[fil][col])
{
    int i,j;

    for(i=0;i<fil;i++)
    {
        printf("[f%d]->\t",i+1);
        for(j=0;j<col;j++)
        {
            printf("%f\t",m[i][j]);
        }
        printf("\n");
    }
}

