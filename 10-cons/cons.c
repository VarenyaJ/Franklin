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

# The code reads a file, removes certain characters from it and splits it into a list of strings.
# Then, it defines a function 'consensus' that receives a list of strings as input.
# The function calculates the frequency of each nucleotide in each position of the strings,
# creates a consensus sequence based on the most frequent nucleotide in each position,
# and returns the consensus sequence and the counts of each nucleotide in each position.
# Finally, the function writes the results to a file and closes it.
# The function is called with the list of strings as input, and its output is printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DNA_STRINGS 10
#define MAX_DNA_LENGTH 1000

// Function to open the input file and extract the DNA strings
void parse_input_file(char* filename, char **dna_strings, int* num_strings, int* string_length) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read in the DNA strings from the FASTA file
    char line[MAX_DNA_LENGTH + 1];
    int i = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        if (line[0] == '>') {
            // Skip the header line
            continue;
        }
        // Remove newline characters from the end of the line
        line[strcspn(line, "\n")] = 0;
        // Copy the DNA string into the array
        strcpy(dna_strings[i], line);
        i++;
    }
    *num_strings = i;
    *string_length = strlen(dna_strings[0]);

    fclose(f);
}

// Function to create the profile matrix
void create_profile_matrix(char **dna_strings, int num_strings, int string_length, int **profile_matrix) {
    // Initialize the profile matrix to all zeros
    memset(*profile_matrix, 0, sizeof(int) * 4 * string_length);

    // Loop through each position in the DNA strings
    for (int i = 0; i < string_length; i++) {
        // Loop through each DNA string and count the occurrences of each nucleotide
        for (int j = 0; j < num_strings; j++) {
            char nucleotide = dna_strings[j][i];
            switch (nucleotide) {
                case 'A':
                    profile_matrix[i][0]++;
                    break;
                case 'C':
                    profile_matrix[i][1]++;
                    break;
                case 'G':
                    profile_matrix[i][2]++;
                    break;
                case 'T':
                    profile_matrix[i][3]++;
                    break;
                default:
                    printf("Invalid nucleotide: %c\n", nucleotide);
                    exit(1);
            }
        }
    }
}

// Function to generate the consensus string
void generate_consensus_string(int profile_matrix[][4], int string_length, char* consensus) {
    // Loop through each position in the profile matrix and find the most common nucleotide
    for (int i = 0; i < string_length; i++) {
        int max_count = 0;
        char max_nucleotide;
        for (int j = 0; j < 4; j++) {
            if (profile_matrix[i][j] > max_count) {
                max_count = profile_matrix[i][j];
                switch (j) {
                    case 0:
                        max_nucleotide = 'A';
                        break;
                    case 1:
                        max_nucleotide = 'C';
                        break;
                    case 2:
                        max_nucleotide = 'G';
                        break;
                    case 3:
                        max_nucleotide = 'T';
                        break;
                }
            }
        }
        consensus[i] = max_nucleotide;
    }
}

