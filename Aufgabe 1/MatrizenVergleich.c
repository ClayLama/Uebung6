#include <stdio.h>

#define DIM 2
#define NENNER_DIVISION 16384

int main() {
	int matrix1[DIM][DIM];
	int matrix2[DIM][DIM];
	int zufallsZahl = 0;			//Zufalllszahl zwischen 0 und 1

	srand(time(NULL));


	//Initialisierung der ersten Matrix zufällig mit Nullen und Einsen
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			matrix1[i][j] = (int)(rand() / NENNER_DIVISION);
		}
	}
	//Initialisierung der zweiten Matrix zufällig mit Nullen und Einsen
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			matrix2[i][j] = (int)(rand() / NENNER_DIVISION);
		}
	}

	printf("\n");
	ausgabeMatrix(matrix1);
	printf("\n");
	ausgabeMatrix(matrix2);

	int gleich = vergleicheMatrizen(matrix1, matrix2);
	printf("%d", gleich);
}

int vergleicheMatrizen(int matrix1[DIM][DIM], int matrix2[DIM][DIM]) {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			if (matrix1[i][j] != matrix2[i][j])
				return 0;
		}
	}
	return 1;
}

int ausgabeMatrix(int matrix[DIM][DIM]) {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			printf("%2d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}