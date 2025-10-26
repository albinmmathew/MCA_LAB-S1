/*PROGRAM 65 ADJACENCY MATRIX USING ARRAYS
@ALBIN MAMMEN MATHEW
Roll No: 08
17/10/2025
*/

#include <stdio.h>

int main() {
	int vertices, edges;
	int src, dest, i, j;

	printf("Enter number of vertices: ");
	scanf("%d", &vertices);

	int adjMatrix[vertices][vertices];

	// Initialize all elements to 0
	for (i = 0; i < vertices; i++) {
		for (j = 0; j < vertices; j++) {
			adjMatrix[i][j] = 0;
		}
	}

	printf("Enter number of edges: ");
	scanf("%d", &edges);

	printf("Enter edges (source destination):\n");
	for (i = 0; i < edges; i++) {
		scanf("%d %d", &src, &dest);
		adjMatrix[src][dest] = 1;
		adjMatrix[dest][src] = 1;	// For undirected graph
	}

	// Display the adjacency matrix
	printf("\nAdjacency Matrix Representation:\n");
	for (i = 0; i < vertices; i++) {
		for (j = 0; j < vertices; j++) {
			printf("%d ", adjMatrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
