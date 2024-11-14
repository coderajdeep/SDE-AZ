// Array Can have duplicate elements
// Time complexity O(n+m)
// Space Complexity O(n+m)
// Space is used to store the answer not to calculate the answer
// Solution 1
// Best approach
class Solution{
    public:
    // arr1, arr2 : the arrays
    // n, m: size of arrays
    // Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> arr;
        int i = 0, j = 0, value;
        while(i<n && j<m) {
            if(arr1[i]<=arr2[j]) {
                value = arr1[i++];
            }
            else {
                value = arr2[j++];
            }
            if(arr.empty() || value > arr.back()) {
                arr.push_back(value);
            }
        }
        while(i<n) {
            if(arr.empty() || arr1[i] > arr.back()) {
                arr.push_back(arr1[i]);
            }
            ++i;
        }
        while(j<m) {
            if(arr.empty() || arr2[j] > arr.back()) {
                arr.push_back(arr2[j]);
            }
            ++j;
        }
        return arr;
    }
};

// Solution 2
// Time complexity O((n+m)log(n+m) + (n+m))
// Space complexity O(n+m)
vector<int> sortedArray(vector<int>& a, vector<int>& b) {
    set<int> st;
    for(int element:a) {
        st.insert(element);
    }
    for(int element:b) {
        st.insert(element);
    }
    return vector<int> (st.begin(), st.end());
}