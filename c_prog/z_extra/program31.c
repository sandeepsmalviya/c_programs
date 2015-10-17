#include<stdio.h>
#include<string.h>

int main() {
	char str1[20]="bamboozled";
	char str2[]="chap";
	char str3[20];
	int l,k;
	
	l=strlen(str1);
	printf("\n length of string=%d",l);
	
	strcpy(str3,str1);
	printf("\nafter copying,string str3=%s",str3);
	
	k=strcmp(str1,str2);
	printf("\non comparing str1 and str2,k=%d",k);

	k=strcmp(str3,str1);
	printf("\non comparing str3 and str1,k=%d",k);

	strcat(str1,str2);
	printf("\non concatenation str1=%s",str1);

	return(0);
}

