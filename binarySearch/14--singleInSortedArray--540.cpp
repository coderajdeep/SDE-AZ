// Single element in sorted array - leetcode 540

// Best approach
// Time complexity O(logn)
// Space complexity O(1)
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-2]!=nums[n-1]) return nums[n-1];
    // Now we can say that the single element can't be on first or last index
    int low = 1, high = n-2, mid;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]) {
            return nums[mid];
        }
        if(mid%2==1) {
            if(nums[mid]==nums[mid-1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            if(nums[mid]==nums[mid+1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// Coding Ninjas
int getSingleElement(vector<int> &arr){
	int n = arr.size();
	if(n==1) return arr[0];
	int lo = 0, hi = n-1, mid;
	while(lo<=hi) {
		mid = lo + (hi-lo)/2;
		if(mid-1>=0 && mid+1<n && arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) {
			return arr[mid];
		}
		else if(mid-1<0 && arr[mid]!=arr[mid+1]) {
			return arr[mid];
		}
		else if(mid+1>=n && arr[mid]!=arr[mid-1]) {
			return arr[mid];
		}
		// odd
		if(mid&1) {
			if(arr[mid]==arr[mid+1]) {
				hi = mid-1;
			}
			else {
				lo = mid+1;
			}
		}
		else {
			if(arr[mid]==arr[mid+1]) {
				lo = mid+1;
			}
			else {
				hi = mid-1;
			}
		}
	}
	return -1;
}