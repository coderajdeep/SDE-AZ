// Geeks
// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// https://youtu.be/l8CuET0jlDU
// Time complexity O(k*k*logk)
// Space complexity O(k) + O(k*k)[this is for storing answer]
// This will work if we use k unequal size of array
class Solution
{
    struct Node {
        int value;
        int arrIndex;
        int arrPos;
        Node(int v, int i, int p) {
            value = v;
            arrIndex = i;
            arrPos = p;
        }
    };
    struct COMP {
        bool operator()(const Node &n1, const Node &n2) const {
            return n1.value > n2.value;
        }
    };
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<Node, vector<Node>, COMP> pq;
        for(int i=0; i<k; ++i) {
            if(arr.size()) {
                pq.push({arr[i][0], i, 0});
            }
        }
        vector<int> ans(k*k);
        int index = 0;
        while(!pq.empty()) {
            Node node = pq.top();
            pq.pop();
            ans[index++] = node.value;
            int arrayIndex = node.arrIndex;
            int ePos = node.arrPos;
            if(ePos<arr[arrayIndex].size()-1) {
                pq.push({arr[arrayIndex][ePos+1], arrayIndex, ePos+1});
            }
        }
        return ans;
    }
};





// Sort K sorted array -- geeks
// Time complexity O(NlogK)
// Space complexity O(K) + O(N) which is used to stored/returned the answer
vector <int> nearlySorted(int arr[], int num, int K){
    vector<int> sortedArray(num);
    priority_queue<int, vector<int>, greater<int>> pq;
    // 1 ≤ k < n
    for(int i=0; i<K; ++i) {
        pq.push(arr[i]);
    }
    for(int i=0; i<num; ++i) {
        if((i+K) < num) pq.push(arr[i+K]);
        sortedArray[i] = pq.top();
        pq.pop();
    }
    return sortedArray;
}