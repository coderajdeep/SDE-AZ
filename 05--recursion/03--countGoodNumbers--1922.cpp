// Time complexity O(2*log(n/2))
// Space complexity O(1)
class Solution {
    const int mod = 1e9+7;
public:
    long long power(long long x, long long n) {
        long long ans = 1;
        while(n) {
            if(n & 1) {
                ans = (ans * x) % mod;
                n = n - 1;
            }
            else {
                x = (x * x) % mod;
                n = (n / 2);
            }
        }
        return ans % mod;
    }
    int countGoodNumbers(long long n) {
        long long oddCount = n/2;
        long long evenCount = (n & 1) ? oddCount + 1 : oddCount;
        return (power(5, evenCount) * power(4, oddCount)) % mod;
    }
};