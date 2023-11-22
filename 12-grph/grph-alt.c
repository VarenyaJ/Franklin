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

#include <stdio.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_LENGTH 10000

int main() {
    char labels[MAX_NODES][MAX_LENGTH];
    char strings[MAX_NODES][MAX_LENGTH];
    int num_strings = 0;
    int i, j;

    // Parse the input file in read mode
    FILE* fp = fopen("input.txt", "r");
    // 'fscanf' reads the file, line by line, and extracts the DNA strings into arrays
    while (fscanf(fp, ">%s\n%s", labels[num_strings], strings[num_strings]) == 2) {
        num_strings++;
    }
    fclose(fp);

    // Create the adjacency list
    int adj_list[MAX_NODES][2];
    int num_edges = 0;
    // A directed graph where each node represents a DNA string,
    // and a directed edge from node i to node j represents an overlap between string i and string j
    // As an adjacency list, each row of the list contains the two node labels corresponding to a unique edge
    for (i = 0; i < num_strings; i++) { // Loop through each pair of DNA strings
        for (j = 0; j < num_strings; j++) {
            if (i == j) {   // Skip the case where i and j are the same
                continue;
            }
            int len_i = strlen(strings[i]);
            int len_j = strlen(strings[j]);
            if (len_i < 3 || len_j < 3) {
                continue;
            }
            if (strncmp(strings[i] + len_i - 3, strings[j], 3) == 0) {  // Check if there is an overlap between the suffix of string i and the prefix of string j
                adj_list[num_edges][0] = i; // Add a directed edge from the node representing the suffix to the node representing the prefix
                adj_list[num_edges][1] = j;
                num_edges++;
            }
        }
    }

    // Output the adjacency list
    // Open the output file in write mode then close it at the end
    fp = fopen("output.txt", "w");
    for (i = 0; i < num_edges; i++) {   // Loop through each edge in the adjacency list
        fprintf(fp, "%s %s\n", labels[adj_list[i][0]], labels[adj_list[i][1]]); // Write the two node labels corresponding to the edge to the output file
    }
    fclose(fp);

    return 0;
}
