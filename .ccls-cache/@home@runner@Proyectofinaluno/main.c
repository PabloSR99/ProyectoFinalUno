#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXCHAR 20
#define barrita "\n======================================\n"
#define barrita2 "\n--------------------------------------\n"

typedef struct {
  int numero;
  bool especial;
  char color[9];
} tipoCarta;

typedef struct {
  List *mano;
  char nombre[20];
  int numCartas;
} tipoJugador;

typedef struct {
  tipoCarta *ultimaJugada;
  bool reversa;
} tipoPartida;

tipoCarta *crearCarta() {

  srand(time(0));

  tipoCarta *carta= (tipoCarta*) malloc(sizeof(tipoCarta));
  carta->especial = false;
  carta->numero = rand() % 15;

  if (carta->numero < 13) {
    int colorNumero = rand() % 4 + 1;
    switch (colorNumero) {
    case 1:
      strcpy(carta->color, "Rojo");
      break;
    case 2:
      strcpy(carta->color, "Verde");
      break;
    case 3:
      strcpy(carta->color, "Azul");
      break;
    case 4:
      strcpy(carta->color, "Amarillo");
      break;
    default:
      break;
    }
  }

  if (carta->numero > 9)
    carta->especial = true;

  return carta;
}

bool esValida(tipoCarta carta, tipoCarta ultimaJugada) {
  // sin tienen igual simbolo se puede tirar, reserva, +2, +4, saltar estan
  // incluidos
  if (carta.numero == ultimaJugada.numero)
    return true;

  // sin tienen igual color se puede tirar, reserva, +2, +4, saltar estan
  // incluidos
  if (strcmp(carta.color, ultimaJugada.color))
    return true;

  return false;
}

void iniciarPartiada(tipoPartida* juego, List *listaJuego) {
  
  for (int i = 0; i < 4; i++) {
    
    tipoJugador* jugadorAux = (tipoJugador*) malloc(sizeof(tipoJugador));
    
    jugadorAux->numCartas = 7;
    
    if (i == 0){
      char nombreAux[20];
      scanf("%s", nombreAux);
      while (getchar() != '\n');
      
      strcpy(jugadorAux->nombre, nombreAux);
    }else if(i == 1){
      strcpy(jugadorAux->nombre, "CLAUDIO TOLEDO");
    }else if(i == 2){
      strcpy(jugadorAux->nombre, "MOHAMED DIAS");
    }else{
      strcpy(jugadorAux->nombre, "MR.HUNDOR");
    }
    
    jugadorAux->mano = createList();
    
    for (int f = 0; f < 7; f++) {
      tipoCarta *carta = crearCarta();
      pushCurrent(jugadorAux->mano, carta);
    }
    pushFrontCircular(listaJuego, jugadorAux);

  }
}

int main(void) {

  tipoPartida *juego = (tipoPartida*) malloc(sizeof(tipoPartida));

  juego->ultimaJugada = crearCarta();

  printf("%d\n", juego->ultimaJugada->numero);
  printf("%s\n", juego->ultimaJugada->color);
  if (juego->ultimaJugada->especial == true) {
    printf("es especial\n");
  } else {
    printf("no es especial\n");
  }
  List *listaJuego = createList();
  iniciarPartiada(juego, listaJuego);

  while(1){

    jugarCarta(juego, listaJuego);




    
  }


  
  return 0;
}
