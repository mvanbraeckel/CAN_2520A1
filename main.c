/*
 * Mitchell Van Braeckel (mvanbrae@uoguelph.ca) 1002297
 * 20/09/2018
 * CIS2520 Assignment 1
 * main.c
        the main program that calls functions of the others (carbon.c, ackermann.c, newton.c)
 */

// =========================== INCLUDED LIBRARIES ===========================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// =========================== FUNCTION PROTOTYPES ==========================
void carbon();
int ackermann(int m, int n);
double newton(double x, double y, double a, int count);
double newton2(double x, double y);

// =============================== FUNCTIONS ================================

/**
 * Fixes each unique character of the word "carbon" iteratively by making sure that
 * all characters right of a character aren't the same. Fixes the first letter, if
 * the next letter isn't the same it fixes that letter, and continues on this pattern
 * until the 6th and final unique letter is fixed, then prints the word and starts the
 * patter of fixing again with a new first letter.
 */
void carbon() {
    char word[7] = "carbon";

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if(j == i) continue; //skips if any are the same

            for (int k = 0; k < 6; k++) {
                if(k == i || k == j) continue; //skips if any are the same

                for (int l = 0; l < 6; l++) {
                    if(l == i || l == j || l == k) continue; //skips if any are the same

                    for (int m = 0; m < 6; m++) {
                        if(m == i || m == j || m == k || m == l) continue; //skips if any are the same

                        for (int n = 0; n < 6; n++) {
                            if(n == i || n == j || n == k || n == l || n == m) continue; //skips if any are the same

                            // if it reaches this line, then all are unique --> so print the permutation
                            printf("%c%c%c%c%c%c\n", word[i], word[j], word[k], word[l], word[m], word[n]);
                        }
                    }
                }
            }
        }
    }
}

/**
 * Models Ackermann's Function using recursion.
 * @param m -The first parameter of Ackermann's Function
 * @param n -The second paramet of Ackermann's Function
 * @return BASE CASE: m=0, n>=0; return n+1 (the value of Ackermann's Function)
 */
int ackermann(int m, int n) {
    // Note: m will always be >= 0 due to prefunction checks
    if(m == 0 && n >= 0) {
        return n+1;

    } else if(m > 0 && n == 0) {
        return ackermann(m-1, 1);

    } else if(m > 0 && n > 0) {
        return ackermann(m-1, ackermann(m, n-1));

    } else {
        fprintf(stderr, "Oops, something went wrong...\n");
        return -1;
    }
}

/**
 * Uses Newton's method to recursively approximate the calculation of a square root
 * @param x -Positive real number that we are trying to find the square root of
 * @param y -Positive ε-value that the approximation must be within accuracy of
 * @param a -Current approximation value
 * @param count -keeps track of the number of recursive calls
 * @return -the current approximation value if it's within accuracy of ε
 */
double newton(double x, double y, double a, int count) {
    // checks the approximation calculation of Newton's method
    if(fabs(a*a - x) <= y || count >= 10000) {
        return a; //within accuracy of ε, so we're done (or reach 10000th approximation which is good enough)

    } else { //try the next approximation of Newton's method
        return newton(x, y, (a + x/a) / 2, ++count);
    }
}

/**
 * Uses Newton's method to iteratively approximate the calculation of a square root
 * @param x -Positive real number that we are trying to find the square root of
 * @param y -Positive ε-value that the approximation must be within accuracy of
 */
double newton2(double x, double y) {
    int count = 0;
    double a = x/2;
    // loop until the approximation is within the accuracy of ε
    while(fabs(a*a - x) > y && count < 10000) {
        a = (a + x/a) / 2; //try the next approximation of Newton's method
        count++;
    }
    return a; //within accuracy of ε, so we're done
}
