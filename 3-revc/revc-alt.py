# Reverse the DNA string
# Use string slicing with a step of -1,
user_input = input("Enter a DNA string or a file name: ")
if user_input.endswith('.txt'):
    with open(user_input, 'r') as f:
        dna = f.read().strip()
else:
    dna = user_input

#dna = 'AAAACCCGGT'

reverse_dna = dna[::-1] # 'AAAACCCGGT'

# Replace each symbol with its complement
# Use a dictionary to map each symbol to its complement
# Then use a list comprehension to replace each symbol in the reversed DNA string.
complements = {'A': 'T', 'C': 'G', 'G': 'C', 'T': 'A'}
reverse_complement = ''.join([complements[symbol] for symbol in reverse_dna])

# Output the reverse complement
print(reverse_complement) # 'ACCGGGTTTT'

#& C:/.../AppData/Local/Microsoft/WindowsApps/python3.10.exe c:/Users/.../3-revc/revc-alt.py