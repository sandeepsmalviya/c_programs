#include<stdio.h>
#include<errno.h>

int main() {
	int fd;
	int flags;
	int mode;
	char *pathname="/home/sandeep/f1.c1";
	char *errormsg=NULL;
	fd = open(pathname, flags, mode);
	if (fd == -1) {
		
		fprintf(stderr, "Soome error=%d\n", errno);
		perror("open");

		errormsg=strerror(errno);
		fprintf(stderr, "Error Message=%s\n", errormsg);

	//	exit(EXIT_FAILURE);
	}else {
		
		printf(" No Error ..proceed for reading a file\n");
	}	

	return 0;

}
