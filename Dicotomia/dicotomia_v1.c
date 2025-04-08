#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x) {
  return pow(x, 3) + (4* pow(x, 2)) - 10 ;
}

int main() {
  double valorA = 1;
  double valorB = 2;
  double valorFuncA = func(valorA);
  double valorFuncB = func(valorB);
  double e = 0.03;
  double valorFuncM;
  double m;

  if((valorFuncA * valorFuncB) < 0) {
    double k = (log(fabs(valorA - valorB)) - log(e))/log(2);

    printf("+---------------------------------------+\n");
    printf("|              Informacoes              |\n");
    printf("+-------------------+-------------------+\n");
    printf("| Valor A: %-*.4f | Valor B: %-*.4f |\n", 8, valorA, 8, valorB);
    printf("+---------------+---+-------------------+\n");
    printf("| Valor e: %-*.2f | Valor k: %-*f |\n", 4, e, 12, k);
    printf("+----+----------+----------+----------+-+--------+----------+----------+-----------+-----------+\n");
    printf("|    | A        | B        | M        | f(A)     | f(B)     | f(M)     | f(A)*f(B) | f(A)*f(B) |\n");
    printf("+----+----------+----------+----------+----------+----------+----------+-----------+-----------+\n");
    for(int i = 0; i < ceil(k); i++) {
      m = (valorA+valorB)/2;
      valorFuncA = func(valorA);
      valorFuncB = func(valorB);
      valorFuncM = func(m);
      if((valorFuncA * valorFuncM) < 0) {
        valorB = m;
      } else if ((valorFuncB * valorFuncM) < 0) {
        valorA = m;
      } else {
        printf("\nPonto 0 = %.4f", m);
      }
    printf("| %-*d | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f |\n", 2, i+1, 8, valorA, 8, valorB, 8, m, 8, valorFuncA, 8, valorFuncB, 8, valorFuncM, 9, (valorFuncA * valorFuncM), 9, (valorFuncB * valorFuncM));
    }
    printf("+----+----------+----------+----------+----------+----------+----------+-----------+-----------+\n");

    printf("\nPonto 0 e aproximadamente = %.4f", m);

  } else {
    printf("Valor do ponto 0 ja foi encontrado");
  }
}