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
#include <stdlib.h>     /*rand()*/
#include <time.h>       /*time()*/

void PideNumero(int*);
int Respuesta(int,int);

main()
{
    int iter,repetir,exito,valor,num;

    srand(time(NULL));                  /*Semilla del generador aleatorio*/
    printf("OK, let's play a game. I've pseudo-randomly chosen a number [1, 1000000]. Try to guess it\n");

    do
    {
        valor = rand() % 1000000 +1;                  /*Función que genera número aleatorio a partir de la semilla.*/
        iter=20;
        exito=0;
        repetir=0;
        while(1)
        {
            printf("You have %d tries.\n\n",iter);
            iter--;
            printf("\nAttemp number %d:  ",(16-iter));
            PideNumero(&num);
            exito=Respuesta(valor,num);

            if(exito)
                break;
            if(iter==0)
            {
                printf("You may need to take this game more seriously\nThe mysterious number you were looking for was: %d\n",valor);
                break;
            }
        }
        printf("\n\n To continue playing, type 1\n");
        scanf("%d",&repetir);
    } while (repetir==1);
    printf("\nEnd\n");
}

void PideNumero(int *p_num)
{
    while(1)
    {
        scanf("%d",p_num);
        if (*p_num>=0)
            break;
        printf("Don't enter negative numbers!\n");
    }
}

int Respuesta(valor,num)
{
    int acierto=0;

    if (valor==num)
    acierto=1;

    switch(acierto)
    {
    case 0:
        if (num>valor)
            printf("Your number is greater\n\n\n");
        else
            printf("Your number is lower\n\n\n");
        break;
    default:
        printf("Congrats, %d was the number I had chosen\n",valor);
        break;
    }
    return(acierto);
}
