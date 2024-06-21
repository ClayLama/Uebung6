#include <stdio.h>

/// Ziel: String wird aus Konsole eingelesen
/// Parameter: string, in dem gespeichert werden soll, maximale Anzahl an Zeichen
/// Return:	Einlesen erfolgreich = 1, gescheitert = 0
int leseString(char string[], int anzahlZeichen) {
	int korrekteEingabe = 0;

	korrekteEingabe = scanf_s("%s", string, anzahlZeichen);

	while (getchar() != '\n') {
		korrekteEingabe = 0;
	}
	return korrekteEingabe;
}

/// Ziel: Länge eines gegebenen Strings wird ermittelt
/// Parameter: String, von dem die Länge ermittelt wird
/// Return:	Länge des Strings
int myStrlen(char s[]) {
	int zaehler = 0;
	while (s[zaehler] != '\0') {
		zaehler++;
	}
	return zaehler;
}

/// Ziel: Zwei Strings werden verglichen und ergebnis wird returned
/// Parameter: Zu vergleichene Strings
/// Return:	0 = Strings gleich, 1 = Strings gleich lang, 2 = Strings verschieden lang
int myStrcmp(char string1[], char string2[]) {
	int laengeString1 = myStrlen(string1);
	int laengeString2 = myStrlen(string2);		//Länge der Strings wird gespeichert

	if (laengeString1 == laengeString2) {
		for (int i = 0; i < laengeString1; i++) {
			if (string1[i] != string2[i])
				return 1;						//Nicht alle chars gleich -> Ausgabe 1
		}
	}
	else
		return 2;								//Länge ungleich -> Ausgabe 2
	return 0;									//Länge gleich und Chars identisch -> Ausgabe 0
}