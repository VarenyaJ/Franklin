# Define a dictionary mapping each nucleotide to its complement
complement = {'A': 't', 'C': 'g', 'G': 'c', 'T': 'a'}

# Convert the sequence to uppercase, reverse it, and complement each nucleotide
dna_seq = "AAAACCCGGT"
rev_comp_seq = ''.join(complement[base] for base in reversed(dna_seq))

# Print the reverse complement in uppercase
print(rev_comp_seq.upper())
