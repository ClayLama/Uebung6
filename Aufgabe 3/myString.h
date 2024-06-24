/// Ziel: String wird aus Konsole eingelesen
/// Parameter: string, in dem gespeichert werden soll, maximale Anzahl an Zeichen
/// Return:	Einlesen erfolgreich = 1, gescheitert = 0
int leseString(char string[], int anzahlZeichen);

/// Ziel: Länge eines gegebenen Strings wird ermittelt
/// Parameter: String, von dem die Länge ermittelt wird
/// Return:	Länge des Strings
int myStrlen(char s[]);

/// Ziel: Zwei Strings werden verglichen und ergebnis wird returned
/// Parameter: Zu vergleichene Strings
/// Return:	0 = Strings gleich, 1 = Strings gleich lang, 2 = Strings verschieden lang
int myStrcmp(char string1[], char string2[]);

/// Ziel: Es wird in gegebenen String nach bestimmten Zeichen gesucht
/// Parameter: Zeichenkette; Zeichen nach dem gesucht werden soll
/// Return:	-1 = Zeichen nicht im String; Sonst Index des ersten Vorkommens des Zeichens
int myStrchr(char s[], char c);

/// Ziel: Es wird in gegebenen String nach bestimmten Zeichen gesucht
/// Parameter: Zeichenkette; Zeichen nach dem gesucht werden soll
/// Return:	-1 = Zeichen nicht im String; Sonst Index des ersten Vorkommens des Zeichens
int myStrrchr(char s[], char c);