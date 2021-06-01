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

void inputArr(long a[], int size)
{
    int i;
    for(i = 0; i<size ; ++i)
    {
        scanf("%lu",&a[i]);
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
    long* c = (long*) calloc(size + 1,sizeof(long));
    int i;
    for(i = size-1;i>=0;--i)
    {
        c[i] = a[i]-b[i]-e;
        if(c[i]<0)
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



int main(){
	unsigned long a,b,p;
	int w,t;
	long *arrA, *arrB;
	while(1){
		int choose = 0;
		system("cls");
		printf("\n1. Nhap dang so.");
		printf("\n2. Nhap dang mang.");
		printf("\n0. Thoat.");
		printf("\n>>chon>> ");
		scanf("%d",&choose);
		switch(choose){
			case 1:
				printf("Nhap p, w: ");
				scanf("%lu%d",&p, &w);
				t = sizeOfArr(p,w);
				printf("Nhap a, b: ");
				scanf("%lu%lu",&a, &b);

				arrA = digitToArray(a,w,t);
				arrB = digitToArray(b,w,t);
				break;
			case 2:
				printf("Nhap p, w: ");
				scanf("%lu%d",&p, &w);
				t = sizeOfArr(p,w);
				printf("Nhap cac phan tu cua mang a: ");
				arrA = (long*) calloc(t,sizeof(long));
				inputArr(arrA,t);
				printf("Nhap cac phan tu cua mang b: ");
				arrB = (long*) calloc(t,sizeof(long));
				inputArr(arrB,t);
				break;
			case 0:
				printf("See u again <3");
				return 0;
			default:
				printf("\nLua chon khong hop le! Nhap phim bat ki de tiep tuc!");
				getch();
				continue;
		}
		long *arrSub = mulSub(arrA,arrB,t,w);
		printf("KQ A - B = [ %d, [",arrSub[t]);
		printArr(arrSub,t);
		printf("]]");
		printf("\nNhan phim bat ki de tiep tuc! ");
		getch();
	}




}
