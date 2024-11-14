// https://www.codingninjas.com/studio/problems/873366

// Time complexity O(n)
// Space complexity O(n)
pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
	vector<int> freq(n+1, 0);
	for(int i=0; i<n; ++i) {
		freq[arr[i]]++;
	}
	int missing = -1, repeating = -1;
	for(int i=1; i<=n; ++i) {
		if(freq[i]==2) repeating = i;
		else if(freq[i]==0) missing = i;
		if(missing!=-1 && repeating!=-1) break;
	}
	return {missing, repeating};
}


// Time complexity O(n)
// Space complexity O(1)
// Mathematical approach
pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
	int sumDiff = 0, squareSumDiff = 0;
	for(int i=1; i<=n; ++i) {
		sumDiff += (arr[i-1] - i);
		squareSumDiff += (arr[i-1]*arr[i-1] - i*i);
	}
	int num1_plus_num2 = squareSumDiff / sumDiff;
	int missingNum = (num1_plus_num2 - sumDiff)/2;
	int repeatedNum = missingNum + sumDiff;
	return {missingNum, repeatedNum};
}

// Will do Bit manipulation way