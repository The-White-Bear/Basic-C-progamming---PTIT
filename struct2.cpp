#include <stdio.h>
#include <string.h>
struct SV
{
    int msv;
    char name[30];
    char date[30];
    float a, b, c, tong;
};
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    struct SV sv[1000];
    for (int i = 0; i < n; i++)
    {
        sv[i].msv = i + 1;
        gets(sv[i].name);
        gets(sv[i].date);
        scanf("%f%f%f", &sv[i].a, &sv[i].b, &sv[i].c);
        getchar();
        sv[i].tong = sv[i].a + sv[i].b + sv[i].c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sv[i].tong < sv[j].tong)
            {
                int tmp = sv[i].msv;
                sv[i].msv = sv[j].msv;
                sv[j].msv = tmp;
                char tmp1[100];
                strcpy(tmp1, sv[i].name);
                strcpy(sv[i].name, sv[j].name);
                strcpy(sv[j].name, tmp1);
                char tmp2[100];
                strcpy(tmp2, sv[i].date);
                strcpy(sv[i].date, sv[j].date);
                strcpy(sv[j].date, tmp2);
                float tong1 = sv[i].tong;
                sv[i].tong = sv[j].tong;
                sv[j].tong = tong1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %.1f\n", sv[i].msv, sv[i].name, sv[i].date, sv[i].tong);
    }
    return 0;
}