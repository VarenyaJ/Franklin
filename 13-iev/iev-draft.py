'''
Averages arise everywhere. In sports, we want to project the average number of games that a team is expected to win;
in gambling, we want to project the average losses incurred playing blackjack; in business, companies want to
calculate their average expected sales for the next quarter.

Molecular biology is not immune from the need for averages. Researchers need to predict the expected number
of antibiotic-resistant pathogenic bacteria in a future outbreak, estimate the predicted number of
locations in the genome that will match a given motif, and study the distribution of alleles throughout
an evolving population. In this problem, we will begin discussing the third issue; first, we need to have a
better understanding of what it means to average a random process.

Problem:
For a random variable X taking integer values between 1 and n , the expected value of X is
E(X) = ∑{n, k=1} [k * Pr(X=k)]. The expected value offers us a way of taking the long-term average of a random
variable over a large number of trials.

As a motivating example, let X
be the number on a six-sided die. Over a large number of rolls, we should expect to obtain an average
of 3.5 on the die (even though it's not possible to roll a 3.5). The formula for expected value confirms that
E(X) = ∑{6, k=1} [k * Pr(X=k)] = 3.5

More generally, a random variable for which every one of a number of equally spaced
outcomes has the same probability is called a uniform random variable (in the die example, this "equal
spacing" is equal to 1). We can generalize our die example to find that if X is a uniform random variable
with minimum possible value a and maximum possible value b , then E(X) = (a+b)/2.
You may also wish to verify that for the dice example, if Y is the random variable associated with
the outcome of a second die roll, then E(X+Y)=7 .

Given: Six nonnegative integers, each of which does not exceed 20,000.
The integers correspond to the number of couples in a population possessing each genotype pairing for a given factor.
In order, the six given integers represent the number of couples having the following genotypes:
    AA-AA
    AA-Aa
    AA-aa
    Aa-Aa
    Aa-aa
    aa-aa
Return: The expected number of offspring displaying the dominant phenotype in the next generation,
under the assumption that every couple has exactly two offspring.
'''

# Goal: To calculate the probability of each genotype pairing resulting in offspring with the dominant phenotype.
# P(X) = #Offpsring_Dominant / #Offspring_Total
# Each couple has 2 offspring: #Offspring_Total = 2*(sum)

# prompt user for input type
input_type = input("Enter 'string' to input a string of integers or 'file' to input a text file: ")

# read input based on type chosen by user 
if input_type == 'string':
    input_str = input("Enter six non-negative integers separated by spaces: ")
elif input_type == 'file':
    filename = input("Enter the filename: ")
    # C:\...\13-iev\rosalind_iev.txt
    with open(filename, 'r') as file:
        input_str = file.read()
else:
    print("Invalid input type")
    exit()

# parse the input
genotypes = list(map(int, input_str.split()))

# calculate the total number of offspring
total_offspring = sum(genotypes) * 2

# calculate the probability of each genotype pairing
probabilities = [genotype / total_offspring for genotype in genotypes]

# calculate the expected number of offspring with dominant phenotype
# multiply each probability with the corresponding # of offspring with the dominant phenotype
# add all the results (∑)
expected_offspring = sum(probabilities[i] * (2 if i < 4 else 1) for i in range(6))

# print the result
print(expected_offspring)
