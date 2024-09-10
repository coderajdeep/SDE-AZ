// Return the number of undirected graphs that can be formed using 'N' vertices, allowing for disconnected components within the graph. 
// Self-edges and multiple edges are not allowed.

int countingGraphs(int N)
{
    int power = (N * (N-1)) / 2;
    return (1<<power);
}