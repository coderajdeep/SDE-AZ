// Time complexity O(n)
// Space complexity O(1)

// If any element's frequency is greater than (n/2) then its a majorith element

// Moore's voting algorithm
// If it's not guaranteed that majority element will exist
// Then we need to check this  
int isMajorityElement(int element, vector<int> &arr) {
    int count = 0, n = arr.size();
    for(int i=0; i<n; ++i) {
        if(element==arr[i]) {
            ++count;
            if(count>(n/2)) {
                return true;
            }
        }
    }
    return false;
}
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    // in place of index, we just can carry the element also
    int count = 0, element;
    for(int i=0; i<n; ++i) {
        if(!count) {
            element = nums[i];
            ++count;
        }
        else if(element==nums[i]) ++count;
        else if(element!=nums[i]) --count;
    }
    // if it is not guaranteed that majoriry element exist then we need to do this below
    // return isMajorityElement(element, nums) ? element : -1;
    // otherwise directly return the element
    return element;
}