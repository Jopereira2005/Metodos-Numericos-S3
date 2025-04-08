#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcula_valor_k(float valorA, float valorB, float erro);
float func(float ponto, float *multi, int grau);
void imprimir_cabecalho_tabela();
void imprimir_final_tabela();
void imprimir_tabela(int iteracao, float valorA, float valorB, float valorM, float valorFuncA, float valorFuncB, float valorFuncM, float fAfM, float fMfB);
void aloca_float(float **num, int tam);

int main() {
    float *multi = NULL;
    int grau;
    float valorA, valorB, erro, m, valorFuncA, valorFuncB, valorFuncM, k;
    
    printf("Informe o grau da funcao (2 a 6): ");
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
    printf("Digite o valor de A: ");
    scanf("%f", &valorA);

    printf("Digite o valor de B: ");
    scanf("%f", &valorB);

    printf("Digite o erro: ");
    scanf("%f", &erro);

    valorFuncA = func(valorA, multi, grau);
    valorFuncB = func(valorB, multi, grau);
    
    if((valorFuncA * valorFuncB) < 0) {
        k = (log(fabs(valorA - valorB)) - log(erro))/log(2);
        imprimir_cabecalho_tabela();
        for(int i = 0; i < ceil(k); i++) {
            m = (valorA+valorB)/2;
            valorFuncA = func(valorA, multi, grau);
            valorFuncB = func(valorB, multi, grau);
            valorFuncM = func(m, multi, grau);
            if(i != 0) {
                if(valorFuncM == 0) {
                    imprimir_tabela(i ,valorA, valorB, m, valorFuncA, valorFuncB, valorFuncM, (valorFuncA * valorFuncM), (valorFuncB * valorFuncM));
                    break;
                }
                if((valorFuncA * valorFuncM) < 0) {
                  valorB = m;
                } else if ((valorFuncB * valorFuncM) < 0) {
                  valorA = m;
                }
            }
            imprimir_tabela(i ,valorA, valorB, m, valorFuncA, valorFuncB, valorFuncM, (valorFuncA * valorFuncM), (valorFuncB * valorFuncM));
          }
          imprimir_final_tabela();
          printf("\nPonto 0 e aproximadamente = %.4f", m);
    } else {
        printf("O ponto zero nao existe no intervalo estipulado.\n");
    }
}

// Realiza a alocação de memória do tipo float
void aloca_float(float **num, int tam) {
    if((*num = (float *) realloc(*num, tam * sizeof(float))) == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
}

// Realiza o calculo do K (numero de passo)
int calcula_valor_k(float valorA, float valorB, float erro){
    return ceil((log10(valorA-valorB) - log10(erro))/(log10(2)));
}

// Funcao que realiza o calculo em em determinado ponto
float func(float ponto, float *multi, int grau) {
    float resultado = 0;
    for(int i = 0; i <= grau; i++) {
        resultado = resultado + (*(multi+i) * pow(ponto, i));
    }

    return resultado;
}

// Imprime o cabecalho da tabela
void imprimir_cabecalho_tabela() {
    printf("+----+----------+----------+----------+-+--------+----------+----------+-----------+-----------+\n");
    printf("|    | A        | B        | M        | f(A)     | f(B)     | f(M)     | f(A)*f(M) | f(M)*f(B) |\n");
    printf("+----+----------+----------+----------+----------+----------+----------+-----------+-----------+\n");
}

// Imprime o final da tabela
void imprimir_final_tabela() {
    printf("+----+----------+----------+----------+----------+----------+----------+-----------+-----------+\n");
}

// Imprime os valores da tabela
void imprimir_tabela(int iteracao, float valorA, float valorB, float valorM, float valorFuncA, float valorFuncB, float valorFuncM, float fAfM, float fMfB){
    printf("| %-*d | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f | %-*.4f |\n", 2, iteracao+1, 8, valorA, 8, valorB, 8, valorM, 8, valorFuncA, 8, valorFuncB, 8, valorFuncM, 9, fAfM, 9, fMfB);	
}
