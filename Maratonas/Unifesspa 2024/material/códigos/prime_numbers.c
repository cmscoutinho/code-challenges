#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    // Cria um array de booleanos e inicializa todos como verdadeiros
    bool* isPrime = (bool*) malloc((n+1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    // Marca números não primos como falsos
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Imprime todos os números primos
    printf("Números primos até %d:\n", n);
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");

    // Libera a memória alocada
    free(isPrime);
}

int main() {
    int n;
    printf("Digite o número limite para encontrar primos: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}
