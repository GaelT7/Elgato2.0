#include<stdio.h>
#include<stdlib.h>

struct jugador
{
    char icono,nombre[10];
}Jugador_1,Jugador_2;

int ganar(char tablero[3][3],char icono)
{
    int band=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0; j<3;j++)
        {
            if(tablero[0][0]==icono && tablero[0][1]==icono && tablero[0][2]==icono ||
               tablero[0][0]==icono && tablero[1][0]==icono && tablero[2][0]==icono ||
               tablero[0][0]==icono && tablero[1][1]==icono && tablero[2][2]==icono ||
               tablero[0][1]==icono && tablero[1][1]==icono && tablero[2][1]==icono ||
               tablero[0][2]==icono && tablero[1][2]==icono && tablero[2][2]==icono ||
               tablero[1][0]==icono && tablero[1][1]==icono && tablero[1][2]==icono ||
               tablero[2][0]==icono && tablero[2][1]==icono && tablero[2][2]==icono ||
               tablero[0][2]==icono && tablero[1][1]==icono && tablero[2][0]==icono)
                band=1;
        }
    }
    return band;
}

int main(){

    char op,tablero[3][3]={'1','2','3','4','5','6','7','8','9'},casilla;
    int pos=1,emp=0,cambio_jugador=0,band=0;


    Jugador_1.icono='X';
    Jugador_2.icono='O';
    printf("\n\nJugador 1: %c",Jugador_1.icono);
    printf("\n\nJugador 2: %c\n\n",Jugador_2.icono);

    for(int i=0;i<3;i++)
    {
        printf("\n");
        for(int j=0;j<3;j++)
        {
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

                    if(cambio_jugador == 0)
                    {

                        do
                        {
                            printf("\ningresa una casilla jugador 1: ");
                            fflush(stdin);
                            scanf(" %c",&casilla);

                            for(int i=0;i<3;i++)
                            {
                                printf("\n");
                                for(int j=0;j<3;j++)
                                {
                                    if(tablero[i][j] == casilla)
                                    {
                                        tablero[i][j] = Jugador_1.icono;
                                        band=1;
                                    }
                                    printf(" [%c]",tablero[i][j]);

                                }
                            }

                            if(band==0)
                            {
                                printf("\n\nCasilla no encontrada\n");
                            }
                        }while(band!=1);
                        band=0;
                        cambio_jugador=1;
                        if(ganar(tablero,Jugador_1.icono)==1)
                            {
                                printf("\nGANO JUGADOR 1");
                                break;
                            }
                    }
                    else
                    {

                        do
                        {
                            printf("\ningresa una casilla jugador 2: ");
                            fflush(stdin);
                            scanf(" %c",&casilla);

                            for(int i=0;i<3;i++)
                            {
                                printf("\n");
                                for(int j=0;j<3;j++)
                                {
                                    if(tablero[i][j] == casilla)
                                    {
                                        tablero[i][j] = Jugador_2.icono;
                                        band=1;
                                    }
                                    printf(" [%c]",tablero[i][j]);
                                }
                            }

                            if(band==0)
                            {
                                printf("\n\nCasilla no encontrada\n");
                            }
                        }while(band!=1);
                        band=0;
                        cambio_jugador=0;
                        if(ganar(tablero,Jugador_2.icono)==1)
                            {
                                printf("\nGANO JUGADOR 2");
                                break;
                            }
                    }
                    emp++;

                }while(emp!=9);

                if(emp==9)
                    printf("\n\nEMPATE");
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

