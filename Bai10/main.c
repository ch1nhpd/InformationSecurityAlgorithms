#include <stdio.h>
#include <stdlib.h>

long long gcd(long a, long b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

long long pollard(long long n)
{
	long long a, b, d;
	a = b =2;
	for(int i = 1; ; ++i)
	{
		a = (a*a +1)%n;
		b = (b*b +1)%n;
		b = (b*b +1)%n;
		d = gcd(n,a-b);
		if(d>1&&d<n)
		{
			printf("KQ: d = %llu\n", d);
			break;
		}else if(d==n)
		{
			printf("Thu voi ham khac!");
			break;
		}
	}
}

int main()
{
	long long n;
	printf("Nhap n: ");
	scanf("%llu",&n);
	pollard(n);
    return 0;
}
