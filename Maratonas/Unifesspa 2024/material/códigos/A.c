/* A.c */
/* Acordes intergaláticos */
/* Autor: Claudio Coutinho */

#include <stdio.h>
#include <stdlib.h>

/* protótipo de funções auxiliares que foram usadas */
void array_fill (int* arr, int value, int size);
void array_print (int* arr, int size);

int main(void) {
	
	/* declaração de variáveis */
	int N, Q;
	int a, b;
	int i, j, f;
	int maior_nota, maior_occ, maior_occ_idx, empate;
	
	/* leitura inicial (N->qtd de teclas; Q->qtd de acordes) */
	scanf ("%i %i", &N, &Q);
	
	/* alocação dinâmica e inicialização de vetores*/
	int* piano = (int*) malloc (N*sizeof(int));
	array_fill (piano, 1, N);
	
	int* occurrence_arr = (int*) malloc (9*sizeof(int));	// vetor para guardar ocorrências de cada nota do acorde

	/* laço principal */	
	for (i = 0; i < Q; i++) {	
		array_fill (occurrence_arr, 0, 9);		// zera vetor de ocorrências
		scanf ("%i %i", &a, &b);				// lê intervalo do acorde (0 <= a < b < N)
		
		maior_nota = piano[a];					// guarda maior nota, caso haja empate da tecla mais frequente
		maior_occ = 0;							// tecla de maior frequência por acorde
		maior_occ_idx = 0;						// índice da tecla de maior frequência
		
		/* laço para calcular frequência de cada tecla */
		for (j = a; j <= b; j++) {
			occurrence_arr[piano[j]]++;			// incrementa a posição da tecla detectada
			if (piano[j] > maior_nota)			// atualiza maior tecla em caso de empate
				maior_nota = piano[j];
		}
		
		empate = 0;								// indica se houve empate
		
		/* laço para definir tecla mais frequente */
		for (j = 0; j < 9; j++) {
			if (occurrence_arr[j] > maior_occ) {
				maior_occ = occurrence_arr[j];
				maior_occ_idx = j;
				empate = 0;
			} else if (occurrence_arr[j] == maior_occ) {	// se uma tecla tem frequência igual à outra, há empate
				empate = 1;
			}
		}
		
		/* definição de 'f' dependendo se houve empate ou não */
		f = (!empate) ? maior_occ_idx : maior_nota;

		/* atualização das notas do piano pertencentes ao acorde */			
		for (j = a; j <= b; j++)
			piano[j] = (piano[j] + f) % 9;
			
	}
	/* fim do laço principal */
	
	/* exibição final do piano */
	for (i = 0; i < N; i++)
		printf ("%i\n", piano[i]);
	
	/* liberação de memória alocada */
	free (piano);
	free (occurrence_arr);
}

/* funções auxiliares */
void array_fill (int* arr, int value, int size) {
	int i;
	
	for (i = 0; i < size; i++)
		arr[i] = value;
}

void array_print (int* arr, int size) {
	int i;
	for (i = 0; i < size; i++)
		printf ("%i|", arr[i]);
}
