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
	printf("[  ");
	for(int i = sizeArr-1;i>=0;--i )
	{
		printf("%d  ",arr[i]);
	}
	printf(" ]\n");
}

int binToDec(int bin[], int start, int end)
{
	int dec=0;
	for(int i = end-1; i>=start; --i)
	{
		dec= dec + bin[i] * pow(2,end-1 - i);
	}
	return dec;
}

void decToBin(int dec, int bin[], int bits)
{
	for(int i = bits-1; i >=0; --i)
	{
		bin[i] = dec%2;
		dec/=2;
	}
}

void intMul(int A[], int B[], int C[], int sizeArr, int w)
{
	for(int i = 0; i< sizeArr*2;C[i]=0,++i);

	for(int i = 0; i<sizeArr;++i)
	{
		int U = 0;
		int V;
		for(int j = 0; j<sizeArr; ++j)
		{
			int UV = C[i+j] + A[i]*B[j] + U;
			int UVbin[w*2];
			decToBin(UV,UVbin,w*2);
			U = binToDec(UVbin,0,w);
			V = binToDec(UVbin,w,w*2);
			C[i+j] = V;
		}
		C[i+sizeArr] = U;
	}

}
int main()
{
    long long a,b,p;
	int  w = 8;
	printf("Nhap a, b, p, w: ");
	scanf("%lld%lld%lld%d",&a,&b,&p,&w);
	int sizeArr = sizeOfArr(p,w);
	int A[sizeArr], B[sizeArr], C[sizeArr*2];
	digitToArr(a,w,A,sizeArr);
	digitToArr(b,w,B,sizeArr);
	intMul(A,B,C,sizeArr,w);

	printArr(A,sizeArr);
	printArr(B,sizeArr);
	printf("KQ: C = ");
	printArr(C,sizeArr*2);
}
