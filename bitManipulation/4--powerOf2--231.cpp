// Check if a number is power of 2 or not -- leetcode 231

// Best solution
// Using Brain Karningam's Algo
// Without using any loop
bool isPowerOfTwo(int n) {
    return (n > 0) && (!(n & (n-1)));
}


bool isPowerOfTwo(int n) {
    if(n<0) return false;
    int count = 0;
    while(n) {
        ++count;
        if(count>1) return false;
        n = (n & (n-1));
        // whenever we substract 1 from any number
        // then from the LSB to first set bit, all bits flips
        // 40 : 00000000 00000000 00000000 00101000
        // 39 : 00000000 00000000 00000000 00100111
    }
    return count == 1;
}

// Brute force way to find total set bits
// Time complexity θ(total bits) -> LSB to MSB
int getTotalSetBit(int n) {
    int count = 0;
    while(n) {
        count += (1 & n);
        n = (n>>1);
    }
    return count;
}
bool isPowerOfTwo(int n) {
    if(n<0) return false;
    int setBitCount = getTotalSetBit(n);
    return (setBitCount == 1);
}

// Brain Karningam's Algorithm
// Time complexity θ(total set bits)
int getTotalSetBit(int n) {
    int count = 0;
    while(n) {
        ++count;
        n = (n & (n-1));
    }
    return count;
}
bool isPowerOfTwo(int n) {
    if(n<0) return false;
    int setBitCount = getTotalSetBit(n);
    return (setBitCount == 1);
}