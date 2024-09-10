// Implement upper bound for non decreasing array - coding ninja
// https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383
// ***In upper bound, if we assume high = n-1 then if target == arr[n-1] then this will not work
// Later solution, I have solved this edge case
int upperBound(vector<int> &arr, int x, int n){
	int low = 0, high = n, mid;
	if(x<arr[0]) {
		low = 0;
	}
	else if(x>=arr[n-1]) {
		low = n;
	}
	else {
		while(low<high) {
			mid = low + (high - low)/2;
			if(x>=arr[mid]) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
	}
	return low;
}


// *** new working code for upper_bound
int upperBound(vector<int> &arr, int target, int n) {
	int low = 0, high = n-1 , mid;
	if (target < arr.front()) {
		return 0;
	}
	else if (target >= arr.back()) {
		return n;
	}
	else {
		while (low < high) {
			mid = low + (high - low) / 2;
			if (arr[mid] <= target) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
	}
	return low;
}