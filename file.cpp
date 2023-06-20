#include <stdio.h>
#include <string.h>
 
typedef struct Student
{
    char name[105], studentCode[105], classes[105];
    float p1, p2, p3;
} Student;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    Student a[n];
    for(int i = 0; i < n; ++i)
    {
        scanf("\n");
        gets(a[i].studentCode);
        gets(a[i].name);
        gets(a[i].classes);
        scanf("%f%f%f", &a[i].p1, &a[i].p2, &a[i].p3);
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(strcmp(a[i].studentCode, a[j].studentCode) > 0)
            {
                Student tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        printf("%d %s %s %s %.1f %.1f %.1f\n", i + 1, a[i].studentCode, a[i].name, a[i].classes, a[i].p1, a[i].p2, a[i].p3);
    return 0;
}

