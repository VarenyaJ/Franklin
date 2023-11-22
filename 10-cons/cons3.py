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


from collections import Counter

# Parse the input file and extract the DNA strings
with open('C:/Users/.../10-cons/input.fasta') as f:
    data = f.read().split('>')[1:]
    dna_strings = [d.split('\n', 1)[1].replace('\n', '') for d in data]

# Create the profile matrix
profile_matrix = {'A': [], 'C': [], 'G': [], 'T': []}
for i in range(len(dna_strings[0])):
    column = [dna[i] for dna in dna_strings]
    counts = Counter(column)
    profile_matrix['A'].append(counts['A'])
    profile_matrix['C'].append(counts['C'])
    profile_matrix['G'].append(counts['G'])
    profile_matrix['T'].append(counts['T'])

# Generate the consensus string
consensus = ''
for i in range(len(dna_strings[0])):
    column = [dna[i] for dna in dna_strings]
    counts = Counter(column)
    consensus += counts.most_common(1)[0][0]

# Print out the consensus string and the profile matrix
print(consensus)
for key, value in profile_matrix.items():
    print(key + ': ' + ' '.join(map(str, value)))