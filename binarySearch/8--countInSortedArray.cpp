// Element count in sorted array

int lowerBound(int low, int high, int target, vector<int>& arr) {
	int mid;
	if(target<=arr[0]) {
		low = 0;
	}
	else if(target>arr[high-1]) {
		low = high;
	}
	else {
		while(low<high) {
			mid = low + (high-low)/2;
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
int upperBound(int low, int high, int target, vector<int>& arr) {
	int mid;
	if(target<arr[0]) {
		low = 0;
	}
	else if(target>=arr[high-1]) {
		low = high;
	}
	else {
		while(low<high) {
			mid = low + (high-low)/2;
			if(target>=arr[mid]) {
				low = mid+1;
			}
			else {
				high = mid;
			}
		}
	}
	return low;
}
int count(vector<int>& arr, int n, int x) {
	int lower = lowerBound(0, n, x, arr);
	if(lower==n) return 0;
	else if(arr[lower]!=x) return 0;
	int upper = upperBound(lower, n, x, arr);
	return (upper-lower);
}


// Using STL
int count(vector<int>& arr, int n, int x) {
	int lower = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	if(lower==n) return 0;
	else if(arr[lower]!=x) return 0;
	int upper = upper_bound(arr.begin()+lower, arr.end(), x) - arr.begin();
	return (upper-lower);
}