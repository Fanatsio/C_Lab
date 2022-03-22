#include <stdio.h>
#include <math.h>

int main() 
{
    double a, b, d, h, s, s1, s2, sn1, sn2, H, k;
    int i, n;
    printf("n >> ");
    scanf("%d", &n);
    a = 0;
    b = 1;
    h = (b - a) / n;
    H = h / 2;
    for (i = 0; i != n; i += 1)
    {
        s1 +=  8 * pow((a + i * h + H), 3) * cos(a + i * h + H);
    }
    s1 *= h;
    a = 1;
    b = 2;
    for (i = 0; i != n; i += 1)
    {
        s2 += log(1 + sqrt(a + i * h + H)) - cos(a + i * h + H);
    }
    s2 *= h;
    sn1 = s1 + s2;
    printf("s = %lf\n", sn1);
    printf("------------------------------------\n");
    for (k = 2 * n; ; 2 * k)
    {
        h = (b - a) / k;
        H = h / 2;
        for (i = 0; i != k; i += 1)
        {
            s1 +=  8 * pow((a + i * h + H), 3) * cos(a + i * h + H);
        }
        s1 *= h;
        a = 1;
        b = 2;
        for (i = 0; i != k; i += 1)
        {
            s2 += log(1 + sqrt(a + i * h + H)) - cos(a + i * h + H);
        }
        s2 *= h;
        sn2 = s1 + s2;
        printf("s = %lf\n", sn1);
        printf("------------------------------------\n");
        d = fabs(sn2 - sn1) / 3;
        if (d < n)
        {
            printf("d = %lf\n", d);
            break;
        }
        else
        {
            sn1 = sn2;
            continue;
        }
    }
    return 0;
}