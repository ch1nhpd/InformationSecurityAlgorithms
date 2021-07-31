#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sizeOfArr(long long p, int w)
{
	double m = ceil(log(p)/log(2));
	return (int) ceil(m/w);
}

void digitToArr(long long a, int w, int arr[], int sizeArr)
{
	for(int i =sizeArr-1; i >= 0; --i)
	{
		long long tmp = pow(2,w*i);
		arr[i] = (int) a/tmp;
		a%=tmp;
	}
}

void printArr(int arr[], int sizeArr)
{
	for(int i = sizeArr-1;i>=0;--i )
	{
		printf("%d  ",arr[i]);
	}
}

int main()
{
	long long a,p;
	int w;
	printf("Nhap a,p,w: ");
	scanf("%lld%lld%d",&a,&p,&w);

	int sizeArr = sizeOfArr(p,w);
    int arr[sizeArr];
    digitToArr(a,w,arr,sizeArr);
    printf("KQ: ");
    printArr(arr,sizeArr);
    return 0;
}
