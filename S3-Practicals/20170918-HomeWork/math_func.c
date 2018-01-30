/* Home Work */

# include <stdlib.h>
# include <stdio.h>

# include "math_func.h"

int main(){
    unsigned long res = fact(19);
    printf("%li\n",res);
    unsigned long res_fibo = fibo(73);
    printf("fibo %li\n",res_fibo);
    unsigned long res_digit = digit_number(71345);
    printf("digit %li\n",res_digit);
    unsigned long res_bin_digit = binary_digit_number(7);
    printf("digit %li\n",res_bin_digit);
    unsigned long res_power2 = power_of_2(3);
    printf("power of 2 %li\n",res_power2);
    unsigned long res_sum0 = divisor_sum(6);
    printf("div %li\n",res_sum0);
    unsigned long res_sum1 = divisor_sum(30);
    printf("div %li\n",res_sum1);



    return 0;
}

unsigned long fact(unsigned long n) {
    unsigned long res = 1 ;
    unsigned long rank = 1;
    while (n != 0){
        res = res * rank;
        n -= 1;
        rank += 1;
    }
    return res;
}

unsigned long fibo(unsigned long n) {
    unsigned long res_fibo = 0;
    unsigned long fibo_0 = 0;
    unsigned long fibo_1 = 1;
    if (n == 0){
        return 0;
    }
    else{
        for (unsigned long i = 1; i < n; i++){
            res_fibo = fibo_1 + fibo_0;
            fibo_0 = fibo_1;
            fibo_1 = res_fibo;
        }
    }
    return res_fibo;
}

unsigned long int_sqrt(unsigned long n) {
    if (n == 0)
        return 0;
    else
    {
        unsigned long j = n;
        unsigned long x = n;
        while (x*x > n)
        {
            x = (x+j/x)/2;
        }
        return x;
    }
}

unsigned long digit_number(unsigned long n) {
    unsigned long digit = 0;
    while (n != 0){
        n = n/10;
        digit += 1;
    }
    return digit;
}

unsigned long binary_digit_number(unsigned long n) {
    unsigned long bin_digit = 0;
    while (n!=0){
        n = n/2;
        bin_digit += 1;
    }
    return bin_digit;
}

unsigned long power_of_2(unsigned long n) {
    unsigned long res_power = 1;
    if (n == 0){
        res_power = 1;
    }
    else{
        for (unsigned long i = 0; i < n; i++)
        {
            res_power = res_power * 2;
        }
    }
    return res_power;
}

unsigned long divisor_sum(unsigned long n)
{
    unsigned long res = 0;
    if (n == 0 || n == 1){
        res = 1;
    }
    else
    {
        for (unsigned long i = 1 ; i < n ; i++){
            if (n%i == 0 && i != n){
                res += i;
            }
        }
    }
    return res;
}
