// Minimum number of days to make m bouquets -- leetcode 1482

// Time complexity O(log(max value - min value in array) * n)
// Space complexity O(1)
bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
    int cnt = 0, count = 0;
    for(int element:bloomDay) {
        if(element<=day) {
            ++cnt;
            if(cnt==k) {
                cnt = 0;
                ++count;
            }
        }
        else {
            cnt = 0;
        }
    }
    return (count >= m);
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long totalFlowerNeeded = (long)m * (long)k;
    if(totalFlowerNeeded>(long)n) return -1;
    int low = INT_MAX, high = INT_MIN;
    for(int element:bloomDay) {
        low = min(low, element);
        high = max(high, element);
    }
    int mid, minDay;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(isPossible(bloomDay, m, k, mid)) {
            minDay = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return minDay;
}