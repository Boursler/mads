#include "math_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define total_iterations 1024
int main(int argc, char **argv)
{
	clock_t start, end;
	double cpu_time_used;
	int ret = 0;
	int length = 1024 * 1024;
	long *arr;
	long i = 0;
	long iterations = 0;
	long arr_bytes = length * sizeof(*arr);
	arr = malloc(arr_bytes);
	if (arr == NULL) {
		return -1;
	}

	for (i = 0; i < length; i++)
		arr[i] = rand();

	start = clock();
	for (iterations = 0; iterations < total_iterations; iterations++)
		ret = (sum(arr, length));

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	free(arr);
	printf("Performance is time: %f\n, on an array of size: %d\n, at a "
	       "rate of: %f gb/sec\n",
	       cpu_time_used, arr_bytes,
	       (arr_bytes * total_iterations) /
		   (cpu_time_used * 1024 * 1024 * 1024));

	return ret;
}