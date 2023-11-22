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

'''
My summary:
    The first line opens a file called "Example12.txt" in read mode and assigns it to the variable 'f'
    The second line initializes an empty list called 'mat'
    The third line reads the entire contents of the file into a string called 'str1'
    The fourth line removes all instances of the string "Rosalind_" from 'str1'
    The fifth line removes all newline characters from 'str1'
    The sixth line removes all digits from 'str1'
    The seventh line splits 'str1' into a list of strings at each ">" character and assigns it to 'mat'
    The eighth line removes any empty strings from 'mat'
'''
f = open("C:/Users/varen/Desktop/My_New_Stuff/no_place_like/Computing/Bioinformatics/Rosalind/10-cons/Example12.txt", "r")
mat = []
str1 = f.read()
str1 = str1.replace("Rosalind_", "")
str1 = str1.replace("\n", "")
str1 = ''.join([i for i in str1 if not i.isdigit()])
mat = str1.split(">")
mat.remove("")

'''
The 'consensus' function takes a list of strings 'm' as input.
Within the function, four empty lists are initialized to store the count of each nucleotide at each position.
Two nested for-loops iterate over each position and each string in 'm', respectively.
For each string, the nucleotide at the current position is counted and added to the appropriate list.
'''
def consensus (m):
    a = []
    c = []
    g = []
    t = []
    for i in range(0, len(mat[0])):
        countA = 0
        countC = 0
        countG = 0
        countT = 0
        for j in mat:
            if (j[i] == "A"):
                countA = countA + 1
            elif (j[i] == "C"):
                countC = countC + 1
            elif (j[i] == "G"):
                countG = countG + 1
            elif (j[i] == "T"):
                countT = countT + 1
        '''
        The counts of each nucleotide at each position are converted to strings
        and concatenated with their respective nucleotide
        and a colon to create four strings 'strA', 'strC', 'strG', and 'strT'.
        '''
        a.append(countA)
        c.append(countC)
        g.append(countG)
        t.append(countT)
    profile = []
    for i in range(0, len(mat[0])):
        if (a[i] >= c[i] and a[i] >= g[i] and a[i] >= t[i]):
            profile.append("A")
        elif (c[i] >= a[i] and c[i] >= g[i] and c[i] >= t[i]):
            profile.append("C")
        elif (g[i] >= a[i] and g[i] >= c[i] and g[i] >= t[i]):
            profile.append("G")
        else:
            profile.append("T")
    strProfile = ''.join(profile)
    strA = 'A: ' + ' '.join(map(str,a))
    strC = 'C: ' + ' '.join(map(str,c))
    strG = 'G: ' + ' '.join(map(str,g))
    strT = 'T: ' + ' '.join(map(str,t))
    '''
    The five resulting strings ('strProfile', 'strA', 'strC', 'strG', and 'strT') are written to a file
    called "result12.txt".
    Finally, the function returns the five strings as a tuple.
    The function is called with 'mat' as input and its output is printed
    '''
    file = open("C:/Users/.../10-cons/result12.txt","w")
    file.write(strProfile)
    file.write("\n")
    file.write(strA)
    file.write("\n")
    file.write(strC)
    file.write("\n")
    file.write(strG)
    file.write("\n")
    file.write(strT)
    file.write("\n")
    file.close()
    return strProfile, strA, strC, strG, strT
print(consensus(mat))


