// 20
// leetcode 15
// 3 SUM

// Time complexity O(n^3log(total unique tuple))
// Space complexity O(2*total unique tuple)
// This will give TLE
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n-2; ++i) {
        for(int j=i+1; j<n-1; ++j) {
            for(int k=j+1; k<n; ++k) {
                if((nums[i]+nums[j]+nums[k])==0) {
                    vector<int> temp{nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}

// Time complexity O(n^2 * logn) 
// Space complexity O(n + 2*total unique tuple) 
// This is giving TLE
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n; ++i) {
        int sum = -nums[i];
        unordered_set<int> s;
        for(int j=0; j<n; ++j) {
            if(j!=i) {
                auto it = s.find(sum-nums[j]);
                if(it!=s.end()) {
                    vector<int> temp{nums[i], nums[j], *it};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                s.insert(nums[j]);
            }
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}


// Time complexity O(n^2 + nlogn) ~ O(n^2)
// Space complexity O(1) [Not considering returning 2D array]
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int index=0; index<n; ++index) {
        if(index>0 && nums[index-1]==nums[index]) continue;
        int low = index+1;
        int high = n-1;
        while(low<high) {
            int sum = nums[index] + nums[low] + nums[high];
            if(sum>0) --high;
            else if(sum<0) ++low;
            else {
                ans.push_back({nums[index], nums[low], nums[high]});
                ++low;
                --high;
                while(low<high && nums[low]==nums[low-1]) ++low;
                while(low<high && nums[high]==nums[high+1]) --high;
            }
        }
    }
    return ans;
}