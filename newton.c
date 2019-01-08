/*
 * Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * 21/09/2018
 * CIS2520 Assignment 1
 * newton.c
        Calculates the square root of x using Newton's method

        Let x, ǫ be a positive real. To calculate the square root of x by Newton’s method, so
        that the square of the solution differs from x is within an accuracy of ǫ, we start with an initial
        approximation a = x/2. If |a ∗ a − x| ≤ ǫ, we stop with the result a. Otherwise we replace a
        with the next approximation, defined by (a+x/a)/2, and then test the result again. In general,
        we keep on computing and testing successive approximations until we find one close enough to
        stop, or a predefined maximum number of iterations or recurssions is reached.

        Write two C functions, using recursion and non-recursion respectively, to implement the above algorithm.
        You should use a sequence of big real numbers and a small ǫ to test your program.
 */

#include "main.c"

int main(int argc, char **argv) {
    // checks that the correct #of command line arguments have been entered
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <input: double x, double ε>\n", argv[0]);
        exit(-1);
    }

    double x, y; //ε
    // converts and checks that the values entered were real numbers
    if(sscanf(argv[1], "%lf", &x) != 1) {
        fprintf(stderr, "Must enter a real number\n");
        exit(-1);
    }
    if(sscanf(argv[2], "%lf", &y) != 1) {
        fprintf(stderr, "Must enter a real number\n");
        exit(-1);
    }

    // checks that the values entered were positive
    if(x < 0) {
        fprintf(stderr, "x must be positive\n");
        exit(-1);
    }
    if(y < 0) {
        fprintf(stderr, "ε must be positive\n");
        exit(-1);
    }

    // prints the values given by the recursive and non-recursive functions of Newton's method
    printf("x = %lf\tε = %lf\n", x, y);
    printf("Recursive: %.16lf\n", newton(x, y, x/2.0, 0));
    printf("Iterative: %.16lf\n", newton2(x, y));
    return 0;
}
