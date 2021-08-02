#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bruteForce(char T[], char P[])
{
	int lenT = strlen(T);
	int lenP = strlen(P);
	for(int i = 0; i<=lenT -lenP;++i)
	{
		int j;
		for(j = 0;j<lenP;++j)
		{
			if(T[i+j]!=P[j])
				break;
		}
		if(j==lenP)
			return i;
	}
	return -1;
}

int main()
{
	char T[255], P[255];
	printf("Nhap chuoi T: ");
	fflush(stdin);
	gets(T);
	printf("Nhap chuoi P can tim: ");
	fflush(stdin);
	gets(P);
	int bf = bruteForce(T,P);
	if(bf>=0)
	{
		printf("Tim thay tai vi tri %d",bf);
	}else
	{
		printf("Khong tim thay!");
	}
    return 0;
}
