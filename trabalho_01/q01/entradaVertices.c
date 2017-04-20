#include <stdio.h>
#include <stdlib.h>
#include "pontoQuadrilatero.h"
#include "entradaVertices.h"

void entrada(Quadrilatero *quadrilatero)
{
  int i = 0;	
  for(i = 0; i<4; i++)
  {
    scanf("%lf",&quadrilatero->vertices[i].x);
    scanf("%lf",&quadrilatero->vertices[i].y);
  }

}

void saida(int convex, double area)
{
  if(convex == 1)
  {
    printf("\nQuadrilatero convexo");
    printf("\nArea: %.2f\n",area);
  }else
  {
    printf("\nQuadrilatero não convexo\n");
  }
}
