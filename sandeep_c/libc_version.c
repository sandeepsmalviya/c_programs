#include<stdio.h>
#include <gnu/libc-version.h>

int main() {


	const char *libc_version=NULL;
	libc_version=gnu_get_libc_version();

	printf("Libc Version= %s\n", libc_version);
	return 0;
}
