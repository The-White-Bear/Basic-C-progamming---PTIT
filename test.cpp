
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct dt {
    int mu;
    int num;
};

typedef struct dt dt;

dt tok(char a[]) {
    dt s;
    s.num = 0;
    int pos;
    s.mu = 0;

    for (int i = 0; i < strlen(a); i++) {
        if (isdigit(a[i]) != 0) {
            s.num = s.num * 10 + (a[i] - '0');
        } else {
            pos = i;
            break;
        }
    }

    for (int i = pos + 3; i < strlen(a); i++) {
        s.mu = s.mu * 10 + (a[i] - '0');
    }

    return s;
}

int cmp(const void *a, const void *b) {
    dt *x = (dt*)a;
    dt *y = (dt*)b;

    if (x->mu > y->mu)
        return -1;
    else
        return 1;
}

int count[100000];

int main() {
    int t;
    scanf("%d", &t);
    getchar();

    while (t--) {
        char a[100000], b[100000];
        gets(a);
        gets(b);

        dt c[10000];
        int n = 0;

        char *token = strtok(a, " ");
        while (token != NULL) {
            c[n++] = tok(token);
            token = strtok(NULL, " ");
        }

        token = strtok(b, " ");
        while (token != NULL) {
            c[n++] = tok(token);
            token = strtok(NULL, " ");
        }

        qsort(c, n, sizeof(dt), cmp);

        for (int i = 1; i < n; i++) {
            if (c[i].mu == c[i - 1].mu) {
                c[i].num = c[i].num + c[i - 1].num;
                c[i - 1].num = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (c[i].num != 0) {
                printf("%d*x^%d", c[i].num, c[i].mu);
                if(i != n-1)
                    printf(" + ");
            }
        }

        printf("\n");
    }

    return 0;
}
