#include<stdio.h>
#include<stdlib.h>
int main(){
    
    char op;
    printf("EL JUEGO DEL GATO");
    printf("Se supone que seguiria programando aqui");
    
    do
    {
        printf("\n\nEL GATO\n");
        printf("\t1. Jugar");
        printf("\t2. Estadisticas");
        printf("\t3. Salir");
        printf("\tSeleccione una opcion: ");
        fflush(stdin);
        scanf(" %c",&op);
        switch(op)
        {
            case '1':
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
