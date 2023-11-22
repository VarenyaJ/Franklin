#   Recall the definition of the Fibonacci numbers from “Rabbits and Recurrence Relations”,
#   which followed the recurrence relation Fn=Fn−1+Fn−2 and assumed that each pair of rabbits
#   reaches maturity in one month and produces a single pair of offspring (one male, one female)
#   each subsequent month.
#   
#   Our aim is to somehow modify this recurrence relation to achieve a dynamic programming solution
#   in the case that all rabbits die out after a fixed number of months.
#   See Figure 4 for a depiction of a rabbit tree in which rabbits live for three months
#   (meaning that they reproduce only twice before dying).

n=96
k=17
f=[1]*100
for i in range(2,n):
  f[i]=f[i-1]+f[i-2]
  if i>=k:
    f[i]-=f[(i-k)-1]  
print(f[i])