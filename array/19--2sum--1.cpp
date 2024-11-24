// 2 sum

// Time complexity O(nlogn)
// Space complexity O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    vector<pair<int, int>>a(n);
    for(int i=0; i<n; ++i) {
        a[i].first = nums[i];
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    int i=0, j=n-1;
    
    while(i<j) {
        if(a[i].first+a[j].first==target)
            return {a[i].second, a[j].second};
        else if(a[i].first+a[j].first>target)
            --j;
        else
            ++i;
    }
    return {};
}

// Time complexity O(n)
// Space complexity O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; ++i) {
        int element = target - nums[i];
        auto it = mp.find(element);
        if(it!=mp.end()) {
            return {it->second, i};
        }
        mp[nums[i]] = i;
    }
    return {};
}