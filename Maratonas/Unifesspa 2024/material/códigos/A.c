/* A.c */
/* Acordes intergal�ticos */
/* Autor: Claudio Coutinho */

#include <stdio.h>
#include <stdlib.h>

/* prot�tipo de fun��es auxiliares que foram usadas */
void array_fill (int* arr, int value, int size);
void array_print (int* arr, int size);

int main(void) {
	
	/* declara��o de vari�veis */
	int N, Q;
	int a, b;
	int i, j, f;
	int maior_nota, maior_occ, maior_occ_idx, empate;
	
	/* leitura inicial (N->qtd de teclas; Q->qtd de acordes) */
	scanf ("%i %i", &N, &Q);
	
	/* aloca��o din�mica e inicializa��o de vetores*/
	int* piano = (int*) malloc (N*sizeof(int));
	array_fill (piano, 1, N);
	
	int* occurrence_arr = (int*) malloc (9*sizeof(int));	// vetor para guardar ocorr�ncias de cada nota do acorde

	/* la�o principal */	
	for (i = 0; i < Q; i++) {	
		array_fill (occurrence_arr, 0, 9);		// zera vetor de ocorr�ncias
		scanf ("%i %i", &a, &b);				// l� intervalo do acorde (0 <= a < b < N)
		
		maior_nota = piano[a];					// guarda maior nota, caso haja empate da tecla mais frequente
		maior_occ = 0;							// tecla de maior frequ�ncia por acorde
		maior_occ_idx = 0;						// �ndice da tecla de maior frequ�ncia
		
		/* la�o para calcular frequ�ncia de cada tecla */
		for (j = a; j <= b; j++) {
			occurrence_arr[piano[j]]++;			// incrementa a posi��o da tecla detectada
			if (piano[j] > maior_nota)			// atualiza maior tecla em caso de empate
				maior_nota = piano[j];
		}
		
		empate = 0;								// indica se houve empate
		
		/* la�o para definir tecla mais frequente */
		for (j = 0; j < 9; j++) {
			if (occurrence_arr[j] > maior_occ) {
				maior_occ = occurrence_arr[j];
				maior_occ_idx = j;
				empate = 0;
			} else if (occurrence_arr[j] == maior_occ) {	// se uma tecla tem frequ�ncia igual � outra, h� empate
				empate = 1;
			}
		}
		
		/* defini��o de 'f' dependendo se houve empate ou n�o */
		f = (!empate) ? maior_occ_idx : maior_nota;

		/* atualiza��o das notas do piano pertencentes ao acorde */			
		for (j = a; j <= b; j++)
			piano[j] = (piano[j] + f) % 9;
			
	}
	/* fim do la�o principal */
	
	/* exibi��o final do piano */
	for (i = 0; i < N; i++)
		printf ("%i\n", piano[i]);
	
	/* libera��o de mem�ria alocada */
	free (piano);
	free (occurrence_arr);
}

/* fun��es auxiliares */
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
