#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char const *argv[]) {
  if (argc == 3){
    const char* short_options = "as";
    int opcao = getopt (argc, argv, short_options);

    double angulo = strtod (argv[2], NULL);

    double (*funcao_seno)(double)
    double (*funcao_arc_seno)(double);
    double valor_seno = 0;
    double valor_arc_seno = 0;

    void* handle = dlopen ("./libseno.so", RTLD_LAZY);
    *(void**) (&funcao_seno) = dlsym (handle, "seno");

    switch (opcao) {
      case 's':
        valor_seno = (*funcao_seno)(angulo);
        printf("seno (%.2lf) = %.4lf\n", angulo, valor_seno);
        dlclose (handle);
        break;
      case 'a':
        *(void**) (&funcao_arc_seno) = dlsym (handle, "arc_seno");
        valor_arc_seno = (*funcao_arc_seno)(angulo);
        dlclose(handle);

        printf("arc_seno (%.2lf) = %.4lf\n", angulo, valor_arc_seno);
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
