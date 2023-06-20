#include <string.h>
#include <stdio.h>

int main()
{

    char str[100][100], temp[100];
    int i, j;
    for (i = 0; i < 5; i++)
        gets(str[i]);
    for (i = 0; i < 5; i++)
        for (j = 0 ; j < 5; j++)
            if (strcmp(str[i], str[j]) < 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }

    for (i = 0; i < 5; i++)
        printf("\n%s", str[i]);
    printf("\n\n");

    return 0;
}