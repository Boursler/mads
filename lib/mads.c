#include "math_lib.h"

long add(long a, long b){
    return a + b;
}

long subtract(long a, long b){
    return a - b;
}

long multiply(long a, long b){
    return a * b;
}

long divide(long a, long b){
    return a / b;
}

long sum_c(long* arr, long len){
    long res = 0;
     for(long i = 0; i < len; i++){
         res += arr[i];
     }
     return res;
}
