// 2sum Problem -- leetcode 1

// Time complexity O(n)
// Space complexity O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; ++i) {
        int element = target - nums[i];
        auto it = mp.find(element);
        if(it == mp.end()) {
            mp[nums[i]] = i;
        }
        else {
            return vector<int> {it->second, i};
        }
    }
    return vector<int> {};
}


// Time complexity O(n)
// Space complexity O(n)
string read(int n, vector<int> book, int target)
{
    unordered_set<int>us;
    for(int i=0; i<n; ++i) {
        if(us.find(target-book[i])==us.end()) {
            us.insert(book[i]);
        }
        else {
            return "YES";
        }
    }
    return "NO";
}
