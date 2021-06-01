#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int rounds(double x)
{
    int iX = (int) x;
    if(x-iX>0)
    {
        return iX+1;
    }
    else
    {
        return iX;
    }
}

long* digitToArray(unsigned long x,int w, int t)
{
    long* a;
    int i;
    a = (long*)malloc(t * sizeof(long));
    for(i = t-1; i>=0; --i)
    {
        a[t-i-1]=x/pow(2,w*i);
        x%=(int)pow(2,w*i);
    }
    return a;
}

void printArr(long a[],int size)
{
	int i;
    for(i =0; i<size; ++i)
    {
        printf("%lu  ",a[i]);
    }
}

int sizeOfArr(unsigned long p,int w)
{
    int m = rounds(log(p)/log(2)) ;
    return m%w ? m/w + 1 : m/w;
}

long* mulSub(long a[] , long b[], int size, int w)
{
    int e = 0;
    int p = pow(2,w);
    long* c = (long*) calloc(size+1,sizeof(long));
    for(int i = size-1;i>=0;--i)
    {
        c[i] = a[i]-b[i]-e;
        if(c[i]<0||c[i]>=p)
        {
            e=1;
            c[i]%=p;
            if(c[i]<0)
            {
                c[i]+=p;
            }
        }else
        {
            e=0;
        }
    }
    c[size] = e;
    return c;
}
int cmp(long a[], long b[], int size)
{
    int i;
    for(i = 0;i< size;++i)
    {
        if(a[i]<b[i])
        {
            return -1;
        }
    }
    if(a[i]==b[i])
    {
        return 0;
    }
    else{
        return 1;
    }
}

long* mulAdd(long a[] , long b[], int size, int w)
{
    int e = 0;
    int p = pow(2,w);
    long* c = (long*) calloc(size + 1,sizeof(long));
    int i;
    for(i = size-1;i>=0;--i)
    {
        c[i] = a[i]+b[i]+e;
        if(c[i]<0||c[i]>=p)
        {
            e=1;
            c[i]%=p;
            if(c[i]<0)
            {
                c[i]+=p;
            }
        }else
        {
            e=0;
        }
    }
    c[size] = e;
    return c;
}

long* addInFp(long a[] , long b[], int size, int w, unsigned long f)
{
    long * c = mulAdd(a,b,size,w);
    long* p = digitToArray(f,w,size);
    if(c[size]==1 || cmp(c,p,4) >=0 )
    {
        return mulSub(c,p,size,w);
    }
    return c;
}

int main(){
	unsigned long a,b,p;
	int w,t;
	long *arrA, *arrB, *arrAdd;

	printf("Nhap p, w: ");
	scanf("%lu%d",&p, &w);
	t = sizeOfArr(p,w);
	printf("Nhap a, b: ");
	scanf("%lu%lu",&a, &b);

	arrA = digitToArray(a,w,t);
	arrB = digitToArray(b,w,t);
	arrAdd = addInFp(arrA,arrB,t,w,p);
	printf("\nA : ");
	printArr(arrA,t);
	printf("\nB : ");
	printArr(arrB,t);
	printf("\nAdd in Fp: A + B = ");
	printArr(arrAdd,t);



}
