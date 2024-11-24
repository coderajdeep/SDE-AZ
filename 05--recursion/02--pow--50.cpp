// pow(x, n) -- leetcode 50

// Time complexity O(logn)
// Iterative approach
double myPow(double x, int n) {
    // n range [-2^31, 2^31 - 1]
    // so -n will be out of integer range
    long nn = (0 < n) ? n : -(long)n;
    double ans = 1.0;

    while(nn > 0) {
        if(nn & 1) {
            ans = (ans * x);
            nn = nn - 1;
        }
        else {
            x = x * x;
            nn = nn / 2;
        }
    }

    return (0 < n) ? ans : ((double) 1 / ans);
}

// Iterative
// Time complexity O(logn)
// Space complexity O(1)
double myPow(double x, int n) {
    if(x==1 || x==0 || n==1) return x;
    if(n==0) return 1;
    long N = n;
    if(N<0) {
        N *= (-1);
        x = (double)1/x;
    }
    double ans = 1;
    while(N) {
        if(N & 1) {
            ans = (ans * x);
            N = (N - 1);
        }
        x = (x * x);
        N = (N / 2);
    }
    return ans;
}


// Time complexity O(logn)
// Recursive stack space O(logn)
double powUtils(double x, long n) {
    if(n == 0) return 1;
    if(n & 1) {
        return x * powUtils(x, n-1);
    }
    else {
        double powValue = powUtils(x, n/2);
        return (powValue * powValue);
    }
}
double myPow(double x, int n) {
    // n range [-2^31, 2^31 - 1]
    // so -n will be out of integer range
    long nn = (0 < n) ? n : -(long)n;
    double ans = powUtils(x, nn);
    return (0 < n) ? ans : ((double) 1 / ans);
}

// Time complexity O(logn)
// Recursive stack space O(logn)
double solve(double x, long n) {
    if(n==0) return 1;
    if(n & 1) return x * solve(x, n-1);
    else return solve(x * x, n/2); 
}
double myPow(double x, int n) {
    if(x==1) return x;
    if(n==0) return 1;
    long N = n;
    if(N<0) {
        x = ((double)1/x);
        N *= (-1);
    }
    return solve(x, N);
}


// Time complexity O(logn)
// Space complexity O(logn) -- recursive stack space
double powUtils(double x, long n) {
    if(n==0) return 1;
    double halfPower = powUtils(x, n/2);
    halfPower = (halfPower * halfPower);
    if(n & 1) return (x * (double)halfPower);
    return halfPower;
}
double myPow(double x, int n) {
    long nn = n >= 0 ? n : -(long)n;
    bool isPositive = n >= 0 ? true : false;
    double ans = powUtils(x, n);
    return isPositive ? ans : ((double)1/ans);
}