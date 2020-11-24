#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <openssl/sha.h>
#include <time.h>

void ramseysleep(int milliseconds)
{
	clock_t start_time = clock();
	while (clock() < start_time + milliseconds);
}

int main()
{
	FILE *fp;
	fp = fopen("random.txt", "a");
	while (1 == 1)
	{
			ramseysleep(1000);
			register int *var asm ("eax");
			srand((int)var);
			int sum = rand();
			fprintf(fp, "%10d\n", sum);
			//printf("%10d\n", sum);
	}

	return 0;
}
