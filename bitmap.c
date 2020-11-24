#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "libbmp.h"
#include "libbmp.c"
#include <unistd.h>
#include <time.h>

void ramseysleep(int milliseconds)
{
	clock_t start_time = clock();
	while (clock() < start_time + milliseconds);
}

int main()
{
	int size = 512;
	bmp_img img;
	bmp_img_init_df(&img, size, size);
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			ramseysleep(1000);
			register int *var asm ("eax");
			srand((int)var);
			int sum = rand();
			if (sum % 2 == 0)
				bmp_pixel_init(&img.img_pixels[y][x], 255,0,0);
			else
				bmp_pixel_init(&img.img_pixels[y][x], 0,0,0);
		}
	}
	bmp_img_write(&img, "experimental.bmp");
	bmp_img_free(&img);

	return 0;
}
