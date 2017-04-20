#include <stdio.h>
#include <stdlib.h>
#include "pontoQuadrilatero.h"
#include "entradaVertices.h"
#include "operacoes.h"



int main()
{
  double distancia = 0;
  Quadrilatero *quadrilatero;

  quadrilatero = (Quadrilatero *)malloc(sizeof(Quadrilatero));

  if(!quadrilatero){
    printf("\nMemória insuficiente\n");
    exit(0);
  }else
  {

    entrada(quadrilatero);

    distancia = calculaComprimento(quadrilatero);

    saida(convexo(quadrilatero), calculaArea(quadrilatero));

  }
  return 0;
}
