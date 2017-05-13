/* Author: 	    Eduardo Cáceres de la Calle
 * Subject: 	Fundamentos de Informática
 * Degree:      Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2014, during my first contact with C.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime_tablero(int [][3]);
void rellena_usuario(int [][3]);
void rellena_ordenador(int [][3],int);
int comprobar3enraya(int [][3]);
int aleatorio(int);

main()
{
    int comenzar=0;
    printf("TRES EN RAYA\n\n");
    printf("El numero 0 simboliza las casillas vacias\nEl numero 1 simboliza sus fichas\nEl numero 2 simboliza las fichas del ordenador\n");
    while(1)
    {
        printf("\nCuando este preparado para jugar, pulse 1\n");
        scanf("%d",&comenzar);
        if(comenzar==1)
            break;
    }

    while(1)
    {
        int tablero[3][3]={0};                          //Con inicialización en 0 (casilla sin marcar)
        unsigned int num;
        int turno=0,i,j,contador=0,fin,salir;

        srand(time(NULL));

                                                        //Sortea quién empieza el juego
        num=rand();
        if(num%2)               //Existe resto -> numero impar -> empiezo yo
            turno=1;

        printf("Tablero inicial:\n");
        imprime_tablero(tablero);
        printf("\n\n");

        while(1)
        {
            if(contador>=9)                                 //Comprueba empate
                break;

            if(turno==0)                                     //Mueve ordenador
            {
                //system("cls");                               //Limpia la pantalla, WINDOWS ONLY
                rellena_ordenador(tablero,contador);
                imprime_tablero(tablero);
                fin=comprobar3enraya(tablero);
                if(fin)
                    break;
                turno=1;
                contador++;
            }

            if(contador>=9)                                  //Comprueba empate
                break;

            rellena_usuario(tablero);
            imprime_tablero(tablero);                        //Mueve usuario
            fin=comprobar3enraya(tablero);
            if(fin)
                break;
            turno=0;
            contador++;
        }
        if(contador>=9)
            printf("\nmmm empate.\n");
        else if(fin==1)
            printf("\nUsted gana, bien hecho\n");
        else
            printf("\nGano yo, otra vez sera.\n");
        printf("\n*******************************\n*******************************\n**Eduardo Caceres de la Calle**\n**          16/08/14         **\n*******************************\n*******************************\n");
        printf("\nTeclee 0 para jugar otra partida, otro numero para salir\n");
        scanf("%d",&salir);
        if(salir==0)
            continue;
        break;
        //system("cls");                WINDOWS ONLY
    }
}

void imprime_tablero(int tablero[][3])
{
    int i,j;

    printf("\n\t\t[c1]\t[c2]\t[c3]\n\n");

    for(i=0;i<3;i++)
    {
        printf("[f%d]\t\t",i+1);
        for(j=0;j<3;j++)
        {
            printf("%d\t",tablero[i][j]);
        }
        printf("\n");
    }
}

void rellena_usuario(int tablero [][3])
{
    int f,c;

    while(1)                                                //Ojo con la correspondencia entre las coordenadas reales y las de los vectores
    {
        printf("SU TURNO:\n");
        printf("Tus coordenadas (f c):\n");
        scanf("%d %d",&f,&c);
        if(tablero[f-1][c-1]==0)
        {
            tablero[f-1][c-1]=1;
            break;
        }
        printf("Elija una casilla vacia, por favor\n");
    }
}

void rellena_ordenador(int tablero[][3],int comienzo)   //Se pasa el contador por valor para adulterar luego
{
    int f,c,adulteracion;

    while(1)                                                     //Ojo con la correspondencia entre las coordenadas reales y las de los vectores
    {
        adulteracion=1;
        while(1)        //Adulteración 1: consigue o evita tres en raya              (el bucle simplemente agrupa los if's)
                        //1ª condición: dos en raya; 2ª condición: no vale dos en raya de ceros (tiene que ser 1 o 2); 3ª condición: que esté libre la casilla de destino
        {
        //Primero revisa si puede finalizar la partida, ganando
            if(tablero[0][0]==tablero[0][1] && tablero[0][0]==2 && tablero[0][2]==0)            //Columna 1
                tablero[0][2]=2;
            else if(tablero[0][0]==tablero[0][2] && tablero[0][0]==2 && tablero[0][1]==0)
                tablero[0][1]=2;
            else if(tablero[0][1]==tablero[0][2] && tablero[0][1]==2 && tablero[0][0]==0)
                tablero[0][0]=2;

            else if(tablero[1][0]==tablero[1][1] && tablero[1][0]==2 && tablero[1][2]==0)        //Columna 2
                tablero[1][2]=2;
            else if(tablero[1][0]==tablero[1][2] && tablero[1][0]==2 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[1][2] && tablero[1][1]==2 && tablero[1][0]==0)
                tablero[1][0]=2;

            else if(tablero[2][0]==tablero[2][1] && tablero[2][0]==2 && tablero[2][2]==0)        //Columna 3
                tablero[2][2]=2;
            else if(tablero[2][0]==tablero[2][2] && tablero[2][0]==2 && tablero[2][1]==0)
                tablero[2][1]=2;
            else if(tablero[2][1]==tablero[2][2] && tablero[2][1]==2 && tablero[2][0]==0)
                tablero[2][0]=2;

            else if(tablero[0][0]==tablero[1][0] && tablero[0][0]==2 && tablero[2][0]==0)        //Fila 1
                tablero[2][0]=2;
            else if(tablero[0][0]==tablero[2][0] && tablero[0][0]==2 && tablero[1][0]==0)
                tablero[1][0]=2;
            else if(tablero[1][0]==tablero[2][0] && tablero[1][0]==2 && tablero[0][0]==0)
                tablero[0][0]=2;

            else if(tablero[0][1]==tablero[1][1] && tablero[0][1]==2 && tablero[2][1]==0)        //Fila 2
                tablero[2][1]=2;
            else if(tablero[0][1]==tablero[2][1] && tablero[0][1]==2 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[2][1] && tablero[1][1]==2 && tablero[0][1]==0)
                tablero[0][1]=2;

            else if(tablero[0][2]==tablero[1][2] && tablero[0][2]==2 && tablero[2][2]==0)        //Fila 3
                tablero[2][2]=2;
            else if(tablero[0][2]==tablero[2][2] && tablero[0][2]==2 && tablero[1][2]==0)
                tablero[1][2]=2;
            else if(tablero[1][2]==tablero[2][2] && tablero[1][2]==2 && tablero[0][2]==0)
                tablero[0][2]=2;

            else if(tablero[0][0]==tablero[1][1] && tablero[0][0]==2 && tablero[2][2]==0)        //Diagonal 1
                tablero[2][2]=2;
            else if(tablero[0][0]==tablero[2][2] && tablero[0][0]==2 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[2][2] && tablero[1][1]==2 && tablero[0][0]==0)
                tablero[0][0]=2;

            else if(tablero[0][2]==tablero[1][1] && tablero[0][2]==2 && tablero[2][0]==0)        //Diagonal 2
                tablero[2][0]=2;
            else if(tablero[0][2]==tablero[2][0] && tablero[0][2]==2 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[2][0] && tablero[0][2]==2 && tablero[0][2]==0)
                tablero[0][2]=2;
        //En el caso de que no se pueda ganar, revisa que pueda evitar la victoria del humano
             else if(tablero[0][0]==tablero[0][1] && tablero[0][0]==1 && tablero[0][2]==0)            //Columna 1
                tablero[0][2]=2;
            else if(tablero[0][0]==tablero[0][2] && tablero[0][0]==1 && tablero[0][1]==0)
                tablero[0][1]=2;
            else if(tablero[0][1]==tablero[0][2] && tablero[0][1]==1 && tablero[0][0]==0)
                tablero[0][0]=2;

            else if(tablero[1][0]==tablero[1][1] && tablero[1][0]==1 && tablero[1][2]==0)        //Columna 2
                tablero[1][2]=2;
            else if(tablero[1][0]==tablero[1][2] && tablero[1][0]==1 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[1][2] && tablero[1][1]==1 && tablero[1][0]==0)
                tablero[1][0]=2;

            else if(tablero[2][0]==tablero[2][1] && tablero[2][0]==1 && tablero[2][2]==0)        //Columna 3
                tablero[2][2]=2;
            else if(tablero[2][0]==tablero[2][2] && tablero[2][0]==1 && tablero[2][1]==0)
                tablero[2][1]=2;
            else if(tablero[2][1]==tablero[2][2] && tablero[2][1]==1 && tablero[2][0]==0)
                tablero[2][0]=2;

            else if(tablero[0][0]==tablero[1][0] && tablero[0][0]==1 && tablero[2][0]==0)        //Fila 1
                tablero[2][0]=2;
            else if(tablero[0][0]==tablero[2][0] && tablero[0][0]==1 && tablero[1][0]==0)
                tablero[1][0]=2;
            else if(tablero[1][0]==tablero[2][0] && tablero[1][0]==1 && tablero[0][0]==0)
                tablero[0][0]=2;

            else if(tablero[0][1]==tablero[1][1] && tablero[0][1]==1 && tablero[2][1]==0)        //Fila 2
                tablero[2][1]=2;
            else if(tablero[0][1]==tablero[2][1] && tablero[0][1]==1 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[2][1] && tablero[1][1]==1 && tablero[0][1]==0)
                tablero[0][1]=2;

            else if(tablero[0][2]==tablero[1][2] && tablero[0][2]==1 && tablero[2][2]==0)        //Fila 3
                tablero[2][2]=2;
            else if(tablero[0][2]==tablero[2][2] && tablero[0][2]==1 && tablero[1][2]==0)
                tablero[1][2]=2;
            else if(tablero[1][2]==tablero[2][2] && tablero[1][2]==1 && tablero[0][2]==0)
                tablero[0][2]=2;

            else if(tablero[0][0]==tablero[1][1] && tablero[0][0]==1 && tablero[2][2]==0)        //Diagonal 1
                tablero[2][2]=2;
            else if(tablero[0][0]==tablero[2][2] && tablero[0][0]==1 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[2][2] && tablero[1][1]==1 && tablero[0][0]==0)
                tablero[0][0]=2;

            else if(tablero[0][2]==tablero[1][1] && tablero[0][2]==1 && tablero[2][0]==0)        //Diagonal 2
                tablero[2][0]=2;
            else if(tablero[0][2]==tablero[2][0] && tablero[0][2]==1 && tablero[1][1]==0)
                tablero[1][1]=2;
            else if(tablero[1][1]==tablero[2][0] && tablero[0][2]==1 && tablero[0][2]==0)
                tablero[0][2]=2;
            else
                adulteracion=0;

            break;
        }

                        //Fin de la adulteración 1

        if(adulteracion==0)
        {
            //Adulteración 2:
            if(comienzo==0)     //Ordenador -> centro
            {
                tablero[1][1]=2;
                break;
            }

            //Adulteración 3:
            if(comienzo==1)     //Humano-Ordenador
            {
                if(tablero[1][1]==0 && (tablero[0][0]==1||tablero[0][2]==1||tablero[2][0]==1||tablero[2][2]==1))    //Humano(esquina)-Ordenador->centro
                    tablero[1][1]=2;
                else if(tablero[1][1]==0)       //Humano(lateral, ni centro ni esquina)-Ordenador->Esquina opuesta
                {
                    if(tablero[1][0]==1)
                        tablero[0][2]=2;
                    else if(tablero[0][1]==1)
                        tablero[2][0]=2;
                    else if(tablero[1][2]==1)
                        tablero[0][2]=2;
                    else if(tablero[2][1]==1)
                        tablero[0][2]=2;
                }
                else            //Humano(centro)-Ordenador->esquina (superior derecha, por ejemplo)
                    tablero[0][0]=2;
                break;
            }

            //Adulteración 4:
            if(comienzo==2) //Ordenador(centro)-Humano(cualquiera)-Ordenador -> esquina
            {
                if(tablero[0][0]==0)    //Ordenador -> esquina superior derecha
                    tablero[0][0]=2;
                else                    //Ordenador -> esquina superior izquierda
                    tablero[0][2]=2;
                break;
            }

            //Adulteración 5:
            if(comienzo==3)         //Humano-Ordenador-Humano-Ordenador
            {
                if(tablero[1][1]==1)                        //tablero[1][1]=1 implica que tablero[0][0]=2
                {                                             //En el caso de que el humano haya empezado con una casilla lateral, si en su segundo turno ocupa el centro esta adulteración no tiene efecto al darse la adulteración 1
                    /*tablero[2][2]=1, porque en caso contrario habría actuado la adulteración 1
                    2   0   0
                    0   1   0
                    0   0   1   */

                    tablero[0][2]=1;
                    break;
                }
                if(tablero[1][1]==2)                    //Si tablero[1][1]=2, humano empezó en una esquina
                {
                    //  1   0   0
                    //  0   2   ?
                    //  0   ?   ?       ? -> Posible 1

                    if(tablero[0][1]==0 && tablero[2][1]==0)
                        tablero[0][1]=2;
                    else if(tablero[1][0]==0 && tablero[1][2]==0)
                        tablero[1][0]=2;
                    break;
                }
            }


            //Si no se da ninguno de los casos anteriores (no hay adulteración):

            c=aleatorio(2);
            f=aleatorio(2);
            if(tablero[f][c]==0)
            {
                printf("Turno del PC: casilla (%d %d)\n\n",f+1,c+1);
                tablero[f][c]=2;
                break;
            }
        }
        else
            break;
    }
}

