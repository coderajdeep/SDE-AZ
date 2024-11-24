// Number of nodes present in N-th Level
// Root's level is 1
int numberOfNodes(int N){
    return (1<<(N-1));
}