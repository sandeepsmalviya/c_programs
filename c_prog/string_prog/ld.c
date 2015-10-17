#include<stdio.h>
#include<string.h>
#include<stdlib.h>



#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))


int levenshtein(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);

    printf("%s length s1len=%d\n", s1, s1len);
    printf("%s length s2len=%d\n", s2, s2len);

    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;

    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;

    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = MIN3(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));


	for(x=0; x <= s2len; x++)	 {
		for(y=0; y <= s1len; y++)	 {									
			printf("%4u", matrix[x][y]);
		}
		printf("\n");
	}		

	printf("\n");

    return(matrix[s2len][s1len]);
}


int main() {

	char *s1 = "google";
	char *s2 = "look at";
	
	unsigned int dist = levenshtein(s1, s2);
	printf("Levenshtein Distance=%u\n",dist);
	
	return 0;
}
