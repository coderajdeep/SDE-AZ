// Min bit flips is required to convert from start to goal -- leetcode 2220

// Time complexity O(start_msb_pos + goal_msb_pos)
// Space complexity O(1)
int minBitFlips(int start, int goal) {
    int count = 0;
    while(start && goal) {
        if((start & 1) != (goal & 1)) {
            ++count;
        }
        start = (start>>1);
        goal = (goal>>1);
    }
    while(start) {
        if(start & 1) {
            ++count;
        }
        start = (start>>1);
    }
    while(goal) {
        if(goal & 1) {
            ++count;
        }
        goal = (goal>>1);
    }
    return count;
}

// Optimized way
// Time complexity θ(total bits need to be flipped in start)
int minBitFlips(int start, int goal) {
    // all of the same bit will be zero
    int num = (start ^ goal);
    // Now need to find number of set bits in num
    // Because this bits need to be flipped in start
    int count = 0;
    while(num) {
        ++count;
        num = (num & (num - 1));
    }
    return count;
}

// Using STL
int minBitFlips(int start, int goal) {
    return __builtin_popcount(start^goal);
    
}