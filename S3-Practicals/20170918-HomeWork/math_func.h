
/* math_func.c: some  maths fuctions */

# ifndef EPITA_IP_S3_20160926_HOMEWORK_MATH_FUNC_H_
# define EPITA_IP_S3_20160926_HOMEWORK_MATH_FUNC_H_

/* fact(n) computes factorial of n              */
unsigned long fact(unsigned long n);

/* fibo(n) computes fibonacci number of rank n  *
 * fibo(0) is defined as 0                      *
 * fibo(1) is defined as 1                      *
 * fibo(n) is defined as fibo(n-1) + fibo(n-2)  */
unsigned long fibo(unsigned long n);

/* int_sqrt(n) returns the integer part of the  *
 * square root of n using the heron method      */
unsigned long int_sqrt(unsigned long n);

/* digit_number(n) compute the number of digits *
 * of n in base-10                              */
unsigned long digit_number(unsigned long n);

/* binary_digit_number(n) compute the required  *
 * number of bits of n in base 2                */
unsigned long binary_digit_number(unsigned long n);

/* power_of_2(n) returns 2 to power the power n */
unsigned long power_of_2(unsigned long n);

/* divisor_sum(n) returns the sum of all the    *
 *  divisors of n including 1 but not n         */
unsigned long divisor_sum(unsigned long n);

# endif
