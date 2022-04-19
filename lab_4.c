#include <stdio.h>
#include <math.h>

double f(int n)
{
    double b, h, H, s, s1, s2;
    b = M_PI / 2;
    h = b / n;
    for (int i = 0; i != n; i ++)
    {
        H = i * h + h / 2;
        s1 += pow(2, H) - 2 + (H) * (H);
        s2 += sqrt(b + H) * exp(-((b + H) * (b + H)));
    }
    s = h * (s1 + s2);
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