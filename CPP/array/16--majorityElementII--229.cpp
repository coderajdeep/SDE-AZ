// leetcode 229
// Majority element II (n/3)

// Time complexity O(n)
// Space complexity O(n)
vector<int> majorityElement(vector<int>& nums) {
    unordered_multiset<int>s;
    int n = nums.size();
    int minCount = n/3;
    vector<int>ans;
    for(int i=0; i<n; ++i) {
        s.insert(nums[i]);
        if(ans.empty()) {
            if(s.count(nums[i])>minCount) {
                ans.push_back(nums[i]);
            }
        }
        else {
            if(ans[0]!=nums[i] && s.count(nums[i])>minCount) {
                ans.push_back(nums[i]);
                return ans;
            }
        }
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(1)
vector<int> majorityCheck(int element1, int element2, vector<int>& nums) {
    int n = nums.size();
    int minCount = n/3;
    int count1 = 0, count2 = 0;
    vector<int> ans;
    for(int i=0; i<n; ++i) {
        if(nums[i]==element1) {
            ++count1;
            if(count1>minCount) {
                if(ans.empty()) {
                    ans.push_back(nums[i]);
                }
                else if(ans[0]!=nums[i]) {
                    ans.push_back(nums[i]);
                    return ans;
                }
            }
        }
        else if(nums[i]==element2) {
            ++count2;
            if(count2>minCount) {
                if(ans.empty()) {
                    ans.push_back(nums[i]);
                }
                else if(ans[0]!=nums[i]) {
                    ans.push_back(nums[i]);
                    return ans;
                }
            }
        }
    }
    return ans;
}
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int element1 = 1e9, element2 = 1e9+1, count1 = 0, count2 = 0;
    for(int i=0; i<n; ++i) {
        if(count1==0 && nums[i]!=element2) {
            count1 = 1;
            element1 = nums[i];
        }
        else if(count2==0 && nums[i]!=element1) {
            count2 = 1;
            element2 = nums[i];
        }
        else if(element1 == nums[i]) {
            count1++;
        }
        else if(element2 == nums[i]) {
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }
    return majorityCheck(element1, element2, nums);
}