// Find ceil and floor of a number in array

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr + n);
	auto lower = lower_bound(arr, arr + n, x);
	int lowerIndex = lower - arr;
	if(lowerIndex==n) {
		return {arr[n-1], -1};
	}
	else if(arr[lowerIndex]==x) {
		return {x, x};
	}
	else if(lowerIndex==0) {
		return {-1, arr[0]};
	}
	else {
		return {arr[lowerIndex-1], arr[lowerIndex]};
	}
}

// Write own lower bound
int lowerBound(int n, int target, int* arr) {
	int low = 0, high = n, mid;
	if(target<=arr[0]) {
		low = 0;
	}
	else if(target>arr[n-1]) {
		low = n;
	}
	else {
		while(low<high) {
			mid = low + (high - low) / 2;
			if(target<=arr[mid]) {
				high = mid;
			}
			else {
				low = mid+1;
			}
		}
	}
	return low;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr + n);
	int lowerIndex = lowerBound(n, x, arr);
	if(lowerIndex==n) {
		return {arr[n-1], -1};
	}
	else if(arr[lowerIndex]==x) {
		return {x, x};
	}
	else if(lowerIndex==0) {
		return {-1, arr[0]};
	}
	else {
		return {arr[lowerIndex-1], arr[lowerIndex]};
	}
}
