 // "" denotes local module
#include "math_lib.h"
 // <> denotes global module
#include <stdio.h>
#include <stdlib.h>

#define RANDOMS 5
int main(int argc, char **argv)
{
	int i = 0;
	int ret = 0;
	long r1;
	long r2;
	printf("Xor Test: ");
	for(i = 0; i < RANDOMS; i++){
		r1 = rand();
		r2 = rand();
		ret = (xor(r1, r2) != (r1^r2));
		if(ret)
			goto test_error;
	}
	printf("Passed\n");
	printf("Or Test: ");
	for (i =0; i < RANDOMS; i++){
		r1 = rand();
		r2 = rand();
		ret = (or(r1, r2) != (r1 | r2));
		if(ret)
			goto test_error;
	}


	printf("Test Passed\n");
	printf("NASM sum test:");
	for(i = 0; i < RANDOMS; i++){
		long arr[5] = {rand(), rand(), rand(), rand(), rand()};
		printf("assembly program output: %ld\n", sum(arr, 5));
		printf("c program output: %ld\n", sum_c(arr,5));
		ret = (sum(arr, 5) != sum_c(arr, 5));
		if(ret)
			goto test_error;
		printf("Passed\n");

		}
	return ret;

test_error:
	printf("Test Failed\n");
	return ret;
}
