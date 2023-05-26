//  Compilation:
//  g++ prot.cpp -o prot.out
//  Executiong:
//  cat rosalind_prot.txt | prot.out > prot.answer

#include <iostream>

int nucleotide2int(char n)
{
    switch (n) {
        case 'U': return 0;
        case 'C': return 1;
        case 'A': return 2;
        case 'G': return 3;
    }
}

char translate(const char codon[3])
{
    char aminoacids[] = {
        'F', 'F', 'L', 'L', 'S', 'S', 'S', 'S',
        'Y', 'Y', '\n','\n','C', 'C', '\n','W',
        'L', 'L', 'L', 'L', 'P', 'P', 'P', 'P',
        'H', 'H', 'Q', 'Q', 'R', 'R', 'R', 'R',
        'I', 'I', 'I', 'M', 'T', 'T', 'T', 'T',
        'N', 'N', 'K', 'K', 'S', 'S', 'R', 'R',
        'V', 'V', 'V', 'V', 'A', 'A', 'A', 'A',
        'D', 'D', 'E', 'E', 'G', 'G', 'G', 'G'};

    int index = 16*nucleotide2int(codon[0]) + 4*nucleotide2int(codon[1]) + nucleotide2int(codon[2]);

    return aminoacids[index];
}

int main()
{
    using std::cin;
    using std::cout;

    char codon[3];

    while (cin.read(codon, 3) && !cin.eof()) {
        char aa = translate(codon);
        if (aa == '\n')
            return 0;
        cout << aa;
    }

}