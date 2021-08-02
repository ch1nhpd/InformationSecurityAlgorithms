#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void lastOccurrence(char P[], int L[])
{
    for(int i =0; i<128; L[i] =-1,++i);
    for(int i = 0; i<strlen(P); ++i)
    {
        int x = P[i];
        L[x] = i;
    }
}

int min(int a, int b)
{
    return a<b?a:b;
}

int boyerMoore(char T[],char P[],  int L[])
{
    int i,j;
    int lenP = strlen(P);
    int lenT = strlen(T);
    i = j = lenP -1;
    while(i<lenT)
    {
        if(T[i]==P[j])
        {
            i--;
            j--;
            if(j<0)
            {
                return i+1;
            }
        }
        else
        {
        	int x = T[i];
            i = i + lenP - min(j, 1 + L[x]);
            j = lenP - 1;
        }
    }
    return -1;
}
int main()
{
    char T[255], P[255];
    int L[128];
    printf("Nhap chuoi T: ");
    fflush(stdin);
    gets(T);
    printf("Nhap chuoi P can tim: ");
    fflush(stdin);
    gets(P);
	lastOccurrence(P,L);
    int bm = boyerMoore(T,P,L);
    if(bm>=0)
    {
        printf("Tim thay tai vi tri %d",bm);
    }
    else
    {
        printf("Khong tim thay!");
    }
    return 0;
}
