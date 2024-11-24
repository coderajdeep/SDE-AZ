// 35
// Superior Elements - Coding Ninjas - Leaders in an array - geeks
// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// https://www.codingninjas.com/studio/problems/superior-elements_6783446

// Time complexity O(n)
// Space complexity O(1)
void swapElement(int& a, int& b) {
    a = a+b;
    b = a-b;
    a = a-b;
}
void reverseArray(int start, int end, vector<int>& arr) {
    while(start<end) {
        swapElement(arr[start++], arr[end--]);
    }
}
vector<int> leaders(int a[], int n){
    vector<int> ans;
    ans.push_back(a[n-1]);
    if(n==1) return ans;
    int maxElement = a[n-1];
    for(int i=n-2; i>=0; --i) {
        if(a[i]>=maxElement) {
            ans.push_back(a[i]);
            maxElement = a[i];
        }
    }
    reverseArray(0, ans.size()-1, ans);
    return ans;
}

// Same time complexity as above
vector<int> superiorElements(vector<int>&a) {
    int n = a.size();
    vector<int> ans;
    ans.push_back(a[n-1]);
    int maxElement = a[n-1];
    for(int i=n-2; i>=0; --i) {
        if(maxElement<a[i]) {
            ans.push_back(a[i]);
            maxElement = a[i];
        }
    }
    return ans;
}