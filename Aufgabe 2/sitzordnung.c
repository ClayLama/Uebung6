#include <stdio.h>

#define HOERSAAL_REIHEN 12
#define HOERSAAL_SPALTEN 10

/// Ziel: Hörsaal wird in der Konsole ausgegeben
/// Parameter: Auszugebene Matrix
/// Return:	/
void ausgabeHoersaal(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]) {
	for (int i = 0; i < HOERSAAL_REIHEN; i++) {
		printf("|");
		for (int j = 0; j < HOERSAAL_SPALTEN; j++) {
			if (matrix[i][j] == 0)
				printf(" |");
			else
				printf("*|");
		}
		printf("\n");
	}
	return;
}

void platzOlli(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]);

int main() {
	int matrixHoersaal[HOERSAAL_REIHEN][HOERSAAL_SPALTEN];	//Plätze des Hörsaals gespeichert als Matrix (0=Frei/1=Besetzt)

	//Initialisierung der Matrix mit Nullen
	for (int i = 0; i < HOERSAAL_REIHEN; i++) {
		for (int j = 0; j < HOERSAAL_SPALTEN; j++) {
			matrixHoersaal[i][j] = 0;
		}
	}

	platzOlli(matrixHoersaal);

	ausgabeHoersaal(matrixHoersaal);

	return 0;
}


void platzOlli(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]) {
	int korrekteEingabe = 1;		//Wird 0, wenn falsche Eingabe
	int platzOlli = 0;				//Eingelesener Wert für Ollis Platz

	printf("Auf welchen Platz in der ersten Reihe soll sich Olli heute setzen?: ");

	//Platzabfrage und Validierung, Wiederholung bis die Eingabe korrekt
	do {
		if (!korrekteEingabe)
			printf("Bitte geben Sie eine Ganzzahl zwischen 1 und %d an: ", HOERSAAL_SPALTEN);
		korrekteEingabe = scanf_s("%2d", &platzOlli);
		if (getchar() != '\n') {
			korrekteEingabe = 0;
			while (getchar() != '\n');
		}
		if (platzOlli < 1 || platzOlli > HOERSAAL_SPALTEN)
			korrekteEingabe = 0;
	} while (!korrekteEingabe);

	matrix[0][platzOlli - 1] = 1;

	return;
}