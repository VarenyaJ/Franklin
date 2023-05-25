#Problem 1: Counting DNA Nucleotides
#Given: A DNA string ss of length at most 1000 nt.
#Return: Four integers (separated by spaces) counting the respective number of times that the symbols 'A', 'C', 'G', and 'T' occur in ss.

with open('C:/.../1-dna/rosalind_dna.txt', 'r') as file:
    string = file.read()
freq = {nucleotide: string.count(nucleotide) for nucleotide in ['A', 'C', 'G', 'T']}
print(freq['A'], freq['C'], freq['G'], freq['T'])