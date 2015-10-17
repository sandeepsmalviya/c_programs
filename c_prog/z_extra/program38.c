#include<stdio.h>
int main() {	
	
	struct book {
		char name[25];
		char author[25];
		int callno;
	};
	
	struct book b1={"let us c","YPK",101};
	struct book *ptr;
	
	ptr=&b1;
	printf("%s %s %d\n",b1.name, b1.author, b1.callno);
	printf("%s %s %d\n",ptr->name, ptr->author, ptr->callno);
	return 0;
}
