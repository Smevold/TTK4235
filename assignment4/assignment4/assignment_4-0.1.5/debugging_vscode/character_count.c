#include <stdio.h>
/* count digits, white space, others */
int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i <= 10; ++i)
    ndigit[i] = 0;

    char string[] = "æåÆØÅø";

    for (int j = 0; string[j] != '\0'; j++) {
        c = string[j];
        if (c >= '0' && c <= '9')
            ndigit[c-'0']++;
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else if (c != -61)
            ++nother;
    }
    printf("digits:\n");
    for (i = 0; i <= 10; ++i){
        printf(" %d: %d,\n", i, ndigit[i]);
    }
    printf("white space = %d, other = %d\n", nwhite, nother);

    return 0;
}