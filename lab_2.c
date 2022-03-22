#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    printf("Enter x -> ");
    scanf("%lf", &x);
    double y = sqrt(sin(2*x)) + sqrt(sin(3*x));
    double z = sqrt(sqrt(log(tan(y - 0.392699))));
    if (isnan(y) == 0 && isnan(z) == 0)
    {
        printf("y(x) = %.3lf\n", y);
        printf("z(x) = %.3lf", z);
    } else
        printf("Error");
    return 0;
}