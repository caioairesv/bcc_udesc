#include <stdio.h>

void exercicio_1() {
    printf("\n--- 1) Coordenadas de um Ponto ---\n");
    float x, y;
    // Lê 2 valores com uma casa decimal representando as coordenadas num plano[cite: 7].
    scanf("%f %f", &x, &y);

    // Determina o quadrante ou se está sobre os eixos/origem[cite: 7].
    if (x == 0.0 && y == 0.0) {
        printf("Origem\n"); // Se na origem, escreve "Origem"[cite: 7].
    } else if (x == 0.0) {
        printf("Eixo Y\n"); // Se sobre o eixo Y, escreve "Eixo Y"[cite: 7].
    } else if (y == 0.0) {
        printf("Eixo X\n"); // Se sobre o eixo X, escreve "Eixo X"[cite: 7].
    } else if (x > 0.0 && y > 0.0) {
        printf("Q1\n");
    } else if (x < 0.0 && y > 0.0) {
        printf("Q2\n"); // Q2 corresponde a X negativo e Y positivo[cite: 7].
    } else if (x < 0.0 && y < 0.0) {
        printf("Q3\n"); // Q3 corresponde a X e Y negativos[cite: 7].
    } else if (x > 0.0 && y < 0.0) {
        printf("Q4\n");
    }
}

void exercicio_2() {
    printf("\n--- 2) Tipos de Triangulos ---\n");
    double a, b, c, temp;
    // Lê 3 valores de ponto flutuante[cite: 7].
    scanf("%lf %lf %lf", &a, &b, &c);

    // Ordena os valores em ordem decrescente, de modo que A represente o maior dos 3 lados[cite: 7].
    if (a < b) { temp = a; a = b; b = temp; }
    if (a < c) { temp = a; a = c; c = temp; }
    if (b < c) { temp = b; b = c; c = temp; }

    // Determina o tipo de triângulo formado[cite: 7].
    if (a >= b + c) {
        printf("NAO FORMA TRIANGULO\n"); // Se A >= B+C, não forma triângulo[cite: 7].
    } else {
        if (a * a == b * b + c * c) {
            printf("TRIANGULO RETANGULO\n"); // Se A² = B² + C²[cite: 7].
        } else if (a * a > b * b + c * c) {
            printf("TRIANGULO OBTUSANGULO\n"); // Se A² > B² + C²[cite: 7].
        } else {
            printf("TRIANGULO ACUTANGULO\n"); // Se A² < B² + C²[cite: 7].
        }

        if (a == b && b == c) {
            printf("TRIANGULO EQUILATERO\n"); // Se os três lados forem iguais[cite: 7].
        } else if (a == b || b == c || a == c) {
            printf("TRIANGULO ISOSCELES\n"); // Se apenas dois dos lados forem iguais[cite: 7].
        }
    }
}

void exercicio_3() {
    printf("\n--- 3) Tempo de Jogo ---\n");
    int inicio, fim, duracao;
    // Lê a hora inicial e a hora final de um jogo[cite: 7].
    scanf("%d %d", &inicio, &fim);

    // Calcula a duração do jogo com um máximo de 24 horas[cite: 7].
    if (inicio < fim) {
        duracao = fim - inicio;
    } else {
        duracao = 24 - inicio + fim; // Pode começar num dia e terminar noutro[cite: 7].
    }

    printf("O JOGO DUROU %d HORA(S)\n", duracao); // Mostra a duração formatada[cite: 7].
}

void exercicio_4() {
    printf("\n--- 4) Pares, Impares, Positivos e Negativos ---\n");
    int n, valor;
    int pares = 0, impares = 0, positivos = 0, negativos = 0;

    // A entrada contém o valor N, seguido de N valores inteiros[cite: 7].
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);

        if (valor % 2 == 0) {
            pares++; // Conta quantos valores foram pares[cite: 7].
        } else {
            impares++; // Conta quantos valores foram ímpares[cite: 7].
        }

        if (valor > 0) {
            positivos++; // Conta quantos valores foram positivos[cite: 7].
        } else if (valor < 0) {
            negativos++; // Conta quantos valores foram negativos[cite: 7].
        }
    }

    // Imprime as mensagens formatadas uma por linha[cite: 7].
    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", impares);
    printf("%d valor(es) positivo(s)\n", positivos);
    printf("%d valor(es) negativo(s)\n", negativos);
}

void exercicio_5() {
    printf("\n--- 5) Medias Ponderadas ---\n");
    int n;
    float v1, v2, v3, media;
    
    // Lê 1 valor inteiro N que representa o número de casos de teste[cite: 7].
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // Cada caso de teste consiste em 3 valores reais[cite: 7].
        scanf("%f %f %f", &v1, &v2, &v3);
        // O primeiro valor tem peso 2, o segundo 3 e o terceiro 5[cite: 7].
        media = ((v1 * 2.0) + (v2 * 3.0) + (v3 * 5.0)) / 10.0;
        printf("%.1f\n", media); // Apresenta a média ponderada com uma casa decimal[cite: 7].
    }
}

void exercicio_6() {
    printf("\n--- 6) Soma de Impares Consecutivos I ---\n");
    int x, y, temp;
    int soma = 0;
    
    // Lê 2 valores inteiros X e Y[cite: 7].
    scanf("%d %d", &x, &y);

    // Garante que X é o menor valor para iterar corretamente
    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }

    // Calcula a soma dos números ímpares entre eles (sem incluir os próprios limites)[cite: 7].
    for (int i = x + 1; i < y; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }

    printf("%d\n", soma); // Imprime o valor inteiro da soma[cite: 7].
}

void exercicio_7() {
    printf("\n--- 7) Soma de Impares Consecutivos II ---\n");
    int n, x, y, temp, soma;
    
    // A primeira linha de entrada é um inteiro N correspondente à quantidade de casos[cite: 7].
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        soma = 0;
        // Cada caso de teste consiste em uma linha contendo dois inteiros X e Y[cite: 7].
        scanf("%d %d", &x, &y);

        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }

        // Apresenta a soma de todos os ímpares existentes entre X e Y[cite: 7].
        for (int j = x + 1; j < y; j++) {
            if (j % 2 != 0) {
                soma += j;
            }
        }
        printf("%d\n", soma); // Imprime a soma para cada caso de teste[cite: 7].
    }
}

int main() {
    int opcao;

    do {
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

        switch(opcao) {
            case 1: exercicio_1(); break;
            case 2: exercicio_2(); break;
            case 3: exercicio_3(); break;
            case 4: exercicio_4(); break;
            case 5: exercicio_5(); break;
            case 6: exercicio_6(); break;
            case 7: exercicio_7(); break;
            case 0: printf("A encerrar o programa...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}