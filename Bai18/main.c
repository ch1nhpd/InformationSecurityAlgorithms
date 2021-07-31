#include <stdio.h>
#include <stdlib.h>

void defaultValue(int x[], int size, int value)
{
	for(int i = 0;i<size;++i)
		x[i]=value;
}

void inputArr(int arr[], int size)
{
	for(int i =size-1;i>=0;--i)
	{
		scanf("%d",&arr[i]);
	}
}

void outputArr(int arr[], int size)
{
	for(int i =size-1;i>=0;--i)
	{
		printf("%d  ",arr[i]);
	}
}
void sub(int a[], int b[], int sub_[] ,int size)
{
	for(int i = 0;i <size;++i)
	{
		sub_[i] = a[i] - b[i];
	}
}

void mul(int a[], int b, int mul_[],int size)
{
	for(int i=0;i<size;++i)
	{
		mul_[i] = a[i]*b;
	}
}

int bacMax(int x[], int size)
{
	for(int i = size-1 ; i>=0 ; --i)
		if(x[i]!=0)
			return i;
	return 0;
}

void mapping(int a[], int b[],int size)
{
	for(int i = 0;i<size;++i)
			b[i] = a[i];
}

int divv(int a[], int b[], int div_[], int mod[],int size)
{
	int bacMaxA = bacMax(a,size);
	int bacMaxB = bacMax(b,size);
	if(bacMaxA<bacMaxB)
	{
		mapping(a,mod,size);
		return 1;
	}
	while(bacMaxA!=0)
	{
		div_[bacMaxA - bacMaxB] = a[bacMaxA] / b[bacMaxB];
		int mul_[size];
		mul(b,div_[bacMaxA-bacMaxB],mul_,size);
		mapping(mul_,a,size);
		divv(mul_,b,div_,mod,size);
	}
	return 0;
}
/*
void xor(int a[], int b[], int xor[], int size)
{
	for(int i = 0 ; i< size;++i)
	{
		xor[i] = (a[i]+b[i])%2;
	}
}*/

void MUL(int a[], int b[], int mul[], int size )
{
	defaultValue(mul,size,0);
	for(int i = 0; i< size;++i)
	{
		for(int j = 0;j<size;++j)
		{
			mul[i+j]+=(a[i]*b[j]);
		}
	}
}

void extent_Euclid(int a[], int b[], int size,int result[])
{
	int x1[size],x2[size],y1[size],y2[size],x[size],y[size];
	defaultValue(x1,size,0);
	defaultValue(x2,size,1);
	defaultValue(y2,size,0);
	defaultValue(y1,size,1);
	int q[size], r[size];
	while(bacMax(b,size)>0)
	{
		divv(a,b,q,r,size);

		int multmp[size];
		MUL(q,x1,multmp,size);
		sub(x2,multmp,x,size);
		MUL(q,y1,multmp,size);
		sub(y2,multmp,y,size);

		mapping(b,a,size);
		mapping(r,b,size);
		mapping(x1,x2,size);
		mapping(x,x1,size);
		mapping(y1,y2,size);
		mapping(y,y1,size);
	}

	mapping(x2,result,size);

}



int main()
{
	int bac;
	printf("Nhap bac cao nhat cua ax va gx: ");
	scanf("%d",&bac);
	bac++;
    int ax[bac],gx[bac],axx[bac];
    printf("Nhap cac he so cua ax: ");
    inputArr(ax,bac);
    printf("Nhap cac he so cua gx: ");
    inputArr(gx,bac);
	extent_Euclid(ax,gx,bac,axx);


}
