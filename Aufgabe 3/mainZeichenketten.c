//�bung 6, Aufgabe 3: "mainZeichenketten.c" (21.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm f�r das Arbeiten mit der eigenen Strin Bibliothek
#include <stdio.h>
#include "myString.h"

#define MAXIMAL_LAENGE 15							//Maximale L�nge der Zeichenketten

int main() {
	char string1[MAXIMAL_LAENGE + 1] = "";
	char string2[MAXIMAL_LAENGE + 1] = "";			//Vektoren, in dem die Eingaben gespeichert werden
	char zeichen[2] = "";								//Eingegebenes Zeichen

	//Startnachricht
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*      Standardfunktionen f\x81r Zeichenketten          *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n\n");

	//Eingabe 1
	printf("Geben Sie den ersten String ein:  ");
	while (!leseString(string1, MAXIMAL_LAENGE + 1))
		printf("Bitte geben Sie eine Zeichenkette ohne Leerzeichen mit maximal %d Zeichen ein: ", MAXIMAL_LAENGE);
	//Eingabe 2
	printf("Geben Sie den zweiten String ein: ");
	while (!leseString(string2, MAXIMAL_LAENGE + 1))
		printf("Bitte geben Sie eine Zeichenkette ohne Leerzeichen mit maximal %d Zeichen ein: ", MAXIMAL_LAENGE);
	//Eingabe 3
	printf("Geben Sie ein Zeichen ein: ");
	while (!leseString(zeichen, 2))
		printf("Bitte geben Sie nur ein Zeichen ein: ");

	//Ausgabe L�nge
	printf("\n");
	printf("Die Laenge des ersten Strings betraegt: %d\n", myStrlen(string1));
	printf("Die Laenge des zweiten Strings betraegt: %d\n", myStrlen(string2));

	//Ausgabe Vergleich der Strings
	printf("\n");
	if (myStrcmp(string1, string2) == 0)
		printf("Die Strings sind gleich.");
	else if (myStrcmp(string1, string2) == 1)
		printf("Die Strings sind gleich lang, aber nicht identisch.");
	else
		printf("Die Strings sind unterschiedlich lang.");
	printf("\n\n");

	//Ausgabe gesuchtes Zeichen Vorw�rtssuche
	if (myStrchr(string1, zeichen[0]) != -1)
		printf("my_strchr: Der Buchstabe \"%c\" befindet sich an Position %d bei der Vorwaertssuche. (Zeichenkette 1)", zeichen[0], myStrchr(string1, zeichen[0]));
	else
		printf("my_strchr: Der Buchstabe \"%c\" befindet sich nicht in der Zeichenkette 1.", zeichen[0]);
	printf("\n\n");

	//Ausgabe gesuchtes Zeichen Vorw�rtssuche
	if (myStrrchr(string2, zeichen[0]) != -1)
		printf("my_strrchr: Der Buchstabe \"%c\" befindet sich an Position %d bei der Rueckwaertssuche. (Zeichenkette 2)", zeichen[0], myStrrchr(string2, zeichen[0]));
	else
		printf("my_strrchr: Der Buchstabe \"%c\" befindet sich nicht in der Zeichenkette 2.", zeichen[0]);
	printf("\n\n");

	//Ausgabe addierte Strings
	if (myStrcat(string1, string2, 15) == 0)
		printf("Der zusammengefuegte String: %s", string1);
	else
		printf("Die Strings konnten nicht zusammengefuegt werden. (Laenge > %d)", MAXIMAL_LAENGE);
	printf("\n\n");

	return 0;
}