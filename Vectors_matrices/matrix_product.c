/* Author: 	Eduardo Cáceres de la Calle
 * Subject: 	Fundamentos de Informática
 * Degree: 	Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2014, during my first contact with C.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

#include <stdio.h>
#define TAM_MAX 100

void Pide_Dimension(int [],int);
void Pide_Datos(int,int,double[*][*]);
void Producto_Matrices(int,int,double[*][*],int,double[*][*],double[*][*]);
void Muestra_Matriz(int,int,double[*][*]);

main()
{
    int vdima[2],vdimb[2];
    int seguir;

    while(1)
    {
        printf("Matriz A:\n");
        Pide_Dimension(vdima,TAM_MAX);

        while(1)                                //Comprueba que las dimensiones de las matrices son correctas a la hora de multiplicarlas
        {
            printf("Matriz B:\n");
            Pide_Dimension(vdimb,TAM_MAX);
            if(vdima[1]==vdimb[0])
                break;
            printf("No es posible multiplicar tales matrices\nRecuerde que col(A) tiene que ser igual a fil(B)\n");
        }

        double m1[vdima[0]][vdima[1]],m2[vdimb[0]][vdimb[1]],mfinal[vdima[0]][vdimb[1]];           //Declaración de las 3 matrices. Si nos deshacemos del vector asignando cada elemento a variables, queda más simples, pero meh.

        printf("\nMatriz A:\n");
        Pide_Datos(vdima[0],vdima[1],m1);
        printf("\nMatriz B:\n");
        Pide_Datos(vdimb[0],vdimb[1],m2);

        Producto_Matrices(vdima[0],vdima[1],m1,vdimb[1],m2,mfinal);

        printf("\nMatriz resultado de multiplicar A por B:\n");
        Muestra_Matriz(vdima[0],vdimb[1],mfinal);


        printf("\n\nTeclee 0 para salir, cualquier otro numero para continuar\n");
        scanf("%d",&seguir);
        if(seguir==0)
            break;
    }
}

void Pide_Dimension(int vdim[],int maximo)
{
    while(1)
    {
        printf("Introduzca las dimensiones de la matriz (mxn):\n");
        scanf("%dx%d",&vdim[0],&vdim[1]);
        if((vdim[0]>0)&&(vdim[0]<=maximo)&&(vdim[1]>0)&&(vdim[1]<=maximo))
            break;
        printf("Valores incorrectos\n");
    }
}

void Pide_Datos(int fil,int col,double m[fil][col])
{
    printf("Introduzca los %d elemenos de cada fila, separados por un espacio\nCuando escriba el ultimo, pulse intro\n",col);
    int i,j;
    for(i=0;i<fil;i++)
    {
        printf("[f%d]= ",i+1);
        for(j=0;j<col;j++)
        {
            scanf("%lf",&m[i][j]);
        }
    }
}

void Producto_Matrices(int fil_a,int col_a,double m1[fil_a][col_a],int col_b,double m2[col_a][col_b],double mfinal[fil_a][col_b])
{
    int i,j,n;                                                 //m1[i][j]   m2[k][n]==[j][n]    mfinal[i][n]
    double acumulador;
    for(i=0;i<fil_a;i++)                            //FILAS A
    {
        for(n=0;n<col_b;n++)                   //COLUMNAS B
        {
            acumulador=0;
            for(j=0;j<col_a;j++)                //COLUMNAS A y FILAS B
            {
                acumulador+=m1[i][j]*m2[j][n];
            }
            mfinal[i][n]=acumulador;
        }
    }
}

void Muestra_Matriz(int fil,int col,double m[fil][col])
{
    int i,j;

    for(i=0;i<fil;i++)
    {
        printf("[f%d]= ",i+1);
        for(j=0;j<col;j++)
        {
            printf("%lf ",m[i][j]);
        }
        printf("\n");
    }
}
