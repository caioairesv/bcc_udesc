#include <stdio.h>

//FUNCOES DOS EXERCICIOS

// Exercicio 1
int tipo_triangulo(float x, float y, float z) {
    // Verifica condicao de existencia do triangulo
    if (x >= y + z || y >= x + z || z >= x + y) {
        return 0; 
    }
    
    if (x == y && y == z) {
        return 1; // Equilatero
    }
    if (x == y || x == z || y == z) {
        return 2; // Isosceles
    }
    return 3; // Escaleno
}

// Exercicio 2
int maior_valor(int a, int b, int c) {
    int maior = a;
    
    // Atualiza apenas se encontrar um valor estritamente maior
    if (b > maior) maior = b;
    if (c > maior) maior = c;
    
    return maior;
}

// Exercicio 3
int is_digit(char c) {
    // Verifica pelo intervalo na tabela ASCII
    return (c >= '0' && c <= '9');
}

// Exercicio 4
int soma_impares_entre(int x, int y) {
    // Garante que x e o menor valor para iterar corretamente
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    
    int soma = 0;
    // Itera apenas entre os limites (exclusivo)
    for (int i = x + 1; i < y; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    return soma;
}

// Exercicio 5
int is_prime(int num) {
    if (num <= 1) return 0;
    
    // Otimizacao: verifica apenas ate a raiz quadrada
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Exercicio 6
int fibo(int n) {
    if (n == 1 || n == 2) return 1; 
    
    // Iteracao para encontrar o n-esimo termo
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Exercicio 7
int soma_especial(int n, int k, int x) {
    int soma = 0, count = 0;
    int atual = x;
    
    // Busca 'n' multiplos de 'k' a partir de 'x'
    while (count < n) {
        if (atual % k == 0) {
            soma += atual;
            count++;
        }
        atual++; 
    }
    return soma;
}

// Exercicio 8
int soma_n_iterativa(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) soma += i;
    return soma;
}

int soma_n_recursiva(int n) {
    if (n == 1) return 1; // Condicao de paragem
    return n + soma_n_recursiva(n - 1);
}

// Exercicio 9
float harm_iterativa(int n) {
    float soma = 0.0;
    // Uso de 1.0 forca a divisao de ponto flutuante
    for (int i = 1; i <= n; i++) soma += 1.0 / i;
    return soma;
}

float harm_recursiva(int n) {
    if (n == 1) return 1.0;
    return (1.0 / n) + harm_recursiva(n - 1);
}

// Exercicio 10
float fatorial(int n) {
    float f = 1.0;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

float e_iterativa(int n) {
    float soma = 0.0;
    for (int i = 0; i <= n; i++) soma += 1.0 / fatorial(i);
    return soma;
}

float e_recursiva(int n) {
    if (n == 0) return 1.0;
    return (1.0 / fatorial(n)) + e_recursiva(n - 1);
}


//INTERFACES DOS EXERCICIOS

void exercicio_1() {
    float x, y, z;
    printf("Insere os tres lados do triangulo: ");
    scanf("%f %f %f", &x, &y, &z);
    
    int tipo = tipo_triangulo(x, y, z);
    printf("Codigo que a funcao devolveu: %d\n", tipo);
    
    if (tipo == 0) printf("Os lados nao formam um triangulo.\n");
    else if (tipo == 1) printf("Triangulo equilatero.\n");
    else if (tipo == 2) printf("Triangulo isosceles.\n");
    else if (tipo == 3) printf("Triangulo escaleno.\n");
}

void exercicio_2() {
    int a, b, c;
    printf("Insere tres valores inteiros: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("O maior valor e: %d\n", maior_valor(a, b, c));
}

void exercicio_3() {
    char c;
    printf("Digita um caractere: ");
    scanf(" %c", &c);
    
    if (is_digit(c)) {
        // Converte char para inteiro usando a tabela ASCII
        int valor = c - '0';
        printf("Isto e um digito. O valor inteiro guardado na variavel e: %d\n", valor);
    } else {
        printf("Nao e um digito de 0 a 9.\n");
    }
}

void exercicio_4() {
    int x, y;
    printf("Digita os valores de x e y: ");
    scanf("%d %d", &x, &y);
    printf("Soma dos impares entre %d e %d = %d\n", x, y, soma_impares_entre(x, y));
}

void exercicio_5() {
    int k, n;
    printf("Digita os valores de k e n: ");
    scanf("%d %d", &k, &n);
    
    int count = 0, atual = k + 1; 
    
    printf("Os %d primeiros primos acima de %d sao:\n", n, k);
    while (count < n) {
        if (is_prime(atual)) {
            printf("%d ", atual);
            count++;
        }
        atual++;
    }
    printf("\n");
}

void exercicio_6() {
    int n;
    printf("Digita a quantidade de termos da sequencia de Fibonacci (n): ");
    scanf("%d", &n);
    printf("Os primeiros %d termos sao: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibo(i));
    }
    printf("\n");
}

void exercicio_7() {
    int n, k, x;
    printf("Digita os valores de n, k e x: ");
    scanf("%d %d %d", &n, &k, &x);
    printf("O somatorio especial e: %d\n", soma_especial(n, k, x));
}

void exercicio_8() {
    int n;
    printf("Digita o valor de n: ");
    scanf("%d", &n);
    printf("Soma (Versao Iterativa): %d\n", soma_n_iterativa(n));
    printf("Soma (Versao Recursiva): %d\n", soma_n_recursiva(n));
}

void exercicio_9() {
    int n;
    printf("Digita o valor de n para a serie harmonica: ");
    scanf("%d", &n);
    printf("Soma Harmonica (Iterativa): %f\n", harm_iterativa(n));
    printf("Soma Harmonica (Recursiva): %f\n", harm_recursiva(n));
}

void exercicio_10() {
    int n;
    printf("Digita o valor de n para a constante e: ");
    scanf("%d", &n);
    printf("Constante e (Iterativa): %f\n", e_iterativa(n));
    printf("Constante e (Recursiva): %f\n", e_recursiva(n));
}

int main() {
    int opcao;
    do {
        printf("\n========================================\n");
        printf("    LISTA 2 - FUNCOES\n");
        printf("========================================\n");
        printf("1 - Tipo de Triangulo\n");
        printf("2 - Maior de Tres Valores\n");
        printf("3 - Verificador de Digito\n");
        printf("4 - Soma de Impares (Funcao)\n");
        printf("5 - Numeros Primos acima de K\n");
        printf("6 - Sequencia de Fibonacci\n");
        printf("7 - Somatorio Especial de Multiplos\n");
        printf("8 - Soma Sequencial (Iter/Rec)\n");
        printf("9 - Serie Harmonica (Iter/Rec)\n");
        printf("10 - Constante de Euler (Iter/Rec)\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("O que queres testar? Escolhe o exercicio (0-10): ");
        
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: exercicio_1(); break;
            case 2: exercicio_2(); break;
            case 3: exercicio_3(); break;
            case 4: exercicio_4(); break;
            case 5: exercicio_5(); break;
            case 6: exercicio_6(); break;
            case 7: exercicio_7(); break;
            case 8: exercicio_8(); break;
            case 9: exercicio_9(); break;
            case 10: exercicio_10(); break;
            case 0: printf("A fechar o programa...\n"); break;
            default: printf("Opcao invalida, tenta de novo!\n");
        }
    } while(opcao != 0);

    return 0;
}