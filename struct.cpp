#include <stdio.h>
#include <math.h>
struct tamgiac
{
    int a, b, c;
    float s;
};

float tinh_dien_tich_tam_giac(tamgiac tg)
{
    float p = (tg.a + tg.b + tg.c) / 2.0;
    float s = sqrt(p * (p - tg.a) * (p - tg.b) * (p - tg.c));
    return s;
}
int cmp(const void *a, const void *b)
{
    tamgiac *tg1 = (tamgiac *)a;
    tamgiac *tg2 = (tamgiac *)b;
    float s1 = tg1->s;
    float s2 = tg2->s;
    if (s1 < s2)
    {
        return -1;
    }
    if (s1 > s2)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    tamgiac *ds=(tamgiac*)malloc(n*sizeof(tamgiac));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &ds[i].a, &ds[i].b, &ds[i].c);
        ds[i].s=tinh_dien_tich_tam_giac(ds[i]);
    }
    qsort(ds,n,sizeof(tamgiac),cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", ds[i].a, ds[i].b, ds[i].c);
    }
}