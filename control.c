#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ramseysleep(int milliseconds)
{
	clock_t start_time = clock();
	while (clock() < start_time + milliseconds);
}

int main()
{
	FILE *fp;
	fp = fopen("control.txt", "a");
	int sum = 1;
	while (1 == 1)
	{
			ramseysleep(1000);
			sum = rand();
			fprintf(fp, "%10d\n", sum);
	}

	return 0;
}
