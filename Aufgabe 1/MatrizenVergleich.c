#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define DIM 2
#define NENNER_DIVISION 16384

/// Ziel:	Zwei Matrizen werden ausgelesen und vergleichen
/// Parameter: 2 Matrizen
/// Return:	0 = Matrizen verschieden / 1 = Matrizen gleich
int vergleicheMatrizen(int matrix1[DIM][DIM], int matrix2[DIM][DIM]);

/// Ziel: Matrix wird in der Konsole ausgegeben
/// Parameter: Auszugebene Matrix
/// Return:	/
void ausgabeMatrix(int matrix[DIM][DIM]);

int main() {
	int matrix1[DIM][DIM];				//DIM * DIM Matrix
	int matrix2[DIM][DIM];				//DIM * DIM Matrix
	int gleichheit = 0;					//Wird 1, wenn zwei Matrizen gleich
	int schleife = 1;					//Wird auf 0 gesetzt, wenn das Programm nicht wiederholt werden soll
	char eingabeWiederholung = '\0';	//Eingabe, ob Schleife wiederholt werden soll

	srand((unsigned int)time(NULL));	//Generiert und initialisiert Pseudo-Zufallszahlen, anhand der aktuellen Zeit

	//Startnachricht
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*           Matrizen auf Gleichheit testen           *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n");
	printf("Programm zur Generierung, Ausgabe und Vergleich zweier Matrizen\n");


	do {
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

		//Ausgabe und initialisierung der generierten Matrizen
		printf("\n");
		printf("Matrix 1:\n");
		ausgabeMatrix(matrix1);
		printf("Matrix 2:\n");
		ausgabeMatrix(matrix2);
		printf("\n");

		//Gleicheit wird überprüft
		gleichheit = vergleicheMatrizen(matrix1, matrix2);
		if (gleichheit)
			printf("Die Matrizen sind gleich.");
		else
			printf("Die Matrizen sind verschieden.");

		//Abfrage, ob das Programm wiederholt werden soll
		printf("\n\n");
		printf("Wollen Sie weiter Matrizen vergleichen? (j/n): ");
		eingabeWiederholung = _getche();
		if ((eingabeWiederholung == 'j' || eingabeWiederholung == 'J'))
			schleife = 1;
		else
			schleife = 0;
		printf("\n\n");
	} while (schleife);
}

/// Ziel:	Zwei Matrizen werden ausgelesen und vergleichen
/// Parameter: 2 Matrizen
/// Return:	0 = Matrizen verschieden / 1 = Matrizen gleich
int vergleicheMatrizen(int matrix1[DIM][DIM], int matrix2[DIM][DIM]) {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			if (matrix1[i][j] != matrix2[i][j])
				return 0;
		}
	}
	return 1;
}

/// Ziel: Matrix wird in der Konsole ausgegeben
/// Parameter: Auszugebene Matrix
/// Return:	/
void ausgabeMatrix(int matrix[DIM][DIM]) {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			printf("%2d", matrix[i][j]);
		}
		printf("\n");
	}
	return;
}