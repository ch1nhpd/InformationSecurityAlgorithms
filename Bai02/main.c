#include <stdio.h>
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
	printf("[  ");
	for(int i = sizeArr-1;i>=0;--i )
	{
		printf("%d  ",arr[i]);
	}
	printf(" ]\n");
}

int mulAdd(int A[], int B[], int C[], int sizeArr, int w)
{
	int e = 0;
	int x = pow(2,w);
	for(int i = 0; i<sizeArr;++i)
	{
		C[i] = A[i] + B[i] + e;
		if(C[i] >=x)
		{
			e = 1;
			C[i]-= x;
		}else
		{
			e = 0;
		}
	}
	return e;
}

int main()
{
	long long p,a,b;
	int w, e;
	printf("Nhap a,b,p,w: ");
	scanf("%lld%lld%lld%d",&a,&b,&p,&w);
	int sizeArr = sizeOfArr(p,w);
	int A[sizeArr], B[sizeArr], C[sizeArr];

	digitToArr(a,w,A,sizeArr);
	digitToArr(b,w,B,sizeArr);
	e = mulAdd(A,B,C,sizeArr,w);

	printArr(A,sizeArr);
	printArr(B,sizeArr);
	printf("KQ: e = %d; C = ",e);
	printArr(C,sizeArr);

}
