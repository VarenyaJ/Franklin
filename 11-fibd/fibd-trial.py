'''
To solve the FIBD problem, modify the Fibonacci sequence generator to keep track of the number
of mature rabbits in addition to the sequence of total rabbits.

Hint Process:
    First:
        Modify the function definition to take three parameters: n for the number of months,
        k for the number of offspring produced by each pair of rabbits,
        and a for the starting number of pairs of rabbits.

    Second
        Initialize two lists, total and mature, both with length n and filled with zeros.
        Set the first element of total to a, and the first element of mature to 0.
        Use a loop to generate the sequence of total rabbits, similar to the original Fibonacci sequence generator.
        However, instead of appending a to the list m, append the sum of the last k elements of mature,
        which represents the number of offspring produced by the mature rabbits.
        Also, add the last element of total to mature, since all rabbits in the last generation will be
        mature in the next generation.

    Third:
        Use another loop to compute the number of mature rabbits in each generation.
        For each month i, set mature[i] to the sum of total[j-k] for j ranging from k to i-1.
        This represents the number of rabbits that matured this month from the offspring produced k months ago.

    Fourth:
        Return the last element of total, which represents the total number of rabbits after n months.

'''
#!/usr/bin/env python

def fibd(n, k, a):
    total = [0] * n
    mature = [0] * n
    total[0] = a
    mature[0] = 0

    for i in range(1, n):
        total[i] = sum(mature[i-1-k:i-1])
        mature[i] = total[i-1]

    return total[-1]

print(fibd(6, 3, 1))