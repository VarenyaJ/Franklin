fasta <- read.delim("file.fasta", header=F, stringsAsFactors=F)
name.idx <- which(grepl("^>", fasta$V1))
fasta.names <- fasta[name.idx,1]
fasta[name.idx,1] <- "<"
df <- as.data.frame(cbind(unlist(strsplit(paste(fasta$V1, collapse=""), "<"))[-1]))
df1<-t(as.data.frame(apply(df,1, function(s){strsplit(s,"")})))
N <- ncol(df1)
df2 <- rbind(df1, rep("A", N), rep("C",N), rep("G",N), rep("T", N))

profile <- apply(df2, 2, table) - 1
consensus <- paste(rownames(profile)[apply(profile,2, which.max)],  collapse="")
cat(consensus, "\n")
print(as.data.frame(profile), row.names=F)