'''
#   Recall the definition of the Fibonacci numbers from “Rabbits and Recurrence Relations”,
#   which followed the recurrence relation Fn=Fn−1+Fn−2 and assumed that each pair of rabbits
#   reaches maturity in one month and produces a single pair of offspring (one male, one female)
#   each subsequent month.
#   
#   Our aim is to somehow modify this recurrence relation to achieve a dynamic programming solution
#   in the case that all rabbits die out after a fixed number of months.
#   See Figure 4 for a depiction of a rabbit tree in which rabbits live for three months
#   (meaning that they reproduce only twice before dying).

Given: Positive integers n ≤ 100 and m ≤ 20.

Return: The total number of pairs of rabbits that will remain after the 'n-th' month if all rabbits
live for 'm' months.
 '''

# Initialize array mat with 2 elements, [1, 1], which represents the number of rabbits in the first two months
mat = [1, 1]
def mortal (months, live): #number of months and max lifespan in months of a rabbit
    for i in range(2, months):
        if (i < live):
            mat.append(mat[len(mat)-2] + mat[len(mat)-1]) 
        elif (i == live or i == live+1):
            mat.append((mat[len(mat)-2] + mat[len(mat)-1]) - 1)
        else:
            mat.append((mat[len(mat)-2] + mat[len(mat)-1]) - (mat[len(mat)-(live+1)]))
    return (mat[len(mat)-1])

print (mortal(96, 17))