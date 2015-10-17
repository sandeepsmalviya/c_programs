#include<stdio.h>
#define FOUND 1;
#define NOTFOUND 0
int main() {

	char masterlist[6][10]={
				"sandeep",
				"priyanka",
				"aarti",
				"rahul",	
				"piya",	
				"basanti"
				};
	
	int i,flag,a;
	char yourname[10];
	
	printf("Enter your name\n");
	scanf("%s",yourname);
	
	flag=NOTFOUND;
	for(i=0;i<=5;i++) {	
			
		a=strcmp(masterlist[i],yourname);
		if(a==0){	
		
			flag=FOUND;
			break;
		}		
	
	}
	
	if(flag==NOTFOUND) {
	
		printf("Sorry, your name is not found\n");

	}
	else {
	
		printf("Your name is found\n");
	
	}
	return 0;
}

int strcmp(char *s1, char *s2) {
	
	while(*s1==*s2) {
	
		if(*s1=='\0') {	
			return 0;
		
		}
		
		s1++;
		s2++;
	}
	
	return (*s1-*s2);
}
