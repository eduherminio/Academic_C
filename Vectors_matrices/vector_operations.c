/* Author:      Eduardo Cáceres de la Calle
 * Subject:     Fundamentos de Informática
 * Degree:      Industrial Electronics and Automatic Control Engineering
 * University:  Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2014, during my first contact with C.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */


//Producto escalar
float productoescalar(int tam, float v1[],float v2[])
{
    float prod,escalar=0;
    int i;

    for(i=0;i<tam;i++)
    {
        prod=v1[i]*v2[i];
        escalar+=prod;
    }
    return(escalar);
}

//Suma de los elementos de un vector
float Suma_Elementos_Vector(int tam, float v[])
{
    int i;
    float suma;

    suma=0;
    for(i=0;i<tam;i++)
        suma+=v[i];

    return(suma);
}

//Halla el elemento menor y mayor de un vector
void Min_Max(float v[],int tam,float mM[])                   //No hace falta introducir el tamaño de mM, pues no se usa en iteración alguna
{
    int i;

    mM[0]=v[0];
    mM[1]=v[0];

    for(i=1;i<tam;i++)                              //i=1, aunque técnicamente no sería necesario
    {
        if(v[i]<mM[0])
            mM[0]=v[i];
        if(v[i]>mM[1])
            mM[1]=v[i];
    }
}

//Averiguar si un vector es capicúa
int Es_Capicua(float v[],int tam)
{
    int i,capicua=1;

    for(i=0;i<tam;i++)
    {
        if(v[i]==v[tam-1-i])
            continue;

        capicua=0;
        break;
    }
    return(capicua);
}

// Other useful functions

//Tamaño de un vector
int Pedir_Valor(int *valor, int maximo)
{
     int rango=1;

    printf("Introduzca el tamanio del vector: ");
    scanf("%d",valor);

    if ((*valor>0)&&(*valor<=maximo))
        rango=0;

    return(rango);
}

//Datos de un vector
void Pedir_Datos(int tam,float v[])
{
    int i;

    printf("Introduzca cada uno de los componentes del vector:\n");
    for(i=0;i<tam;i++)
    {
        printf("Elemento %d: ",i+1);
        scanf("%f",&v[i]);
    }
    printf("\n");
}

//Mostrar un vector por pantalla (VERTICAL)
void Muestra_Vector(int fil,int res[])
{
    int i;

    printf("\nEl vector resultante es:\n");
    for(i=0;i<fil;i++)
    {
        printf("[v%d]=%d\n",i+1,res[i]);
    }
}

//¿Vector contenido en otro vector?         n(v)>m(W)
int encuentra_subvector(int v[], int n, int w[], int m)
{
    int i,j,k,l=0;
    int ok=0;
    int acumul=0;

    for(i=0;i<n;i++)
    {
        if(w[0]==v[i])                          //Si encuentra una coincidencia entre el primer miembro del vector pequeño y cualquiera del grande:
        {
            k=i;
            while(v[k]==w[l])                   //Nuevos contadores para ambos vectores:
            {                                   //  -   El del vector grande, 'k', debe ser igual a 'i', ya que sigue comprobando
                acumul++;                       //          a partir de la posición en la que se ha encontrado  la coincidencia
                l++;                            //  -   El del vector pequeño, 'l' debe empezar en 0 (inicializado en la declaración).

                k++;
            }
        }
        if (acumul==m)                          //Si, en efecto, son iguales, salir
        {
            ok=1;
            break;
        }
        acumul=0;
    }
    return ok;
}
