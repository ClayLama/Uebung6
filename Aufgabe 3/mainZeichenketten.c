//Übung 6, Aufgabe 3: "mainZeichenketten.c" (21.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm für das Arbeiten mit der eigenen Strin Bibliothek
#include <stdio.h>
#include "myString.h"

#define MAXIMAL_LAENGE 15							//Maximale Länge der Zeichenketten

int main() {
	char string1[MAXIMAL_LAENGE+1] = "";		
	char string2[MAXIMAL_LAENGE+1] = "";			//Vektoren, in dem die Eingaben gespeichert werden

	//Startnachricht
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*      Standardfunktionen f\x81r Zeichenketten          *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n\n");

	//Eingabe 1
	printf("Geben Sie den ersten String ein:  ");
	while (!leseString(string1, MAXIMAL_LAENGE+1))
		printf("Bitte geben Sie eine Zeichenkette ohne Leerzeichen mit maximal %d Zeichen ein: ", MAXIMAL_LAENGE);
	//Eingabe 2
	printf("Geben Sie den zweiten String ein: ");
	while (!leseString(string2, MAXIMAL_LAENGE+1))
		printf("Bitte geben Sie eine Zeichenkette ohne Leerzeichen mit maximal %d Zeichen ein: ", MAXIMAL_LAENGE);

	//Ausgabe Länge
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

	return 0;
}