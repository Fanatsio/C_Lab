#include <stdio.h>
#include <math.h>

double f(int n)
{
    double a, b, d, h, s, s1, s2;
    int i;
    a = 0;
    b = M_PI / 2;
    h = (b - a) / n;
    for (i = 0; i != n; i += 1)
    {
        s1 += pow(2, a + i * h + h / 2) - 2 + (a + i * h + h / 2) * (a + i * h + h / 2);
    }
    s1 *= h;
    a = M_PI / 2;
    b = M_PI;
    for (i = 0; i != n; i += 1)
    {
        s2 += sqrt(a + i * h + h / 2) * exp(-((a + i * h + h / 2) * (a + i * h + h / 2)));
    }
    s2 *= h;
    s = s1 + s2;
    return s;
}

int main() 
{
    double s, sn;
    int i, n;
    printf("n >> ");
    scanf("%d", &n);
    sn = f(n);
    printf("s = %lf\n", sn);
    for (n *= 2; ;)
    {
        s = f(n);
        double d = fabs(s - sn) / 3;
        if (d < n)
        {
            printf("d = %lf\n", d);
            break;
        }
        else
        {
            sn = s;
            continue;
        }
    }
    return 0;
}