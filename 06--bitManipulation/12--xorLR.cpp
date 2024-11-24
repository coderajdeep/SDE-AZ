// XOR of [L,R]  -- coding ninjas
// https://www.geeksforgeeks.org/calculate-xor-1-n/
// How optimized approach works

// Time complexity O(R-L)
// Space complexity O(1)
int findXOR(int L, int R){
    int ans = 0;
    for(int i=L; i<=R; ++i) {
        ans ^= i;
    }
    return ans;
}


// Time complexity O(1)
// Space complexity O(1)
// Needs to find xor from 1 to R --> xorR
// And xor from 1 to L-1 --> xorL
// Then we need to calculate xorR ^ xorL
// XOR of first n natural number
int getXOR(int n) {
    int rem = (n%4);
    if(rem==0) return n;
    else if(rem==1) return 1;
    else if(rem==2) return n+1;
    else return 0;
}
int findXOR(int l, int r) {
    if(l == r) return r;
    int xorR = getXOR(r);
    if(l == 1) return xorR;
    int xorL = getXOR(l-1);
    return xorR ^ xorL;
}
/*
*** First n natural number xor
1- Find n % 4. Lets say rem = n % 4
2- If rem = 0, then XOR will be same as n. 
3- If rem = 1, then XOR will be 1. 
4- If rem = 2, then XOR will be n+1. 
5- If rem = 3 ,then XOR will be 0.
*/