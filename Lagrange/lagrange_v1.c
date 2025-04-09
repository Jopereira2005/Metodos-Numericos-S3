#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void aloca_float(float **num, int tam);
float calculo_px(float valor_x, float *valores_x, float *valores_fx, int grau);

int main() {
    int pontos, grau;
    char op;
    float valor_x;
    float *valores_x = NULL;
    float *valores_fx = NULL;

    // Recebendo o grau da função
    printf("Digite o grau da funcao que deseja obter: ");
    scanf("%i", &grau);

	// Recebendo o número de pontos a partir do grau indicado
    pontos = grau + 1;

    // Alocação usando função para os valores de x e f(x) de acordo com o tamanho
    aloca_float(&valores_x, pontos);
    aloca_float(&valores_fx, pontos);

    for(int i = 0; i < pontos; i++) {
        // Recebendo os valores da tabela x | f(x)
        printf("\nDigite o %i valor de x da tabela: ", i+1);
        scanf("%f", valores_x+i);

        printf("Digite o %i valor de f(x) da tabela: ", i+1);
        scanf("%f", valores_fx+i);
    }

    // Cabeçalho da tabela x | f(x)
    printf("\n+---------------+-------------------+");
    printf("\n|       x       |        f(x)       |");
    printf("\n+---------------+-------------------+");

    for(int i = 0; i < pontos; i++) {
        // Imprimindo os valores da tabela x | f(x)
        printf("\n| %-13.4f | %-17.4f |", *(valores_x + i), *(valores_fx + i));
    }
    printf("\n+---------------+-------------------+\n\n");
    system("pause");

    do {
        // Recebendo o valor de x para o calculo 
        printf("\nDigite o valor de x no qual deseja interpolar: ");
        scanf("%f", &valor_x);

        // Mostrando valor de f(x)
        printf("O valor de f(x) de x = %.4f interpolado e: %.4f\n\n", valor_x, calculo_px(valor_x, valores_x, valores_fx, pontos));

        fflush(stdin);

        // Pergunta caso queira interpolar outro valor
        printf("\nDeseja interpolar outro valor de x?(S/N): ");
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');
}

// Realiza a alocação de memória do tipo float
void aloca_float(float **num, int tam) {
    if((*num = (float *) realloc(*num, tam * sizeof(float))) == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
}

// Realiza o calculo da interpolação de acordo com os valores inseridos
float calculo_px(float valor_x, float *valores_x, float *valores_fx, int grau) {
    float p_x = 0;
    for(int i = 0; i < grau; i++) {
        float l_i = 1;
        for(int j = 0; j < grau; j++) {
            if(i != j) {
                l_i *= (valor_x - *(valores_x+j))/(*(valores_x+i) - *(valores_x+j));
            }
        }
        p_x += (*(valores_fx+i) * l_i);
    }
    return p_x;
}