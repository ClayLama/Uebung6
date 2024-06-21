//Übung 6, Aufgabe 3: "mainZeichenketten.c" (21.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm zum Aufrufen der eigenen Funktion
#include <stdio.h>
#include "myString.h"

int main() {
	char string = "vier";
	leseString(string, 5);
	return 0;
}