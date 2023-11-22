/*
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
*/


/*
Check if the correct number of arguments have been provided to the program

Open the input file in read mode using the built-in fopen() function

Create an empty list seq_list to store the DNA sequences. Allocate memory for 1000 sequences

Read the input file line by line using the kseq_read() function from the kseq.h library and extract the DNA string for each sequence. Allocate memory for each sequence string

Create an empty dictionary adj_list to store the adjacency list. Allocate memory for 1000 key-value pairs

Iterate over each pair of DNA sequences using nested loops and check for overlap of length 3 using the find_overlap() function. If there is an overlap, add the key-value pair to the adjacency list

Print the adjacency list in the required format using a loop to iterate over the key-value pairs

Free memory allocated for sequences and adjacency list

Close the input file using the built-in fclose() function
*/

#include <stdio.h>
#include <stdlib.h>
#include "kseq.h"

// declare the type of file handler and the read() function
KSEQ_INIT(FILE*, kseq_read)

// function to find overlap between two DNA sequences
int find_overlap(char* s, char* t, int k) {
    int i, j;
    for (i = 0, j = strlen(t) - k; i < k; i++, j++) {
        if (s[i] != t[j]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.fasta>\n", argv[0]);
        return 1;
    }

    // open input file in read mode
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // create empty list of DNA sequences
    char** seq_list = malloc(sizeof(char*) * 1000);
    int seq_count = 0;

    // read input file line by line and extract DNA string for each sequence
    kseq_t* seq = kseq_init(fp);
    while (kseq_read(seq) >= 0) {
        seq_list[seq_count] = malloc(sizeof(char) * (seq->seq.l + 1));
        strcpy(seq_list[seq_count], seq->seq.s);
        seq_count++;
    }
    kseq_destroy(seq);

    // create empty dictionary to store adjacency list
    char** adj_list_keys = malloc(sizeof(char*) * 1000);
    char** adj_list_vals = malloc(sizeof(char*) * 1000);
    int adj_count = 0;

    // iterate over each pair of DNA sequences and check for overlap of length 3
    for (int i = 0; i < seq_count; i++) {
        for (int j = 0; j < seq_count; j++) {
            if (i != j && find_overlap(seq_list[i], seq_list[j], 3)) {
                // if there is an overlap, add identifier of second sequence to list of values corresponding to identifier of first sequence in dictionary
                adj_list_keys[adj_count] = malloc(sizeof(char) * 10);
                sprintf(adj_list_keys[adj_count], "seq%d", i+1);
                adj_list_vals[adj_count] = malloc(sizeof(char) * 10);
                sprintf(adj_list_vals[adj_count], "seq%d", j+1);
                adj_count++;
            }
        }
    }

    // print adjacency list in required format
    for (int i = 0; i < adj_count; i++) {
        printf("%s %s\n", adj_list_keys[i], adj_list_vals[i]);
    }

    // free memory allocated for sequences and adjacency list
    for (int i = 0; i < seq_count; i++) {
        free(seq_list[i]);
    }
    free(seq_list);
    for (int i = 0; i < adj_count; i++) {
        free(adj_list_keys[i]);
        free(adj_list_vals[i]);
    }
    free(adj_list_keys);
    free(adj_list_vals);

    // close input file
    fclose(fp);

    return 0;
}
