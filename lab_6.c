#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
}

void rep(int n, int a[])
{
    int sum, pr, B[n];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
            {
                printf("i = %d    j = %d\n", i, j);
                sum = a[i] + a[j];
                pr = a[i] * a[j];
                printf("sum = %d    pr = %d\n", sum, pr);
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                        B[k] = sum;
                    else if (k == j)
                        B[k] = pr;
                    else
                        B[k] = a[k];
                    printf("%d  ", B[k]);
                }
            }
}

int main() {
    srand(time(NULL));
    int n;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    rep(n, A);
    return 0;
}