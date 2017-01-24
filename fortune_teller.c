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
#include <math.h>

main()
{
    int inf=0,sup=1000000,solucion=0,contador=1,again=0;
    int num,valor;

    do
    {

        printf("Let's play a game\n\nChoose a number between 0 & 1.000.000\nWrite it down, you little cheater!\nI bet I guess your number asking you only 20 questions (or even less)\n\n");

        printf("These are the rules:\n");
        printf("If the number is correct, enter 1\nIf your number is less than the one showed, enter 2\nOn the other hand, if it's greater, enter 3\n\n");

        while (1)
        {
            num=(sup+inf)/2;
            printf("Is your secret number %d ?\n",num);
            scanf("%d",&valor);

            switch (valor)
            {
            case 1:
                solucion=1;
                break;
            case 2:
                sup=num;
                break;
            case 3:
                inf=num;
                break;
            }
            if (solucion)
                break;
            contador++;
        }
        fin:
            printf("Game over, I won\n");
            printf("I've used (only) %d questions :)\n\n",contador);

            printf("Wanna play again?\nYeah! ->\tHit any number, but 0\nMaybe later ->\tHit 0\n");
            scanf("%d",&again);

    } while (again!=0);

}
