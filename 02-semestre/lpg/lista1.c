#include <stdio.h>

void exercicio_1()
{
    printf("\n--- 1) Coordenadas de um Ponto ---\n");

    printf("Digite as coordenadas X e Y do ponto (separadas por espaco): ");
    double x, y;
    scanf("%lf %lf", &x, &y);

    if (x == 0 && y == 0)
    {
        printf("O ponto esta na origem.\n");
    }
    else if (x == 0)
    {
        printf("O ponto esta sobre o eixo Y.\n");
    }
    else if (y == 0)
    {
        printf("O ponto esta sobre o eixo X.\n");
    }
    else if (x > 0 && y > 0)
    {
        printf("O ponto esta no primeiro quadrante.\n");
    }
    else if (x < 0 && y > 0)
    {
        printf("O ponto esta no segundo quadrante.\n");
    }
    else if (x < 0 && y < 0)
    {
        printf("O ponto esta no terceiro quadrante.\n");
    }
    else if (x > 0 && y < 0)
    {
        printf("O ponto esta no quarto quadrante.\n");
    }
}

void exercicio_2()
{
    printf("\n--- 2) Tipos de Triangulos ---\n");
    printf("Digite os comprimentos dos tres lados do triangulo: ");
    double a, b, c, temp;

    scanf("%lf %lf %lf", &a, &b, &c);

    // 1. Ordenação decrescente para garantir que 'a' seja o maior lado
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a < c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b < c)
    {
        temp = b;
        b = c;
        c = temp;
    }

    // 2. Verificação se forma triângulo
    if (a >= b + c)
    {
        printf("NAO FORMA TRIANGULO\n");
    }
    else
    {
        // Classificação quanto aos ângulos
        if (a * a == b * b + c * c)
        {
            printf("TRIANGULO RETANGULO\n");
        }
        else if (a * a > b * b + c * c)
        {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        else
        {
            printf("TRIANGULO ACUTANGULO\n");
        }

        // Classificação quanto aos lados (bloco separado do bloco de ângulos)
        if (a == b && b == c)
        {
            printf("TRIANGULO EQUILATERO\n");
        }
        else if (a == b || b == c || a == c)
        {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
}
void exercicio_3()
{
    printf("\n--- 3) Tempo de Jogo ---\n");
    printf("Digite a hora de inicio e a hora de termino do jogo (separadas por espaco): ");

    int jogo =24, inicio =0, termino =0, duracao =0;
    scanf("%d %d", &inicio, &termino);

    duracao = termino - inicio;

    if (duracao <= 0)
    {
        duracao += jogo;
    }
    printf("A duracao do jogo foi de %d horas.\n", duracao);

}

void exercicio_4()
{
    printf("\n--- 4) Pares, Impares, Positivos e Negativos ---\n");
    printf("Digite 5 numeros inteiros (separados por espaco): ");

}

void exercicio_5()
{
    printf("\n--- 5) Medias Ponderadas ---\n");
    // Escreva o codigo do Exercicio 5 aqui
}

void exercicio_6()
{
    printf("\n--- 6) Soma de Impares Consecutivos I ---\n");
    // Escreva o codigo do Exercicio 6 aqui
}

void exercicio_7()
{
    printf("\n--- 7) Soma de Impares Consecutivos II ---\n");
    // Escreva o codigo do Exercicio 7 aqui
}

int main()
{
    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("    LISTA 1 - SELECAO E REPETICAO\n");
        printf("========================================\n");
        printf("1 - Coordenadas de um Ponto\n");
        printf("2 - Tipos de Triangulos\n");
        printf("3 - Tempo de Jogo\n");
        printf("4 - Pares, Impares, Positivos e Negativos\n");
        printf("5 - Medias Ponderadas\n");
        printf("6 - Soma de Impares Consecutivos I\n");
        printf("7 - Soma de Impares Consecutivos II\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("Escolha o exercicio que deseja executar (0-7): ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            exercicio_1();
            break;
        case 2:
            exercicio_2();
            break;
        case 3:
            exercicio_3();
            break;
        case 4:
            exercicio_4();
            break;
        case 5:
            exercicio_5();
            break;
        case 6:
            exercicio_6();
            break;
        case 7:
            exercicio_7();
            break;
        case 0:
            printf("Saindo do programa... Bons estudos!\n");
            break;
        default:
            printf("Opcao invalida! Por favor, digite um numero entre 0 e 7.\n");
        }
    } while (opcao != 0);

    return 0;
}