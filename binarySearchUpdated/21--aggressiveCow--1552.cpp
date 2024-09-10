// Magnetic Force Between Two Balls -- leetcode 1552
// Time complexity O(nlogn) + O(n*log2(max-min))
// Space complexity O(1)
bool isPossible(vector<int>& position, int m, int diff) {
    int n = position.size(), cnt = 1, last = position.front();
    for(int i=1; i<n; ++i) {
        if(position[i]-last>=diff) {
            last = position[i];
            ++cnt;
        }
        if(cnt == m) return true;
    }
    return false;
}
int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    int minElement = position.front(), maxElement = position.back();
    int ans = (maxElement - minElement);
    if(m==2) return ans;
    int low = 1, high = (maxElement - minElement);
    // high = (maxElement - minElement)/(m-1);
    // this high also correct
    // this will take slightly less execution time
    while(low<=high) {
        int mid = low + (high-low)/2;
        bool possible = isPossible(position, m, mid);
        if(possible) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}


// Geeks solution
bool isPossible(vector<int>& stalls, int k, int diff) {
    int n = stalls.size(), cnt = 1, last = stalls.front();
    for(int i=1; i<n; ++i) {
        if(stalls[i]-last>=diff) {
            last = stalls[i];
            ++cnt;
        }
        if(cnt == k) return true;
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    int minElement = stalls.front(), maxElement = stalls.back();
    int ans = (maxElement - minElement);
    if(k==2) return ans;
    int low = 1, high = (maxElement - minElement)/(k-1);
    while(low<=high) {
        int mid = low + (high-low)/2;
        bool possible = isPossible(stalls, k, mid);
        if(possible) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}