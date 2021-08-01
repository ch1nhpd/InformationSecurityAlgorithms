#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b)
{
	while (b!=0)
	{
		long long tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

long long pollardRho(long long n)
{
	long long a,b;
	a=b=2;
	while(1)
	{
		a = (a*a + 1)%n;
		b = (b*b + 1)%n;
		b = (b*b + 1)%n;
		long long d = gcd(a-b,n );
		if(d>1&&d<n)
		{
			return d;
		}else if(d == n)
		{
			return 0;
		}
	}
}

int main()
{
	long long a;
    printf("Nhap a: ");
    scanf("%lld",&a);
    long long p =pollardRho(a);
    if(p!=0)
	{
		printf("KQ: %lld", p);
	}else
	{
		printf("Thu voi ham khac!");
	}
    return 0;
}
