int myStrlen(char s[]) {
	int zaehler = 0;
	while (s[zaehler] != '\0')
		zaehler++;
	return zaehler;
}

int leseString(char string, maximalLaenge) {
	int korrekteEingabe = 0;

	korrekteEingabe = fgets(string, maximalLaenge, stdin);
}