#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _c_ 617
#define MAX_STRING 255

int failure(char P[], int F[])
{
    int lenP = strlen(P);
    F[0] =-1;
    for(int i = 1; i<lenP; ++i)
    {
        int j;
        for(j = i - 1; j>0; --j)
        {
            if(cmp(P,0,i - j, j))
            {
                F[i] = j;
                break;
            }
        }
        if(j == 0)
        {
            F[i] = 0;
        }
    }
}

int cmp(char P[], int start1, int start2, int length)
{
    for(int i = 0; i< length; ++i)
    {
        if(P[start1 + i] != P[start2 + i] )
            return 0;
    }
    return 1;
}

int kmp(char T[], char P[], int F[], int *dem)
{
    //Knuth-Morris-Pratt
    int i,j;
    i = j = (*dem) =0;
    while(i<strlen(T))
    {
        while(j < strlen(P))
        {
            (*dem)++;
            if(T[i+j]!=P[j])
            {
                i = i+ j - F[j] -1;
                j = (F[j] == -1)?0:F[j];
                break;
            }
            else
            {
                j++;
            }
        }
        if(j == strlen(P))
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    return -1;
}

int main()
{
	int dem;
    char T[MAX_STRING], P[MAX_STRING];

    printf("Nhap chuoi T: ");
    fflush(stdin);
    gets(T);
    printf("Nhap chuoi can tim P: ");
    fflush(stdin);
    gets(P);


    int F[strlen(P)];
    failure(P,F);
    int KMP = kmp(T,P,F,&dem);
    if(KMP>=0)
    {
        printf("Vi tri: %d\nSo lam so sanh: %d\n",KMP,dem);
    }
    else
    {
        printf("Khong tim thay!\n");
    }


    /*
    	T: abacaabaccabacabaabb
    	P: abacab ==> vt: 10; dem = 19
    */

}
