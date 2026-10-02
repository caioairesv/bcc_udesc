#include <stdio.h>

// Helper para o Exercicio 3
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Exercicio 1
int compara(float a[], float b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

// Exercicio 2
void fibonacci(int v[], int n) {
    if (n > 0) v[0] = 1;
    if (n > 1) v[1] = 1;
    for (int i = 2; i < n; i++) {
        v[i] = v[i - 1] + v[i - 2];
    }
}

// Exercicio 3
int soma_primos(int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(v[i])) {
            soma += v[i];
        }
    }
    return soma;
}

// Exercicio 4
void busca_todos(int v[], int n, int chave, int indices[]) {
    int idx_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (v[i] == chave) {
            indices[idx_count] = i;
            idx_count++;
        }
    }
    
    for (int i = idx_count; i < n; i++) {
        indices[i] = -1;
    }
}

// Exercicio 5
int busca_seq_rec(int v[], int n, int chave) {
    if (n == 0) return -1;
    if (v[n - 1] == chave) return n - 1;
    return busca_seq_rec(v, n - 1, chave);
}

// --- Funcoes de Interface ---

void exercicio_1() {
    int n;
    printf("Tamanho dos vetores: ");
    scanf("%d", &n);
    
    float a[n], b[n];
    printf("Insere os %d valores do vetor A: ", n);
    for(int i = 0; i < n; i++) scanf("%f", &a[i]);
    
    printf("Insere os %d valores do vetor B: ", n);
    for(int i = 0; i < n; i++) scanf("%f", &b[i]);
    
    int sao_iguais = compara(a, b, n);
    printf("Retorno: %d (%s)\n", sao_iguais, sao_iguais ? "Iguais" : "Diferentes");
}

void exercicio_2() {
    int n;
    printf("Tamanho da sequencia de Fibonacci: ");
    scanf("%d", &n);
    
    if (n <= 0) return;
    
    int v[n];
    fibonacci(v, n);
    
    printf("Vetor Fibonacci: ");
    for(int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

void exercicio_3() {
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    
    int v[n];
    printf("Insere os %d valores: ", n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    
    printf("Soma dos numeros primos: %d\n", soma_primos(v, n));
}

void exercicio_4() {
    int n, chave;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    
    int v[n], indices[n];
    printf("Insere os %d valores: ", n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    
    printf("Chave de busca: ");
    scanf("%d", &chave);
    
    busca_todos(v, n, chave, indices);
    
    printf("Vetor de indices: {");
    for(int i = 0; i < n; i++) {
        printf("%d%s", indices[i], i < n - 1 ? ", " : "");
    }
    printf("}\n");
}

void exercicio_5() {
    int n, chave;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    
    int v[n];
    printf("Insere os %d valores: ", n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    
    printf("Chave de busca: ");
    scanf("%d", &chave);
    
    int pos = busca_seq_rec(v, n, chave);
    if(pos != -1) {
        printf("Chave encontrada no indice %d\n", pos);
    } else {
        printf("Chave nao encontrada (-1)\n");
    }
}

int main() {
    int opcao;
    do {
        printf("\n--- LISTA 3 ---\n");
        printf("1 - Comparar vetores\n");
        printf("2 - Fibonacci em vetor\n");
        printf("3 - Soma de primos no vetor\n");
        printf("4 - Busca de todos os indices\n");
        printf("5 - Busca sequencial recursiva\n");
        printf("0 - Sair\n");
        printf("Escolha o exercicio (0-5): ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: exercicio_1(); break;
            case 2: exercicio_2(); break;
            case 3: exercicio_3(); break;
            case 4: exercicio_4(); break;
            case 5: exercicio_5(); break;
            case 0: break;
            default: printf("Invalido.\n");
        }
    } while(opcao != 0);

    return 0;
}