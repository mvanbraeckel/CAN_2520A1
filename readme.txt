CIS*2520: Data Structures - Assignment #1

To compile, just type "make" to compile everything.

main.c - contains the functions to answer each question, as well as #include's
         the other 3 .c programs contain #include "main.c" so they can use the functions

Q1: carbon.c    - Usage: ./carbon
/**
 * Prints all the permutations of the letters of the string "carbon"
 */
E.g.
Input: ./carbon
Output:
carbon
[..718 other permutations..]
nobrac

Q2: ackermann.c - Usage: ./ackermann <input: int m, int n>
/**
 * Models Ackermann's Function using recursion - prints the result of Ackermann's function: A(m, n)
 */
E.g.
Input: ./ackermann 2 2
Output:
A(2,2) = 7

Ranges:
(0, 2147483646) - highest combination for m=0 because any higher n-value will cause integer overflow (and become negative)
(1, 261876)*    - highest combination for m=1, because any higher n-value will cause a segmentation fault
(2, 130988)*    - highest combination for m=2, because any higher n-value will cause a segmentation fault
(3, 14)         - highest combination for m=3, because any higher n-value will cause a segmentation fault
(4, 1)          - highest combination for m=4, because any higher n-value will cause a segmentation fault
(5, 0)          - highest combination for m=5, because the only value that works is n=0 since any higher n-value will cause a segmentation fault
                - no combination for m>=6 because any combination with m=6 will cause a segmentation fault
NOTE: * these n-values vary slightly each time you compile, so they will be slightly off sometimes

Q3: newton.c    - Usage: ./newton <input: double x, double ε>
/**
 * Uses Newton's method to recursively approximate the calculation of a square root
 */
E.g.
Input: ./newton 4 0.001
Output:
x = 4.000000    ε = 0.001000
Recursive: 2.0000000000000000
Iterative: 2.0000000000000000