int comprobar3enraya(int tablero[][3])
{
    int gana=0;

    int i,j;
    int v[3];

    for(i=0;i<3;i++)                                //Comprueba filas
    {
        for(j=0;j<3;j++)
        {
            v[j]=tablero[i][j];
        }
        if((v[0]==v[1])&&(v[1]==v[2]))                        //No, no encontraba una manera mejor
            {
                gana=v[1];
                return(gana);
            }
    }

    for(j=0;j<3;j++)                                //Comprueba columnas
    {
        for(i=0;i<3;i++)
        {
            v[i]=tablero[i][j];
        }
        if((v[0]==v[1])&&(v[1]==v[2]))
            {
                gana=v[1];
                return(gana);
            }
    }
                                                    //Comprueba diagonal ppal
    v[0]=tablero[0][0];
    v[1]=tablero[1][1];
    v[2]=tablero[2][2];

    if((v[0]==v[1])&&(v[1]==v[2]))
    {
        gana=v[1];
        return(gana);
    }
                                                    //Comprueba diagonal secundaria
    v[0]=tablero[0][2];
    v[1]=tablero[1][1];
    v[2]=tablero[2][0];

    if((v[0]==v[1])&&(v[1]==v[2]))
        gana=v[1];

    return (gana);
}

int aleatorio(int sup)     //Devuelve un valor aleatorio entre 0 y sup
{
    return(rand()%(sup+1)); //Devuelve 0,1 o 2
}

