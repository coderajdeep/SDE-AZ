// Tapping Rainwater -- leetcode 42

// Best solution
// Time complexity O(n)
// Space complexity O(1)
int trap(vector<int>& height) {
    int left = 0, right = height.size()-1, leftMax = 0, rightMax = 0, totalWater = 0;
    while(left < right) {
        if(height[left] <= height[right]) {
            if(height[left] >= leftMax) {
                leftMax = height[left];
            }
            else {
                // https://youtu.be/m18Hntz4go8?t=1033
                // How we are make sure there is rightMax exist which is greater equal than leftMax
                totalWater += (leftMax - height[left]);
            }
            ++left;
        }
        else {
            if(height[right] >= rightMax) {
                rightMax = height[right];
            }
            else {
                totalWater += (rightMax - height[right]);
            }
            --right;
        }
    }
    return totalWater;
}

// Time complexity O(n)
// Space complexity O(n)
int trap(vector<int>& height) {
    int n = height.size();
    if(n < 3) return 0;
    int left[n], right[n];
    left[0] = height[0];
    right[n-1] = height[n-1];

    int start = 1, end = n-2;
    while(start<(n-1) && end>=1) {
        left[start] = max(height[start], left[start-1]);
        right[end] = max(height[end], right[end+1]);
        ++start;
        --end;
    }

    int total = 0;
    for(int i=1; i<(n-1); ++i) {
        int wallHeight = min(left[i], right[i]);
        total += (wallHeight > height[i] ? wallHeight - height[i] : 0);
    }
    return total;
}