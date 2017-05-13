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
#include <string.h>
#define MAX_COD 10
#define MAX_REF 1000
#define D 0         //DÍA
#define M 1         //MES
#define A 2         //AÑO

typedef struct
{
    char cod[MAX_COD];
    int fecha[3];
    int num;
    float precio;
}PRODUCTO;

void Muestra(PRODUCTO);                        //No se pone PRODUCTO prod
PRODUCTO Crea_Referencia(void);                //Es de tipo PRODUCTO porque va a devolver un vector de estructura, como se puede ver en la declaración
int Elige_Opcion(void);
int Borra_Referencia(PRODUCTO[],int *);

main()
{
    PRODUCTO prod[MAX_REF]={0};                 //Acumula los datos introducidos
    int opcion,num_referencia=0,i=0;
    int j,borrado;

    do
    {
        opcion=Elige_Opcion();
        switch (opcion)
        {
        case 0:
            printf("Fin del programa");
            break;

        case 1:
            prod[i]=Crea_Referencia();
            i++;
            break;

        case 2:
            printf("\n\tref.\tfecha\t\tnum.\tprecio\n");
            for(j=0;j<i;j++)
            {
                printf("%d.\t",j+1);
                Muestra(prod[j]);                   //SE PASA EL ELEMENTO DL VECTOR, NO TODO EL VECTOR
            }
            break;

        case 3:
            borrado=Borra_Referencia(prod,&i);
            i=i-borrado;                                    //CLAVE Evita que queden huecos 'vacíos' cada vez que se borra, pero hay que poner un contador para ver si se ha borrado algo o no
            break;

        default:
            printf("Opcion no valida\n");
            continue;
        }
    }while(opcion!=0);
}

int Elige_Opcion(void)
{
    int eleccion;

    printf("\n0. Salir\n"
           "1. Crear nueva referencia\n"
           "2. Mostrar todas las referencias\n"
           "3. Borrar referencia\n");
    scanf("%d",&eleccion);

    return(eleccion);
}

PRODUCTO Crea_Referencia(void)
{
    int longitud;

    PRODUCTO aux;

    while(1)
    {
        printf("num ref.: ");
        scanf("%s",&aux.cod);
        longitud=strlen(aux.cod);           //Uso de strlen para cerciorarse de introducir una referencia de menos de 10 caracteres
        if (longitud<MAX_COD)
            break;
        printf("Referencia demasiado larga\n");
    }

    printf("Fecha(dd/mm/aaaa): ");
    scanf("%d/%d/%d",&aux.fecha[D],&aux.fecha[M],&aux.fecha[A]);    //Uso propuesto de D,M,A como 1,2,3 para hacer algo más legible el código

    printf("nº items: ");
    scanf("%d",&aux.num);

    printf("Precio(euros): ");
    scanf("%f",&aux.precio);
    printf("\n");

    return(aux);
}

void Muestra(PRODUCTO prod)         //Saca los datos de UNA referencia
{
    printf("%s\t",prod.cod);
    printf("%d/%d/%d\t",prod.fecha[D],prod.fecha[M],prod.fecha[A]);
    printf("%d\t",prod.num);
    printf("%f",prod.precio);
    printf("\n");
}

int Borra_Referencia(PRODUCTO prod[],int *num)
{
    char cod[MAX_COD];
    int opcion,i,j;
    int contador=0,existeref=0;

    printf("Introduzca el codigo: ");
    scanf("%s",cod);

    for(i=0;i<*num;i++)
    {
        if(strcmp(cod,prod[i].cod)==0)
        {
            existeref++;
            printf("Esta seguro de que quiere borrar esta referencia?\n");
            Muestra(prod[i]);
            printf("1. Si\n");
            scanf("%d",&opcion);
            if (opcion==1)
            {
                contador++;
                for(j=i;j<(*num);j++)
                {
                    prod[j]=prod[j+1];
                }
            }
        }
    }
    if(contador==0)
        printf("\nNo existe esa referencia\n");

        return(contador);
}
