// Capacity to ship packages within D days -- leetcode 1011
// Time complexity O(log(sum of weights - max weight) * N) + O(N)
pair<int, int> totalWeight(vector<int>& weights) {
    int total = 0;
    int maxWeight = INT_MIN;
    for(int weight : weights) {
        maxWeight = max(maxWeight, weight);
        total += weight;
    }
    return pair<int, int> {maxWeight, total};
}
bool isPossible(vector<int>& weights, int days, int midWeight) {
    int dayRequired = 0;
    int totalWeight = 0;
    int n = weights.size();
    for(int i=0; i<n; ++i) {
        totalWeight += weights[i];
        if(totalWeight >= midWeight) {
            ++dayRequired;
            if(dayRequired > days) return false;
            if(totalWeight > midWeight) {
                totalWeight = weights[i];
            }
            else {
                totalWeight = 0;
            }
        } 
    }
    if((totalWeight > 0)  && (totalWeight < midWeight)) ++dayRequired;
    return (dayRequired <= days);
}
int shipWithinDays(vector<int>& weights, int days) {
    pair<int, int> p = totalWeight(weights);
    int low = p.first, high = p.second, mid, ans;
    cout<<low << " "<<high<<endl;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(isPossible(weights, days, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}