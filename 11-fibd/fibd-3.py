#   Recall the definition of the Fibonacci numbers from “Rabbits and Recurrence Relations”,
#   which followed the recurrence relation Fn=Fn−1+Fn−2 and assumed that each pair of rabbits
#   reaches maturity in one month and produces a single pair of offspring (one male, one female)
#   each subsequent month.
#   
#   Our aim is to somehow modify this recurrence relation to achieve a dynamic programming solution
#   in the case that all rabbits die out after a fixed number of months.
#   See Figure 4 for a depiction of a rabbit tree in which rabbits live for three months
#   (meaning that they reproduce only twice before dying).


# Define a function to generate a modified Fibonacci sequence
# k: number of terms to generate
# f: starting point of the sequence
def fib(k, f):
    m = []  # Initialize an empty list to store the sequence
    a = 1   # Initialize the first term of the sequence to 1
    b = 1   # Initialize the second term of the sequence to 1

    # Generate the first f terms of the sequence
    for i in range(f):
        m.append(a)  # Append the current term to the list
        c = a + b    # Compute the next term of the sequence
        a = b        # Update the current term to the next term
        b = c        # Update the next term to the computed term

    # Generate the remaining k-f terms of the sequence
    for i in range(k-1):
        m.append(sum(m[:len(m)-1]))  # Append the sum of the previous k-1 terms
        del m[0]                     # Remove the first term of the sequence

    print(m[0])  # Print the first term of the modified sequence

fib(96, 17)
