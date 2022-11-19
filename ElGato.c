#include<stdio.h>
#include<stdlib.h>

struct jugador
{
    char icono,nombre[10];
}Jugador_1,Jugador_2;

int main(){

    char op,tablero[3][3];
    int tablero_aux[3][3],pos=1,emp=0,casilla,cambio_jugador=0,band=0;
    for(int i=0;i<3;i++)
    {
        printf("\n");
        for(int j=0;j<3;j++)
        {
            tablero_aux[i][j] = pos;
            pos++;
            printf(" [%i]",tablero_aux[i][j]);
        }
    }
    Jugador_1.icono='x';
    Jugador_2.icono='o';
    printf("\n\nJugador 1: %c",Jugador_1.icono);
    printf("\n\nJugador 2: %c",Jugador_2.icono);

    for(int i=0;i<3;i++)
    {
        printf("\n");
        for(int j=0;j<3;j++)
        {
            tablero[i][j]=' ';
            printf(" [%c]",tablero[i][j]);
        }
    }

    do
    {
        printf("\n\nEL GATO\n");
        printf("1. Jugar\n");
        printf("2. Estadisticas\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        fflush(stdin);
        scanf(" %c",&op);

        switch(op)
        {
            case '1':
                do
                {

                    printf("\ningresa una casilla: ");
                    fflush(stdin);
                    scanf(" %i",&casilla);
                    if(cambio_jugador == 0)
                    {
                        for(int i=0;i<3;i++)
                        {
                            printf("\n");
                            for(int j=0;j<3;j++)
                            {
                                if(tablero_aux[i][j] == casilla)
                                {
                                    tablero[i][j] = Jugador_1.icono;
                                    tablero_aux[i][j] = 0;
                                    band=1;

                                }

                                printf(" [%c]",tablero[i][j]);

                            }
                        }
                        if(band!=1)
                        {
                            printf("Casilla no encontrada");
                            band=0;
                        }
                        cambio_jugador=1;
                    }
                    else
                    {
                        for(int i=0;i<3;i++)
                        {
                            printf("\n");
                            for(int j=0;j<3;j++)
                            {
                                if(tablero_aux[i][j] == casilla)
                                {
                                    tablero[i][j] = Jugador_2.icono;
                                    tablero_aux[i][j] = 0;
                                    band=1;

                                }

                                printf(" [%c]",tablero[i][j]);

                            }
                        }
                        if(band!=1)
                        {
                            printf("Casilla no encontrada");
                            band=0;
                        }
                        cambio_jugador=0;
                    }
                    emp++;
                }while(emp!=9);
                break;
            case '2':
                break;
            case '3':
                printf("\nPrograma terminado");
                break;
            default:
                printf("\nOpcion invalida");
        }
    }while(op!='3');





return 0;
}
