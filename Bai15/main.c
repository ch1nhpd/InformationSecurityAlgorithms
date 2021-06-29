#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 	255
int brute_force(char T[], char P[], int* dem)
{
	int i,j;
	int lenT, lenP;
	lenT=strlen(T);
	lenP= strlen(P);
	i = j = 0;
	(*dem) = 0;
	while(i<lenT)
	{
		(*dem)++;
		if(T[i] == P[j])
		{
			i++;
			j++;
			if( j == lenP)
			{
				return i - lenP;
			}
		}else{
			i = i - j + 1;
			j = 0;
		}
	}
	return -1;
}


int main()
{
    char T[MAX_STRING], P[MAX_STRING];
    int dem;
    printf("Nhap chuoi T: ");
    fflush(stdin);
    gets(T);
    printf("Nhap chuoi can tim P: ");
    fflush(stdin);
    gets(P);
    int result = brute_force(T,P,&dem);
    if(result<0)
	{
		printf("P khong co trong T!\n");
	}else{
		printf("P xuat hien o vi tri: %d\nSo lan so sanh: %d\n",result,dem);
	}

	/*TEST CASE
	T: "a string searching example is standard"
	P: “example"

	T: "aaaaaaaaaaaaaaaaaaaaaaaaaah"
	P: "aaah"

	*/
}
