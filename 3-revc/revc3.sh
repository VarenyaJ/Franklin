# single-line
rev rosalind_revc.txt | tr ATCG TAGC
# multi-line sequences
tr -d "\n" < rosalind_revc.txt | rev | tr ATCG TAGC
# for FASTA
grep -v "^>" rosalind_revc.txt.fasta | tr -d "\n" | rev | tr ATCG TAGC