// Number of NGE -- Coding Ninjas & Geeks for Geeks

void merge(int low, int mid, int high, vector<pair<int, int>> &arr, vector<int> &NGEs) {
        
    int n1 = mid - low + 1;
    int n2 = high - mid;
    pair<int, int> *arr1 = new pair<int, int>[n1];
    pair<int, int> *arr2 = new pair<int, int>[n2];
    
    for(int i=0; i<n1; ++i) {
        arr1[i] = arr[i + low];
    }
    for(int i=0; i<n2; ++i) {
        arr2[i] = arr[i + mid + 1];
    }
    
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2) {
        if(arr1[i].first < arr2[j].first) {
            NGEs[arr1[i].second] += (n2 - j);
            arr[low + k] = arr1[i++];
        }
        else {
            arr[low + k] = arr2[j++];
        }
        ++k;
    }
    while(i<n1) {
        arr[low+k] = arr1[i++];
        ++k;
    }
    while(j<n2) {
        arr[low+k] = arr2[j++];
        ++k;
    }
    delete arr1;
    delete arr2;
}

void mergeSort(int low, int high, vector<pair<int, int>> &arr, vector<int> &NGEs) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(low, mid, arr, NGEs);
        mergeSort(mid+1, high, arr, NGEs);
        merge(low, mid, high, arr, NGEs);
    }
}

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    
    vector<int> NGEs(n , 0);
    vector<int> ans(queries);
    vector<pair<int, int>> arrs(n);
    
    for(int i=0; i<n; ++i) {
        arrs[i] = make_pair(arr[i], i);
    }
    
    mergeSort(0, n-1, arrs, NGEs);
    
    for(int i=0; i<queries; ++i) {
        ans[i] = NGEs[indices[i]];
    }
    
    return ans;
}


// Brute fource
// Time complexity O(Q*n)
// Space complexity O(1) 
int NGE(int index, int n, vector<int>& arr) {
    int count = 0;
    for(int i=index+1; i<n; ++i) {
        if(arr[index]<arr[i]) {
            ++count;
        }
    }
    return count;
}

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    int n = arr.size(), q = query.size();
    vector<int> ans(q);
    for(int i=0; i<q; ++i) {
        ans[i] = NGE(query[i], n, arr);
    }
    return ans;
}