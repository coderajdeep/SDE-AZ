// Set the right most unset bit - coding ninjas

int setBits(int N){
    // This will be zero if LSB to MSB all bits are set
    // For example 7, 15, 31, 63, 127, 255, ..
    int num = (N & (N+1));
    return (num==0)? N : (N | (N+1));
}