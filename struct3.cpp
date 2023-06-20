#include <stdio.h>
#include <string.h>
int main()
{
    char s[20];
    char x[1005][20];
    int dem = 0;
    while (scanf("%s", s) != -1)
    {
        strcpy(x[dem], s);
        dem++;
    }
    int max = 0;
    for (int i = 0; i < dem; i++)
    {
        if (max < strlen(x[i]))
        {
            max = strlen(x[i]);
        }
    }
    char y[1005][20];
    int n = 0;
    for (int i = 0; i < dem; i++)
    {
        if (max == strlen(x[i]))
        {
            strcpy(y[n], x[i]);
            n++;
        }
    }
    int b[1005];
    for (int i = 0; i < n; i++)
    {
        b[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!strcmp(y[i], y[j]))
                {
                    b[j] = 0;
                    b[i]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
            printf("%s %d %d\n", y[i], max, b[i]);
    }
}