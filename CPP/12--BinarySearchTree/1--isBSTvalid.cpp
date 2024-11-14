// Time complexity O(n)
// Space complexity O(1)

bool isValidBST(vector<int> &order){
    int n = order.size();
    for(int i=1; i<n; ++i) {
        if(order[i-1]>=order[i]) 
            return false;
    }
    return true;
}
