#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
    while(b!=0)
    {
        int tmp = a%b;
        a= b;
        b = tmp;
    }
    return a;
}

long long mulPow(int a, int k,int n)
{
    if(k==0)
    {
        return 1;
    }
    long long p = mulPow(a,k/2,n);
    if(k%2==0)
    {
        return (p*p)%n;
    }
    else
    {
        return (a*p*p)%n;
    }
}

int dkCanVaDu(int n)
{
    int N = n;
    int dem = 0;
    int mu;
    for(int i =2; i<=2*n; ++i)
    {
        if(N%i==0)
        {
            dem++;
            mu = 0;
            if((n-1)%(i-1)!=0)
            {
                return 0;
            }
            while(N%i==0)
            {
            	mu++;
                N/=i;
            }
        }
        if(mu>=2)
			return 0;
    }
    if(dem <3)
        return 0;
    return 1;
}

int isCamichael(int n)
{
	int hopSo =0;
    for(int a = 2; a<n; ++a)
    {
    	if(n%a==0)
			hopSo = 1;
        if(gcd(a,n)==1 && mulPow(a,n-1,n)!=1)
        {
            return 0;
        }
    }
    return hopSo&&dkCanVaDu(n);
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    for(int i = 2; i<=n; ++i)
        if(isCamichael(i))
            printf("%d   ",i);
    return 0;
}
