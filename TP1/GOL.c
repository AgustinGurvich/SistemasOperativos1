#include "Game.h"

char* transformaFinal(char* entrada) {
  int largo = strlen(entrada);
  char* final = malloc(sizeof(char) * (largo + 2));
  strncpy(final, entrada, largo - 4);
  final[largo - 4] = '\0';
  strcat(final, "final");
  return final;
}

int main(int argc, char* argv[]) {
  int cantHilos = get_nprocs();
  game_t* juego = loadGame(argv[1]);
  congwayGoL(juego, cantHilos);
  char* guardado = transformaFinal(argv[1]);
  writeBoard(juego->board, guardado);
  free(guardado);
  return 0;
}