double power(double base, int exp) {

    if( exp == 0)
       return 1;
    double temp = power(base, exp/2);
    if (exp%2 == 0)
        return temp*temp;
    else {
        if(exp > 0)
            return base*temp*temp;
        else
            return (temp*temp)/base; //negative exponent computation
    }

}


double seno(double angulo){
  int a,sinal,b,c;
	double fat,rad,soma,expoente;
	soma=0;
	sinal=1;
	expoente=1;
	fat=1;
	b=1;
  rad=angulo*3.1415/180;

  for(a=1;a<=3;a+=1)
	{
		for(c=1;c<=b;c+=1)
			  fat=fat*c;
	  soma=soma+sinal*power(rad,expoente)/fat;
		expoente+=2;
		b+=2;
		fat=1;
		sinal=-sinal;
 }

    return soma;
}
