// Next greater element -- leetcode 496

// Better solution
// Time complexity O(n)
// Space complexity O(n)
void nextGreaterHash(vector<int>& nums, unordered_map<int, int>& umap) {
    stack<int> stk;
    int n = nums.size();
    for(int i=n-1; i>=0; --i) {
        while(!stk.empty() && stk.top()<=nums[i]) {
            stk.pop();
        }
        if(!stk.empty()) {
            umap[nums[i]] = stk.top();
        }
        stk.push(nums[i]);
    }
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    unordered_map<int, int> umap;
    vector<int> ans(n, -1);
    nextGreaterHash(nums2, umap);
    for(int i=0; i<n; ++i) {
        auto it = umap.find(nums1[i]);
        if(it != umap.end()) {
            ans[i] = it->second;
        }
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> um;
    stack<int>stk;
    int n2 = nums2.size();
    for(int i=n2-1; i>=0; --i) {
        while(!stk.empty() && stk.top()<=nums2[i]) {
            stk.pop();
        }
        if(!stk.empty()) {
            um[nums2[i]] = stk.top();
        }
        stk.push(nums2[i]);
    }
    int n1 = nums1.size();
    vector<int> ans(n1);
    for(int i=0; i<n1; ++i) {
        auto it = um.find(nums1[i]);
        if(it!=um.end()) {
            ans[i] = it->second;
        }
        else {
            ans[i] = -1;
        }
    }
    return ans;
}

// coding ninjas
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	stack<int> stk;
	vector<int> ans(n);
	for(int i=n-1; i>=0; --i) {
		while(!stk.empty() && stk.top()<=arr[i]) {
			stk.pop();
		}
		if(stk.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = stk.top();
		}
		stk.push(arr[i]);
	}
	return ans;
}