#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
    char s[90], b; int z = 0;
    fgets(s, 80, stdin);
    scanf("%c", &b);
    for (int i = 0; s[i]; z += s[i++] == b);
    printf("%sDer Buchstabe %c kommt %dmal vor.", s, b, z);
}

void transposeMatrix(int a[][3], int b[][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            b[i][j] = a[j][i];
}