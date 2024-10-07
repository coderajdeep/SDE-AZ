// Quick Sort has a variable space complexity depending on the pivot selection and the degree of partitioning balance, 
// ranging from O(log n) to O(n).
// Time complexity θ(nlogn) O(n^2) [based upon the pivot selection]

// taking first as a pivot
int partitionArray(int input[], int start, int end) {
	int pivot = input[start];
	int i = start, j = end;
	while(i<j) {
		while(i<=end && pivot >= input[i]) ++i;
		while(j>=start && pivot< input[j]) --j;
		if(i<j) swap(input[i], input[j]);
	}
	swap(input[start], input[j]);
	return j;
}

void quickSort(int input[], int start, int end) {
	if(start<end) {
		int pivotIndex = partitionArray(input, start, end);
		quickSort(input, start, pivotIndex-1);
		quickSort(input, pivotIndex+1, end);
	}
}

// taking last as a pivot
int partitionArray(int input[], int start, int end) {
	int pivot = input[end];
	int i = start, j = end;
	while(i<j) {
		while(i<=end && pivot > input[i]) ++i;
		while(j>=start && pivot <= input[j]) --j;
		if(i<j) swap(input[i], input[j]);
	}
	swap(input[end], input[i]);
	return i;
}

void quickSort(int input[], int start, int end) {
	if(start<end) {
		int pivotIndex = partitionArray(input, start, end);
		quickSort(input, start, pivotIndex-1);
		quickSort(input, pivotIndex+1, end);
	}
}