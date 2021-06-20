#include <stdio.h>
#include <stdlib.h>
int size;
void fact(int n, int coSo[], int soMu[])
{
	int pos = 0;
	for(int i = 2 ;i<=n;++i)
	{
		if(n%i==0)
		{
			coSo[pos] = i;
			soMu[pos] = 0;
			while(n%i==0)
			{
				soMu[pos]++;
				n/=i;
			}
			pos++;
		}
	}
	size = pos;
}

void printArr(int a[])
{
	printf("[ ");
	for(int i = 0; i<size;++i)
	{
		printf("%d ",a[i]);
	}
	printf("]\n");
}
int main()
{
	int n, coSo[5], soMu[5];
	printf("Nhap n: ");
	scanf("%d",&n);
	fact(n,coSo,soMu);
	printf("Co so: ");
	printArr(coSo);
	printf("So mu: ");
	printArr(soMu);
    return 0;
}
