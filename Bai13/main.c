#include <stdio.h>
#include <stdlib.h>



int gcd(int a, int b)
{
	while(b>0)
	{
		int t = a;
		a = b;
		b = t%b;
	}
	return a;
}

int mul(int a, int k, int n)
{
	int b = 1;
	if(k==0)
		return b;
	int A = a;
	if(k%2==1)
	{
		b = a;
	}
	k/=2;
	while(k>0)
	{
		A = A*A%n;
		if(k%2 ==1)
		{
			b = A * b % n;
		}
		k/=2;
	}
	return b;
}

int dkCanVaDu(int n)
{
	int N =n;
	int size = 0;
	int i = 2;
	int before =1;
	while(n>1)
	{
		if(n%i==0)
		{
			if(i!=before)
			{
				size++;
				before = i;
				if((N-1)%(before-1)!=0)
				{
					return 0;
				}
			}else{
				return 0;
			}
			n/=i;
		}else{
			i++;
		}
	}
	if(size >=3)
	{
		return 1;
	}
}

int isCarmichael(int n)
{
	int hopSo = 0;
	for(int i = 2; i<=n-2;++i)
	{
		if(n%i==0)
		{
			hopSo = 1;
		}
		if(gcd(n,i)==1)
		{
			if(mul(i, n -1, n)!=1)
				return 0;
		}
	}
	if(hopSo&&dkCanVaDu(n))
	{
		return 1;
	}
	return 0;
}


int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("\n%d %sla so Carmichael!\n",n,isCarmichael(n)?" ":"khong ");
    return 0;
}
