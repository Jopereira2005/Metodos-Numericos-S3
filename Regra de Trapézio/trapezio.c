#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcula_valor_k(float valorA, float valorB, float erro);
float func(float valor, float *multi, int grau);
void aloca_float(float **num, int tam);

int main() {
  float *multi = NULL;
  int grau;
  float valorA, valorB, divisoes, valorH, integral = 0;
  
  printf("Informe o grau da funcao (1 a 10): ");
  scanf("%i", &grau);
  aloca_float(&multi, grau+1);

	//Receber os multiplicadores. Dica: Armazenar os valores em um vetor.
	//aX^0 + bX^1 + cX^2 --->Indice do vetor igual ao expoente
  for(int i = grau; i >= 0; i--) {
    printf("Informe o fator multiplicador de x^%i(%c): ", i, 65+(grau-i));
    scanf("%f", multi+i);
  }

  //Exibindo a funcao recebida
  printf("A funcao recebida foi: ");
  for (int i = grau; i >= 0; i--) {
    float aux = *(multi + i);
    (aux < 0) ? aux = aux * -1 : 0;
           
    if (*(multi + i) != 0) {
      if (i != grau) {
        if (*(multi + i) < 0) {
          printf(" - ");
        } else {
          printf(" + ");
        }
      } else if (*(multi + i) < 0) {
        printf("-");
      }

      if (i == 0) {
        printf("%.2f", aux);
      } else if (i == 1) {
        printf("%.2fx", aux);
      } else {
        printf("%.2fx^%i", aux, i);
      }
    }
  }

  printf("\n\n");
  system("pause");
  printf("Digite o primeiro valor do intervalo: ");
  scanf("%f", &valorA);

  printf("Digite o segundo valor do intervalo: ");
  scanf("%f", &valorB);

  printf("Digite  quantidade de divisoes: ");
  scanf("%f", &divisoes);

  valorH = (valorB - valorA)/divisoes;

  integral = func(valorA, multi, grau) + func(valorB, multi, grau);
  for (int i = 1; i <= (divisoes - 1); i++) {
    integral += (2*(func((valorA + (i*valorH)), multi, grau)));
  }
  integral = integral*(valorH/2);

  printf("\nIntervalo: [%.0f;%.0f]", valorA , valorB);
  printf("\nH: %.4f", valorH);
  printf("\nIntegral: %.4f ", integral);
}

// Realiza a alocação de memória do tipo float
void aloca_float(float **num, int tam) {
  if((*num = (float *) realloc(*num, tam * sizeof(float))) == NULL) {
      printf("Erro de alocacao de memoria\n");
      exit(1);
  }
}

// Funcao que realiza o calculo com determinado valor
float func(float valor, float *multi, int grau) {
  float resultado = 0;
  for(int i = 0; i <= grau; i++) {
      resultado = resultado + (*(multi+i) * pow(valor, i));
  }

  return resultado;
}
