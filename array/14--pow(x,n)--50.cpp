// leetcode 50
// Implement Pow(x, n)

// Time complexity O(n)
// Space complexity O(1)
// TLE
double myPow(double x, int n) {
    double ans = 1.0;
    if(x==1.0) return ans;
    long nn = n;
    if(nn<0) nn *= (-1);
    for(long i=0; i<nn; ++i) {
        ans = (ans*x);
    }
    if(n<0) {
        ans = (1/ans);
    }
    return ans;
}

// Time complexity O(logn)
// Space complexity O(1)
double myPow(double x, int n) {
    double ans = 1.0;
    if(x==1.0) return ans;
    long nn = n;
    if(nn<0) nn *= (-1);
    while(nn) {
        if(nn%2) {
            ans = (ans*x);
            nn = nn-1;
        }
        else {
            x = (x*x);
            nn = (nn/2);
        }
    }
    if(n<0) {
        ans = (1/ans);
    }
    return ans;
}