/*
 * Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * 20/09/2018
 * CIS2520 Assignment 1
 * ackermann.c
        Prints the result of Ackermann's function: A(m, n)
            - Gets 2 integer command line arguments to use for the values of m and n respectively
        Also, it prints the range of integer parameters, (m,n), does not exceed the value of the maximum
            integer in the C system on the SoCS machines
                - in other words, what the max value of n is for each value of m >= 0 (since m,n >= 0),
                    so entering any value of n over a certain threshold compared to the accompanying m value
                    will cause the program to encounter a segmention fault (due to numbers becoming too large or
                    overflow since an integer value can only be so large)
 */

#include "main.c"

int main(int argc, char **argv) {
    // checks that the correct #of command line arguments have been entered
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <input: int m, int n>\n", argv[0]);
        exit(-1);
    }
    // NOTE: if values of m or n are inputted as a decimal, then it will be rounded down to the nearest whole number
    // NOTE: if values of m or n are inputted as non-numbers (characters), then it will be treated as a 0

    // converts and checks that the values entered are positive
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    // checks that the values entered are positive or 0
    if(m < 0 || n < 0) {
        fprintf(stderr, "Integers must be greater than or equal to 0\n");
        exit(-1);
    }

    // prints the value of Ackermann's function using the given values of m and n
    printf("A(%d,%d) = %d\n", m, n, ackermann(m,n));
    return 0;
}
