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

/// Ziel: Es wird in gegebenen String nach bestimmten Zeichen gesucht
/// Parameter: Zeichenkette; Zeichen nach dem gesucht werden soll
/// Return:	-1 = Zeichen nicht im String; Sonst Index des ersten Vorkommens des Zeichens
int myStrchr(char s[], char c) {
	int zaehler = 0;			//Zählt die Indexe des Strings durch
	//Sucht von links nach Buchstaben, bis gefunden
	do {
		if (s[zaehler] == c)
			return zaehler+1;
		zaehler++;
	} while (s[zaehler] != '\0');
	return -1;		//Nichts gefunden
}

/// Ziel: Es wird in gegebenen String nach bestimmten Zeichen gesucht 
/// Parameter: Zeichenkette; Zeichen nach dem gesucht werden soll
/// Return:	-1 = Zeichen nicht im String; Sonst Index des letzten Vorkommens des Zeichens
int myStrrchr(char s[], char c) {
	int letzteStelle = 0;		//Stringlänge wird bestimmt
	int zaehler = 0;			//Zählt die Indexe des Strings durch

	letzteStelle = myStrlen(s)-1;

	//Sucht von rechts nach Buchstaben, bis gefunden
	do {
		if (s[letzteStelle-zaehler] == c)
			return (letzteStelle - zaehler)+1;
		zaehler++;
	} while ((letzteStelle - zaehler) >= 0);
	return -1;		//Nichts gefunden
}

/// Ziel: Es werden zwei Strings in einem gespeichert 
/// Parameter: String1, String2, Maximallänge zusammen
/// Return:	-1 = Funktion gescheitert, 0 = erfolgreich ausgeführt
int myStrcat(char s1[], char s2[], int n) {
	int laenge1 = myStrlen(s1);
	int laenge2 = myStrlen(s2);

	//Fehleefall: Strings zu lang
	if (laenge1 + laenge2 > n)
		return -1;

	for (int i = 0; i < laenge2; i++)
		s1[i + laenge1] = s2[i];
	s1[laenge2 + laenge1] = '\0';
	return 0;
}