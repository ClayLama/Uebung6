/// Ziel: String wird aus Konsole eingelesen
/// Parameter: string, in dem gespeichert werden soll, maximale Anzahl an Zeichen
/// Return:	Einlesen erfolgreich = 1, gescheitert = 0
int leseString(char string[], int anzahlZeichen);

/// Ziel: L�nge eines gegebenen Strings wird ermittelt
/// Parameter: String, von dem die L�nge ermittelt wird
/// Return:	L�nge des Strings
int myStrlen(char s[]);

/// Ziel: Zwei Strings werden verglichen und ergebnis wird returned
/// Parameter: Zu vergleichene Strings
/// Return:	0 = Strings gleich, 1 = Strings gleich lang, 2 = Strings verschieden lang
int myStrcmp(char string1[], char string2[]);