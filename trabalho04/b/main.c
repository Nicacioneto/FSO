#include <stdio.h>
#include <stdlib.h>

#include "../libseno.h"

int main(int argc, char const *argv[]) {
  if (argc == 3){
    const char* short_options = "as";

    int opcao = getopt (argc, argv, short_options);
    double angulo = strtod (argv[2], NULL);
    double valor_seno, arcoseno;

    switch (opcao) {
      case SENO:
        valor_seno = seno(angulo);
        printf("seno (%.2f) = %.4lf\n", angulo, valor_seno);
        break;
      case ARCOSENO:
        arcoseno = arc_seno(angulo);

        printf("arc_seno (%.2lf) = %.4lf\n", angulo, arcoseno);
        break;
      default:
        printf("Parametros incorretos.\n");
    }
  }
  else {
    printf("Parametros incorretos.\n");
  }
  return 0;
}
