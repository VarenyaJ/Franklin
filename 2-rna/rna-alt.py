import argparse

def transcribe(dna):
    rna = dna.replace('T', 'U')
    return rna

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Transcribe DNA to RNA')
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--string', type=str, help='DNA string to transcribe')
    group.add_argument('--file', type=str, help='path to file containing DNA string')

    args = parser.parse_args()

    if args.string:
        dna = args.string
    elif args.file:
        with open(args.file, 'r') as f:
            dna = f.read()
    else:
        print('Error: please specify either --string or --file')
        exit()

    rna = transcribe(dna)
    print(rna)


'''
ArgParse
# Note to self: look into using Click CLI as an alternative to ArgParse

# Transcribe a DNA string entered as a command-line argument
$ python transcribe.py --string GATGGAACTTGACTACGTAAATT
GAUGGAACUUGACUACGUAAAUU

# Transcribe a DNA string from a file
$ python transcribe.py --file dna.txt
GAUGGAACUUGACUACGUAAAUU

'''