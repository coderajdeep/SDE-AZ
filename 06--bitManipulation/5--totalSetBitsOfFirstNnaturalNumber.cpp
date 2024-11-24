// Leetcode 338
// Count total set bits from first N natural number
vector<int> countBits(int n) {
    vector<int> ans(n+1);
    ans[0] = 0;
    for(int i=1; i<=n; ++i) {
        ans[i] = 1 + ans[i & (i-1)];
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)

int countSetBits(int N)
{
    int arr[N+1];
    arr[0] = 0;
    int ans = 0;
    for(int i=1; i<=N; ++i) {
        arr[i] = arr[i&(i-1)] + 1;
        ans += arr[i];
    }
    return ans;
}




/*
   Space Complexity : O(Log(N))

   where 'N' is the number till which we have to count set bits..
*/
int countSetBits(int N)
{
    // We have 'd' which is the size of repeating window.
    // We are using 'x' to run the loop Log(N) times which is equal to the number of bits in its binary representation.
    int d=2,ans=0,x=N;
    while(x)
    {

        // Using the Mathematical formula explained in the Approach.
        ans+=((N+1)/d)*(d/2) + max((N+1)%d-d/2,0);

        // Window size double every time we shift to the next left bit.
        d*=2;
        x/=2;
    }
    return ans;
}