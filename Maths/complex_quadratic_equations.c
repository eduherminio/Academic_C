/* Author:      Eduardo Cáceres de la Calle
 * Subject:     Fundamentos de Informática
 * Degree:      Industrial Electronics and Automatic Control Engineering
 * University:  Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2014, during my first contact with C.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

// PD: Sorry for the goto's, I was starting to code, may fix them one day!

#include <stdio.h>
#include <math.h>

main ()
{
    float a,b,c,t,x,y,pas1,pas2;
    int continuar;

    while(1)
    {
        continuar=0;
        printf("Introduzca los valores de a, b y c separados por un espacio, siendo la ecuacion de segundo grado a resolver de la forma:\n"
               "ax^2+bx+c=0\n"
               "Si algun parametro es nulo, introduzca el valor 0\n\n");

        scanf("%f %f %f",&a,&b,&c);

        if (a==0)
        {
            if (b==0)
            {
                 printf("\nLa ecuacion introducida no tiene solucion\n");
                 goto fin;
            }
            else
            {
                x=(-c)/b;
                printf("\nLa ecuacion tiene solucion real\n"
                        "El valor de x que cumple la ecuacion es:\n");
                printf("x= %f",x);
                goto fin;
            }
        }
        else
        {
        t=((b*b)-(a*c*4));
        }

        if (t>0)
        {
            x=((-b)+sqrt(t))/(a*2);
            y=((-b)-sqrt(t))/(a*2);

            printf("\nLa ecuacion introducida tiene solucion real\n"
            "Los dos valores de x que cumplen la ecuacion son:\n");
            printf("x1= %f\n",x);
            printf("x2= %f\n",y);
        }

        else if (t==0)
        {
            printf("\nLa ecuacion introducida tiene solucion real\n"
            "El valor doble de x que cumple la ecuación es:\n");
            printf("x1=x2= %f",x);
        }
        else
        {
            printf("\nLa ecuacion introducida no tiene solucion real.\n"
                   "Sin embargo, sus soluciones imaginarias son:\n");

            pas1=((-b)/(a*2));
            pas2=(sqrt(-t))/(2*a);

            printf("x1= %f + %f i\n",pas1,pas2);
            printf("x2= %f - %f i\n",pas1,pas2);

            printf("Entiendase 'i' como la unidad imaginaria (la raiz cuadrada de -1)");
        }
        fin:                                                                                            //Uso de 'goto' casi inevitable, para saltar la parte indeseada;
        printf("\n\nTeclee 1 para salir, cualquier otro numero para continuar\n");                      //pero sin salirse del bucle (break) ni llegar al final (continue)
        scanf("%d",&continuar);

        if (continuar==1)
            break;
    }
}
