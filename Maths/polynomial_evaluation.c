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
#include <math.h>
#define GRADO_MAX 20

int pedirvalor(int *,int);
void pedirdatos(int,float[]);
float Calcula_VectorX(int,float[]);

main()
{
    int grado,tam,grvalido,i,continuar;
    float x,polinomio;

    while(1)
    {
        grvalido=pedirvalor(&grado,GRADO_MAX);

        if(grvalido==1)
        {
            tam=grado+1;
            continuar=0;
            polinomio=0;
            float vx[tam];                          //Declaraciones de los vectores, después de fijar su tamaño y ver si es válido
            float v[tam];

            printf("Introduzca los coeficientes:\n");
            pedirdatos(tam,v);

            x=Calcula_VectorX(tam,vx);

            for(i=0;i<tam;i++)
            {
                polinomio+=(v[i]*vx[i]);
            }

            printf("\nEl valor del polnomio ");
            for(i=0;i<tam;i++)
            {
                printf("%+f(x^%d) ",v[i],i);                //%+f para escribir con signo
            }
            printf("en x=%f es %+f\n",x,polinomio);         //%+f para escribir con signo

        }
        else
        {
            printf("El grado introducido no es valido\n");
        }

        printf("\nTeclee 0 para salir, cualquier otro numero para continuar: ");
        scanf("%d",&continuar);
        if(continuar==0)
            break;
        printf("\n");
    }

}

int pedirvalor(int *grado,int maximo)  //Si pones TAM_MAX no funciona, es como si pusieras un numero
{
    int rango=0;

    printf("Grado del polinomio: ");
    scanf("%d",grado);
    if((*grado>0)&&(*grado<maximo))
        rango=1;

    return(rango);
}

void pedirdatos(int tam,float g[])
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Coeficiente %d: ",i+1);
        scanf("%f",&g[i]);
    }
}

float Calcula_VectorX(int tam, float g[])
{
    int i;
    float x;

    printf("Introduzca el valor de la variable x: ");
    scanf("%f",&x);

    for(i=0;i<tam;i++)
    {
        g[i]=pow(x,i);
    }

    return(x);
}
