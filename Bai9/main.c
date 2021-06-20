#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    int s[n+1] ;
    for(int i = 2 ; i<=n; ++i)
	{
		int x = i*2;
		while(x<=n)
		{
			s[x] = 1;
			x+=i;
		}
	}
	printf("Cac SNT <= %d la: ",n);
	for(int i = 2; i<=n;++i)
	{
		if(s[i]!=1)
		{
			printf("%d, ",i);
		}
	}
    return 0;
}
