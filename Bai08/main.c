#include <stdio.h>
#include <stdlib.h>

long inverInFp(long a, long p)
{
	int u,v,x,x1,x2,r,q;
	u = a;
	v = p;
	x1 = 1;
	x2 = 0;
	while(u!=1)
	{
		q = v/u;
		r = v%u;
		x = x2-q*x1;

		v = u;
		u = r;
		x2= x1;
		x1 = x;
	}
	return x1;
}

/*long euclideEx(long a, long b, long* x, long* y)
{
	int d,x1,x2,y1,y2;
	if(b==0)
	{
		d = a;
		*x =1;
		*y =0;
	}else
	{
		x2=1;x1=0;y2=0;y1=1;
		while(b>0)
		{
			int q = a/b;
			int r = a%b;
			*x = x2 - q*x1;
			*y = y2 - q*y1;

			a = b; b = r;
			x2 = x1; x1 = *x;
			y2 = y1; y1 = *y;
		}
		d = a; *x = x2; *y = y2;
	}
	return d;
}*/

int main()
{
    long a,p;
    printf("Nhap hai so: ");
    scanf("%ld%ld",&a,&p);

    printf("%li ^-1 mod %li = %li", a,p,inverInFp(a,p));
}
