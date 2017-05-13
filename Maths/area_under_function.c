/* Author:      Eduardo Cáceres de la Calle
 * Subject:     Fundamentos de Informática
 * Degree:      Industrial Electronics and Automatic Control Engineering
 * University:  Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2014, during my first contact with C.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */


/*Curva base: f(x)=x^2*/
#include <stdio.h>
#include <math.h>

double PideDatos(double*,double*,int*);
double Rectangulo(double,double);
double Area_Real(double*,double*);

main()
{
    double inf,sup,base,x,a_rect,area,area_real;
        int num,i,salir;
    while(1)
    {
        area=0;
        salir=0;
        base=PideDatos(&inf,&sup,&num);

        for(i=0;i<num;i++)

        {
            x=inf+(i*base);
            a_rect=Rectangulo(x,base);
            area+=a_rect;
        }
        area_real=Area_Real(&inf,&sup);

        printf("El area comprendida entre x=%lf y x=%lf es %lf\n",inf,sup,area);
        printf("El area real que abarca la funcion es %lf\n",area_real);

        printf("\nTeclee cualquier numero salir\nTeclee 0 para seguir calculando areas\n");
        scanf("%d",&salir);
        if (salir)
            break;
    }
}

double PideDatos(double* p_inf,double* p_sup,int* p_num)
{
    int num;
    double base;

    while(1)
    {
        printf("Introduzca los limites inferior y superior, separados por un espacio\n");
        scanf("%lf %lf",p_inf,p_sup);

        if(*p_sup>*p_inf)
            break;
        printf("Error, limite inferior mayor que limite superior\nPrueba de nuevo\n\n");
    }

    printf("Introduzca el numero de rectangulos\n(a mayor numero, mejor aproximacion)\n");
    scanf("%d",p_num);
    if(*p_num<10)
    {
        *p_num=10;
        printf("El numero de rectangulos ha sido cambiado automaticamente a 10\n");
    }

    base=(double)(*p_sup-*p_inf)/(*p_num);                     /*CASTING FUNDAMENTAL*/
    return(base);
}

double Rectangulo(double x,double base)     /*Modificar para otra curva*/
{
    double area;

    area=base*pow(x,2);                                 /*FUNCIÓN*/
    return(area);
}

double Area_Real(double *p_inf,double *p_sup)   /*Modificar para otra curva*/
{
    double area;

    area=(pow(*p_sup,3)/3)-(pow(*p_inf,3)/3);           /*Evalución de la primitiva de la función)*/
    return(area);
}
