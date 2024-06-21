int myStrlen(char s[]) {
	int zaehler = 0;
	while (s[zaehler] != '\0')
		zaehler++;
	return zaehler;
}