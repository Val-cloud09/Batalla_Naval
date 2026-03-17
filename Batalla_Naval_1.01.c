#include <stdio.h>
#include <string.h>

int main() {
    int tablero[5][5];
    int fila, columna;
    char jugador[25];
    char nom_barcos[3][40];
    int indice[5][5];
    int bar_hun = 0;

//---------------------------------------------------------- Pide nombre del usuario------------------------------------------------------------------- 
    printf("Nombre del jugador\n");
    fgets(jugador, sizeof(jugador),stdin);

    printf("Jugador: %s",jugador);
//----------------------------------------------------------- Nombre de los barcos--------------------------------------------------------------------
    for(int i = 0; i < 3; i++) {
        printf("Nombre del barco %d: ", i + 1);
        fgets(nom_barcos[i], sizeof(nom_barcos[i]), stdin);
}

    printf("Barco 1: %s", nom_barcos[0]);
    printf("Barco 2: %s", nom_barcos[1]);
    printf("Barco 3: %s", nom_barcos[2]);
// ---------------------------------------------------------inicializar tablero------------------------------------------------------------------
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tablero[i][j] = 0;}
}
//--------------------------------------------------------- Inicializar indice--------------------------------------------------------------------
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            indice[i][j] = -1;}
}

// -----------------------------------------------------Colocar barcos manualmente-----------------------------------------------------------------
    tablero[1][2] = 1;
    indice [1][2] = 0;
    tablero[3][4] = 1;
    indice [3][4] = 1;
    tablero[0][0] = 1;
    indice [0][0] = 2;

//------------------------------------------------------ Mostrar tablero inicial-------------------------------------------------------------------
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("~ ");
}
        printf("\n");
}
for(int turno=0;turno<5;turno++){
//---------------------------------------------------------- Pedir disparo-----------------------------------------------------------------------
    printf("Turno de %s",jugador);
    printf("Fila: ");
    scanf("%d", &fila);
    printf("Columna: ");
    scanf("%d", &columna);

//--------------------------------------------------- evaluar si hay barco o agua------------------------------------------------------------------
    if(tablero[fila][columna]==1){
        int id = indice[fila][columna];
        printf("\n%s impacto el barco %s\n", jugador, nom_barcos[id]);
        tablero[fila][columna]=3;
        bar_hun++;
    }
    else{
        printf("\n------agua-----\n");
        tablero[fila][columna]=4;
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++){

            if(tablero[i][j]==1){
                printf("~ ");
    }
            else if(tablero[i][j]==4){
                printf("O ");
    }
            else if(tablero[i][j]==3){
                printf("X ");
    }
            else{
                printf("~ ");
            }
        }
        printf("\n");
    }
//----------------------------------------------------------- condicion fin de la partida-----------------------------------------------------------
    if(bar_hun == 3){
        printf("\n%s gano la partida!\n", jugador);
        break;
}
}
    return 0;
}
