// 4Sum
// leetcode 18

// Brute force
// Time complexity O(n^4 * log(total unique quadruplets))
// Space complexity O(2 * total unique quadruplets)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n-3; ++i) {
        for(int j=i+1; j<n-2; ++j) {
            for(int k=j+1; k<n-1; ++k) {
                for(int l=k+1; l<n; ++l) {
                    long sum = (long)nums[i]+(long)nums[j]+(long)nums[k]+(long)nums[l];
                    if(sum==target) {
                        vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}

// Hashing approach
// Time complexity O(n^3 * log(no of unique quadruplets))
// Space complexity O(2 * no of unique quadruplets)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n-1; ++i) {
        for(int j=i+1; j<n; ++j) {
            unordered_set<int>s;
            for(int k=0; k<n; ++k) {
                if(k!=i && k!=j) {
                    int num = (target - nums[i] - nums[j] - nums[k]);
                    auto it = s.find(num);
                    if(it!=s.end()) {
                        vector<int> temp{nums[i], nums[j], nums[k], num};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    s.insert(nums[k]);
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}

// Two pointer approach
// Time complexity O(n^3)
// Space complexity if we avoid answer then constant otherwise O(total unique quadruplets)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; ++i) {
        // avoid the duplicates while moving i
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; ++j) {
            // avoid the duplicates while moving j
            if(j>(i+1) && nums[j]==nums[j-1]) continue;
            // two pointers
            int low = j+1;
            int high = n-1;
            while(low<high) {
                long sum = (long)nums[i] + (long)nums[j] + (long)nums[low] + (long)nums[high];
                if(sum>target) high--;
                else if(sum<target) ++low;
                else {
                    ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                    --high;
                    ++low;
                    while(low<high && nums[high]==nums[high+1]) --high;
                    while(low<high && nums[low]==nums[low-1]) ++low;
                }
            }
        }
    }
    return ans;
}