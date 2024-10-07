// Leaders in an array -- Coding Ninjas

// Time complexity O(n)
// Space complexity O(n) --> space is used for storing the answer
vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int n = a.size(), largestElement = a.back();
    ans.push_back(largestElement);
    for(int i=n-2; i>=0; --i) {
        if(a[i]>largestElement) {
            largestElement = a[i];
            ans.push_back(largestElement);
        }
    }
    return ans;
}