int main() {
    //char dna_strings[MAX_DNA_STRINGS][MAX_DNA_LENGTH + 1];
    char **dna_strings = (char **)malloc(MAX_DNA_STRINGS * sizeof(char *));
    for (int i = 0; i < MAX_DNA_STRINGS; i++) {
        dna_strings[i] = (char *)malloc((MAX_DNA_LENGTH + 1) * sizeof(char));
    }
    char *consensus = (char *)malloc((MAX_DNA_LENGTH + 1) * sizeof(char));
    //int profile_matrix[MAX_DNA_LENGTH][4];
    int **profile_matrix = (int **)calloc(MAX_DNA_LENGTH, sizeof(int *));
    for (int i = 0; i < MAX_DNA_LENGTH; i++) {
            profile_matrix[i] = (int *)calloc(4, sizeof(int));
        }
    int num_strings, string_length;

    // Parse the input file
    parse_input_file("input.fasta", dna_strings, &num_strings, &string_length);

    // Create the profile matrix
    create_profile_matrix(dna_strings, num_strings, string_length, profile_matrix);

    // Generate the consensus string
    generate_consensus_string(profile_matrix, string_length, consensus);

    // Print out the consensus string and the profile matrix
    printf("%s\n", consensus);
    printf("A:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][0]);
    }
    printf("\nC:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][1]);
    }
    printf("\nG:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][2]);
    }
    printf("\nT:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][3]);
    }
    printf("\n");

    for (int i = 0; i < MAX_DNA_STRINGS; i++) {
        free(dna_strings[i]);
    }
    free(dna_strings);
    for (int i = 0; i < string_length; i++) {
        free(profile_matrix[i]);
    }
    free(profile_matrix);

    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DNA_STRINGS 10
#define MAX_DNA_LENGTH 1000

// Function to open the input file and extract the DNA strings
void parse_input_file(char* filename, char dna_strings[][MAX_DNA_LENGTH + 1], int* num_strings, int* string_length) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read in the DNA strings from the FASTA file
    char line[MAX_DNA_LENGTH + 1];
    int i = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        if (line[0] == '>') {
            // Skip the header line
            continue;
        }
        // Remove newline characters from the end of the line
        line[strcspn(line, "\n")] = 0;
        // Copy the DNA string into the array
        strcpy(dna_strings[i], line);
        i++;
    }

    *num_strings = i;
    *string_length = strlen(dna_strings[0]);

    fclose(f);
}

// Function to create the profile matrix
void create_profile_matrix(char dna_strings[][MAX_DNA_LENGTH + 1], int num_strings, int string_length, int profile_matrix[][4]) {
    // Initialize the profile matrix to all zeros
    memset(profile_matrix, 0, sizeof(int) * 4 * string_length);

    // Loop through each position in the DNA strings
    for (int i = 0; i < string_length; i++) {
        // Loop through each DNA string and count the occurrences of each nucleotide
        for (int j = 0; j < num_strings; j++) {
            char nucleotide = dna_strings[j][i];
            switch (nucleotide) {
                case 'A':
                    profile_matrix[i][0]++;
                    break;
                case 'C':
                    profile_matrix[i][1]++;
                    break;
                case 'G':
                    profile_matrix[i][2]++;
                    break;
                case 'T':
                    profile_matrix[i][3]++;
                    break;
                default:
                    printf("Invalid nucleotide: %c\n", nucleotide);
                    exit(1);
            }
        }
    }
}

// Function to generate the consensus string
void generate_consensus_string(int profile_matrix[][4], int string_length, char* consensus) {
    // Loop through each position in the profile matrix and find the most common nucleotide
    for (int i = 0; i < string_length; i++) {
        int max_count = 0;
        char max_nucleotide;
        for (int j = 0; j < 4; j++) {
            if (profile_matrix[i][j] > max_count) {
                max_count = profile_matrix[i][j];
                switch (j) {
                    case 0:
                        max_nucleotide = 'A';
                        break;
                    case 1:
                        max_nucleotide = 'C';
                        break;
                    case 2:
                        max_nucleotide = 'G';
                        break;
                    case 3:
                        max_nucleotide = 'T';
                        break;
                }
            }
        }
        consensus[i] = max_nucleotide;
    }
}

int main() {
    char dna_strings[MAX_DNA_STRINGS][MAX_DNA_LENGTH + 1];
    char consensus[MAX_DNA_LENGTH + 1];
    int profile_matrix[MAX_DNA_LENGTH][4];
    int num_strings, string_length;

    // Parse the input file
    parse_input_file("input.fasta", dna_strings, &num_strings, &string_length);

    // Create the profile matrix
    create_profile_matrix(dna_strings, num_strings, string_length, profile_matrix);

    // Generate the consensus string
    generate_consensus_string(profile_matrix, string_length, consensus);

    // Print out the consensus string and the profile matrix
    printf("%s\n", consensus);
    printf("A:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][0]);
    }
    printf("\nC:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][1]);
    }
    printf("\nG:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][2]);
    }
    printf("\nT:");
    for (int i = 0; i < string_length; i++) {
        printf(" %d", profile_matrix[i][3]);
    }
    printf("\n");

    return 0;
}
*/