#include <stdio.h>

int myStrlen(char s[], int groesseString) {
	int zaehler = 0;
	while (s[zaehler] != '\0')
		zaehler++;
	return zaehler;
}

int leseString(char string[], int anzahlZeichen) {
	int korrekteEingabe = 0;

	korrekteEingabe = scanf_s("%s", string, anzahlZeichen);

	if (getchar() != '\0') {
		while (getchar() != '\0');
		korrekteEingabe = 0;
	}
	return korrekteEingabe;
}