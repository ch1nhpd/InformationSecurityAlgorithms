#include <stdio.h>
#include <stdlib.h>

int binhPhuongLap(int x,int n,int m)
{
    int p;
    if (n==0)
        return 1;
    p=binhPhuongLap(x,n/2,m);
    if (n%2==0)
        return (p*p)%m;
    else
        return (p*p*x)%m;
}

int mulpow(int a, int k, int n)
{
    //return: a^k mod n
    int b =1;
    if(k == 0)
        return b;

    int A = a;
    if(k%2==1)
        b = a;
    k/=2;

    while(k>0)
    {
        A = A*A %n;
        if(k%2==1)
        {
            b = A * b %n;
        }
        k/=2;
    }
    return b;
}

char* fermat(int n, int t)
{
    for(int i = 1; i<=t; ++i)
    {
        int a = rand() % (n-3) + 2;
        int r = mulpow(a, n-1, n);
        if(r!=1)
            return "Hop so!";
    }
    return "Nguyen to!";
}

char* miller_Rabin(int n, int t)
{
    int s=0;
    int r = n-1;
    if(r%2)
    {
        return "Hop so!";
    }
    while(1)
    {
        r/=2;
        s++;
        if(r%2)
            break;
    }

    for(int i = 1; i<=t; ++i)
    {
        int a = rand() % (n-3) + 2;
        int y = mulpow(a, r, n);
        if( y != 1 && y !=n-1)
        {
            int j = 1;
            while(j<=s - 1&& y!= n -1)
            {
                y = y* y % n;
                if (y==1)
                {
                    return "Hop so!";
                }
                j++;
            }
            if (y!= n -1)
            {
                return "Hop so!";
            }
        }
    }
    return "Nguyen to!";
}

int main()
{
    int n;
    /*printf("Nhap n:  ");
    scanf("%d",&n);
    printf("Fermat      ==> %s",fermat(n,5));
    printf("\nMiler Rabin ==> %s", miller_Rabin(n,5));*/
    printf("\n\t%d",mulpow(7,180,9));
    printf("\n\t%d",binhPhuongLap(7,180,9));
    return 0;
}
