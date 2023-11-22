'''
Networks arise everywhere in the practical world, especially in biology. Networks are prevalent in popular applications such as modeling the spread of disease, but the extent of network applications spreads far beyond popular science. Our first question asks how to computationally model a network without actually needing to render a picture of the network.

First, some terminology: graph is the technical term for a network; a graph is made up of hubs called nodes (or vertices), pairs of which are connected via segments/curves called edges. If an edge connects nodes v and w, then it is denoted by v,w (or equivalently w,v).
    an edge v,w is incident to nodes v and w; we say that v and w are adjacent to each other;
    the degree of v is the number of edges incident to it;
    a walk is an ordered collection of edges for which the ending node of one edge is the starting node of the next (e.g., {v1,v2}, {v2,v3}, {v3,v4}, etc.);
    a path is a walk in which every node appears in at most two edges;
    path length is the number of edges in the path;
    a cycle is a path whose final node is equal to its first node (so that every node is incident to exactly two edges in the cycle); and
    the distance between two vertices is the length of the shortest path connecting them.
Graph theory is the abstract mathematical study of graphs and their properties.



A graph whose nodes have all been labeled can be represented by an adjacency list, in which each row of the list contains the two node labels corresponding to a unique edge.

A directed graph (or digraph) is a graph containing directed edges, each of which has an orientation.
That is, a directed edge is represented by an arrow instead of a line segment;
the starting and ending nodes of an edge form its tail and head, respectively.
The directed edge with tail v and head w is represented by (v,w) (but not by (w,v) ).
A directed loop is a directed edge of the form (v,v) .

For a collection of strings and a positive integer k, the overlap graph for the strings is a directed graph
O{k} in which each string is represented by a node, and string s is connected to string t with a
directed edge when there is a length k suffix of s that matches a length k prefix of t , as long as s≠t ;
we demand s≠t to prevent directed loops in the overlap graph (although directed cycles may be present).

Given: A collection of DNA strings in FASTA format having total length at most 10 kbp.
Return: The adjacency list corresponding to O{3}. You may return edges in any order.
'''

'''
To solve the problem without Biopython, we can read the input file in FASTA format and create a list of tuples containing the identifier and DNA string for each sequence. Here are the modified steps:

Open the input file in read mode.

Create an empty list to store the DNA sequences.

Read the input file line by line and extract the identifier and DNA string for each sequence.
Append the identifier and DNA string as a tuple to the list of sequences.

Define a function to find the overlap between two DNA sequences.
The function should take two sequences and a value of 'k' as input and return True if there is a length
'k' suffix of the first sequence that matches a length prefix of the second sequence.
Otherwise, it should return False.

Create an empty dictionary to store the adjacency list.

For each pair of DNA sequences, check if there is an overlap of length 3.
If there is an overlap, add the identifier of the second sequence to the list of values
corresponding to the identifier of the first sequence in the dictionary.
Print the adjacency list in the required format.
'''

'''
Open the input file in read mode using the built-in open() function

Create an empty list seq_list to store the DNA sequences

Read the input file line by line using the readlines() method and extract the identifier and DNA string for each sequence. The strip() method is used to remove any leading or trailing whitespace characters

Append the identifier and DNA string as a tuple to the list of sequences

Define a function find_overlap() to find the overlap between two DNA sequences. The function takes two sequences and a value of k as input and returns True if there is a length k suffix of the first sequence that matches a length k prefix of the second sequence. Otherwise, it returns False

Create an empty dictionary adj_list to store the adjacency list

Iterate over each pair of DNA sequences using nested loops and check for overlap of length 3 using the find_overlap() function. If there is an overlap, add the identifier of the second sequence to the list of values corresponding to the identifier of the first sequence in the dictionary

Print the adjacency list in the required format using nested loops to iterate over the dictionary keys and values

'''
# open input file in read mode
with open("C:/.../12-grph/rosalind_grph.txt", "r") as f:
    lines = f.readlines()

seq_list = []
identifier = ""
sequence = ""

# read input file line by line and extract identifier and DNA string for each sequence
for line in lines:
    if line.startswith(">"):
        if identifier != "":
            seq_list.append((identifier, sequence))
            sequence = ""
        identifier = line.strip()[1:]   # remove ">" from identifier
    else:
        sequence += line.strip()

# append last sequence to list of sequences
seq_list.append((identifier, sequence))

# function to find overlap between two DNA sequences
def find_overlap(s, t, k):
    return s[-k:] == t[:k]

# create empty dictionary to store adjacency list
adj_list = {}

# iterate over each pair of DNA sequences and check for overlap of length 3
for i in range(len(seq_list)):
    for j in range(len(seq_list)):
        if i != j and find_overlap(seq_list[i][1], seq_list[j][1], 3):
            # if there is an overlap, add identifier of second sequence to list of values corresponding to identifier of first sequence in dictionary
            if seq_list[i][0] not in adj_list:
                adj_list[seq_list[i][0]] = []
            adj_list[seq_list[i][0]].append(seq_list[j][0])

# print adjacency list in required format
for key in adj_list:
    for val in adj_list[key]:
        print(key, val)

'''
from Bio import SeqIO

# function to find overlap between two DNA sequences
def find_overlap(s, t, k):
    return s[-k:] == t[:k]

# parse input file in FASTA format and create list of tuples containing identifier and DNA string
records = list(SeqIO.parse("input.fasta", "fasta"))
seq_list = [(r.id, str(r.seq)) for r in records]

# create empty dictionary to store adjacency list
adj_list = {}

# iterate over each pair of DNA sequences and check for overlap of length 3
for i in range(len(seq_list)):
    for j in range(len(seq_list)):
        if i != j and find_overlap(seq_list[i][1], seq_list[j][1], 3):
            # if there is an overlap, add identifier of second sequence to list of values corresponding to identifier of first sequence in dictionary
            if seq_list[i][0] not in adj_list:
                adj_list[seq_list[i][0]] = []
            adj_list[seq_list[i][0]].append(seq_list[j][0])

# print adjacency list in required format
for key in adj_list:
    for val in adj_list[key]:
        print(key, val)
'''