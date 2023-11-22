dna_profile <- function(dna) {
  dna_tokens <- c('A', 'C', 'G', 'T')
  data.frame(dna=dna_tokens, count=sapply(dna_tokens, function(x) sum(dna==x)))
}

data <- sapply(scan('rosalind_cons.txt', character(), quiet=TRUE), function(x) unlist(strsplit(x, '')))
profile <- Reduce(function(x,y) merge(x,y,'dna'), apply(data, 1, dna_profile))
rownames(profile) <- profile$dn

cat(apply(profile[,-1],2,function(x) rownames(profile)[which.max(x)]), "\n", sep='')
profile$dna <- sapply(profile$dna, function(x) paste(x, ':', sep=''))
apply(profile, 1, function(x) cat(x, "\n"))