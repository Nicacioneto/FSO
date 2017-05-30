#include <stdio.h>

int calculaFatorial(int num){
  int resultado = num;
  num -=1;
  while(num>0){
    resultado *= num;
    num --;
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

  int divisor=0, fat=0, sinal = -1, k = 0;
  //Calcula a série
  for(k=0;k<4;k++){
    sinal=-sinal;
    dividendo = sinal*power(angulo,(1 + 2*k));
    divisor = calculaFatorial(1+2*k);
    somador += dividendo/divisor;
  }
  return somador;
}


int main(){

double angulo = 0;
  printf("Informe o valor de x\n");
  scanf("%lf",&angulo);
  printf("seno = %lf\n",seno(angulo));
}
