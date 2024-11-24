// 36
// Reverse number - leetcode 7

int reverse(int x) {
    int ans = 0;
    int intMax = INT_MAX/10;
    int intMin = INT_MIN/10;
    while(x) {
        if((ans>intMax) || (ans<intMin)) {
            return 0;
        }
        ans = (ans*10) + (x%10);
        x = x/10;
    }
    return ans;
}