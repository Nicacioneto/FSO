#include <stdio.h>
#include "libseno.h"

int calculaFatorial(int num){
  int resultado = num;
  if(num == 0)
  {
    resultado = 1;
  } else
  {
    num -=1;
    while(num>0){
      resultado *= num;
      num --;
    }
  }
    return resultado;
}

double power(double x, int y)
{
    double temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

double seno(double angulo){

  double somador = 0, dividendo = 0;

  int divisor=0, sinal = -1, k = 0;
  //Calcula a série
  for(k=0;k<4;k++){
    sinal=-sinal;
    dividendo = sinal*power(angulo,(1 + 2*k));
    divisor = calculaFatorial(1+2*k);
    somador += dividendo/divisor;
  }
  return somador;
}

double arc_seno(double seno){
  double somador = 0, dividendo = 0;
  int k = 0, divisor = 0;

  if(seno<1){
      for(k=0;k<4;k++){
        dividendo = power(seno, 1+2*k)*(1.0/2.0)*k;
        printf("dividendo = %lf  ",dividendo);
        divisor = calculaFatorial(k)+2*k*calculaFatorial(k);
        printf("divisor = %d\n",divisor);
        somador+=dividendo/divisor;
      }
    }
    return somador;

}
