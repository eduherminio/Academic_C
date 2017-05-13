/* Author:      Eduardo Cáceres de la Calle
 * Subject:     Fundamentos de Informática
 * Degree:      Industrial Electronics and Automatic Control Engineering
 * University:  Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2014, during my first contact with C.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */


//Suma de dos matrices
void Suma_Matrices(int fil, int col, int m1[fil][col], int m2[fil][col], int suma[fil][col])
{
    int i,j;

    for(i=0;i<fil;i++)
    {
        for(j=0;j<col;j++)
        {
            suma[i][j]=m1[i][j]+m2[i][j];
        }
    }
}

//Producto de una matriz por un vector(vertical)
void Producto_Matriz_Vector(int fil,int col,int m[fil][col],int v[],int res[])
{
    int i,j,suma;

    for(i=0;i<fil;i++)
    {
        suma=0;
        for(j=0;j<col;j++)          //COL=TAM
        {
            suma+=m[i][j]*v[j];
        }
        res[i]=suma;
    }
}

//Producto de dos matrices
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

// Other useful functions

//Tamaño de una matriz
int Pedir_Fil_Col(int *fil, int *col, int maximo)
{
    int valor=1;

    printf("Introduzca el numero de filas y el de columnas separados por un espacio\n");
    scanf("%d %d",fil,col);

    if(*fil<0 || *fil>maximo || *col<0 || *col>maximo)
       valor=0;

    return(valor);
}

//Datos de una matriz (DOS DIMENSIONES)
void Pedir_Datos_Matriz(int fil, int col, int matriz[fil][col])
{
    int i,j;

    printf("Introduzca los datos de su matriz:\n");
    printf("Para ello, separe cada elemento por un espacio\nPulse intro cuando haya introducido %d elementos en cada fila\n",col);
    for(i=0;i<fil;i++)
    {
        printf("[f%d] ",i+1);
        for(j=0;j<col;j++)
        {
            scanf("%d",&matriz[i][j]);          //OJO: NO DEJAR ESPACIO DESPUÉS DEL scanf
        }
    }
}

//Datos de una matriz (DE MANERA SOSA o MÁS DE DOS DIMENSIONES)
void Pedir_Datos_Matriz(int fil,int col,int m[fil][col])
{
    int i,j;
    for(i=0;i<fil;i++)
        {
        for(j=0;j<col;j++)
            {
                printf("m[%d][%d]=",i,j);
                scanf("%d",&m[i][j]);
            }
        }
}

//Mostrar una matriz por pantalla (DOS DIMENSIONES)
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

//Mostrar una matriz por pantalla (DE MANERA SOSA o MÁS DE DOS DIMENSIONES)
void Muestra_Matriz(int fil,int col,int m[fil][col])
{
    int i,j;
    printf("\n");
    for(i=0;i<fil;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
