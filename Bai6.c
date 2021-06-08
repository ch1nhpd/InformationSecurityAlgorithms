#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArr(long a[],int size)
{
    for(int i =size -1; i>=0; --i)
    {
        printf("%lu  ",a[i]);
    }
    printf("\n");
}

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

int sizeOfArr(unsigned long f,int w)
{
    int m = rounds(log(f)/log(2)) ;
    return m%w ? m/w + 1 : m/w;
}

long* digitToArray(unsigned long x,int w, int t)
{
    long* a;
    a = (long*)malloc(t * sizeof(long));
    for(int i =0; i<t; ++i)
    {
        a[t-1-i]=x/pow(2,w*(t-1-i));
        x%=(int)pow(2,w*(t-1-i));
    }
    return a;
}

long* decToBin(long a, int sizeOfBin)
{
    long* bin = (long*) calloc(sizeOfBin,sizeof(long));
    for(int i = sizeOfBin-1;i>=0;--i)
    {
        bin[i] = a%2;
        a/=2;
    }
    return bin;
}

long binToDec(int bin[], int start, int end)
{
    int dec=0;
    for(int i = start;i<end;++i){
        dec+=(bin[i]*pow(2,end-1-i));
    }
    return dec;
}

long* intMul(long a[], long b[], int size, int w)
{
    long* c = (long*) calloc(2*size,sizeof(long));
    for(int i = 0; i<size;++i)
    {
        int u=0;
        long uvDec;
        for(int j = 0; j< size ;++j)
        {
            uvDec = c[i+j] + a[i]*b[j] + u;
            long* uvBin = decToBin(uvDec,2*w);
            u = binToDec(uvBin,0,w);
            int v = binToDec(uvBin,w,2*w);
            c[i+j] = v;
        }
        c[i + size] = u;
    }
    return c;

}

int main()
{
	int w,t;
    unsigned long a,b,f;

    printf("Nhap a,b,f: ");
    scanf("%lu%lu%lu",&a,&b,&f);
    printf("Nhap so bit w = ");
    scanf("%d",&w);

    t = sizeOfArr(f,w);
    
    long *aArr = digitToArray(a,w,t);
    long *bArr = digitToArray(b,w,t);
    
    printf("\nA = ");
	printArr(aArr,t);
	printf("\nB = ");
    printArr(bArr,t);
    
    long *mul = intMul(aArr,bArr,t,w);
    printf("\nInt mul A.B = ");
    printArr(mul,w);
}
