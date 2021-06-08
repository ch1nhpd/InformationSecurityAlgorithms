#include <stdio.h>
#include <stdlib.h>

long gcd_euclid(unsigned long a, unsigned long b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd_euclid(b, a%b);
}
int main()
{
    unsigned long a, b;
    printf("Nhap a, b: ");
    scanf("%lu%lu",&a,&b);
    long gcd = a>b?gcd_euclid(a,b):gcd_euclid(b,a);
    printf("gcd(%lu, %lu) = %lu",a,b,gcd);
}
