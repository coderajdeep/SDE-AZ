// Square root of a number -- coding ninjas

// Time complexity O(logn)
// Space complexity O(1)
int floorSqrt(int n) {
    if(n<=1) return n;
    if(n<9) return 2;
    long long low = 3, high = (n/2), mid, squareValue;
    while(low <= high) {
        mid = low + (high - low) / 2;
        squareValue = mid * mid;
        if(n == squareValue) {
            // if this occures, then n is the perfect square
            return mid;
        }
        else if(squareValue < n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
        
    }
    // If flows reach to this point then n is not a perfet square
    // high is the highest possible integer which is less than the actual square root
    // low is the lowest possible integer which is greater than the actual square root
    // so actual square root lies between (high, low)
    return high;
}