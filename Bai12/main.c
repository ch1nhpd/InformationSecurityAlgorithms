#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mulPow(int a, int k, int n)
{
    if(k==0)
    {
        return 1;
    }
    int p =mulPow(a,k/2,n);
    if(k%2==0)
    {
        return (p*p)%n;
    }
    else
    {
        return (a*p*p)%n;
    }
}

int fermat(int n, int t)
{
    for(int i =0; i<t; ++i)
    {
        int a = rand() % (n-3) + 2;
        int r = mulPow(a,n-1,n);
        if(r!=1)
        {
            return 0;
        }
    }
    return 1;
}

int miller_Rabin(int n, int t)
{
	if(n%2==0)
	{
		return 0;
	}
	int s = 0;
	int r = n-1;
	while(r%2==0)
	{
		s++;
		r/=2;
	}

	for(int i = 1;i<=t;++i)
	{
		int a = rand() % (n-3) +2;
		int y = mulPow(a,r,n);
		if(y!=1&&y!=n-1)
		{
			int j =1;
			while(j<=s-1&&y!=n-1)
			{
				y = y*y%n;
				if(y==1)
					return 0;
				++j;
			}
			if(y!=n-1)
				return 0;
		}
	}
	return 1;
}
int main()
{
	int n,t;
    printf("Nhap n,t: ");
    scanf("%d%d",&n,&t);
    printf("Fermat ==> %d la %s!\n",n,fermat(n,t)?"SNT":"Hop so");
    printf("Miller_Rabin ==> %d la %s!\n",n,miller_Rabin(n,t)?"SNT":"Hop so");
    return 0;
}
