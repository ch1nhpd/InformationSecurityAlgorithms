#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(char P[], int start1, int start2, int len)
{
	for(int i = 0;i<len;++i)
	{
		if(P[start1+i] != P[start2+i])
		{
			return 0;
		}
	}
	return 1;
}

void failure(char P[], int F[])
{
	F[0] = -1;
	for(int i =1; i<strlen(P);++i)
	{
		for(int len = i -1 ; len>=0;--len)
		{
			if(cmp(P,0,i-len,len)==1)
			{
				F[i] = len;
				break;
			}
		}
	}
}

int kmp(char T[], char P[], int F[])
{
	int i,j;
	i = j =0;
	int lenP = strlen(P);
	int lenT = strlen(T);
	while(i - j <=lenT - lenP)
	{
		if(T[i]==P[j])
		{
			i++;j++;
			if(j==lenP)
				return i-j;
		}else{
			i = i + j - F[j];
			j = F[j]==-1?0:F[j];
		}
	}
	return -1;
}

int main()
{
    char T[255], P[255];
    int F[255];
    printf("Nhap chuoi T: ");
    fflush(stdin);
    gets(T);
    printf("Nhap chuoi P can tim: ");
    fflush(stdin);
    gets(P);
	failure(P,F);
    int k = kmp(T,P,F);
    if(k>=0)
    {
        printf("Tim thay tai vi tri %d",k);
    }
    else
    {
        printf("Khong tim thay!");
    }
    return 0;
}
