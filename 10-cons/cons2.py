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

# Parse the input file containing the DNA strings in FASTA format and store them in a list or matrix
# Use the Biopython library to read the FASTA file and store the sequences in a list
from Bio import SeqIO

sequences = []
for record in SeqIO.parse("C:/Users/.../10-cons/input.fasta", "fasta"):
    sequences.append(record.seq)
# Create a profile matrix by counting the occurrence of each nucleotide at each position in the DNA strings
# Use a nested list or a dictionary to store the counts
profile_matrix = {'A': [0] * len(sequences[0]), 'C': [0] * len(sequences[0]), 'G': [0] * len(sequences[0]), 'T': [0] * len(sequences[0])}

for seq in sequences:
    for i in range(len(seq)):
        profile_matrix[seq[i]][i] += 1
# Find the consensus string by selecting the most frequent nucleotide at each position in the profile matrix
# If there is a tie: select any of the nucleotides
consensus = ''
for i in range(len(sequences[0])):
    max_count = 0
    max_nucleotide = ''
    for nucleotide in profile_matrix.keys():
        if profile_matrix[nucleotide][i] > max_count:
            max_count = profile_matrix[nucleotide][i]
            max_nucleotide = nucleotide
    consensus += max_nucleotide
# Write the consensus string and profile matrix to an output file or print them to the console
# Save the profile matrix as a CSV file using a Pandas library function
import pandas as pd

df = pd.DataFrame(profile_matrix)
df.to_csv('profile_matrix.csv')

with open('output.txt', 'w') as f:
    f.write(consensus)