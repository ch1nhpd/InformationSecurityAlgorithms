#include <stdio.h>
#include <stdlib.h>

unsigned long inverInFp(unsigned long a, unsigned long p)
{
    unsigned long u,v,q,r,x,x1,x2;
    u = a;
    v = p;
    x1=1;
    x2=0;
    while(u!=1)
    {
        q = v/u;
        r = v%u;
        x = x2 - q*x1;

        v = u;
        u =r;
        x2 = x1;
        x1 = x;
    }
    return x1;
}

int main()
{
    unsigned long a, p;
    printf("Nhap hai so a, p: ");
    scanf("%lu%lu",&a,&p);
	printf("%lu ^ -1 mod %lu = %lu",a,p,inverInFp(a,p));
}
