#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *mem(int n, int m) 
{
  int *a = (int *)malloc(n * m * sizeof(int));
  if (!a) 
  {
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
  }
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
        a[i * m + j] = i * m + j + 1;
  return a;
}

void print(int n, int m, int array[])
{
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < m; j++) 
      printf("% 4d ", array[i * m + j]);
    printf("\n");
  }
  printf("\n");
}

void fill(int n, int m, int A[]) 
{
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) 
      A[i * m + j] = rand() % 10;
}

void trans(int n, int m, int A[], int B[])
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            B[i * m + j] = A[j * m + i];
}

void mult(int n, int m, int A[], int B[], int C[])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            C[i * n + j] = 0;
            for(int k = 0; k < m; k++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
        }
}

int main()
{
    srand(time(NULL));
    int n, m;
    printf("n -> ");
    scanf("%d", &n);
    printf("m -> ");
    scanf("%d", &m);
    int *A = mem(n, m);
    printf("\nA:\n");
    fill(n, m, A);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
            printf("% 4d ", A[i * m + j]);
        printf("\n");
    }
    int *B = mem(m, n);
    printf("\nB:\n");
    trans(n, m, A, B);
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
            printf("% 4d ", B[i * m + j]);
        printf("\n");
    }
    int *C = mem(n, n);
    printf("\nC:\n");
    mult(n, m, A, B, C);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
            printf("% 5d ", C[i * m + j]);
        printf("\n");
    }
    free(A);
    free(B);
    free(C);
    return 0;
}