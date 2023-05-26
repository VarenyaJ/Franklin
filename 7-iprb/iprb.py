# Return of the Punnet Square

#Problem 7: Mendel's First Law
#Given: Three positive integers k, m, and n, representing a population containing k+m+nk+m+n organisms:
#   kk individuals are homozygous dominant for a factor, mm are heterozygous, and nn are homozygous recessive.
#Return: The probability that two randomly selected mating organisms will produce an individual possessing a dominant allele
#   (and thus displaying the dominant phenotype). Assume that any two organisms can mate.

def probability (homozygous_dominant, heterozygous, homozygous_recessive):
    sum = 0
    P_SumTotalMinusOne = (homozygous_dominant + heterozygous + homozygous_recessive - 1)
    P_dominant = (homozygous_dominant / (homozygous_dominant + heterozygous + homozygous_recessive))
    P_heterozygous = (heterozygous / (homozygous_dominant + heterozygous + homozygous_recessive))
    P_recessive = (homozygous_recessive / (homozygous_dominant + heterozygous + homozygous_recessive))
    for i in range (0, 9):
        if (i == 0):
            sum = sum + P_dominant * ((homozygous_dominant - 1) / P_SumTotalMinusOne)
        elif (i == 2):
            sum = sum + P_dominant * (heterozygous / P_SumTotalMinusOne)
        elif (i == 3):
            sum = sum + P_dominant * (homozygous_recessive / P_SumTotalMinusOne)
        elif (i == 4):
            sum = sum + P_heterozygous * (homozygous_dominant / P_SumTotalMinusOne)
        elif (i == 5):
            sum = sum + P_heterozygous * ((heterozygous - 1) / P_SumTotalMinusOne) * 0.75
        elif (i == 6):
            sum = sum + P_heterozygous * (homozygous_recessive / P_SumTotalMinusOne) * 0.5
        elif (i == 7):
            sum = sum + P_recessive * (homozygous_dominant / P_SumTotalMinusOne)
        elif (i == 8):
            sum = sum + P_recessive * (heterozygous / P_SumTotalMinusOne) * 0.5
    return sum

print(probability(15,29,23))