#include <stdio.h>
#include <stdlib.h>
#include <math.h>


main()
{
    int pontos, n, grau, cont, i, j;
    float Px, valorCalcular, Li;
    char resp;

    //Usando MATRIZES
    //float matriz[2][10]; //Linha 0: valores de X, Linha 1: valores de f(x)

    //Usando Vetores
    //float *valoresX = NULL;
    //float *valoresFX = NULL;

    printf("Digite o grau da funcao que deseja obter: ");
    scanf("%i", &grau);

	//Obtendo o número de pontos a partir do grau indicado
    pontos = grau + 1;

    //Alocação do tamanho solicitado
    //valoresX =  (float *)malloc(n * sizeof(float));
    //valoresFX = (float *)malloc(n * sizeof(float));

    for(cont=0; cont<pontos; cont++)
    {
        //MATRIZES
        //Recebendo os valores da tabela (valores de X e f(x)
        //Linha 0: Valores de X
        //Linha 1: Valores de f(x)

        //PONTEIROS
        //Exemplo de receber valores com ponteiros:
        //printf("Digite o valor do %i valor de X: ", cont);
        //scanf("%f", valoresX+cont);
    }

    do
    {
        printf("Digite o valor que deseja calcular: ");
        scanf("%f", &valorCalcular);
/*
        Px = 0;
        //Implementar o calculo do Teorema de Lagrange
        for(i.....
        {
            //Acessando os valores do ponteiro
            //*(valoresX+i)

            for(j...)
            {
				//Acessando os valores do ponteiro
                //*(valoresX+j)

            }

            //Calculo final do Px
            Px = ....
        }
*/

        fflush(stdin);
        printf("Deseja calcular outro valor (s/n)? ");
        scanf("%c", &resp);
    }while (resp == 's' || resp == 'S');

    //Liberando a memória
    //free(valoresX);
    //free(valoresFX);

    system("pause");
}
