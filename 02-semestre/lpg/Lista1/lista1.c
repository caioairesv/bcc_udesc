#include <stdio.h>

void exercicio_1() {
    printf("\n--- 1) Coordenadas de um Ponto ---\n");
    float x, y;
    scanf("%f %f", &x, &y);

    // Verifica a posicao exata do ponto
    if (x == 0.0 && y == 0.0) {
        printf("Origem\n");
    } else if (x == 0.0) {
        printf("Eixo Y\n");
    } else if (y == 0.0) {
        printf("Eixo X\n");
    } else if (x > 0.0 && y > 0.0) {
        printf("Q1\n");
    } else if (x < 0.0 && y > 0.0) {
        printf("Q2\n");
    } else if (x < 0.0 && y < 0.0) {
        printf("Q3\n");
    } else if (x > 0.0 && y < 0.0) {
        printf("Q4\n");
    }
}

void exercicio_2() {
    printf("\n--- 2) Tipos de Triangulos ---\n");
    double a, b, c, temp;
    scanf("%lf %lf %lf", &a, &b, &c);

    // Ordena os lados para garantir que A seja o maior
    if (a < b) { temp = a; a = b; b = temp; }
    if (a < c) { temp = a; a = c; c = temp; }
    if (b < c) { temp = b; b = c; c = temp; }

    // Testa a condicao de existencia do triangulo
    if (a >= b + c) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        // Classificacao por angulos
        if (a * a == b * b + c * c) {
            printf("TRIANGULO RETANGULO\n");
        } else if (a * a > b * b + c * c) {
            printf("TRIANGULO OBTUSANGULO\n");
        } else {
            printf("TRIANGULO ACUTANGULO\n");
        }

        // Classificacao por lados
        if (a == b && b == c) {
            printf("TRIANGULO EQUILATERO\n");
        } else if (a == b || b == c || a == c) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
}

void exercicio_3() {
    printf("\n--- 3) Tempo de Jogo ---\n");
    int inicio, fim, duracao;
    scanf("%d %d", &inicio, &fim);

    // Calcula considerando que o jogo pode virar a noite
    if (inicio < fim) {
        duracao = fim - inicio;
    } else {
        duracao = 24 - inicio + fim;
    }

    printf("O JOGO DUROU %d HORA(S)\n", duracao);
}

void exercicio_4() {
    printf("\n--- 4) Pares, Impares, Positivos e Negativos ---\n");
    int n, valor;
    int pares = 0, impares = 0, positivos = 0, negativos = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);

        // Separa pares e impares
        if (valor % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        // Separa positivos e negativos (ignorando o zero)
        if (valor > 0) {
            positivos++;
        } else if (valor < 0) {
            negativos++;
        }
    }

    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", impares);
    printf("%d valor(es) positivo(s)\n", positivos);
    printf("%d valor(es) negativo(s)\n", negativos);
}

void exercicio_5() {
    printf("\n--- 5) Medias Ponderadas ---\n");
    int n;
    float v1, v2, v3, media;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%f %f %f", &v1, &v2, &v3);
        // Calcula a media com os pesos 2, 3 e 5
        media = ((v1 * 2.0) + (v2 * 3.0) + (v3 * 5.0)) / 10.0;
        printf("%.1f\n", media);
    }
}

void exercicio_6() {
    printf("\n--- 6) Soma de Impares Consecutivos I ---\n");
    int x, y, temp;
    int soma = 0;
    
    scanf("%d %d", &x, &y);

    // Garante que x e o menor valor para o laco for funcionar
    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }

    for (int i = x + 1; i < y; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }

    printf("%d\n", soma);
}

void exercicio_7() {
    printf("\n--- 7) Soma de Impares Consecutivos II ---\n");
    int n, x, y, temp, soma;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        soma = 0;
        scanf("%d %d", &x, &y);

        // Ordena x e y para iterar corretamente
        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }

        for (int j = x + 1; j < y; j++) {
            if (j % 2 != 0) {
                soma += j;
            }
        }
        printf("%d\n", soma);
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