// Check i-th bit set or not

bool isKthBitSet(int n, int k) {
    return ((n & (1 << (k-1))) != 0);
}