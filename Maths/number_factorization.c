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

main()
{

    while(1)
    {
        int num,seguir,i=2,resto=0;

        printf("Numero: ");
        scanf("%d",&num);

        while (num!=1)
        {
            if(num==0)
                break;
            if (resto==0)                       //Evita escribir el número al no ser que en la iteracción se haya encontrado un divisor.
                printf("\n%d\t\t\t",num);           //Implica inicializar el resto a 0 para escribirlo al principio.

            resto=num%i;
            if(resto==0)
            {
                num/=i;
                printf("| %d",i);
            }
            else
                i++;                            //Sólo pasa de número cuando el resto no es cero, dadno posibilidad a un divisor con multiplicidad mayor a 1.
        }

        if(num!=0)
            printf("\n1");

        printf("\n\nPulse 0 para salir, cualquier otro numero para continuar\n");
        scanf("%d",&seguir);
        if(seguir==0)
            break;

        printf("\n");
    }
}
