// Majority element II

// Best approach
// Time complexity O(n)
// Space complexity O(1)
vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0, element1 = INT_MIN, element2 = INT_MIN, len = nums.size()/3;
    for(int element:nums) {
        if(element1 == element) ++count1;
        else if(element2 == element) ++count2;
        else if(count1 == 0) {
            element1 = element;
            count1 = 1;
        }
        else if(count2 == 0) {
            element2 = element;
            count2 = 1;
        }
        else {
            --count1;
            --count2;
        }
    }
    return majorityCheck(element1, element2, len, nums);
}
// majority check is must
vector<int> majorityCheck(int element1, int element2, int len, vector<int> &arr) {
    int cnt1 = 0, cnt2 = 0;
    vector<int> ans;
    for(int element:arr) {
        if(element==element1) ++cnt1;
        if(element==element2) ++cnt2;
    }
    if(cnt1>len) ans.push_back(element1);
    if(cnt2>len) ans.push_back(element2);
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
vector<int> majorityElement(vector<int>& nums) {
    unordered_multiset<int>ums;
    vector<int> ans;
    int len = nums.size()/3;
    for(int element:nums) {
        ums.insert(element);
        if(ums.count(element)>len) {
            if(ans.empty() || ans.back()!=element) {
                ans.push_back(element);
            }
            if(ans.size()==2) return ans;
        }
    }
    return ans;
}

// Same solution
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> um;
    for(int num : nums) {
        um[num]++;
        if(um[num]>(n/3)) {
            if(ans.empty() || ans.back()!=num) {
                ans.push_back(num);
            }
        }
        if(ans.size()==2) return ans;
    }
    return ans;
}