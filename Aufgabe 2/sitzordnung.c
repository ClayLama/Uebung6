#include <stdio.h>

#define HOERSAAL_REIHEN 12
#define HOERSAAL_SPALTEN 10

/// Ziel: Hörsaal wird in der Konsole ausgegeben
/// Parameter: Auszugebene Matrix
/// Return:	/
void ausgabeHoersaal(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]);

/// Ziel: Es wird eine Sitzplatznummer von der Konsole asugegeben und Olli wird darauf gesetzt
/// Parameter: Hörsaal-Matrix
/// Return:	/
void platziereOlli(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]);

/// Ziel: Es werden alle belegten Plätze des Saals gezählt
/// Parameter: Hörsaal-Matrix
/// Return:	/
int zaehleBelegtePlaetze(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]);

/// Ziel: Es wird eine Geprüft, ob der gegebene Sitzplatz frei ist
/// Parameter: Hörsaal-Matrix, Reihe und Spalte des zu prüfenden Sitzplatzes
/// Return:	/
int platzFrei(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN], int reihePlatz, int spaltePlatz);

int main() {
	int matrixHoersaal[HOERSAAL_REIHEN][HOERSAAL_SPALTEN] = { 0 };	//Plätze des Hörsaals gespeichert als Matrix (0=Frei/1=Besetzt)

	//Olli wird in der ersten Reihe platziert
	platziereOlli(matrixHoersaal);
	
	printf("\nSitzplatzverteilung eine halbe Stunde vor der Vorlesung:\n");
	ausgabeHoersaal(matrixHoersaal);

	//Restlich Plätze werden nach vorgaben belegt
	for (int i = 0; i < HOERSAAL_REIHEN; i++) {
		for (int j = 0; j < HOERSAAL_SPALTEN; j++) {
			if (platzFrei(matrixHoersaal, i, j))
				matrixHoersaal[i][j] = 1;
		}
	}

	printf("\nSitzplatzverteilung zum Beginn der Vorlesung:\n");
	ausgabeHoersaal(matrixHoersaal);

	printf("\nEs sind %d Plaetze belegt.\n\n", zaehleBelegtePlaetze(matrixHoersaal));

	return 0;
}
/// Ziel: Hörsaal wird in der Konsole ausgegeben
/// Parameter: Auszugebene Matrix
/// Return:	/
void ausgabeHoersaal(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]) {
	for (int i = 0; i < HOERSAAL_REIHEN; i++) {
		printf("|");
		for (int j = 0; j < HOERSAAL_SPALTEN; j++) {
			if (matrix[i][j] == 0)
				printf(" |");
			else if (matrix[i][j] == 2)
				printf("O|");
			else
				printf("*|");
		}
		printf("\n");
	}
	return;
}

/// Ziel: Es wird eine Sitzplatznummer von der Konsole asugegeben und Olli wird darauf gesetzt
/// Parameter: Hörsaal-Matrix
/// Return:	/
void platziereOlli(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]) {
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

	matrix[0][platzOlli - 1] = 2;

	return;
}

/// Ziel: Es werden alle belegten Plätze des Saals gezählt
/// Parameter: Hörsaal-Matrix
/// Return:	/
int zaehleBelegtePlaetze(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN]) {
	int anzahlStudenten = 0;
	for (int i = 0; i < HOERSAAL_REIHEN; i++) {
		for (int j = 0; j < HOERSAAL_SPALTEN; j++) {
			if (matrix[i][j] != 0)
				anzahlStudenten++;
		}
	}
	return anzahlStudenten;
}

/// Ziel: Es wird eine Geprüft, ob der gegebene Sitzplatz frei ist
/// Parameter: Hörsaal-Matrix, Reihe und Spalte des zu prüfenden Sitzplatzes
/// Return:	0 = Platz darf nicht belegt werden / 1 = Platz darf belegt werden
int platzFrei(int matrix[HOERSAAL_REIHEN][HOERSAAL_SPALTEN], int reihePlatz, int spaltePlatz) {
	//Falsche Parameter werden abgefangen
	if (reihePlatz < 0 || reihePlatz > HOERSAAL_REIHEN - 1 || spaltePlatz < 0 || spaltePlatz > HOERSAAL_SPALTEN - 1)
		return 0;

	//Ausgewählter Platz besetzt
	if (matrix[reihePlatz][spaltePlatz])
		return 0;

	//Vorderplatz besetzt
	if (reihePlatz != 0) {
		if (matrix[reihePlatz - 1][spaltePlatz])
			return 0;
	}

	//Sonderfall: Rechter Randplatz
	if (spaltePlatz == HOERSAAL_SPALTEN - 1 && matrix[reihePlatz][spaltePlatz - 1] == 0)
		return 1;
	else if (spaltePlatz == HOERSAAL_SPALTEN - 1 && matrix[reihePlatz][spaltePlatz - 1])
		return 0;

	//Sonderfall: Linker Randplatz
	if (spaltePlatz == 0 && matrix[reihePlatz][spaltePlatz + 1] == 0)
		return 1;
	else if (spaltePlatz == 0 && matrix[reihePlatz][spaltePlatz + 1])
		return 0;



	//Sonderfall 2. Platz von Rechts
	if (spaltePlatz == HOERSAAL_SPALTEN - 2 && matrix[reihePlatz][spaltePlatz + 1])
		return 0;

	//Allgemein
	if (matrix[reihePlatz][spaltePlatz - 1]) {
		//Sondefall 2. Platz von Links
		if (spaltePlatz == 1)
			return 0;

		//Rechter Platz von Olli belegt
		if (matrix[reihePlatz][spaltePlatz + 1])
			return 0;
		//Sitznachbar hat keinen Platz
		if (spaltePlatz >= 2) {
			if (matrix[reihePlatz][spaltePlatz - 2])
				return 0;
		}
	}
	return 1;
}