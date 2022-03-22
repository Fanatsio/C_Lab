#include <stdio.h>

int expon(int x, int k)
{
    if (k == 0)
        return 1;
    int e = expon(x, k / 2);
    if (k % 2 == 0)
        return e * e;
    else
        return x * e * e;
}

int main() {
    int n, d;
    printf("Enter n -> ");
    scanf("%d", &n);
    printf("Enter d -> ");
    scanf("%d", &d);
    int res = 1;
    int i = 1;
    while(i <= d)
    {
        res = n * res;
        i++;
    }
    printf("exponentiation = %d\n", expon(5, 3));
    printf("res = %d\n", res);
    return 0;
}