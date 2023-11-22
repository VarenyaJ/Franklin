/*
#Problem 10: Consensus and Profile
#Given: A collection of at most 10 DNA strings of equal length (at most 1 kbp) in FASTA format.
#Return: A consensus string and profile matrix for the collection. (If several possible consensus strings exist, then you may return any one of them.)

'''
A matrix is a rectangular table of values divided into rows and columns. An m×n matrix has m rows and
n columns. Given a matrix A, we write Ai,j to indicate the value found at the
intersection of row i and column j.

Say that we have a collection of DNA strings, all having the same length n.
Their profile matrix is a 4×n matrix P in which P1,j represents the number of times
that 'A' occurs in the jth position of one of the strings, P2,j represents the number of times
that C occurs in the jth position, and so on (see below).

A consensus string c is a string of length n formed from our collection by taking the
most common symbol at each position; the jth symbol of c therefore corresponds to the symbol 
having the maximum value in the j-th column of the profile matrix.
Of course, there may be more than one most common symbol, leading to multiple possible consensus strings.
'''

# Process Breakdown:
    # The code reads a file, removes certain characters from it and splits it into a list of strings
    # Then, it defines a function 'consensus' that receives a list of strings as input
    # The function calculates the frequency of each nucleotide in each position of the strings,
    # creates a consensus sequence based on the most frequent nucleotide in each position,
    # and returns the consensus sequence and the counts of each nucleotide in each position
    # Finally, the function writes the results to a file and closes it
    # The function is called with the list of strings as input, and its output is printed
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 1000

int main() {
    ////////////////////////////////////////////////////////////////
    // Note to self: look at dynamic memory allocations
    ////////////////////////////////////////////////////////////////
    char** dna_strings = (char**) malloc(MAX_STRINGS * sizeof(char*)); // Allocate memory for dna strings
    for (int i = 0; i < MAX_STRINGS; i++) {
        dna_strings[i] = (char*) malloc((MAX_LENGTH + 1) * sizeof(char)); // Allocate memory for each dna string
    }

    // Parse the input file and extract the DNA strings
    FILE* fp = fopen("input.fasta", "r");
    char line[MAX_LENGTH + 2]; // Add 2 to account for \n and \0 characters
    int num_strings = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (line[0] == '>') {
            continue;
        }
        line[strcspn(line, "\n")] = '\0'; // Remove the trailing newline characters
        strcpy(dna_strings[num_strings], line);
        num_strings++;
    }
    fclose(fp);

    // Create the profile matrix
    int** profile_matrix = (int**) malloc(4 * sizeof(int*)); // Allocate memory for profile matrix
    for (int i = 0; i < 4; i++) {
        profile_matrix[i] = (int*) calloc(MAX_LENGTH, sizeof(int)); // Allocate memory for each row of profile matrix and initialize the value to 0
    }
    for (int i = 0; i < strlen(dna_strings[0]); i++) {
        char column[MAX_STRINGS];
        for (int j = 0; j < num_strings; j++) {
            column[j] = dna_strings[j][i];
        }
        for (int j = 0; j < 4; j++) {
            profile_matrix[j][i] = count_occurrences(column, num_strings, "ACGT"[j]); // Count the occurrences of each nucleotide and store the count in the profile matrix
        }
    }

    // Generate the consensus string
    char* consensus = (char*) malloc((strlen(dna_strings[0]) + 1) * sizeof(char)); // Allocate memory for consensus string
    for (int i = 0; i < strlen(dna_strings[0]); i++) {
        int max_count = 0;
        char max_nucleotide = ' ';
        for (int j = 0; j < 4; j++) {
            if (profile_matrix[j][i] > max_count) {
                max_count = profile_matrix[j][i];
                max_nucleotide = "ACGT"[j];
            }
        }
        consensus[i] = max_nucleotide;
    }
    consensus[strlen(dna_strings[0])] = '\0';

    // Print out the consensus string and the profile matrix
    printf("%s\n", consensus);
    for (int i = 0; i < 4; i++) {
        printf("%c:", "ACGT"[i]);
        for (int j = 0; j < strlen(dna_strings[0]); j++) {
            printf(" %d", profile_matrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    ////////////////////////////////////////////////////////////////
    // Note to self: if using dynamic memory allocation, free all memory, otherwise compiler will spit out segfault
    ////////////////////////////////////////////////////////////////
    for (int i = 0; i < MAX_STRINGS; i++) {
        free(dna_strings[i]);
    }
    free(dna_strings);
    for (int i = 0; i < 4; i++) {
        free(profile_matrix[i]);
    }
    free(profile_matrix);
    free(consensus);

    return 0;
}

// This was pulled straight out of a S.O. or Biostars post, can't remember which
int count_occurrences(char* string, int length, char target) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (string[i] == target) {
            count++;
        }
    }
    return count;
}