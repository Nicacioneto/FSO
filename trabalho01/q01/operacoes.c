#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pontoQuadrilatero.h"

//Esta função calcula a distância entre dois pontos no plano cartesiano
double calculaComprimento(Quadrilatero *quadrilatero){

    double distancia = 0, potencia1 = 0, potencia2 = 0;

    potencia1 =  pow((quadrilatero->vertices[1].x - quadrilatero->vertices[0].x),2);

    potencia2 = pow((quadrilatero->vertices[1].y - quadrilatero->vertices[0].y),2);

    distancia = sqrt(potencia1+potencia2);

    return distancia;
}

//Esta função determina se o quadrilatero é ou não convexo
int convexo(Quadrilatero *quadrilatero)
{
  int i = 0;
  double det[4];



  for (i=0; i<4; i++)
  {

    det[i] = ((quadrilatero->vertices[(i+2)%4].x - quadrilatero->vertices[(i+1)%4].x) * (quadrilatero->vertices[(i+1)%4].y - quadrilatero->vertices[i%4].y));
    det[i]-= ((quadrilatero->vertices[(i+2)%4].y - quadrilatero->vertices[(i+1)%4].y) * (quadrilatero->vertices[(i+1)%4].x - quadrilatero->vertices[i%4].x));
  }

  if ((det[0] >= 0 && det[1] >= 0 && det[2] >= 0 && det[3] >= 0) || (det[0] <= 0 && det[1] <= 0 && det[2] <= 0 && det[3] <= 0) )
  {
  	 return 1;

  }else
  {
      return 0;
  }

}
double calculaArea(Quadrilatero *quadrilatero)
{
  int i = 0;
  double area = 0;
  for (i = 0; i < 2; ++i)
  {
      area += quadrilatero->vertices[i].x * quadrilatero->vertices[i+1].y;
      area -= quadrilatero->vertices[i+1].x * quadrilatero->vertices[i].y;
  }
  area = abs(area);

  return area;
}
