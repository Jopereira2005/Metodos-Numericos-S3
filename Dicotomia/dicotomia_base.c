#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Dicas:
        Potencia: pow(base, expoente)
        Arredondar para cima: ceil(valor)
        Modulo/ValorAbsoluto: fabs(valor)
*/


//Prototipo das funcoes
//Criar funcao para calcular a DICOTOMIA
float CalculaValorK(float a, float b, float erro);
float funcaoX(float ponto);
void ImprimirCabecalhoTabela();
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB);

int grau;
float multi[7]; //Indice 0 a 6
/*
PONTEIROS - DICAS

//Criar uma variavel tipo ponteiro
float *myVar = NULL;

//Alocacao do tamanho solicitado (grau indicado)
myVar = (float *)malloc(tamanho * sizeof(float));

//Dentro do for para receber os valores
scanf("%f", myVar+i);

//Acessando os valores do vetor
//*(myVar+i)

//Liberando a memoria
//free(myVar);
*/

main()
{
    int i;

    //printf("%-9i|%8i\n", 19, 12);

	//Receber o grau da funcao entre 2 a 6
    printf("Informe o grau da funcao (2 a 6): ");
    scanf("%i", &grau);

	//Receber os multiplicadores. Dica: Armazenar os valores em um vetor.
	//aX^0 + bX^1 + cX^2 --->Indice do vetor igual ao expoente
    for(i=grau; i>=0; i--)
    {
        printf("Informe o fator multiplicador de x^%i(%c): ", i, 65+(grau-i));
        scanf("%f", &multi[i]);
    }


    //Exibindo a funcao recebida
    printf("A funcao recebida foi: ");
    for(i=grau; i>=0; i--)
    {
        if(i==0)
            printf("%.2f = 0", multi[i], i);
        else
            printf("%.2fx^%i + ", multi[i], i);
    }


    printf("\n\n");
    system("pause");
    printf("\n\n");

    printf("Resultado: %f %f %f\n", funcaoX(0), funcaoX(1), funcaoX(2));
    system("pause");
    //Receber os valores de
        //a, b, erro

	//Verificar se no intervalo [A, B] existe zero de funcao

	//Se existir encontar o valor de K
	//K = CalculaValorK(A, B, Erro)

    //Exibindo o cabecalho
    ImprimirCabecalhoTabela();

    //while (I <= K)
    //{

        //Implementacao da DICOTOMIA

        //Exibindo os valores na tabela
        ImprimirTabela(1, 2, 3, 4, 5, 6, 7, '+', '-');
    //}

    system("pause");
}


//Realiza o calculo do K (numero de passo)
float CalculaValorK(float a, float b, float erro)
{
    float fValorK;

    //Realizar o calculo do valor do K
    fValorK = (log10(b-a) - log10(erro))/(log10(2));


    return ceil(fValorK);
}

//Funcao que realiza o calculo em em determinado ponto
float funcaoX(float ponto)
{
    int i;
    float resultado;
    resultado = 0;

    for(i=0; i<=grau; i++)
    {
        resultado = resultado + multi[i]*pow(ponto, i);
    }

    return resultado;
}

//Imprimindo o cabecalho
void ImprimirCabecalhoTabela()
{
	/*
    //Impressao do cabecalho
    printf("I |  a\t|  b\t|  m\t|  f(a)\t|  f(b)\t|  f(m)\t| fa*fm\t| fm*fb\t|\n");
    printf("--+-----+-------+-------+-------+-------+-------+-------+-------+\n");
	*/
	//Impressao do cabecalho
    printf("I |\ta\t|\tb\t|\tm\t|\tf(a)\t|\tf(b)\t|\tf(m)\t|fa*fm\t|fm*fb\t|\n");
    printf("--+-------------+---------------+---------------+---------------+---------------+---------------+-------+-------+\n");

}

//Imprimindo a tabela com os valores
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB)
{
    //printf("%i |%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%c\t|%c\t|\n", iteracao, a, b, m, fA, fB, fM, fAfM, fMfB);
	printf("%i |%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%c\t|%c\t|\n", iteracao, a, b, m, fA, fB, fM, fAfM, fMfB);
}
