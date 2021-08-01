#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void eratos(int n)
{
    int arr[n+1];
    for(int i = 0; i<=n; arr[i]=0,++i);
    printf("||v1|| Cac so nguyen to <= %d la:  ",n);
    for(int i = 2; i<=n; ++i)
    {
        if(arr[i]!=1)
        {
            printf("%d  ",i);
            for(int j = 2; j*i<=n; ++j)
            {
                arr[i*j] = 1;
            }
        }
    }
}
void eratos_pd(int arr[], int delta, int r)
{
    int m = r;
    for(int j =2; j*j<m; ++j)
    {
        if(arr[j]==0)
        {
        	int min;
            if(m==delta)
            {
                min = j*2;
            }
            else
            {
                min = ceil((m-delta)*1.0/j) * j;
            }
            while(min<=m)
            {
                arr[min] =1;
                min+=j;
            }
        }
    }
}
void eratosV2(int n)
{
    int arr[n+1];
    int delta = (int) sqrt(n) -1;
    int deltas = (int) ceil(n*1.0/delta);
    for(int i =0; i<n+1; arr[i]=0,++i);

    for(int i =0; i<deltas; ++i)
    {
        int r = delta*(i+1);
        if(r>n)
		{
			r = n;
		}
        eratos_pd(arr,delta,r);
    }

    printf("\n||V2|| Cac so nguyen to <= %d la:  ",n);
    for(int i =2;i<=n;++i)
	{
		if(arr[i]==0)
		{
			printf("%d  ",i);
		}
	}
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    eratos(n);
    eratosV2(n);
    return 0;
}
