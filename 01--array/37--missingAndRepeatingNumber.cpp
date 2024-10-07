// Solution 1
// Complecated one
// Bit manipulation
lass Solution {
  public:
    int getBitNo(int num) {
        int bitNo = 0;
        while(true) {
            if((num & (1<<bitNo)) != 0) {
                return bitNo;
            }
            ++bitNo;
        }
        return 32;
    }
    vector<int> findTwoElement(vector<int>& arr) {
        int xr = 0, n = arr.size();
        for(int i=0; i<n; ++i) {
            xr = (xr ^ (i+1) ^ arr[i]);
        }
        // let's say repeating number is x and missing number is y
        // xr = (x^y)
        // as x and y are different means xr is non zero
        // we will find the first set bit position
        int bitNo = getBitNo(xr);
        
        // All of the numbers and 1 to n
        // If we find, whose bit is set on 'bitNo' bit position
        // Then all of the numbers will be cancel out as same number xor is zero
        // x will appear three times and xor will be x
        // so in xr_zero and xr_one will x and y
        // But we need to traverse one more time to figure out the missing and repeating number
        int xr_zero = 0, xr_one = 0;
        for(int i=0; i<n; ++i) {
            if((arr[i] & (1<<bitNo)) == 0) {
                xr_zero ^= arr[i];
            }
            else {
                xr_one ^= arr[i]; 
            }
            if(((i+1) & (1<<bitNo)) == 0) {
                xr_zero ^= (i+1);
            }
            else {
                xr_one ^= (i+1); 
            }
        }
        for(int i=0; i<n; ++i) {
            if(xr_zero==arr[i]) {
                return vector<int> {xr_zero, xr_one};
            }
            else if(xr_one==arr[i]) {
                return vector<int> {xr_one, xr_zero};
            }
        }
        return {};
    }
};

// Solution 2
// Mathematical approach
// Time complexity O(n)
// Space complexity O(1)
vector<int> findTwoElement(vector<int> arr, int n) {
    long val1 = 0, val2 = 0;
    for(int i=0; i<n; ++i) {
        val1 += (i+1-arr[i]);
        // Type casting
        val2 += (static_cast<long>(i+1)*static_cast<long>(i+1) - static_cast<long>(arr[i])*static_cast<long>(arr[i]));
    }
    int missing = (val1 + (val2/val1))/2;
    int repeat = missing - val1;
    return vector<int> {repeat, missing};
}

// Solution 3
// Using Hashing
// Time complexity O(n)
// Space complexity O(n)
vector<int> findTwoElement(vector<int> arr, int n) {
    vector<int> hash(n+1, 0);
    for(int i=0; i<n; ++i) {
        hash[arr[i]]++;
    }
    vector<int> ans(2);
    bool flag1 = false, flag2 = false;
    for(int i=1; i<=n; ++i) {
        if(hash[i]==2) {
            ans[0] = i;
            flag1 = true;
        }
        else if(hash[i]==0) {
            ans[1] = i;
            flag2 = true;
        }
        if(flag1 && flag2) return ans;
    }
    return ans;
}