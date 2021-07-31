#include <stdio.h>
#include <stdlib.h>

int gcd_euclide(long x, long y)
{
	if(y!=0)
		return gcd_euclide(y,x%y);
	else
		return x;
}

int main()
{
	long x,y;
    printf("Nhap hai so: ");
    scanf("%ld%ld",&x,&y);
    printf("gcd = %d",gcd_euclide(x,y));
    return 0;
}
