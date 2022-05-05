#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int m, int a[n][m])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 100;
}

void trans(int n, int m, int a[n][m], int b[m][n])
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = a[j][i];
}

void mult(int n, int m, int a[n][m], int b[n][m], int c[n][m])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("n -> ");
    scanf("%d", &n);
    printf("m -> ");
    scanf("%d", &m);
    int A[n][m], B[m][n], C[m][n];
    fill(n, m, A);
    trans(n, m, A, B);
    mult(n, m, A, B, C);
    printf("A: \n");
    for (int i = 0; i < n; i++, putchar('\n'))
        for (int j = 0; j < m; j++)
            printf("%d ", A[i][j]);
    printf("B: \n");
    for (int i = 0; i < m; i++, putchar('\n'))
        for (int j = 0; j < n; j++)
            printf("%d ", B[i][j]);
    printf("C: \n");
    for (int i = 0; i < n; i++, putchar('\n'))
        for (int j = 0; j < m; j++)
            printf("%d ", C[i][j]);
    return 0;
}