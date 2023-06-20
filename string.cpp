#include <stdio.h>
#include <string.h>
#include <ctype.h>
int dem_so_tu(char s[1000])
{
    char *p = strtok(s, " ");
    int cnt = 0;
    while (p)
    {
        cnt++;
        p = strtok(NULL, " \n");
    }
    return cnt;
}
void dem_ky_tu(char s[1000])
{
    int l = strlen(s);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for (int i = 0; i < l; i++)
    {
        if (isalpha(s[i]))
        {
            cnt1++;
        }
        else if (isdigit(s[i]))
        {
            cnt2++;
        }
        else
        {
            cnt3++;
        }
    }
    printf("%d %d %d\n", cnt1, cnt2, cnt3);
}
void xoa_tu(char s[1000], char s2[100])
{
    char *p = strtok(s, " ");
    while (p)
    {
        if (strcmp(p, s2))
        {
            printf("%s ", p);
        }
        p = strtok(NULL, " \n");
    }
}
void loai_bo_trung_nhau(char s[1000])
{
    char res[101][101] = {};
    int n = 0;
    char *token = strtok(s, " ");
    while (token != NULL)
    {
        int check = 1;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(token, res[i]) == 0)
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            strcpy(res[n], token);
            n++;
        }
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < n; i++)
        printf("%s ", res[i]);
}
void chuanhoa1(char s[1000])
{
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        s[i] = tolower(s[i]);
    }
    char *p = strtok(s, " ");
    char words[100][100];
    int count = 0;
    while (p)
    {
        strcpy(words[count], p);
        count++;
        p = strtok(NULL, " \n");
    }
    for (int i = 0; i < count; i++)
    {
        words[i][0] = toupper(words[i][0]);
        printf("%s ", words[i]);
    }
    printf("\n");
}
void chuanhoa2(char s[1000])
{
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        s[i] = tolower(s[i]);
    }
    char *p = strtok(s, " ");
    char words[100][100];
    int count = 0;
    while (p)
    {
        strcpy(words[count], p);
        count++;
        p = strtok(NULL, " \n");
    }
    for (int i = 1; i < count - 1; i++)
    {
        words[i][0] = toupper(words[i][0]);
        printf("%s ", words[i]);
    }
    words[count - 1][0] = toupper(words[count - 1][0]);
    printf("%s", words[count - 1]);
    printf(", ");
    for (int i = 0; i < strlen(words[0]); i++)
    {
        words[0][i] = toupper(words[0][i]);
    }
    printf("%s", words[0]);
    printf("\n");
}
int romanToDecimal(char roman_numeral[])
{
    int values[7] = {1, 5, 10, 50, 100, 500, 1000};
    int total = 0;
    int previous_value = 0;

    for (int i = strlen(roman_numeral) - 1; i >= 0; i--)
    {
        int value;

        switch (roman_numeral[i])
        {
        case 'I':
            value = values[0];
            break;
        case 'V':
            value = values[1];
            break;
        case 'X':
            value = values[2];
            break;
        case 'L':
            value = values[3];
            break;
        case 'C':
            value = values[4];
            break;
        case 'D':
            value = values[5];
            break;
        case 'M':
            value = values[6];
            break;
        }

        if (value < previous_value)
        {
            total -= value;
        }
        else
        {
            total += value;
        }

        previous_value = value;
    }

    return total;
}

int main()
{
    int num_tests;
    scanf("%d", &num_tests);
    
    for (int i = 0; i < num_tests; i++)
    {
        char roman_numeral[100];
        scanf("%s", roman_numeral);

        int decimal_value = romanToDecimal(roman_numeral);

        printf("%d\n", decimal_value);
    }

    return 0;
}