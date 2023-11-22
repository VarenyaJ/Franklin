/*
#   Recall the definition of the Fibonacci numbers from “Rabbits and Recurrence Relations”,
#   which followed the recurrence relation Fn=Fn−1+Fn−2 and assumed that each pair of rabbits
#   reaches maturity in one month and produces a single pair of offspring (one male, one female)
#   each subsequent month.
#   
#   Our aim is to somehow modify this recurrence relation to achieve a dynamic programming solution
#   in the case that all rabbits die out after a fixed number of months.
#   See Figure 4 for a depiction of a rabbit tree in which rabbits live for three months
#   (meaning that they reproduce only twice before dying).
*/
#include <stdio.h>
#include <stdlib.h>

int getRabbitPairs(int n, int m) {
    int* dp = (int*) malloc(n * sizeof(int));   // Dynamically allocate memory for the dp array
    dp[0] = 1;          // Initialize the number of rabbit pairs for the first month to 1
    dp[1] = 1;          // Initialize the number of rabbit pairs for the second month to 1

    int i;
    for (i = 2; i < n; i++) {
        if (i < m) {
            dp[i] = dp[i-1] + dp[i-2];              // Compute the number of rabbit pairs for the current month using the standard Fibonacci recurrence relation
        } else if (i == m || i == m+1) {
            dp[i] = dp[i-1] + dp[i-2] - 1;          // Modify the recurrence relation to account for the fixed lifespan of the rabbits
        } else {
            dp[i] = dp[i-1] + dp[i-2] - dp[i-m-1];  // Modify the recurrence relation to account for the fixed lifespan of the rabbits
        }
    }

    int pairs = dp[n-1];   // Store the number of rabbit pairs for the nth month in a separate variable
    free(dp);              // Deallocate the memory used by the dp array
    return pairs;          // Return the number of rabbit pairs for the nth month
}

int main() {
    int n = 87;     // Set the number of months
    int m = 23;     // Set the lifespan of the rabbits
    int pairs = getRabbitPairs(n, m);   // Call the function to compute the total number of rabbit pairs after n months with m lifespan
    printf("%d\n", pairs);  // Print the total number of rabbit pairs after n months with m lifespan
    return 0;
}
