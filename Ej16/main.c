#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	int z;
} Point;

int i, j, k;

int main(int argc, char **argv) {
	i = 2;
	j = 3;
	k = 1;
	Point ***a = malloc(i * sizeof(Point**));
	for (int i2 = 0; i2 < i; i2++) {
		*(a + i2) = malloc(j * sizeof(Point*));

		for (int j2 = 0; j2 < j; j2++) {
			*(*(a + i2) + j2) = malloc(k * sizeof(Point));

			for (int k2 = 0; k2 < k; k2++) {
				Point p = { i2, j2, k2 };
				*(*(*(a + i2) + j2) + k2) = p;
			}
		}
	}

	printf("X:%i,Y:%i,Z:%i", a[1][2][0].x, a[1][2][0].y, a[1][2][0].z);

	for (int i2 = 0; i2 < i; i2++) {

		for (int j2 = 0; j2 < j; j2++) {

			free(*(a + i2) + j2);
		}
		free(a + i2);
	}
	free(a);

}
