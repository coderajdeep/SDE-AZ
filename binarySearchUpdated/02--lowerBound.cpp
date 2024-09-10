// Implement lower bound for non decreasing array - coding ninja
// https://www.codingninjas.com/studio/problems/lower-bound_8165382

// Time complexity O(logn)
// Space complexity O(1)
// ***In lower bound, if we assume high = n-1 then there will be no problem
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n, mid;
	if(x<arr[0]) {
		low = 0;
	}
	else if(x>arr[n-1]) {
		low = n;
	}
	else {
		while(low<high) {
			mid = low + (high - low) / 2;
			if(x <= arr[mid]) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return low;
}

// *** new working code for lower_bound
int lowerBound(vector<int> arr, int n, int target) {
	int low = 0, high = n-1 , mid;
	if (target < arr.front()) {
		return 0;
	}
	else if (target > arr.back()) {
		return n;
	}
	else {
		while (low < high) {
			mid = low + (high - low) / 2;
			if (target <= arr[mid]) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return low;
}


// Same solution
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n , mid;
	if (x < arr.front()) {
		return 0;
	}
	else if (x > arr.back()) {
		return n;
	}
	else {
		while (low < high) {
			mid = low + (high - low) / 2;
			if (x <= arr[mid]) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return low;
}