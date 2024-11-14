static bool comp(Item &a, Item &b) {
    return (((double)a.value) / ((double)a.weight)) >= ((double)b.value) / ((double)b.weight);
}
double fractionalKnapsack(int w, Item arr[], int n) {
    sort(arr, arr+n, comp);
    double total = 0;
    for(int i=0; i<n && w>0; ++i) {
        if(arr[i].weight<=w) {
            total += arr[i].value;
            w -= arr[i].weight;
        }
        else if(w>0) {
            total += ((double)arr[i].value/(double)arr[i].weight) * w;
            w = 0;
        }
    }
    return total;
}