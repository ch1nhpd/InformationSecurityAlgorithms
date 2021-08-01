#include <stdio.h>
#include <stdlib.h>

int fact(int n, int arr[10][10])
{
	int N = n;
    int flag = 0;
    int j =0;
    while(n%2==0)
    {
        if(flag ==0)
        {
            arr[0][j] = 2;
            arr[1][j] = 1;
            flag = 1;
        }
        else
        {
            arr[1][j]+=1;
        }
        n/=2;
    }
    if(flag ==1)
    {
        j++;
        flag =0;
    }
    for(int i =3; i<= n; i+=2)
    {
        while(n%i==0)
        {
            if(flag ==0)
            {
                arr[0][j] = i;
                arr[1][j] = 1;
                flag = 1;
            }
            else
            {
                arr[1][j]+=1;
            }
            n/=i;
        }
        if(flag ==1)
        {
            j++;
            flag =0;
        }
    }
    return j;
}

void printArr(int arr[10][10], int sizeArr)
{
	printf("Co so: ");
	for(int i =0;i<2;++i)
	{
		for(int j =0;j<sizeArr;++j)
		{
			printf("%d  ",arr[i][j]);
		}
		if(i==0)
		{
			printf("\nSo mu: ");
		}

	}
}

int main()
{
    int n, arr[10][10];
    printf("Nhap n: ");
    scanf("%d",&n);
	int dem = fact(n,arr);
	printArr(arr,dem);
    return 0;
}
