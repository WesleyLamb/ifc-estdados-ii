/* C program for solution of Hamiltonian Cycle problem
   using backtracking */
#include<stdio.h>

// Number of vertices in the graph
#define V 6

void printSolution(int path[]);
int isSafe(int v, int graph[V][V], int path[], int pos);
int hamCycleUtil(int graph[V][V], int path[], int pos);
int hamCycle(int graph[V][V]);

// driver program to test above function
int main()
{
    char c;
    int grafo1[V][V] = {{0,1,1,1,0,0},
                        {1,0,1,0,1,0},
                        {1,1,0,0,0,1},
                        {1,0,0,0,0,1},
                        {0,1,0,0,0,1},
                        {0,0,1,1,1,0}};

    hamCycle(grafo1);
    scanf("%c", &c);

    int grafo2[V][V] = {{0,1,1,1,1,1},
                        {1,0,1,1,1,1},
                        {1,1,0,1,1,1},
                        {1,1,1,0,1,1},
                        {1,1,1,1,0,1},
                        {1,1,1,1,1,0}};

    hamCycle(grafo2);
    scanf("%c", &c);

    int grafo3[V][V] = {{0,0,1,0,1,0},
                        {0,0,1,0,0,1},
                        {1,1,0,1,1,0},
                        {0,0,1,0,0,1},
                        {1,0,1,0,0,1},
                        {0,1,0,1,1,0}};

    hamCycle(grafo3);
    scanf("%c", &c);

    int grafo4[V][V] = {{0,0,0,1,0,1},
                        {1,0,0,0,1,0},
                        {1,1,0,1,0,0},
                        {0,1,0,0,0,1},
                        {1,0,1,1,0,0},
                        {0,1,1,0,1,0}};

    hamCycle(grafo4);
    scanf("%c", &c);

    return 0;
}

/* A utility function to check if the vertex v can be added at
   index 'pos' in the Hamiltonian Cycle constructed so far (stored
   in 'path[]') */
int isSafe(int v, int graph[V][V], int path[], int pos)
{
    /* Check if this vertex is an adjacent vertex of the previously
       added vertex. */
    if (graph [ path[pos-1] ][ v ] == 0)
        return 0;

    /* Check if the vertex has already been included.
      This step can be optimized by creating an array of size V */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

/* A recursive utility function to solve hamiltonian cycle problem */
int hamCycleUtil(int graph[V][V], int path[], int pos)
{
    /* base case: If all vertices are included in Hamiltonian Cycle */
    if (pos == V)
    {
        // And if there is an edge from the last included vertex to the
        // first vertex
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return 1;
        else
          return 0;
    }

    // Try different vertices as a next candidate in Hamiltonian Cycle.
    // We don't try for 0 as we included 0 as starting point in hamCycle()
    for (int v = 1; v < V; v++)
    {
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            /* recur to construct rest of the path */
            if (hamCycleUtil (graph, path, pos+1) == 1)
                return 1;

            /* If adding vertex v doesn't lead to a solution,
               then remove it */
            path[pos] = -1;
        }
    }

    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
       then return false */
    return 0;
}

/* This function solves the Hamiltonian Cycle problem using Backtracking.
  It mainly uses hamCycleUtil() to solve the problem. It returns false
  if there is no Hamiltonian Cycle possible, otherwise return true and
  prints the path. Please note that there may be more than one solutions,
  this function prints one of the feasible solutions. */
int hamCycle(int graph[V][V])
{
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    /* Let us put vertex 0 as the first vertex in the path. If there is
       a Hamiltonian Cycle, then the path can be started from any point
       of the cycle as the graph is undirected */
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == 0 )
    {
        printf("\nNão existe solução\n");
        return 0;
    }

    printSolution(path);
    return 1;
}

/* A utility function to print solution */
void printSolution(int path[])
{
    printf ("\nExiste solução:"
            " o Ciclo Hamiltoniano é:\n");
    for (int i = 0; i < V; i++)
        printf(" %d ->", path[i]);

    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}