#Read data
dna <- read.table("rosalind_cons.txt",as.is=T)
acgt <- matrix(c("A","C","G","T"))

dna <- t(apply(matrix(1:dim(dna)[1]),1,function(x){strsplit(dna[x,], NULL)[[1]]}))

#Make Profile
profile <- apply(acgt,1,function(x){
            apply(ifelse(dna==x,1,0),2,sum)
                        })
profile<-t(profile)
rownames(profile)<-acgt

#Make Consensus
c<-matrix(apply(profile,2,max))
consensus <- paste(apply(matrix(1:dim(dna)[2]),1,function(x){rownames(profile)[profile[,x]==c[x]][1]}),collapse="")

#Output Results
rownames(profile)<- c("A:","C:","G:","T:")
write.table(consensus,"output.txt",row.names=F,col.names=F,quote = F)
write.table(profile,"output.txt",row.names=T,col.names=F,quote = F,append=T)