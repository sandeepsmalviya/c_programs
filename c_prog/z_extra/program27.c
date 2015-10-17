#include<stdio.h>
int main() {
	char name[]="sandeep";
	int i;
	
	i=0;
	while(name[i])
	{ 
		printf("\n%c%c%c%c",name[i],i[name],*(name+i),*(i+name));
		i++;
	}
return 0;
}
