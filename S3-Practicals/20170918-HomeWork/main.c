# include <err.h>
# include <stdlib.h>
# include <stdio.h>
 
# include "math_func.h"
 
typedef unsigned long (*functype)(unsigned long);
 
const functype ops[] = {
  fact,
  fibo,
  int_sqrt,
  digit_number,
  binary_digit_number,
  power_of_2,
  divisor_sum
};
 
const char *op_names[] = {
  "fact",
  "fibo",
  "int_sqrt",
  "digit_number",
  "binary_digit_number",
  "power_of_2",
  "divisor_sum"
};
 
const char usage[] =
  " <op> <min> <max>\n"
  "\tOperators:\n"
  "\t\t0: factorial\n"
  "\t\t1: fibonacci\n"
  "\t\t2: integer square root\n"
  "\t\t3: number of digits\n"
  "\t\t4: number of binary digits\n"
  "\t\t5: power of 2\n"
  "\t\t6: sum of divisors\n";
 
static
void test(size_t op, unsigned long minval, unsigned long maxval) {
  for (size_t i = minval; i <= maxval; ++i) {
    printf("%s(%lu) = %lu\n", op_names[op], i, ops[op](i));
  }
}
 
int main(int argc, char *argv[]) {
  if (argc < 4)
    errx(1, "%s", usage);
  unsigned long op, minval, maxval;
  op = strtoul(argv[1], NULL, 10);
  minval = strtoul(argv[2], NULL, 10);
  maxval = strtoul(argv[3], NULL, 10);
  test(op, minval, maxval);
  return 0;
}
