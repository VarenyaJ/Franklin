#include <stdio.h>
#include <string.h>

int main() {
    char dna[1000];
    char reverse_dna[1000];
    char reverse_complement[1000];
    int i, j;

    // Get user input
    printf("Enter a DNA string: ");
    scanf("%s", dna);

    // Reverse the DNA string
    int n = strlen(dna);
    for (i = 0, j = n - 1; i < n; i++, j--) {
        reverse_dna[i] = dna[j];
    }
    reverse_dna[n] = '\0';

    // Replace each symbol with its complement
    for (i = 0; i < n; i++) {
        switch (reverse_dna[i]) {
            case 'A':
                reverse_complement[i] = 'T';
                break;
            case 'C':
                reverse_complement[i] = 'G';
                break;
            case 'G':
                reverse_complement[i] = 'C';
                break;
            case 'T':
                reverse_complement[i] = 'A';
                break;
            default:
                // Invalid symbol
                printf("Invalid DNA symbol: %c\n", reverse_dna[i]);
                return 1;
        }
    }
    reverse_complement[n] = '\0';

    // Output the reverse complement
    printf("%s\n", reverse_complement);

    return 0;
}
