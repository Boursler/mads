// "" denotes local module
#include "math_lib.h"
// <> denotes global module
#include <stdio.h>
#include <stdlib.h>

#define RANDOMS 5

int sum_test(long (*f)(long *, long))
{
	int;
	int ret = 0;
	int max_length = 1024 * 1024;
	int len = 0;
	long *arr;
	long i = 0;
	int j = 0;
	arr = malloc(max_length * sizeof(*arr));
	if (arr == NULL) {
		return -1;
	}
	for (i = 0; i < RANDOMS; i++) {
		len = rand() % max_length;
		for (j = 0; j < len; j++) {
			arr[j] = rand();
		}

		ret = ((*f)(arr, len) != sum_c(arr, len));
		if (ret) {
			break;
		}
	}
	free(arr);
	return ret;
}

int main(int argc, char **argv)
{
	int i = 0;
	int ret = 0;
	long r1;
	long r2;
	printf("Xor Test: ");
	for (i = 0; i < RANDOMS; i++) {
		r1 = rand();
		r2 = rand();
		ret = (xor(r1, r2) != (r1 ^ r2));
		if (ret)
			goto test_error;
	}
	printf("Passed\n");
	printf("Or Test: ");
	for (i = 0; i < RANDOMS; i++) {
		r1 = rand();
		r2 = rand();
		ret = (or (r1, r2) != (r1 | r2));
		if (ret)
			goto test_error;
	}

	printf("Test Passed\n");
	printf("NASM sum test:");
	ret = sum_test(sum);
	if (ret) {
		printf("failed");
	} else {
		printf("Passed\n");
	}
	return ret;

test_error:
	printf("Test Failed\n");
	return ret;
}
