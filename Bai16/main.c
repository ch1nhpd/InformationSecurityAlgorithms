#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX_STRING  256

void lastOccurrence(char P[], int L[])
{
	for(int i = 0; i<128;++i)
	{
		L[i] = -1;
	}

	for(int i =  0; P[i] != '\0'; i++)
	{
		int ascii = P[i];
		L[ascii] = i;
	}
}

int min(int x, int y)
{
	return x < y ? x: y;
}

void toLower(char x[])
{
	for(int i = 0; i< strlen(x);++i)
	{
		if(x[i]>=65 &&x[i]<=90)
		{
			x[i] +=32;
		}
	}
}

int boyer_moore(char T[], char P[], int L[], int *dem)
{
	int i, j ;
	int m = strlen(P);
	i = j = m - 1;
	*dem = 0;
	while(i< strlen(T))
	{
		(*dem)++;
		if(T[i]!=P[j])
		{
			int ascii = T[i];
			i = i + m - min(j,1+L[ascii]);
			j = m -1;
		}
		else
		{
			i--;
			j--;
			if( j < 0 )
				return i+1;
		}
	}
	return -1;
}

int main()
{
	int L[128], dem;
	char P[MAX_STRING], T[MAX_STRING];
	printf("Nhap chuoi T: ");
	fflush(stdin);
	gets(T);
	printf("Nhap chuoi P can tim: ");
	fflush(stdin);
	gets(P);
	toLower(P);
	toLower(T);
	lastOccurrence(P,L);

	int boyerMoore = boyer_moore(T, P, L, &dem);
	if(boyerMoore >=0 )
	{
		printf("\nP xuat hien trong T tai: i = %d", boyerMoore);
		printf("\nSo lan so sanh la: %d\n", dem);
	}else{
		printf("Khong tim thay P trong T!\ndem = %d\n",dem);
	}

	/*	TEST CASE
	T: "aaaaaaaaa"
	P: "baaaaa“ ==> DEM =24

	T: "abacaabadcabacabaabb"
	P: "abacab" ==>dem = 13

	T: "a pattern matching algorithm"
	P: "rithm"  ==> dem =11



	*/
}
