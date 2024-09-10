// Using STL
// Best solution
// Time complexity O(logn)
// Space complexity O(1)
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int lowerBoundIndex = (lower_bound(a.begin(), a.end(), x) - a.begin());
	// Greater than last element
	if(lowerBoundIndex == n) return pair<int, int> {a.back(), -1};
	// target is present
	if(a[lowerBoundIndex] == x) return pair<int, int> {x, x};
	// Less than first element
	if(lowerBoundIndex == 0) return pair<int, int> {-1, a.front()};
	// In between two elements
	return pair<int, int> {a[lowerBoundIndex-1], a[lowerBoundIndex]};
}


// Time complexity O(logn)
// Space complexity O(1)
int lowerBound(vector<int> &arr, int n, int target) {
	int low = 0, high = n, mid;
	if(arr[0]>target) return 0;
	if(arr[n-1]<target) return n;
	else {
		while(low<high) {
			mid = low + (high - low) / 2;
			if(arr[mid]>=target) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		return low;
	}
	return -1;
}

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int lowBound = lowerBound(arr, n, x);
	// target is greater than all of the element in the array
	if(lowBound == n) return pair<int, int> {arr[n-1], -1};

	if(lowBound == 0) {
		// target exist
		if(arr[0] == x) return pair<int, int> {arr[0], arr[0]};
		// target does not exist
		else return pair<int, int> {-1, arr[0]};
	}
	// target exist
	if(arr[lowBound] == x) return pair<int, int> {arr[lowBound], arr[lowBound]};
	// target does not exist
	return pair<int, int> {arr[lowBound-1], arr[lowBound]};
}


// Time complexity O(2*logn)
// Space complexity O(1)
int lowerBound(vector<int> &arr, int n, int target) {
	int low = 0, high = n, mid;
	if(arr[0]>target) return 0;
	if(arr[n-1]<target) return n;
	else {
		while(low<high) {
			mid = low + (high - low) / 2;
			if(arr[mid]>=target) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		return low;
	}
	return -1;
}
int upperBound(vector<int> &arr, int n, int target) {
	int low = 0, high = n, mid;
	if(arr[0]>target) return 0;
	if(arr[n-1]<target) return n;
	else {
		while(low<high) {
			mid = low + (high - low) / 2;
			if(arr[mid]<=target) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
		return low;
	}
	return -1;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int lowBound = lowerBound(a, n, x);
	// target is greater than all of the element in the array
	if(lowBound==n) {
		return pair<int, int> {a[n-1], -1};
	}
	int upBound = upperBound(a, n, x);
	// target exist in array
	if(lowBound != upBound) {
		return pair<int, int> {a[lowBound], a[lowBound]};
	}
	// target is less than all of the element in the array
	if(lowBound==0) {
		return pair<int, int> {-1, a[0]};
	}
	// target not exist in the array but target is between array elements
	return pair<int, int> {a[lowBound-1], a[lowBound]};
}