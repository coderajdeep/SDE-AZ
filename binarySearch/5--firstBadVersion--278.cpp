// First bad version 
// leetcode 275

int firstBadVersion(int n) {
    int low = 1, high = n, mid;
    while(low<high) {
        mid = low + (high - low) / 2;
        if(isBadVersion(mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}